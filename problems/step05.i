[Mesh]
  type = GeneratedMesh
  dim = 1
  nx = 1000
  xmax = 2.54
[]

[Variables]
  [./ne] # Scaling is sometimes needed for convergence
    scaling = 1e-13
  [../]
[]

[AuxVariables]
  [./potential_MMS]
    order = FIRST
    family = LAGRANGE
  [../]
  [./ne_MMS]
    order = FIRST
    family = LAGRANGE
  [../]
[]

[AuxKernels]
  [./potential_aux]
    type = FunctionAux
    variable = potential_MMS
    function = potential_func
  [../]
  [./ne_MMS_aux]
    type = FunctionAux
    variable = ne_MMS
    function = ne_profile_func
  [../]
[]

[Kernels]
  [./electron_diffusion]
    type = CoeffDiffusion
    diffusivity = 1.1988e6
    variable = ne
  [../]
  [./electron_field_advection]
    type = EFieldAdvection
    variable = ne
    potential = potential_MMS
    mobility = 3e5
    sign = -1.0
  [../]
  [./ne_gnd_state_ioniz]
    type = GndStateIonizationElectrons
    variable = ne
    second_species = 3.22e16 # background gas density (cm^-3)
    mean_energy = 4 # electron mean energy (3/2 * T_e)
  [../]
  [./rhs]
    type = BodyForce
    function = rhs_func
    variable = ne
  [../]
[]

[BCs]
  [./left]
    type = DirichletBC
    variable = ne
    value = 1000
    boundary = left
  [../]
  [./right]
    type = DirichletBC
    variable = ne
    value = 1000
    boundary = right
  [../]
[]

[Functions]
  [./potential_func]
    type = ParsedFunction
    value = '(1 / 5) * (-x * x + 2.54 * x)'
  [../]
  [./rhs_func]
    type = ParsedFunction
    value = '2400038827339.6 * x * x - 6096098621442.58 * x + (-1.2e13 * x + 1.524e13) * (-0.4 * x + 0.508) + 47951879998058.6'
  [../]
  [./ne_profile_func]
    type = ParsedFunction
    value = '2e7 * (-x * x + 2.54 * x) + 1000'
  [../]
[]

[Materials]
  [./argon_ionization] # assume mean_en = 4
    type = GenericConstantMaterial
    prop_names = ki
    prop_values = 6.02909e-17
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
