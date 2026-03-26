set term png enhanced
set output "projectile.png"

set xlabel "x"
set ylabel "y"

set grid

plot "out" using 2:3 notitle
