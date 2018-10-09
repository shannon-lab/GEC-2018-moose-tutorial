[Mesh]
  type = GeneratedMesh # Generates lines, rectangles, and rectangular prisms
  dim = 1 # Mesh dimension
  nx = 20 # Number of elements in the x direction
  xmax = 2.54 # (cm) Distance between the plates
[]

[Variables]
  [./potential]   # Default order is FIRST and default family is LAGRANGE
  [../]
[]

[Kernels]
  [./poisson]
    type = Diffusion  # A Laplacian operator
    variable = potential  # Operate on the "potential" variable from above
  [../]
[]

[BCs]
  [./left]
    type = DirichletBC  # u = value BC
    variable = potential
    boundary = left # Name of a sideset from the generated mesh
    value = 100 # (V) Peak voltage from paper.
  [../]
  [./right]
    type = DirichletBC
    variable = potential
    boundary = right
    value = 0 # (V) Voltage of grounded surface.
  [../]
[]

[Problem]
  type = FEProblem  # The "normal" type of Finite Element Problem in MOOSE
  coord_type = XYZ  # Cartesian coordinate system
[]

[Executioner]
  type = Steady # Steady state problem
  solve_type = 'PJFNK' # Preconditioned Jacobian Free Newton Krylov
  petsc_options_iname = '-pc_type -pc_hypre_type' # PetSc command line options that match with the values below
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true # Output data in Exodus file format
[]
