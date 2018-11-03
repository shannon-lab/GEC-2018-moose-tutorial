[Mesh]
  type = GeneratedMesh
  dim = 1
  nx = 100
  xmax = 0.0254
[]

[Variables]
  [./V]
  [../]
[]

[Kernels]
  [./poisson]
    type = ExampleMatDiffusion
    variable = V
    # permittivity (eps_R = 1.01) will be taken from a material
  [../]
  [./RHS]
    type = BodyForce
    variable = V
    function = 9.05e6 # from (e / eps0)*(5e15 - 4.5e15)
  [../]
[]

[BCs]
  [./left]
    type = DirichletBC
    variable = V
    boundary = left
    value = 100
  [../]
  [./right]
    type = DirichletBC
    variable = V
    boundary = right
    value = 0
  [../]
[]

[Materials]
  [./example_material]
    type = ExampleMaterial
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
