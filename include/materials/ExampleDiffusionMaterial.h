#ifndef EXAMPLEDIFFUSIONMATERIAL_H
#define EXAMPLEDIFFUSIONMATERIAL_H

#include "Material.h"

class ExampleDiffusionMaterial;

template <>
InputParameters validParams<ExampleDiffusionMaterial>();

/**
 *  An example material class for providing a derived Diffusion
 *  kernel class with a diffusiity parameter
 */
class ExampleDiffusionMaterial : public Material
{
public:
  ExampleDiffusionMaterial(const InputParameters & parameters);

protected:
  virtual void computeQpProperties() override;

  MaterialProperty<Real> & _diffusivity;
};

#endif // EXAMPLEDIFFUSIONMATERIAL_H
