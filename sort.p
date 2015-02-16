set terminal png size 800,600 enhanced font "Ubuntu,16"
set output 'sort.png'
set title "Insertionsort"
set xlabel "Items"
set ylabel "Time (ms)"
set grid
plot "data.dat" title ""
