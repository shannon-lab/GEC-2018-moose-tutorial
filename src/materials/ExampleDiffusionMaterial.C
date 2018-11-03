#include "ExampleDiffusionMaterial.h"

registerMooseObject("TutorialApp", ExampleDiffusionMaterial);

template <>
InputParameters
validParams<ExampleDiffusionMaterial>()
{
  InputParameters params = validParams<Material>();
  return params;
}

ExampleDiffusionMaterial::ExampleDiffusionMaterial(const InputParameters & parameters)
  : Material(parameters), _diffusivity(declareProperty<Real>("diffusivity"))
{
}

void
ExampleDiffusionMaterial::computeQpProperties()
{
  // Diffusivity as defined from Step 02
  _diffusivity[_qp] = 64.29;
}
