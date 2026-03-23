set term png enhanced size 800,600
set output "diff.png"

set logscale
set grid

set xlabel "dx"
set ylabel "error"

plot "diff.out" using 1:2 notitle with lines
