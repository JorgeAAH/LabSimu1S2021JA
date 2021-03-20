/*
Autor: jorgeaah
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 Copyright (C) 2019 Free Software Foundation, Inc. This is free software; see the source for copying conditions. There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
Compilado:
Fecha: sáb 20 mar 2021 10:32:42 CST
Librerias: stdio,
Resumen:
Entrada:
Salida:
*/

//Librerias
#include <stdio.h>

int main()
{
	printf("Programa que calcula la raiz cuadrada entera de un numero N positivo ingresado.  \n");
	printf("Ingrese el numero N: ");
	float N;
	scanf("%f", &N);
	int i = 1;
	while ( ((float)i * (float)i) < N)
	{
		i++;
	}
	printf("El resultado es: %d. \n", i-1);
	return 0;
}
