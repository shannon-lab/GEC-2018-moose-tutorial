#include "FieldAux.h"

registerMooseObject("TutorialApp", FieldAux);

template <>
InputParameters
validParams<FieldAux>()
{
  InputParameters params = validParams<AuxKernel>();
  params.addRequiredCoupledVar("potential", "The potential variable.");
  return params;
}

FieldAux::FieldAux(const InputParameters & parameters)
  : AuxKernel(parameters),

    _grad_potential(coupledGradient("potential"))
{
}

Real
FieldAux::computeValue()
{
  return -_grad_potential[_qp](0);
}
