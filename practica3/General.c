/*
 * Programa que imprime f(x_k) y/o los p(x_k) solicitados en ser ejecutado con nodos equidistantes y/o de chebyshev
 * y con n = 4, 8, 16, 32, 64 pedidas
 * si queremos imprimirlas todas, al ejecutar deberemos añadir los flags: -f -e 4 8 16 32 64 -c 4 8 16 32 64
 * las imprime por columnas para poder redirigir el output a gnuplot (o cualquier programa para graficarlo)
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

/*en caso de error, libera la memoria reservada*/

int	error_memoria(int k, int *enes, double **nodos, double ***mats)
{
	int	n;

	if (mats)
	{
		for (int i = 0; i < k; i++)			//para cada matriz
		{
			if (mats[i])
			{
				n = enes[i];
				for (int j = 0; j <= n; j++)			//liberamos las filas
					if (mats[i][j])
						free(mats[i][j]);
				free(mats[i]);
			}
		}
	free(mats);
	}
	if (nodos)
	{
		for (int i = 0; i <= k; i++)		//para cada vector
		{
			if (nodos[i])
				free(nodos[i]);
		}
		free(nodos);
	}
	if (enes)				//las enes
		free(enes);
	return (0);
}

/*si el input es icorrecto, explica como deberia ser*/

int	error_formato()
{
	printf("\nEl formato de input esperado es el siguiente:\n");
	printf("Una vez compilado, supongamos que el ejecutable se llama a.out.\n");
	printf("Se admiten los siguientes argumentos:\n\t-f para imprimir los valores de la funcion\n");
	printf("\t-e seguido de algunos de los valores siguientes que tomara como n: 4, 8, 16, 32, 64\n");
	printf("\t-c seguido de algunos de los valores siguienes que tomara como n: 4, 8, 16, 32, 64\n");
	printf("El orden de los flags no importa, se imprimiran siempre en el sigiente: x, f, e, c con los valores de las enes en el orden introducido\n");
	printf("Ejemplos:\n\t./a.out -e 4 64 -f\n\timprime los valores para la f y para equidistante con n = 4, n = 64\n");
	printf("\t./a.out -f -c 4 -e 4\n\timprime la f i las aproximaciones con ambos tipos de nodos para n = 4\n\n");
	return (0);
}

/*retorna 1 si tiene el formato correcto y 0 si no. Ademas, identifica si pide f, e y c */

int	control_input(int argc, char **argv, int *f, int *e, int *c)
{
	int	i;				//iterador
	int	flag;			//flag == 0 significa que buscamos un flag, flag == 1, que buscamos valores de n
	int	aux;			//variable auxiliar

	if (argc == 1)				//se necesitan argumentos
		return (error_formato());
	i = 1;
	flag  = 0;				//empezamos buscando flag
	while (argv[i] != NULL)
	{
		if (flag == 0)		//si buscamos flag
		{
			if (argv[i][0] != '-' || (argv[i][1] != 'f' && argv[i][1] != 'e' && argv[i][1] != 'c'))		//solo se admite -f -c -e
				return (error_formato());
			if (argv[i][1] == 'f')
			{
				if (*f == 1)			//solo se admite -f una vez
					return (error_formato());
				*f = 1;
			}
			else if (argv[i][1] == 'e')		//solo se admite -e una vez
			{
				if (*e == 1)
					return (error_formato());
				*e = 1;
			}
			else			//solo se admite -c una vez
			{
				if (*c == 1)
					return (error_formato());
				*c = 1;
			}
			if (argv[i][1] != 'f')			//para f no se admiten valores de n
				flag = 1;
		}
		else			//si buscamos valores para n
		{
			aux = 0;
			for (int n = 2; n <= 64; n *= 2)		//miramos que el valor de la n sea 4, 8, 16, 32 o 64
			{
				if (atoi(argv[i]) == n)
					aux++;
			}
			if (aux == 0)			//si no es uno de los valores esperados
				return (error_formato());
			if ((argv[i + 1] && argv[i + 1][0] == '-') || !argv[i + 1])		//miramos si hay mas enes para esos nodos
				flag = 0;
		}
		i++;
	}
	if (flag == 1)			//para evitar que -e o -c no tengan valores de n
		return (error_formato());
	return (1);
}

/*calcula cuantas enes se piden despues del -d donde d va a ser una e o una c*/

int	numerode(char **argv, char d)
{
	int	i = 0;
	int	n = 1;			//sabemos que una habrá seguro porque si no habría dado error

	while (argv[i] && argv[i][1] != d)		//mientras no sea el caracter que buscamos
		i++;
	if (!argv[i])			//en caso de haber recorrido todo el string y no haber encontrado el flag
		return (0);
	i++;
	while (argv[i + 1] && argv[i + 1][0] != '-')		//cuenta cuantos numeros hay, el ultimo se contabiliza en la iniciacion
	{
		i++;
		n++;
	}
	return (n);
}

/*llena el vector n con las enes. Primero las de equidistantes i despues chebyshev, ambos grupos en el orden intorducido*/

void llenar_enes(char **argv, int	*enes, int e, int c)
{
	int	i = 0;
	int	j = 0;

	if (e)			//si se pide equidistantes
	{
		while (argv[i][1] != 'e')
			i++;
		i++;
		while (argv[i] && argv[i][0] != '-')
		{
			enes[j] = atoi(argv[i]);
			i++;
			j++;
		}
		i = 0;
	}
	if (c)			//si se pide chebyshev
	{
		while (argv[i][1] != 'c')
			i++;
		i++;
		while (argv[i] && argv[i][0] != '-')
		{
			enes[j] = atoi(argv[i]);
			i++;
			j++;
		}
	}
}

