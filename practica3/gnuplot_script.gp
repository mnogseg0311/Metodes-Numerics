#script de gnuplot para graficar individual y comparativamente los datos del fichero doc pensado para contener los distintos datos referentes
#a los distintos polinomios interpoladores obrenidos mediante nodos equidistantes / de Chebyshev y n = 4, 8, 16, 32, 64
#suponemos el programa inicial se ha ejecutado con todos los flags que admite y existe un subdirectorio anomenado graficas donde las guardaremos
#se puede comentar con #'s lo que no se desee o modificar al gusto

doc = "datos.txt"
en4="graficas/equidistantes4.eps"
en8="graficas/equidistantes8.eps"
en16="graficas/equidistantes16.eps"
en32="graficas/equidistantes32.eps"
en64="graficas/equidistantes64.eps"
cn4="graficas/chebyshev4.eps"
cn8="graficas/chebyshev8.eps"
cn16="graficas/chebyshev16.eps"
cn32="graficas/chebyshev32.eps"
cn64="graficas/chebyshev64.eps"
equi="graficas/equidistantes.eps"
cheby="graficas/chebyshev.eps"
n4="graficas/ene4.eps"
n8="graficas/ene8.eps"
n16="graficas/ene16.eps"
n32="graficas/ene32.eps"
n64="graficas/ene64.eps"

set term post eps color solid
set xrange [-1:1]
set yrange [0:1]

set out en4
set title "Equidistantes, n = 4"
plot doc u 1:2 title 'f' w l, doc u 1:3 title 'p' w l

set out en8
set title "Equidistantes, n = 8"
plot doc u 1:2 title 'f' w l, doc u 1:4 title 'p' w l

set out en16
set title "Equidistantes, n = 16"
plot doc u 1:2 title 'f' w l, doc u 1:5 title 'p' w l

set out en32
set title "Equidistantes, n = 32"
plot doc u 1:2 title 'f' w l, doc u 1:6 title 'p' w l

set out en64
set title "Equidistantes, n = 64"
plot doc u 1:2 title 'f' w l, doc u 1:7 title 'p' w l

set out cn4
set title "Chebyshev, n = 4"
plot doc u 1:2 title 'f' w l, doc u 1:8 title 'p' w l

set out cn8
set title "Chebyshev, n = 8"
plot doc u 1:2 title 'f' w l, doc u 1:9 title 'p' w l

set out cn16
set title "Chebyshev, n = 16"
plot doc u 1:2 title 'f' w l, doc u 1:10 title 'p' w l

set out cn32
set title "Chebyshev, n = 32"
plot doc u 1:2 title 'f' w l, doc u 1:11 title 'p' w l

set out cn64
set title "Chebyshev, n = 64"
plot doc u 1:2 title 'f' w l, doc u 1:12 title 'p' w l

set out equi
set title "Equidistantes. Comparativa para las n"
plot doc u 1:2 title 'f' w l, doc u 1:3 title 'n=4' w l, doc u 1:4 title 'n=8' w l, doc u 1:5 title 'n=16' w l, doc u 1:6 title 'n=32' w l, doc u 1:7 title 'n=64' w l

set out cheby
set title "Chebyshev. Comparativa para las n"
plot doc u 1:2 title 'f' w l, doc u 1:8 title 'n=4' w l, doc u 1:9 title 'n=8' w l, doc u 1:10 title 'n=16' w l, doc u 1:11 title 'n=32' w l, doc u 1:12 title 'n=64' w l

set out n4
set title "n = 4. Comparativa equidistantes y chebyshev"
plot doc u 1:2 title 'f' w l, doc u 1:3 title 'equidistantes' w l, doc u 1:8 title 'chebyshev' w l

set out n8
set title "n = 8. Comparativa equidistantes y chebyshev"
plot doc u 1:2 title 'f' w l, doc u 1:4 title 'equidistantes' w l, doc u 1:9 title 'chebyshev' w l

set out n16
set title "n = 16. Comparativa equidistantes y chebyshev"
plot doc u 1:2 title 'f' w l, doc u 1:5 title 'equidistantes' w l, doc u 1:10 title 'chebyshev' w l

set out n32
set title "n = 32. Comparativa equidistantes y chebyshev"
plot doc u 1:2 title 'f' w l, doc u 1:6 title 'equidistantes' w l, doc u 1:11 title 'chebyshev' w l

set out n64
set title "n = 64. Comparativa equidistantes y chebyshev"
plot doc u 1:2 title 'f' w l, doc u 1:7 title 'equidistantes' w l, doc u 1:12 title 'chebyshev' w l
