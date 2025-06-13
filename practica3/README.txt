------Guía de los programas de la práctica 3 de Métodos Numéricos de 2023------

1.Programa General.c
Programa que aplica diferencias divididas para "obtener" el polinomio interpolador de la función f(x) y evaluarlo en x = -0.989 + 0.011i con i = 0, ..., 180.
Puede utilizar tanto nodos equidistantes como nodos de Chebyshev. Ambos con n = 4, 8, 16, 32, 64.
Se debe especificar cuáles se quieren.
La primera columna del output siempre van a ser las abscisas de interpolación, las x.
A continuación, si se pide en ejecutar con el flag -f, imprimirà una columna con f(x).
Después, indicado con -e n_1, ..., n_s, imprimirá las equis evaluadas en el polinomio obtenido con nodos equidistantes para las enes introducidas (cantidad variable) que deben estar en el rango ya indicado.
Finalmente, indicado con -c n_1, ..., n_r, lo mismo para nodos de Cebyshev.
Mencionar que el orden del output en cuanto a metodos es siempre este, pero las enes dentro de cada uno no se ordenan ni se mira que sean distintas, va a imprimir las pedidas en el orden introducido.
Así, si quisiéramos imprimir la f, n = 8 para equidistantes y n = 4, 8 para Chebysev, algunas de las opciones equivalentes serían:
	./a.out -f -e 8 -c 4 8
	./a.out -e 8 -c 8 4 -f
	./a.out -c 8 4 -f -e 4
entre otras, donde a.out es el ejecutable creado en compilar

Para visualizar gráficas con los dados obtenidos en el output, se puede utilizar el programa gnuplot.
Hágase al gusto.

Hemos creado un script ejecutable que te hace las gráficas básicas y las guarda en formato .eps en una carpeta llamada graficas en el mismo directorio. De hecho, son dos scripts, uno en bash para linux y otro para gnuplot. Estos se pueden modificar para obtener otros ficheros, pero como lo hemos planteado es útil para obtener todas las graficas más básicas a la vez.

Linux
	simplemente ejecutar ./script.sh
	ya va a compilar el programa, se pueden cambiar variables si el ejecutable tiene otro nombre o lo que se quiera.
	la carpeta graficas, si no existe se crea y, si existe se reemplaza.
	si se quiere cambiar el nombre de dicha carpeta, se tendra que cambiar también el path para los ficheros en el script de gnuplot

Windows
	se debe crear un subdirectorio en el directorio actual llamado graficas (o como se desee y modificar el script)
	seguidamente compilar:
		gcc -Wall -Werror -Wextra General.c -lm
	supongamos el ejecutable se llama a, entonces:
		a -f -e 4 8 16 32 64 -c 4 8 16 32 64 > datos.txt
	y finalmente ejecutamos el script de gnuplot:
		gnuplot "gnuplot_script.gp"
		
En ambos sistemas operativos, se deben tener permiso de ejecucion para los ficheros script, en el caso de no tenerlos, concedáselos antes.

2. Programa ErroresMayor.c

Programa que imprime el mayor error entre la imagen de la función f(x) = 1/(1+(5x)^2) y la imagen del polinomio interpolador calculado a partir de n nodos equidistantes y de Chebyshev de entre los valores x = -0.989 + 0.011*i con i = 0, ..., 180, y para cada n = 4, 8, 16, 32, 64.

3. Programa IntInvBessel.c

Programa que calcula una aproximación del cero de la función de Bessel de primera especie de orden cero, J_0(x), haciendo uso de interpolación inversa a partir de una tabla de datos. El programa calcula estas aproximaciones usando los valores positivos, negativos y simétricos más cercanos al cero de la función y usando polinomios interpoladores de grados 1, 3 y 5.