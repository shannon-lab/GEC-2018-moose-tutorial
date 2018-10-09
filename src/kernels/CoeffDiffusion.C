#include "CoeffDiffusion.h"

registerMooseObject("TutorialApp", CoeffDiffusion);

template <>
InputParameters
validParams<CoeffDiffusion>()
{
  // Start with the parameters from our parent kernel
  InputParameters params = validParams<Diffusion>();

  // Now add any extra parameters that this class needs:

  // Add a required parameter. If this isn't provided in the input file
  // MOOSE will throw an error.
  params.addRequiredParam<Real>("diffusivity", "Particle diffusivity.");
  return params;
}

CoeffDiffusion::CoeffDiffusion(const InputParameters & parameters)
  : Diffusion(parameters),

    // Get the parameters from the input file
    _diffusivity(getParam<Real>("diffusivity"))
{
}

Real
CoeffDiffusion::computeQpResidual()
{
  // D * grad_u * grad_phi[i]
  return _diffusivity * Diffusion::computeQpResidual();
}

Real
CoeffDiffusion::computeQpJacobian()
{
  // D * grad_phi[j] * grad_phi[i]
  return _diffusivity * Diffusion::computeQpJacobian();
}
