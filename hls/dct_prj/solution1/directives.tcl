############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
## Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
############################################################
set_directive_top -name dct "dct"
set_directive_array_partition -dim 1 -factor 8 -type cyclic "dct_2d" col_inbuf
set_directive_array_partition -dim 1 -factor 8 -type cyclic "dct" buf_2d_out
