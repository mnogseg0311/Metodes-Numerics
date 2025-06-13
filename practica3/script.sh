#!/bin/bash

PROGRAMA='General.c'
FLAGS='-Wall -Werror -Wextra'
DOCUMENTO='datos.txt'
CARPETA='graficas'
EJECUTABLE='a.out'

rm -rf $CARPETA
mkdir $CARPETA
gcc $FLAGS $PROGRAMA -lm
./$EJECUTABLE -f -e 4 8 16 32 64 -c 4 8 16 32 64 > $DOCUMENTO
gnuplot "gnuplot_script.gp"

#script pensado para ejecutar con todos los flags porque el script de gnuplot esta pensado para este formato
#en caso de querer utilizarlo con unas flags distintas, ejecutar cambiar "-f -e 4 8 16 32 64 -c 4 8 16 32 64" por "$@"
#y añadir los flags deseados en ejecutar este script, la variable $@ se refiere a todos los argumentos recibidos.
#notase que entonces se deberá modificar el script de gnuplot.
