// Programa que calcula el cero real positivo del polinomio x^3 - x - 400, haciendo uso de bisección 4 veces y después del método de Newton, en doble precisión

#include <stdio.h>
#include <math.h>

double f(double x) { //    Función que evalúa el polinomio del enunciado
    return x*x*x - x - 400;
}

double df(double x) { //    Función que evalúa la derivada del polinomio del enunciado
    return 3*x*x - 1;
}

int main() {

    double aux = 0, x = 2; //    Declaramos una variable auxiliar, y el valor inicial del algoritmo, que se sugiere como x_0 = 2, ambas en doble precisión
    double a = 2, b = 8, p = 0; //    Declaramos los extremos del intervalo sobre el que vamos a aplicar bisección, así como la variable auxiliar que usaremos
    int nmax = 100, n = 0; //    Declaramos el número máximo de iteraciones que queramos realizar y el índice de los bucles

    int i = 0;
    while (i < 3) { // Mientras la longitud del intervalo actual sea mayor a la precisión que buscamos, y no hayamos llegado al número máximo de iteraciones, seguimos
        p = (a + b)/2;      //    Calculamos el punto medio del intervalo actual
        if (f(a)*f(p) <= 0) //    Veamos en qué subdivisión del intervalo está el cero
            b = p;          //    El cero se encuentra a la derecha del punto medio
        else
            a = p;          //    El cero se encuentra a la izquierda del punto medio
        i++;
    }

    x = (a+b)/2;

    while (fabs(x - aux) > 1E-15 && n<nmax) { //    Mientras dos valores consecutivos de la iteración disten más que la precisión deseada, y no hayamos llegado al número máximo de iteraciones, seguimos.
        aux = x; //    Guardamos el valor antes de operar
        x -= f(x)/df(x); //    Aplicamos el algoritmo del método de Newton
        n++;
    }

    fprintf(stdout, "alfa = %.16G, despues de %i iteraciones.\n", x, n); //    Imprimimos el valor de la aproximación del cero del polinomio, así como el número de iteraciones requeridas
    fprintf(stdout, "p(alfa) = %.16G \n", f(x)); //    Imprimimos por pantalla, en doble precisión, la imagen de la aproximación calculada

    return 0;
}
