#include "EFieldAdvection.h"

registerMooseObject("TutorialApp", EFieldAdvection);

InputParameters
EFieldAdvection::validParams()
{
  InputParameters params = Kernel::validParams();
  params.addRequiredCoupledVar("potential", "The electric potential.");
  params.addRequiredParam<Real>("mobility", "Electron mobility.");
  params.addRequiredParam<Real>("sign", "Species charge sign (1.0 or -1.0).");
  return params;
}

EFieldAdvection::EFieldAdvection(const InputParameters & parameters)
  : Kernel(parameters),

    _grad_potential(coupledGradient("potential")),
    _mobility(getParam<Real>("mobility")),
    _sign(getParam<Real>("sign")),
    _potential_id(coupled("potential"))
{
}

Real
EFieldAdvection::computeQpResidual()
{
  return _sign * _mobility * _u[_qp] * _grad_potential[_qp] * _grad_test[_i][_qp];
}

Real
EFieldAdvection::computeQpJacobian()
{
  return _sign * _mobility * _phi[_j][_qp] * _grad_potential[_qp] * _grad_test[_i][_qp];
}

Real
EFieldAdvection::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _potential_id)
    return _sign * _mobility * _u[_qp] * _grad_phi[_j][_qp] * _grad_test[_i][_qp];

  else
    return 0;
}
