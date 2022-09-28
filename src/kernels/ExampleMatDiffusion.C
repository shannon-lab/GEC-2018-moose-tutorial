#include "ExampleMatDiffusion.h"

registerMooseObject("TutorialApp", ExampleMatDiffusion);

InputParameters
ExampleMatDiffusion::validParams()
{
  // Start with the parameters from our parent kernel
  InputParameters params = Diffusion::validParams();
  // This doesn't need any more parameters, since diffusivity
  // is being called from a material.
  return params;
}

ExampleMatDiffusion::ExampleMatDiffusion(const InputParameters & parameters)
  : Diffusion(parameters),

    // Get the parameters from the active material
    _diffusivity(getMaterialProperty<Real>("diffusivity"))
{
}

Real
ExampleMatDiffusion::computeQpResidual()
{
  // D * grad_u * grad_phi[i]
  return _diffusivity[_qp] * Diffusion::computeQpResidual();
}

Real
ExampleMatDiffusion::computeQpJacobian()
{
  // D * grad_phi[j] * grad_phi[i]
  return _diffusivity[_qp] * Diffusion::computeQpJacobian();
}
