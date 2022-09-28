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
    type = CoeffDiffusion
    variable = n
    diffusivity = 64.29  # Ion diffusivity from paper
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

[Problem]
  type = FEProblem
  coord_type = XYZ
[]

[Executioner]
  type = Steady
  solve_type = 'NEWTON'
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]
