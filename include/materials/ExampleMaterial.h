#ifndef EXAMPLEMATERIAL_H
#define EXAMPLEMATERIAL_H

#include "Material.h"

class ExampleMaterial;

template <>
InputParameters validParams<ExampleMaterial>();

/**
 *  An example material class for providing a derived Diffusion
 *  kernel class with a diffusiity parameter
 */
class ExampleMaterial : public Material
{
public:
  ExampleMaterial(const InputParameters & parameters);

protected:
  virtual void computeQpProperties() override;

  MaterialProperty<Real> & _diffusivity;
};

#endif // EXAMPLEMATERIAL_H
