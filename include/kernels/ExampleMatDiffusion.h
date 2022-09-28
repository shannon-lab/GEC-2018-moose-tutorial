#pragma once

// Including the "Diffusion" Kernel here so we can extend it
#include "Diffusion.h"

class ExampleMatDiffusion;

template <>
InputParameters validParams<ExampleMatDiffusion>();

/**
 * Computes the residual contribution: D * grad_u * grad_phi, where
 * D is defined via a material.
 */
class ExampleMatDiffusion : public Diffusion
{
public:
  ExampleMatDiffusion(const InputParameters & parameters);

protected:
  // Kernels _must_ override computeQpResidual()
  virtual Real computeQpResidual() override;
  // This is optional, but recommended!
  virtual Real computeQpJacobian() override;

  // Will be set from active material
  const MaterialProperty<Real> & _diffusivity;
};
