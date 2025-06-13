// Programa que calcula un cero del polinomio x^3-x-40 utilizando el m�todo de Newton
#include <stdio.h>
#include <math.h>

float f_float(float x) { //  Funci�n que eval�a el polinomio del enunciado en simple precisi�n
    return x*x*x - x - 40;
}

double f_double(double x) { //  Funci�n que eval�a el polinomio del enunciado en doble precisi�n
    return x*x*x - x - 40;
}

float df_float(float x) { //  Funci�n que eval�a la derivada del polinomio del enunciado en simple precisi�n
    return 3*x*x - 1;
}

double df_double(double x) { //  Funci�n que eval�a la derivada del polinomio del enunciado en doble precisi�n
    return 3*x*x - 1;
}

int main () {
    float auxf = 0, xf = 2; //    Declaramos una variable auxiliar, y el valor inicial del algoritmo, que se sugiere como x_0 = 2, ambas en simple precisi�n
    int nmax = 100, n = 0;  //    Declaramos el n�mero m�ximo de iteraciones que queramos realizar y el �ndice de los bucles

    while (fabsf(xf - auxf) > 1E-8 && n<nmax) { //    Mientras dos valores consecutivos de la iteraci�n disten m�s que la precisi�n deseada, y no hayamos llegado al n�mero m�ximo de iteraciones, seguimos.
        auxf = xf; //    Guardamos el valor actual antes de operar
        xf -= f_float(xf)/df_float(xf); //    Aplicamos el algoritmo del m�todo de Newton
        n++;
    }

    fprintf(stdout, "Simple precision: \n");
    fprintf(stdout, "alfa = %.8G, despues de %i iteraciones.\n", xf, n); //    Imprimimos el valor de la aproximaci�n del cero del polinomio, calculada en simple precisi�n, as� como el n�mero de iteraciones requeridas
    fprintf(stdout, "p(alfa) = %.8G \n\n", f_float(xf)); //    Imprimimos por pantalla, en simple precisi�n, la imagen de la aproximaci�n calculada

    double auxd = 0, xd = 2; //    Declaramos una variable auxiliar, y el valor inicial del algoritmo, que se sugiere como x_0 = 2, ambas en doble precisi�n
    n = 0; //   Reiniciamos el contador para el siguiente bucle

    while (fabs(xd - auxd) > 1E-15 && n<nmax) { //    Mientras dos valores consecutivos de la iteraci�n disten m�s que la precisi�n deseada, y no hayamos llegado al n�mero m�ximo de iteraciones, seguimos.
        auxd = xd; //    Guardamos el valor antes de operar
        xd -= f_double(xd)/df_double(xd); //    Aplicamos el algoritmo del m�todo de Newton
        n++;
    }

    fprintf(stdout, "Doble precision: \n");
    fprintf(stdout, "alfa = %.16G, despues de %i iteraciones.\n", xd, n); //    Imprimimos el valor de la aproximaci�n del cero del polinomio, calculada en doble precisi�n, as� como el n�mero de iteraciones requeridas
    fprintf(stdout, "p(alfa) = %.16G \n", f_double(xd)); //    Imprimimos por pantalla, en doble precisi�n, la imagen de la aproximaci�n calculada

    return 0;
}
