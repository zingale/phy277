set term png enhanced size 800,600
set output "projectile-drag.png"

set xlabel "x"

set ylabel "y"
set yrange [0:]

set grid

plot 'proj-nodrag.txt' using 2:3 title "no drag", \
     'proj-drag0.3.txt' using 2:3 title "C = 0.3"
