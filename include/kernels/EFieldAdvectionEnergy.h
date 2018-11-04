#ifndef EFIELDADVECTIONENERGY_H
#define EFIELDADVECTIONENERGY_H

#include "Kernel.h"

class EFieldAdvectionEnergy;

template <>
InputParameters validParams<EFieldAdvectionEnergy>();

/**
 *
 */
class EFieldAdvectionEnergy : public Kernel
{
public:
  EFieldAdvectionEnergy(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

private:
  const VariableGradient & _grad_potential;

  const VariableValue & _electron_density;

  Real _mobility;

  unsigned int _potential_id;

  unsigned int _electron_id;
};

#endif // EFIELDADVECTIONENERGY_H
