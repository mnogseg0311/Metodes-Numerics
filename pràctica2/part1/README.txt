------Guía de los programas de la práctica 2 de Métodos Numéricos de 2023 (primera parte)------

1. Programa Cardano
Este programa calcula una aproximación del cero del polinomio x^3-x-40 utilizando la fórmula de Cardano en simple y doble precisión y la imprime por pantalla, así como su imagen.

2. Programa Newton
Calcula un cero del polinomio x^3-x-40 utilizando el método de Newton, en simple y doble precisión e imprime los resultados por pantalla, así como el número de iteraciones empleadas y la imagen de nuestra aproximación. El programa está diseñado con unas tolerancias de 10^(-8) y 10*^(-15) para simple y doble precisión respectivamente.
Se puede modificar el polinomio en la función f, modificando también df si es necesario para que contenga su derivada.
Cambiando el valor de nmax, redefinimos el tope de iteraciones que va a hacer aún que no haya encontrado la raíz.

3. Programa Cardano2
Programa que aproxima, en doble precisión, el cero real positivo del polinomio x^3-x-400 utilizando la fórmula de Cardano. Este imprime la aproximación del cero así como la imagen del polinomio para observar la magnitud del error.

4. Programas Biseccion, Secante y Newton2
Estos programas aproximan, en doble precisión, el cero real positivo del polinomio x^3-x-400 haciendo uso de los métodos de bisección, de la secante y de Newton respectivamente. En los dos primeros métodos se parte del intervalo [2,8], y en el tercero la semilla es x=2. La tolerancia es siempre de 10*^(-15).
Los programas imprimen por pantalla tanto la aproximación del cero, como el número de iteraciones requeridas, y la imagen de la aproximación del cero.
Se puede modificar el polinomio en la función f en los tres programas, modificando también df en el programa Newton2.
Cambiando el valor de nmax, redefinimos el tope de iteraciones que va a hacer aún que no haya encontrado la raíz.

5. Programa TablaPb1Aproximaciones
Programa que imprime una tabla con las aproximaciones del cero positivo del polinomio x^3-x-400 para los métodos de bisección, secante y Newton, junto al número de iteraciones.
Se puede modificar el polinomio en la función f, modificando también df si es necesario para que contenga su derivada. La tolerancia es siempre de 10*^(-15).
Cambiando el valor de nmax, redefinimos el tope de iteraciones que va a hacer aún que no haya encontrado la raíz.

5. Programa TablaPb1OrdenConvergencia
Programa que imprime una tabla con las aproximaciones de los límites de la definición de orden de convergencia para valores p=1, p=2, y p=1.5 para los métodos de bisección, secante y Newton, respectivamente, para encontrar el cero positivo del polinomio x^3-x-400. En la tabla se imprimen estas approximaciones junto al número de iteraciones requeridas. En los métodosde bisección y secante se parte del intervalo [2,8], y en el de Newton, la semilla es x=2. La tolerancia es siempre de 10*^(-15).
Se puede modificar el polinomio en la función f, modificando también df si es necesario para que contenga su derivada.
Cambiando el valor de nmax, redefinimos el tope de iteraciones que va a hacer aún que no haya encontrado la raíz.
También se pueden modificar los exponentes p para observar otras aproximaciones para comprobar si son (como mínimo o exactamente) de otro orden.

6. Programa Newton3
Programa que calcula un cero del polinomio x^3-x-400 usando cuatro bisecciones y siguiendo con el valor obtenido como semilla para el método de Newton, en doble precisión. Este imprime los resultados por pantalla, así como el número de iteraciones empleadas y la imagen de nuestra aproximación. El programa está diseñado con una tolerancia de 10*^(-15) y parte del intervalo [2,8].
Se puede modificar el polinomio en la función f, modificando también df si es necesario para que contenga su derivada.
Cambiando el valor de nmax, redefinimos el tope de iteraciones que va a hacer aún que no haya encontrado la raíz.

7. Programa Iteración
Este programa utiliza la iteración propuesta en el ejercicio 2 para aproximar la raíz real de un polinomio f(x) partiendo de un pivoto x_0 suficientemente cercano.
Se puede modificar el polinomio en la función f, modificando también fprima si es necesario para que contenga su derivada.
Cambiando el valor de nmax, redefinimos el tope de iteraciones que va a hacer aún que no haya encontrado la raíz.

8. Programa Convergencia
Es el mismo programa que el anterior y se puede modificar de la misma forma, pero en lugar de imprimir por pantalla la aproxiamción encontrada de la raíz, imprime una tabla
con los cocientes de las diferencias entre las iteraciones en su valor absoluto para poder apreciar cuál es su orden de convergencia.