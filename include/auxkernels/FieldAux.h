#pragma once

#include "AuxKernel.h"

class FieldAux : public AuxKernel
{
public:
  static InputParameters validParams();

  FieldAux(const InputParameters & parameters);

protected:
  virtual Real computeValue() override;

  const VariableGradient & _grad_potential;
};
