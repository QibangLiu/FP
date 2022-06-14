[Mesh]
  type = GeneratedMesh # Can generate simple lines, rectangles and rectangular prisms
  dim = 2 # Dimension of the mesh
  nx = 100 # Number of elements in the x direction
  ny = 10 # Number of elements in the y direction
  xmax = 0.0075 # Length of test chamber
  ymax = 0.0055 # Test chamber radius, Wall thickness need to be considered
[]

[Problem]
  type = FEProblem # This is the "normal" type of Finite Element Problem in MOOSE
  coord_type = RZ # Axisymmetric RZ
  rz_coord_axis = X # Which axis the symmetry is around
[]

[Variables]
  [temperature]
    # Adds a Linear Lagrange variable by default
  []
[]

[Kernels]
  [./diffusion]
    type = FrompTemperature
    variable = temperature # Operate on the "temperature" variable from above
    thermal_conductivity = 0.15 
  [../]
[]

[BCs]
  [inlet]
    type = ADDirichletBC # Simple u=value BC
    variable = temperature # Variable to be set
    boundary = 'left' # Name of a sideset in the mesh
    value = 483.15 # (K) only applied t<t_trig
  []
  [outlet]
    type = ADDirichletBC
    variable = temperature
    boundary = 'right'
    value = 0 # (K)  Intial is 0, 
  [../]
[]

[Executioner]
  type = Steady # Steady state problem
  solve_type = NEWTON # Perform a Newton solve

  # Set PETSc parameters to optimize solver efficiency
  petsc_options_iname = '-pc_type -pc_hypre_type' # PETSc option pairs with values below
  petsc_options_value = ' hypre    boomeramg'
[]

[Outputs]
  exodus = true # Output Exodus format
[]