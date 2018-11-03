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
    type = FunctionDirichletBC
    variable = V
    boundary = left
    function = voltage_wave
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

[Functions]
  [./voltage_wave]
    type = ParsedFunction
    value = '100*sin(2*pi*13.56e6*t)'
  [../]
[]

[Problem]
  type = FEProblem
  coord_type = XYZ
[]

[Executioner]
  type = Transient
  dt = 7.37464e-09 # 10 timesteps per period
  end_time = 7.37464e-07 # 10 periods
  nl_rel_tol = 1e-07
  solve_type = 'PJFNK'
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]
