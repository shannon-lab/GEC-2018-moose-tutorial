#include "ExampleMaterial.h"

registerMooseObject("TutorialApp", ExampleMaterial);

InputParameters
ExampleMaterial::validParams()
{
  InputParameters params = Material::validParams();
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
