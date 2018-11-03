[Mesh]
  type = GeneratedMesh
  dim = 1
  nx = 100
  xmax = 2.54
[]

[Variables]
  [./n]
  [../]
[]

[Kernels]
  [./laplace_coeff]
    type = ExampleMatDiffusion
    variable = n
    # diffusivity will now be pulled from a material
  [../]
[]

[BCs]
  [./left]
    type = DirichletBC
    variable = n
    boundary = left
    value = 1e4
  [../]
  [./right]
    type = DirichletBC
    variable = n
    boundary = right
    value = 0
  [../]
[]

[Materials]
  [./example_material]
    type = ExampleDiffusionMaterial
  [../]
[]

[Problem]
  type = FEProblem
  coord_type = XYZ
[]

[Executioner]
  type = Steady
  solve_type = 'PJFNK'
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]
