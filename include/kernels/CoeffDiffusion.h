#pragma once

// Including the "Diffusion" Kernel here so we can extend it
#include "Diffusion.h"

/**
 * Computes the residual contribution: D * grad_u * grad_phi
 */
class CoeffDiffusion : public Diffusion
{
public:
  static InputParameters validParams();

  CoeffDiffusion(const InputParameters & parameters);

protected:
  // Kernels _must_ override computeQpResidual()
  virtual Real computeQpResidual() override;
  // This is optional, but recommended!
  virtual Real computeQpJacobian() override;

  // Will be set from the input file
  Real _diffusivity;
};
