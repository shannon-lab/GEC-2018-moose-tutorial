CDF      
      
len_string     !   len_line   Q   four      	time_step          len_name   !   num_dim       	num_nodes         num_elem      
num_el_blk        num_node_sets         num_side_sets         num_el_in_blk1        num_nod_per_el1       num_side_ss1      num_side_ss2      num_nod_ns1       num_nod_ns2       num_nod_var       num_info   �         api_version       @�
=   version       @�
=   floating_point_word_size            	file_size               int64_status             title         step01_out.e       maximum_name_length                    
time_whole                            Z   	eb_status                             �   eb_prop1               name      ID              �   	ns_status         	                    �   ns_prop1      	         name      ID              �   	ss_status         
                    �   ss_prop1      
         name      ID              �   coordx                      �      �   coordy                      �      \   coordz                      �      	   eb_names                       $      	�   ns_names      	                 D      	�   ss_names      
                 D      
   
coor_names                         d      
X   node_num_map                    T      
�   connect1                  	elem_type         EDGE2         �         elem_num_map                    P      �   elem_ss1                              side_ss1                             elem_ss2                             side_ss2                             node_ns1                             node_ns2                             vals_nod_var1                          �      Z   name_nod_var                       $         info_records                      M�      <                                         ?�A�7Kƨ?�A�7Kƨ?�bM���?�A�7Kƨ?�Q��R?�bM���?�r� ě�?�A�7Kƨ?�I�^5?}?�Q��R?�Z�1(?�bM���?�j~��"�?�r� ě�?�z�G�{@ A�7Kƨ@E����@I�^5?}@M����@Q��R                                                                                                                                                                                                                                                                                                                                                                                    left                             right                              right                            left                                                                                                                                                              	   
                                                                                 	   	   
   
                                                                                          	   
                                                potential                           ####################                                                             # Created by MOOSE #                                                             ####################                                                             ### Command Line Arguments ###                                                    -i step01.i### Version Info ###                                                 Framework Information:                                                           MOOSE Version:           git commit dd82623d04 on 2018-10-09                     LibMesh Version:         655cf5f0984cd5489592188478eb275901d95a02                PETSc Version:           3.8.3                                                   Current Time:            Tue Oct  9 13:15:31 2018                                Executable Timestamp:    Tue Oct  9 12:41:22 2018                                                                                                                                                                                                  ### Input File ###                                                                                                                                                []                                                                                 inactive                       =                                                 initial_from_file_timestep     = LATEST                                          initial_from_file_var          = INVALID                                         element_order                  = AUTO                                            order                          = AUTO                                            side_order                     = AUTO                                            type                           = GAUSS                                         []                                                                                                                                                                [BCs]                                                                                                                                                               [./left]                                                                           boundary                     = left                                              control_tags                 = INVALID                                           enable                       = 1                                                 extra_matrix_tags            = INVALID                                           extra_vector_tags            = INVALID                                           implicit                     = 1                                                 inactive                     =                                                   isObjectAction               = 1                                                 matrix_tags                  = system                                            type                         = DirichletBC                                       use_displaced_mesh           = 0                                                 variable                     = potential                                         vector_tags                  = nontime                                           diag_save_in                 = INVALID                                           save_in                      = INVALID                                           seed                         = 0                                                 value                        = 100                                             [../]                                                                                                                                                             [./right]                                                                          boundary                     = right                                             control_tags                 = INVALID                                           enable                       = 1                                                 extra_matrix_tags            = INVALID                                           extra_vector_tags            = INVALID                                           implicit                     = 1                                                 inactive                     =                                                   isObjectAction               = 1                                                 matrix_tags                  = system                                            type                         = DirichletBC                                       use_displaced_mesh           = 0                                                 variable                     = potential                                         vector_tags                  = nontime                                           diag_save_in                 = INVALID                                           save_in                      = INVALID                                           seed                         = 0                                                 value                        = 0                                               [../]                                                                          []                                                                                                                                                                [Executioner]                                                                      inactive                       =                                                 isObjectAction                 = 1                                               type                           = Steady                                          compute_initial_residual_before_preset_bcs = 0                                   contact_line_search_allowed_lambda_cuts = 2                                      contact_line_search_ltol       = INVALID                                         control_tags                   =                                                 enable                         = 1                                               l_abs_step_tol                 = -1                                              l_max_its                      = 10000                                           l_tol                          = 1e-05                                           line_search                    = default                                         line_search_package            = petsc                                           mffd_type                      = wp                                              nl_abs_step_tol                = 1e-50                                           nl_abs_tol                     = 1e-50                                           nl_max_funcs                   = 10000                                           nl_max_its                     = 50                                              nl_rel_step_tol                = 1e-50                                           nl_rel_tol                     = 1e-08                                           no_fe_reinit                   = 0                                               petsc_options                  = INVALID                                         petsc_options_iname            = '-pc_type -pc_hypre_type'                       petsc_options_value            = 'hypre boomeramg'                               restart_file_base              =                                                 solve_type                     = PJFNK                                           splitting                      = INVALID                                       []                                                                                                                                                                [Kernels]                                                                                                                                                           [./poisson]                                                                        inactive                     =                                                   isObjectAction               = 1                                                 type                         = Diffusion                                         block                        = INVALID                                           control_tags                 = Kernels                                           diag_save_in                 = INVALID                                           enable                       = 1                                                 extra_matrix_tags            = INVALID                                           extra_vector_tags            = INVALID                                           implicit                     = 1                                                 matrix_tags                  = system                                            save_in                      = INVALID                                           seed                         = 0                                                 use_displaced_mesh           = 0                                                 variable                     = potential                                         vector_tags                  = nontime                                         [../]                                                                          []                                                                                                                                                                [Mesh]                                                                             inactive                       =                                                 displacements                  = INVALID                                         block_id                       = INVALID                                         block_name                     = INVALID                                         boundary_id                    = INVALID                                         boundary_name                  = INVALID                                         construct_side_list_from_node_list = 0                                           ghosted_boundaries             = INVALID                                         ghosted_boundaries_inflation   = INVALID                                         isObjectAction                 = 1                                               second_order                   = 0                                               skip_partitioning              = 0                                               type                           = GeneratedMesh                                   uniform_refine                 = 0                                               allow_renumbering              = 1                                               bias_x                         = 1                                               bias_y                         = 1                                               bias_z                         = 1                                               centroid_partitioner_direction = INVALID                                         construct_node_list_from_side_list = 1                                           control_tags                   =                                                 dim                            = 1                                               elem_type                      = INVALID                                         enable                         = 1                                               gauss_lobatto_grid             = 0                                               ghosting_patch_size            = INVALID                                         max_leaf_size                  = 10                                              nemesis                        = 0                                               nx                             = 20                                              ny                             = 1                                               nz                             = 1                                               parallel_type                  = DEFAULT                                         partitioner                    = default                                         patch_size                     = 40                                              patch_update_strategy          = never                                           xmax                           = 2.54                                            xmin                           = 0                                               ymax                           = 1                                               ymin                           = 0                                               zmax                           = 1                                               zmin                           = 0                                             []                                                                                                                                                                [Mesh]                                                                           []                                                                                                                                                                [Outputs]                                                                          append_date                    = 0                                               append_date_format             = INVALID                                         checkpoint                     = 0                                               color                          = 1                                               console                        = 1                                               controls                       = 0                                               csv                            = 0                                               dofmap                         = 0                                               execute_on                     = 'INITIAL TIMESTEP_END'                          exodus                         = 1                                               file_base                      = INVALID                                         gmv                            = 0                                               gnuplot                        = 0                                               hide                           = INVALID                                         inactive                       =                                                 interval                       = 1                                               nemesis                        = 0                                               output_if_base_contains        = INVALID                                         perf_graph                     = 0                                               print_linear_residuals         = 1                                               print_mesh_changed_info        = 0                                               print_perf_log                 = 0                                               show                           = INVALID                                         solution_history               = 0                                               sync_times                     =                                                 tecplot                        = 0                                               vtk                            = 0                                               xda                            = 0                                               xdr                            = 0                                             []                                                                                                                                                                [Problem]                                                                          inactive                       =                                                 isObjectAction                 = 1                                               name                           = 'MOOSE Problem'                                 type                           = FEProblem                                       library_name                   =                                                 library_path                   =                                                 object_names                   = INVALID                                         register_objects_from          = INVALID                                         block                          = INVALID                                         control_tags                   =                                                 coord_type                     = XYZ                                             enable                         = 1                                               error_on_jacobian_nonzero_reallocation = 0                                       extra_tag_matrices             = INVALID                                         extra_tag_vectors              = INVALID                                         force_restart                  = 0                                               ignore_zeros_in_jacobian       = 0                                               kernel_coverage_check          = 1                                               material_coverage_check        = 1                                               near_null_space_dimension      = 0                                               null_space_dimension           = 0                                               parallel_barrier_messaging     = 1                                               restart_file_base              = INVALID                                         rz_coord_axis                  = Y                                               skip_additional_restart_data   = 0                                               skip_nl_system_check           = 0                                               solve                          = 1                                               transpose_null_space_dimension = 0                                               use_nonlinear                  = 1                                             []                                                                                                                                                                [Variables]                                                                                                                                                         [./potential]                                                                      block                        = INVALID                                           eigen                        = 0                                                 family                       = LAGRANGE                                          inactive                     =                                                   initial_condition            = INVALID                                           order                        = FIRST                                             outputs                      = INVALID                                           scaling                      = 1                                                 initial_from_file_timestep   = LATEST                                            initial_from_file_var        = INVALID                                         [../]                                                                          []                                                                                                                                                                                                                                                                 ?�      @Y    @@W�   0@V�    @U@   @T     @R�    �@Q�    �@P@    �@N    @K�   _@I    @@F�   @D     �@A�    �@>    �@9    >@4     �@.    �@$     �@    	        