#include "ElectronDiffusionEnergy.h"

registerMooseObject("TutorialApp", ElectronDiffusionEnergy);

template <>
InputParameters
validParams<ElectronDiffusionEnergy>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredParam<Real>("diffusivity", "Diffusivity of the species.");
  params.addRequiredCoupledVar("electrons", "Electron species density coupled variable.");
  return params;
}

ElectronDiffusionEnergy::ElectronDiffusionEnergy(const InputParameters & parameters)
  : Kernel(parameters),

    _diffusivity(getParam<Real>("diffusivity")),
    _electron_density(coupledValue("electrons")),
    _grad_electron_density(coupledGradient("electrons")),
    _electron_id(coupled("electrons"))
{
}

Real
ElectronDiffusionEnergy::computeQpResidual()
{
  return -_grad_test[_i][_qp] * (5 / 3) * -_diffusivity * std::exp(_u[_qp]) *
         std::exp(_electron_density[_qp]) * _grad_electron_density[_qp];
}

Real
ElectronDiffusionEnergy::computeQpJacobian()
{
  return -_grad_test[_i][_qp] * (5 / 3) * -_diffusivity * std::exp(_u[_qp]) * _phi[_j][_qp] *
         std::exp(_electron_density[_qp]) * _grad_electron_density[_qp];
}

Real
ElectronDiffusionEnergy::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _electron_id)
    return -_grad_test[_i][_qp] * (5 / 3) * -_diffusivity * std::exp(_u[_qp]) *
           (std::exp(_electron_density[_qp]) * _phi[_j][_qp] * _grad_electron_density[_qp] +
            std::exp(_electron_density[_qp]) * _grad_phi[_j][_qp]);

  else
    return 0;
}
