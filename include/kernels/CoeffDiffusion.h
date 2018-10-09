#ifndef COEFFDIFFUSION_H
#define COEFFDIFFUSION_H

// Including the "Diffusion" Kernel here so we can extend it
#include "Diffusion.h"

class CoeffDiffusion;

template <>
InputParameters validParams<CoeffDiffusion>();

/**
 * Computes the residual contribution: D * grad_u * grad_phi
 */
class CoeffDiffusion : public Diffusion
{
public:
  CoeffDiffusion(const InputParameters & parameters);

protected:
  // Kernels _must_ override computeQpResidual()
  virtual Real computeQpResidual() override;
  // This is optional, but recommended!
  virtual Real computeQpJacobian() override;

  // Will be set from the input file
  Real _diffusivity;
};

#endif // COEFFDIFFUSION_H
