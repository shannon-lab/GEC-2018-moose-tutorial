#ifndef ENERGYIONIZATION_H
#define ENERGYIONIZATION_H

#include "Kernel.h"

class EnergyIonization;

template <>
InputParameters validParams<EnergyIonization>();

/**
 *
 */
class EnergyIonization : public Kernel
{
public:
  EnergyIonization(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

private:
  const MaterialProperty<Real> & _k;

  const VariableValue & _electron_density;

  Real _N_gas;

  Real _energy_exchange;

  unsigned int _electron_id;
};

#endif // ENERGYIONIZATION_H
