#include "GndStateIonizationElectrons.h"

registerMooseObject("TutorialApp", GndStateIonizationElectrons);

template <>
InputParameters
validParams<GndStateIonizationElectrons>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("second_species", "Second species involved in reaction.");
  params.addRequiredCoupledVar("mean_energy", "Electron mean energy variable name.");
  return params;
}

GndStateIonizationElectrons::GndStateIonizationElectrons(const InputParameters & parameters)
  : Kernel(parameters),

    _second_species_density(coupledValue("second_species")),
    _k(getMaterialProperty<Real>("ki")),
    _mean_en(coupledValue("mean_energy"))
{
}

Real
GndStateIonizationElectrons::computeQpResidual()
{
  return -_test[_i][_qp] * _k[_qp] * _second_species_density[_qp] * _u[_qp];
}

Real
GndStateIonizationElectrons::computeQpJacobian()
{
  return 0;
}
