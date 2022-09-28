#pragma once

#include "Kernel.h"

class GndStateIonizationElectrons;

template <>
InputParameters validParams<GndStateIonizationElectrons>();

/**
 *
 */
class GndStateIonizationElectrons : public Kernel
{
public:
  GndStateIonizationElectrons(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;

private:
  const VariableValue & _second_species_density;

  const MaterialProperty<Real> & _k;

  const VariableValue & _mean_en;
};
