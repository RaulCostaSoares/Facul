if {[file isdirectory work]} {vdel -all -lib work}
vlib work
vmap work work
vcom -work work -2008 -explicit dec.vhd
vcom -work work -2008 -explicit tb_dec.vhd
vsim work.tb_dec
quietly set StdArithNoWarnings 1
quietly set StdVitalGlitchNoWarnings 1
do wave.do
run 1700ns
