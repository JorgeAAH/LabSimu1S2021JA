/*
Autor: jorgeaah
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 Copyright (C) 2019 Free Software Foundation, Inc. This is free software; see the source for copying conditions. There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
Compilado: gcc Lab4Pro2.c
Fecha: mar 04 may 2021 10:09:05 CST
Librerias: stdio,
Resumen: El programa acepta 5 números enteros, los ordena de forma ascendente y muestra el vector ordenado.
Entrada: Vector de 5 números enteros desordenados.
Salida: Vector de 5 número enteros ordenados.
*/

//Librerias
#include <stdio.h>

int main()
{
	printf("Importante, ingrese solo números enteros.\n");
	int vector[5];
	for (int i = 0; i < 5; i++)
	{
		printf("Ingrese el elemento %i del vector:", i+1);
		scanf("%i", &vector[i]);
	}
	//Algoritmo de ordenación.
	for (int i = 4; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (vector[j+1] < vector[j])
			{
				int temp = vector[j+1];
				vector[j+1] = vector[j];
				vector[j] =  temp;
			}
		}
	}
	printf("Vector ordenado:%i,%i,%i,%i,%i.", vector[0], vector[1], vector[2], vector[3], vector[4]);
	return 0;
}
