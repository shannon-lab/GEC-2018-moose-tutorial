#include "EnergyIonization.h"
#include "Function.h"

registerMooseObject("TutorialApp", EnergyIonization);

template <>
InputParameters
validParams<EnergyIonization>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("electrons", "Electron density coupled variable.");
  params.addRequiredParam<Real>("background_gas_density", "The background gas density.");
  return params;
}

EnergyIonization::EnergyIonization(const InputParameters & parameters)
  : Kernel(parameters),

    _k(getMaterialProperty<Real>("ki")),
    _electron_density(coupledValue("electrons")),
    _N_gas(getParam<Real>("background_gas_density")),
    _energy_exchange(15.7),
    _electron_id(coupled("electrons"))
{
}

Real
EnergyIonization::computeQpResidual()
{
  return _test[_i][_qp] * _energy_exchange * _k[_qp] * _N_gas * _electron_density[_qp];
}

Real
EnergyIonization::computeQpJacobian()
{
  return _test[_i][_qp] * _energy_exchange * _N_gas * _electron_density[_qp] *
         (2.34e-14 * 0.59 * std::pow((2 / 3), 0.59) * std::pow(_u[_qp], -0.41) *
              std::exp(-17.44 * 3 / (2 * _u[_qp])) +
          2.34e-14 * std::pow((2 * _u[_qp] / 3), 0.59) * (17.44 * 3 / (2 * _u[_qp] * _u[_qp])) *
              std::exp(-17.44 * 3 / (2 * _u[_qp])));
}

Real
EnergyIonization::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _electron_id)
    return _test[_i][_qp] * _energy_exchange * _k[_qp] * _N_gas * _phi[_j][_qp];

  else
    return 0;
}
