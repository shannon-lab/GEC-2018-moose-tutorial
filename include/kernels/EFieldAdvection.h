#pragma once

#include "Kernel.h"

class EFieldAdvection : public Kernel
{
public:
  static InputParameters validParams();

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
