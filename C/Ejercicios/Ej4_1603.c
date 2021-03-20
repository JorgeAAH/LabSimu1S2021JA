/*
Autor: jorgeaah
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 Copyright (C) 2019 Free Software Foundation, Inc. This is free software; see the source for copying conditions. There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
Compilado:
Fecha: sáb 20 mar 2021 11:32:31 CST
Librerias: stdio,
Resumen:
Entrada:
Salida:
*/

//Librerias
#include <stdio.h>

int es_primo(int N);

int main()
{
	printf("Programa que muestra todos los numeros primos en un determinado rango. \n");
	int N1;
	int N2;
	printf("Ingrese el menor valor del rango (incluido en este): ");
	scanf("%d", &N1);
	printf("Ingrese el mayor valor del rango (incluido en este): ");
	scanf("%d", &N2);
	int i = N1;
	while (i <= N2)
	{
		int primo = es_primo(i);
		if (1 == primo)
		{
			printf("%d\n", i);
		}
		i++;
	}
	return 0;
}

int es_primo(int N)
{
	int j = 2;
	int primo = 1;
	while ((j < N) && (1 == primo))
	{
		if (0 == N % j)
		{
			primo = 0;
		}
		j++;
	}
	return primo;
}
