#include "FieldAux.h"

registerMooseObject("TutorialApp", FieldAux);

InputParameters
FieldAux::validParams()
{
  InputParameters params = AuxKernel::validParams();
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
