/*
Autor: jorgeaah
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 Copyright (C) 2019 Free Software Foundation, Inc. This is free software; see the source for copying conditions. There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
Compilado: gcc Lab4Pro6.c -lm
Fecha: vie 07 may 2021 22:25:19 CST
Librerias: stdio, math
Resumen: Programa que calcula sumatorias.
Entrada: Número n.
Salida: Sumatorias
*/

//Librerias
#include <stdio.h>
#include <math.h>

int main()
{
	int n = 0;
	printf("Ingrese un número n: ");
	scanf("%i", &n);
	float suma_a = 0.0F;
	float suma_b = 0.0F;
	float suma_c = 0.0F;
	float suma_d = 0.0F;
	for (int i = 1; i <= n; i++)
	{
		float temp = (float) i;
		suma_a += temp*temp*(temp-3.0F);
	}
	for (int i = 2; i <= n; i++)
	{
		float temp = (float) i;
		suma_b += 3.0F/(temp-1.0F);
	}
	for (int i = 1; i <= n; i++)
	{
		float temp = (float) i;
		float signo = -1.0F;
		if (0 == i % 2)
		{
			signo = 1.0F;
		}
		
		suma_c += 0.4472136F*pow(1.6180340F, temp)-signo*0.4472136F*pow(0.6180340F, temp);
	}
	for (int i = 2; i <= n; i++)
	{
		float temp = (float) i;
		suma_d += 0.1F*(3.0F*pow(2.0F, temp - 2.0F) + 4.0F);
	}
	printf("El resultado de la sumatoria a es %.1f. \n", suma_a);
	printf("El resultado de la sumatoria a es %.1f. \n", suma_b);
	printf("El resultado de la sumatoria a es %.1f. \n", suma_c);
	printf("El resultado de la sumatoria a es %.1f. \n", suma_d);
	return 0;
}
