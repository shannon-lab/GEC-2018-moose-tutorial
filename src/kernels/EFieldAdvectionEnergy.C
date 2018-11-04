#include "EFieldAdvectionEnergy.h"

registerMooseObject("TutorialApp", EFieldAdvectionEnergy);

template <>
InputParameters
validParams<EFieldAdvectionEnergy>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("potential", "The electric potential.");
  params.addRequiredCoupledVar("electrons", "The electron density.");
  params.addRequiredParam<Real>("mobility", "Electron mobility.");
  return params;
}

EFieldAdvectionEnergy::EFieldAdvectionEnergy(const InputParameters & parameters)
  : Kernel(parameters),

    _grad_potential(coupledGradient("potential")),
    _electron_density(coupledValue("electrons")),
    _mobility(getParam<Real>("mobility")),
    _potential_id(coupled("potential")),
    _electron_id(coupled("electrons"))
{
}

Real
EFieldAdvectionEnergy::computeQpResidual()
{
  return -_grad_test[_i][_qp] * (5 / 3) * std::exp(_u[_qp]) * _mobility *
         std::exp(_electron_density[_qp]) * _grad_potential[_qp];
}

Real
EFieldAdvectionEnergy::computeQpJacobian()
{
  return -_grad_test[_i][_qp] * (5 / 3) * std::exp(_u[_qp]) * _phi[_j][_qp] * _mobility *
         std::exp(_electron_density[_qp]) * _grad_potential[_qp];
}

Real
EFieldAdvectionEnergy::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _potential_id)
    return -_grad_test[_i][_qp] * (5 / 3) * std::exp(_u[_qp]) * _mobility *
           std::exp(_electron_density[_qp]) * _grad_phi[_j][_qp];

  else if (jvar == _electron_id)
    return -_grad_test[_i][_qp] * (5 / 3) * std::exp(_u[_qp]) * _mobility *
           std::exp(_electron_density[_qp]) * _phi[_j][_qp] * _grad_potential[_qp];

  else
    return 0;
}
