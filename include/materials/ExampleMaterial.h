#pragma once

#include "Material.h"

/**
 *  An example material class for providing a derived Diffusion
 *  kernel class with a diffusiity parameter
 */
class ExampleMaterial : public Material
{
public:
  static InputParameters validParams();

  ExampleMaterial(const InputParameters & parameters);

protected:
  virtual void computeQpProperties() override;

  MaterialProperty<Real> & _diffusivity;
};
