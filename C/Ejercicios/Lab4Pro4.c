/*
Autor: jorgeaah
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 Copyright (C) 2019 Free Software Foundation, Inc. This is free software; see the source for copying conditions. There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
Compilado: gcc Lab4Pro4.c
Fecha: mar 04 may 2021 12:18:18 CST
Librerias: stdio,
Resumen: El programa acepta dos matrices de 3x3 y caclucla una batería de operaciones entre ellas.
Entrada: Matrices de 3x3.
Salida: Resultados de las operaciones.
*/

//Librerias
#include <stdio.h>

//No se intentará hacer el programa muy "general" para matrices de nxn. (KISS).
//Pero se intentará que una matriz ingresada si pueda ser el resultado sin conflictos.

void imprimir_matriz(float** matriz);
void leer_matriz(float** matriz_resultante);
void matriz_por_constante(float** matriz, float constante, float** matriz_ingresada);
void suma_matrices(float** matriz_resultante, float** matriz_a, float** matriz_b);
void multiplicacion_matrices(float** matriz_resultante, float** matriz_a, float** matriz_b);
float determinante_matriz(float** matriz);
void transpuesta_matriz(float** matriz_resultante, float** matriz);
void inversa_matriz(float** matriz_resultante, float** matriz);
void reduccion_gauss(float** matriz_resultante, float** matriz);

void imprimir_matriz(float** matriz)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%.2f	", matriz[i][j]);
		}
		printf("\n");
	}
}

void leer_matriz(float** matriz_resultante)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("Ingrese el elemento en la posición (%i, %i):", i, j);
			scanf("%f", &matriz_resultante[i][j]);
		}
	}
}

void matriz_por_constante(float** matriz_resultante, float constante, float** matriz)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matriz_resultante[i][j] = constante*matriz[i][j];
		}
	}
}
