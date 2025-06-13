// Programa que aplica interpolación inversa a una tabla de imágenes de la función de Bessel en unos puntos determinados

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

double P(int n, double x, double xi[6], double mat[6][6]) {
    double aux = mat[n][n];
    for (int i=n-1; i>=0; i--) { //    Evalúamos el polomio por Horner
        aux *= x-xi[i];
        aux += mat[i][i];
    }
    return aux;
}

int main() {

    double fx[12] = {0.281818559374385, 0.223890779141236, 0.166606980331990, 0.110362266922174, 0.055539784445602, 0.002507683297244,
    -0.048383776468198, -0.096804954397038, -0.142449370046012, -0.185036033364387, -0.224311545791968, -0.260051954901934};
    //    Declaramos el vector de aproximaciones de las imágenes de las abscisas de soporte para la función de Bessel
    double x[6];
    double mat[6][6];
    char metodos[3][11];

    strcpy(metodos[0], "positivos\0");
    strcpy(metodos[1], "negativos\0");
    strcpy(metodos[2], "simetricos\0");

    for (int k=0; k<3; k++) { //    Para cada método

        if (k == 0) {
            for (int i=0; i<=5; i++)  //    Calculamos las abscisas de soporte que usaremos para interpolar valores positivos,
                x[i] = fx[5-i];       //    correspondientes a las aproximaciones guardadas de las imágenes de la función de Bessel

            for (int i=0; i<=5; i++)       //    Seleccionamos las ordenadas de soporte como las abscisas correspondientes
                mat[i][0] = 2.4 - 0.1*i;
        }

        else if (k == 1) {
            for (int i=0; i<=5; i++) //    Calculamos las abscisas de soporte que usaremos para interpolar valores negativos,
                x[i] = fx[6+i];      //    correspondientes a las aproximaciones guardadas de las imágenes de la función de Bessel

            for (int i=0; i<=5; i++)       //    Seleccionamos las ordenadas de soporte como las abscisas correspondientes
                mat[i][0] = 2.5 + 0.1*i;
        }

        else {
            for (int i=0; i<=5; i++)                       //    Calculamos las abscisas de soporte que usaremos para interpolar valores simetricos,
                x[i] = fx[5 + (int)pow(-1,i+1)*((i+1)/2)]; //    correspondientes a las aproximaciones guardadas de las imágenes de la función de Bessel

            for (int i=0; i<=5; i++)                           //    Seleccionamos las ordenadas de soporte como las abscisas correspondientes
                mat[i][0] = 2.4 + 0.1*pow(-1,i+1)*((i+1)/2);
        }

        for (int j=1; j<=5; j++) {   //    Vamos guardando los iterados del método de las diferencias divididas de Newton en nuestra matriz triangular superior
            for(int k=0; k<j; k++)
                mat[k][j] = 0.;       //    Guardamos las componentes superiores de la matriz como 0
            for(int i=j; i<=5; i++)
                mat[i][j] = (mat[i][j-1] - mat[i-1][j-1])/(x[i]-x[i-j]);
        }

        for (int l=1; l<=3; l++) //    Imprimimos los ceros aproximados para cada estrategia, usando polinomios interpoladores de grado 1, 3 y 5
            printf("El cero aproximado interpolando %i valores %s es: %.16G\n", 2*l, metodos[k], P(1+2*l, 0, x, mat));

        printf("\n");
    }

    return 0;
}
