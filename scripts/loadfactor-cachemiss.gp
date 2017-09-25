reset
set ylabel '%'
set style fill solid
set title 'cache performance comparison'
set term png enhanced font 'Verdana,10'
set output 'cachemiss.png'

plot [:][:50]'src/cache.txt' using 2:xtic(1) with histogram title 'original', \
'' using 3:xtic(1) with histogram title '0.8'  , \
'' using 4:xtic(1) with histogram title '0.75'  , \
'' using 5:xtic(1) with histogram title '0.7' , \
'' using ($0-0.1):($2+0.001):2 with labels title ' ', \
'' using ($0):($3+0.0015):3 with labels title ' ', \
'' using ($0+0.2):($4+0.0015):4 with labels title ' ', \
'' using ($0+0.4):($5+0.0015):5 with labels title ' '
