#include "CoupledEnergyDiffusion.h"

registerMooseObject("TutorialApp", CoupledEnergyDiffusion);

template <>
InputParameters
validParams<CoupledEnergyDiffusion>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredParam<Real>("diffusivity", "Diffusivity of the species.");
  params.addRequiredCoupledVar("electrons", "Electron species density coupled variable.");
  return params;
}

CoupledEnergyDiffusion::CoupledEnergyDiffusion(const InputParameters & parameters)
  : Kernel(parameters),

    _diffusivity(getParam<Real>("diffusivity")),
    _electron_density(coupledValue("electrons")),
    _electron_id(coupled("electrons"))
{
}

Real
CoupledEnergyDiffusion::computeQpResidual()
{
  return -_grad_test[_i][_qp] * (5 / 3) * -_diffusivity * std::exp(_electron_density[_qp]) *
         std::exp(_u[_qp]) * _grad_u[_qp];
}

Real
CoupledEnergyDiffusion::computeQpJacobian()
{
  return -_grad_test[_i][_qp] * (5 / 3) * -_diffusivity * std::exp(_electron_density[_qp]) *
         (std::exp(_u[_qp]) * _grad_phi[_j][_qp] +
          std::exp(_u[_qp]) * _phi[_j][_qp] * _grad_u[_qp]);
}

Real
CoupledEnergyDiffusion::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _electron_id)
    return -_grad_test[_i][_qp] * (5 / 3) * -_diffusivity * std::exp(_electron_density[_qp]) *
           _phi[_j][_qp] * std::exp(_u[_qp]) * _grad_u[_qp];

  else
    return 0;
}
