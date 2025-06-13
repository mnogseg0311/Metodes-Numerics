// Programa que calcula el cero real positivo del polinomio x^3 - x - 400, haciendo uso del método de Newton, en doble precisión

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
    int nmax = 100, n = 0; //    Declaramos el número máximo de iteraciones que queramos realizar y el índice de los bucles

    while (fabs(x - aux) > 1E-15 && n<nmax) { //    Mientras dos valores consecutivos de la iteración disten más que la precisión deseada, y no hayamos llegado al número máximo de iteraciones, seguimos.
        aux = x; //    Guardamos el valor antes de operar
        x -= f(x)/df(x); //    Aplicamos el algoritmo del método de Newton
        n++;
    }

    fprintf(stdout, "alfa = %.16G, despues de %i iteraciones.\n", x, n); //    Imprimimos el valor de la aproximación del cero del polinomio, así como el número de iteraciones requeridas
    fprintf(stdout, "p(alfa) = %.16G \n", f(x)); //    Imprimimos por pantalla, en doble precisión, la imagen de la aproximación calculada

    return 0;
}
