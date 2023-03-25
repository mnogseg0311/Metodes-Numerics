------Guía de los programas de la práctica 1 de Métodos Numéricos de 2023 (segunda parte)------

1. Programas CrecientePS/PD
Estos aproximan la suma parcial de n sumantes mediante la expresión propuesta en el enunciado con el índice del sumatorio creciente.
Para cambiar el número de sumantes, se debe entrar en los ficheros fuente Creciente*.c y cambiar el valor asignado en n.

2. Programas DecrecientePS/PD
Estos aproximan la suma parcial de n sumantes mediante la expresión propuesta en el enunciado con el índice del sumatorio decreciente.
Para cambiar el número de sumantes, se debe entrar en los ficheros fuente Decreciente*.c y cambiar el valor asignado en n.

3. Programas AlternativaPS/PD
Estos calculan la suma parcial de n sumantes mediante la expresión alternativa propuesta en el informe de prácticas, con el índice del sumatorio decreciente.
Para cambiar el número de sumantes, se debe entrar en los ficheros fuente Alternativa*.c y cambiar el valor asignado en n.

4. Programa Tablas
Este programa imprime dos tablas de valores para poder ver cómo se comportan los tres algoritmos al ir incrementando el número de sumantes de las sumas parciales.
Se puede imprimir la aproximación del valor de la serie o su error absoluto. Para escoger esto, se debe dar el valor de 0 y 1 respectivamente a la variable "opcion" del main.
Modificando, en el main también, nf y bloquef cambiamos el número de sumantes de la mayor suma parcial y la cantidad de sumantes que se añaden en cada fila de la tabla en precisión simple.
nd y bloqued hacen lo mismo para precisión doble.
Así, si se quiere calcular el error absoluto de las aproximaciones aumentando los sumantes en 500 para float hasta llegar a los 7000, y aumentando en 5000 hasta los 50000 para double,
daremos los siguientes valores:
	opcion = 1
	nf = 500
	bloquef = 7000
	nd = 5000
	bloqued = 50000
Si la ventana de la consola es demasiado pequeña las filas van a partirse en distintas líneas y quedará muy poco claro de leer.