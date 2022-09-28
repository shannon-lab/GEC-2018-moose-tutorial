#pragma once

#include "Kernel.h"

class GndStateIonizationElectrons : public Kernel
{
public:
  static InputParameters validParams();

  GndStateIonizationElectrons(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;

private:
  const VariableValue & _second_species_density;

  const MaterialProperty<Real> & _k;

  const VariableValue & _mean_en;
};
