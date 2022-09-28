#pragma once

#include "AuxKernel.h"

class FieldAux;

template <>
InputParameters validParams<FieldAux>();

class FieldAux : public AuxKernel
{
public:
  FieldAux(const InputParameters & parameters);

protected:
  virtual Real computeValue() override;

  const VariableGradient & _grad_potential;
};
