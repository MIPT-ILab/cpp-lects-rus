set grid
unset title
set terminal svg size 800,480 fixed
set output 'primes-p2.svg'
plot "plot.1" with linespoints notitle, "plot.2" with linespoints notitle, "plot.3" with linespoints notitle
