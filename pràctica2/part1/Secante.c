// Programa que calcula el cero real positivo del polinomio x^3 - x - 400, haciendo uso del método de la secante, en doble precisión

#include <stdio.h>
#include <math.h>

double f(double x) { //    Función que evalúa el polinomio del enunciado
    return x*x*x - x - 400;
}

int main() {
    double a = 2, b = 8, aux = 0; //    Inicializamos, en doble precisión, las dos variables que usaremos para calcular la sucesión. Estas toman valores 2 y 8 porque el intervalo inicial es el [2,8]
    int nmax = 100, n = 0; //    Declaramos el número máximo de iteraciones que queramos realizar y el índice de los bucles

    while (fabs(a-b) > 1E-15 && n<nmax) {
        a = a - f(a)*(b-a)/(f(b)-f(a)); //  Reescribimos la variable a con el nuevo valor de la sucesión, ya que el valor que guardaba ya no lo necesitamos
        aux = a;
        a = b; //   Intercambiamos los valores de las variables a y b
        b = aux;
        n++;
        printf("n = %i    |    alfa = %.16G\n", n, b);
    }

    printf("El cero del polinomio es %.16G, despues de %i iteraciones. \n", b, n); //    Imprimimos el valor de la aproximación del cero del polinomio, así como el número de iteraciones requeridas
    printf("p(alfa) = %.16G \n", f((a+b)/2)); //    Imprimimos por pantalla la imagen de la aproximación calculada

    return 0;
}
