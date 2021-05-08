/*
Autor: jorgeaah
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 Copyright (C) 2019 Free Software Foundation, Inc. This is free software; see the source for copying conditions. There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
Compilado: gcc Lab4Pro5.c
Fecha: mié 05 may 2021 18:21:26 CST
Librerias: stdio,
Resumen: El programa acepta un número y encuentra el factorial de este por medio de recursividad.
Entrada: Número al que se le obtendrá el factorial.
Salida: Factorial del número.
*/

//Librerias
#include <stdio.h>

double factorial(double n);

int main()
{
	printf("Ingrese el número al que se le obtendrá el factorial:");
	double n;
	scanf("%lf", &n);
	printf("El valor del factorial es %.0lf.\n", factorial(n));
	return 0;
}

double factorial(double n)
{
	if (0 == n)
	{
		return 1.0;
	}
	else
	{
		return n*factorial(n-1.0);
	}
}
