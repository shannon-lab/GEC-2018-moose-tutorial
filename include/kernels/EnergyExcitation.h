#ifndef ENERGYEXCITATION_H
#define ENERGYEXCITATION_H

#include "Kernel.h"

class EnergyExcitation;

template <>
InputParameters validParams<EnergyExcitation>();

/**
 *
 */
class EnergyExcitation : public Kernel
{
public:
  EnergyExcitation(const InputParameters & parameters);

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

#endif // ENERGYEXCITATION_H