double	efe(double x)
{
	return (1/(1 + 25*x*x));
}

double	P(int n, double x, double xi[n], double **mat)
{
	double	aux = mat[n][n];

	for (int i = n - 1; i >= 0; i--)
	{
		aux *= x - xi[i];     //evaluamos por horner
		aux += mat[i][i];
	}
	return (aux);
}

int	main(int argc, char **argv)
{
	int		f = 0;          //si se quiere printear los valores de la f conocida
	int	 	e = 0;          //si se quiere printear por algun ene con equidistante
	int		c = 0;          //si se quiere printear por algun ene con chebyshev
	int		k;		        //numero de matrices que tendremos que crear
	int		ne;				//guardaremos cuantas enes hay por e
	int		nc;				//guardaremos cuantas enes hay por c
	int		n;				//variable auxiliar
	int		*enes;			//vector donde guardaremos las enes requeridas
	double	x;				//x donde vamos a evaluar los polinomios y la funcion si se pide
	double	**nodos = NULL; //vamos a guardar los distintos nodos que utilizaremos
	double	***mats = NULL; //triple puntero, guardaremos las matrices
	double	pi = (double)3.14159265358979323846;		//pi en doble precision

	if (!control_input(argc, argv, &f, &e, &c))     //si hay un error en el formato del input
		return (0);

	k = argc - (1 + f + e + c);         //el uno es por la ejecucion: el ./a.out (en caso de linux)
	ne = numerode(argv, 'e');           //ne es el numero de enes para equidistante
	nc = numerode(argv, 'c');           //nc es el numero de enes para chebyshev
	if (k)
	{
		enes = malloc(sizeof(int) * (k + 1));       //reservamos la memoria
		if (!enes)              //protegemos el malloc
			return (error_memoria(k, enes, nodos, mats));
		llenar_enes(argv, enes, e, c);        //cogemos las enes
		nodos = malloc(sizeof(double *) * k);           //reservamos memoria
		if (!nodos)             //protegemos el malloc
			return (error_memoria(k, enes, nodos, mats));
		for (int l = 0; l < ne; l++)        //calculamos los nodos equidistantes
		{
			n = enes[l];            //para cada n pedida por equidistantes
			nodos[l] = malloc(sizeof(double) * (n + 1));        //reservamos memoria
			if (!nodos[l])          //protegemos
				return (error_memoria(k, enes, nodos, mats));
			for (int i = 0; i <= n; i++)            //llenamos con los nodos
				nodos[l][i] = -1 + i*2./n;
		}
		for (int l = 0; l < nc; l++)           //calculamos los nodos de chebyshev
		{
			n = enes[ne + l];           //para cada n pedida por chebyshev
			nodos[ne + l] = malloc(sizeof(double) * (n + 1));       //reservamos memoria
			if (!nodos[ne + l])         //protegemos el malloc
				return (error_memoria(k, enes, nodos, mats));
			for (int i = 0; i <= n; i++)        //llenamos con los nodos
				nodos[ne + l][i] = cos((2*i + 1)*pi/((n + 1)*2));
		}
		mats = malloc(sizeof(double**) * k);        //reservamos la memoria para el array de punteros a las matrices
		if (!mats)          //protegemos el malloc
			return (error_memoria(k, enes, nodos, mats));
		for (int i = 0; i < k; i++)         //reservamos memoria para las matrices
		{
			n = enes[i];            //para cada n pedida
			mats[i] = malloc(sizeof(double *) * (n + 1));       //reservamos memoria para las filas
			if (!mats[i])           //protegemos
				return (error_memoria(k, enes, nodos, mats));
			for (int j = 0; j < n + 1; j++)         //para cada fila
			{
				mats[i][j] = malloc(sizeof(double) * (n + 1));      //reservamos memoria para las columnas
				if (!mats[i][j])        //protegemos el malloc
					return (error_memoria(k, enes, nodos, mats));
			}
		}
		for (int i = 0; i < k; i++)         //llenamos la primera columna de cada matriz con las imagenes de los nodos
		{
			n = enes[i];            //para cada ene
			for (int j = 0; j < n + 1; j++)             //calculamos las imagenes
				mats[i][j][0] = efe(nodos[i][j]);
		}
		for (int i = 0; i < k; i++)           //llenamos las matrices con las diferencias divididas
		{
			n = enes[i];        //para cada ene
			for (int j = 1; j < n + 1; j++)             //para cada columna
			{
				for (int h = 0; h < j; h++)         //llenamos con ceros encima de la diagonal
					mats[i][h][j] = 0.;
				for (int r = j; r < n + 1; r++)         //diferencias divididas
					mats[i][r][j] = (mats[i][r][j - 1] - mats[i][r - 1][j - 1])/(nodos[i][r] - nodos[i][r - j]);
			}
		}
	}
	for (int i = 0; i <= 180; i++)
	{
		x = -0.989 + 0.011*i;    //    punto donde evaluamos
		printf("%.16G", x);      //    imprimimos las equis
		if (f == 1)   //    si se quiere imprimir las imágenes de la función
			printf("\t%.16G", efe(x));
		if (k)
		{
			for (int j = 0; j < k; j++) //    las aproximaciones pedidas
     		{
      	      n = enes[j];              //    para cada ene
      	      printf("\t%.16G", P(n, x, nodos[j], mats[j]));
     	   }
		}
		printf("\n");
	}
	return (0);
}
