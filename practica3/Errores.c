//Programa que imprime dos columnas para cada n = 4, 8, 16, 32, 64 para comparar
//el valor absoluto de f(x_k) - p(x_k) con p obtenida con nodos equidistantes i con nodos de Chebyshev

#include <stdio.h>
#include <math.h>

double f(double x)
{
	return (1/(1 + 25*x*x));
}

double P(int n, double x, double xi[n], double mat[n + 1][n + 1])
{
	double	aux = mat[n][n];
	for (int i = n - 1; i >= 0; i--)
	{
		aux *= x - xi[i];
		aux += mat[i][i];
	}
	return (aux);
}

void	imprimir_tabla(int n, double nodose[n + 1], double nodosc[n + 1], double mate[n + 1][n + 1], double matc[n + 1][n + 1])
{
	double	x = -0.989 - 0.011;		//para empezar con x=-0.989

	printf("\nErrores para n = %d\n", n);
	printf("|f(x_k) - Pequidistante(x_k)|    |f(x_k) - Pchebyshev(x_k)|\n");
	for (int i = 0; i <= 180; i++)
	{
		x += 0.011;
		printf("   %.16G	    %.16G\n", fabs(f(x) - P(n, x, nodose, mate)), fabs(f(x) - P(n, x, nodosc, matc)));
	}
}

void	tabla_error(int n)
{
	double	nodosequi[n + 1];
	double	nodoscheby[n + 1];
	double	matequi[n + 1][n + 1];
	double	matcheby[n + 1][n + 1];
	double	pi = (double)3.14159265358979323846;

	for (int i = 0; i <= n; i++)			//calculamos los nodos equidistantes
		nodosequi[i] = -1 + i*2./n;

	for (int i = 0; i <= n; i++)			//calculamos los nodos de chebyshev
		nodoscheby[i] = cos((2*i + 1)*pi/((n + 1)*2));
	//llenamos la matriz de los nodos equidistantes
	for (int i = 0; i <= n; i++)			//guardamos las imagenes de los nodos en la primera columna
		matequi[i][0] = f(nodosequi[i]);
	for (int j = 1; j <= n; j++)			//llenamos la matriz triangular superior
	{
		for (int k = 0; k < j; k++)			//ponemos los ceros
			matequi[k][j] = 0;
		for (int i = j; i <= n; i++)		//hacemos diferencias divididas
			matequi[i][j] = (matequi[i][j - 1] - matequi[i - 1][j - 1]) / (nodosequi[i] - nodosequi[i - j]);
	}
	//llenamos la matriz de los nodos de Chebyshev
	for (int i = 0; i <= n; i++)			//guardamos las imagenes de los nodos en la primera columna
		matcheby[i][0] = f(nodoscheby[i]);
	for (int j = 1; j <= n; j++)			//llenamos la matriz triangular superior
	{
		for (int k = 0; k < j; k++)			//ponemos los ceros
			matcheby[k][j] = 0;
		for (int i = j; i <= n; i++)		//hacemos diferencias divididas
			matcheby[i][j] = (matcheby[i][j - 1] - matcheby[i - 1][j - 1]) / (nodoscheby[i] - nodoscheby[i - j]);
	}
	imprimir_tabla(n, nodosequi, nodoscheby, matequi, matcheby);		//imprimimos las columnas
}

int	main()
{
	for (int n = 4; n <= 64; n = 2*n)		//para cada ene
		tabla_error(n);
	return (0);
}
