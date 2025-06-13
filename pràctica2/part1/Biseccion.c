// Programa que calcula el cero real positivo del polinomio x^3 - x - 400, haciendo uso del método de bisección, en doble precisión

#include <stdio.h>
#include <math.h>

double f(double x) { //    Función que evalúa el polinomio del enunciado
    return x*x*x - x - 400;
}

int main() {
    double a = 2, b = 8; //    Inicializamos, en doble precisión, las dos variables que van a ir determinando los intervalos en los que se encuentra nuestro cero.
                         //    Estas toman valores 2 y 8 porque el intervalo inicial es el [2,8]

    double p = 0;        //    Inicializamos, en doble precisión, la variable que cogerá el punto medio del intervalo en el que estemos trabajando para hacer la bisección

    int nmax = 100, n = 0; //    Declaramos el número máximo de iteraciones que queramos realizar y el índice de los bucles

    while ((8.-2.)/pow(2,n) > 1E-15 && n<nmax) { // Mientras la longitud del intervalo actual sea mayor a la precisión que buscamos, y no hayamos llegado al número máximo de iteraciones, seguimos.
        p = (a + b)/2;      //    Calculamos el punto medio del intervalo actual
        if (f(a)*f(p) <= 0) //    Veamos en qué subdivisión del intervalo está el cero
            b = p;          //    El cero se encuentra a la derecha del punto medio
        else
            a = p;          //    El cero se encuentra a la izquierda del punto medio
        n++;
        printf("n = %i    |    alfa = %.16G\n", n, (a+b)/2);
    }

    printf("El cero del polinomio es %.16G, despues de %i iteraciones. \n", (a+b)/2, n); //    Imprimimos el valor de la aproximación del cero del polinomio, así como el número de iteraciones requeridas
    printf("p(alfa) = %.16G \n", f((a+b)/2)); //    Imprimimos por pantalla la imagen de la aproximación calculada

    return 0;
}
