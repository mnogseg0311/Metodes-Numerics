//Programa que calcula, en doble precisión, las raíces reales de un polinomio de grado 2, evitando errores de cancelación producidos por la fórmula cuadrática
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    double a = 20;		//Inicializamos, en doble precisión, el coeficiente de x^2
    double b = 80; 		//Inicializamos, en doble precisión, el coeficiente de x
    double c = 4E-15; 		//Inicializamos, en doble precisión, el término independiente

    if(a==0) { 		//Comprovamos que el polinomio sea de grado exactamente 2 para poder usar la fórmula cuadrática
        fprintf(stderr, "El polinomio introducido no es de grado exactamente 2.");
        return 1;
    }
    else if (b*b < 4*a*c) { 		//Comprobamos que haya soluciones reales en el poliomio introducido
        fprintf(stderr, "Discriminante negrativo: el polinomio no tiene solucion real.");
        return 1;
    }
    //Utilizamos la función sqrt que toma y devuelve valores en doble precisión.
    else if (b>0) 		//Con la fórmula alternativa evitamos la cancelación en x1.
        fprintf(stdout, "Las raices del polinomio introducido son: x1 = %.16G y x2 = %.16G \n", (-2*c)/(b + sqrt(b*b - 4*a*c)), (-b - sqrt(b*b-4*a*c))/(2*a));
    else if (b<0) 		//Con la fórmula alternativa evitamos la cancelación en x2.
        fprintf(stdout, "Las raices del polinomio introducido son: x1 = %.16G y x2 = %.16G \n", (-b + sqrt(b*b-4*a*c))/(2*a), (-2*c)/(b - sqrt(b*b - 4*a*c)));
    else if (b==0) 		//Si b=0, entonces no se puede dar que b^2 >> 4*a*c. No hay errores por cancelación, así que podemos aplicar la fórmula cuadrática con normalidad.
        fprintf(stdout, "Las raices del polinomio introducido son: x1 = %.16G y x2 = %.16G \n", (-b + sqrt(b*b-4*a*c))/(2*a), (-b - sqrt(b*b-4*a*c))/(2*a));
    return 0;
}
