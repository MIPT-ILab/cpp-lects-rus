set grid
unset title
set terminal svg size 800,480 fixed
set output 'primes-log.svg'
plot "log1.plot" with linespoints notitle, "log2.plot" with linespoints notitle, "log3.plot" with linespoints notitle
