------Guía de los programas de la práctica 2 de Métodos Numéricos de 2023 (segunda parte)------

1. Programa Iteración Problema 3
Este programa calcula una aproximación del cero real del polinomio x^3-x-400 utilizando el método de Halley, en precisión doble, y la imprime por pantalla, así como su imagen.
La variable x_k se inicializa con el valor de x_0.
Para cambiar el máximo de iteraciones, modificar nmax.
Se puede modificar el polinomio en la función f, modificando también df si es necesario para que contenga su derivada.

2. Programa Convergencia Problema 3
Programa con la misma iteración que el programa anterior. Las indicaciones en cuanto a funciones y variables son las mismas.
La diferencia es que este no imprime la aproximación y su imagen, sino que imprime una tabla que muestra los cocientes de las diferencias entre las iteraciones.

3. Programa Iteración Problema 4
Calcula la iteración pk propuesta en el ejercicio 4 que teóricamente converge en pi utilizando las medianas aritmética y geométrica. Imprime por pantalla el error absoluto respecto una aproximación de pi con precisión doble.
Para cambiar el máximo de iteraciones, modificar kmax.

4. Programa Convergencia Problema 4
Programa con la misma iteración que el programa anterior.
No calcula los errores absolutos respecto el límite teórico, como el segundo programa descrito, lo que hace es imprimir una tabla de los cocientes de las diferencias entre las iteraciones para poder apreciar el orden de convergencia.

5. Programa extra
Genera aleatoriamente los coeficientes de los polinomios de tercer grado p y q que definen f un número modificable de veces: variable aproximaciones
Por cada f definido, aplicamos el algoritmo visto en el apartado b del ejercicio extra para encontrar una "aproximación" de la raíz cuadrada de x + 1.
Imprime los datos por cada caso.

6. Programa extra 2
Variación del programa anterior. La diferencia es que genera f(x) aleatorias hasta que una aproxime la raíz con la precisión pedida en el bucle.
A mejorar: en algunos casos el resultado de dicha aproximación resulta -1.#IND, probablemente a causa de intentar calcular la raíz de un negativo.
En estos casos, volver a compilar.