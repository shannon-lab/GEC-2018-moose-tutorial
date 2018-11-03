#include "ExampleMaterial.h"

registerMooseObject("TutorialApp", ExampleMaterial);

template <>
InputParameters
validParams<ExampleMaterial>()
{
  InputParameters params = validParams<Material>();
  return params;
}

ExampleMaterial::ExampleMaterial(const InputParameters & parameters)
  : Material(parameters), _diffusivity(declareProperty<Real>("diffusivity"))
{
}

void
ExampleMaterial::computeQpProperties()
{
  // Relative permittivity
  _diffusivity[_qp] = 1.01;
}
