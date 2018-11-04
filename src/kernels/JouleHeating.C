#include "JouleHeating.h"

registerMooseObject("TutorialApp", JouleHeating);

template <>
InputParameters
validParams<JouleHeating>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("electrons", "Electron density variable.");
  params.addRequiredParam<Real>("diffusivity", "Electron diffusivity.");
  params.addRequiredParam<Real>("mobility", "Electron mobility.");
  params.addRequiredCoupledVar("potential", "The electric potential.");
  return params;
}

JouleHeating::JouleHeating(const InputParameters & parameters)
  : Kernel(parameters),

    _electron_density(coupledValue("electrons")),
    _grad_electron_density(coupledGradient("electrons")),
    _diffusivity(getParam<Real>("diffusivity")),
    _mobility(getParam<Real>("mobility")),
    _grad_potential(coupledGradient("potential")),
    _e(1.602177e-19),
    _electron_id(coupled("electrons")),
    _potential_id(coupled("potential"))
{
}

Real
JouleHeating::computeQpResidual()
{
  return -_test[_i][_qp] * _e *
         (-_diffusivity * _grad_electron_density[_qp] +
          _mobility * _electron_density[_qp] * _grad_potential[_qp]) *
         _grad_potential[_qp];
}

Real
JouleHeating::computeQpJacobian()
{
  return 0;
}

Real
JouleHeating::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _electron_id)
    return -_test[_i][_qp] * _e *
           (-_diffusivity * _grad_phi[_j][_qp] + _mobility * _phi[_j][_qp] * _grad_potential[_qp]) *
           _grad_potential[_qp];

  else if (jvar == _potential_id)
    return -_test[_i][_qp] * _e *
           (-_diffusivity * _grad_electron_density[_qp] * _grad_phi[_j][_qp] +
            2 * _mobility * _electron_density[_qp] * _grad_potential[_qp] * _grad_phi[_j][_qp]);

  else
    return 0;
}
