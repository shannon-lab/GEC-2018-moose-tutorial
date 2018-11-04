#ifndef EFIELDADVECTION_H
#define EFIELDADVECTION_H

#include "Kernel.h"

class EFieldAdvection;

template <>
InputParameters validParams<EFieldAdvection>();

/**
 *
 */
class EFieldAdvection : public Kernel
{
public:
  EFieldAdvection(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

private:
  const VariableGradient & _grad_potential;

  Real _mobility;

  Real _sign;

  unsigned int _potential_id;
};

#endif // EFIELDADVECTION_H
