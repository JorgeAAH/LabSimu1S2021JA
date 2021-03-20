/*
Autor: jorgeaah
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 Copyright (C) 2019 Free Software Foundation, Inc. This is free software; see the source for copying conditions. There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
Compilado:
Fecha: sáb 20 mar 2021 09:49:29 CST
Librerias: stdio,
Resumen:
Entrada:
Salida:
*/

//Librerias
#include <stdio.h>

int main()
{
	int n = 0;
	float med = 0.0F;
	float x;
	printf("Debe ingresar tantas alturas como quiera, pero una negativa detiene el programa. \n");
	printf("Ingrese una altura: \n");
	scanf("%f", &x);
	float max = x;
	float min = x;
	while (0 <= x)
	{
		n++;
		med += x;
		if (x > max)
		{
			max = x;
		}
		if (x < min)
		{
			min = x;
		}
		printf("Ingrese una altura: \n");
		scanf("%f", &x);
	}
	if (0 == n)
	{
		printf("No se escribieron alturas positivas. \n");
	} else 
	{
		printf("Media: %f, maximo: %f, minimo: %f. \n", med/(float)n, max, min);
	}
	return 0;
}       
