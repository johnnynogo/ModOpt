############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
## Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
############################################################
open_project dct_prj
set_top dct
add_files src/dct.cpp
add_files -tb src/dct_test.cpp
add_files -tb src/in.dat
add_files -tb src/out.golden.dat
open_solution "DATAFLOW" -flow_target vitis
set_part {xc7z100ffg900-2}
create_clock -period 10 -name default
config_interface -m_axi_alignment_byte_size 64 -m_axi_latency 64 -m_axi_max_widen_bitwidth 512
config_rtl -register_reset_num 3
config_cosim -enable_dataflow_profiling -tool xsim -trace_level all
config_export -format xo -output /home/modopt/modopt13/johnny/ModOpt/hls/vitis_hls_analysis/reference-files
#source "./dct_prj/DATAFLOW/directives.tcl"
csim_design
csynth_design
cosim_design -enable_dataflow_profiling -trace_level all
export_design -rtl verilog -format xo -output /home/modopt/modopt13/johnny/ModOpt/hls/vitis_hls_analysis/reference-files
