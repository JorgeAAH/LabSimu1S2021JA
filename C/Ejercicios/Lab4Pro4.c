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

void imprimir_matriz(float matriz[][3]);
void leer_matriz(float matriz_resultante[][3]);
void matriz_por_constante(float matriz[][3], float constante, float matriz_ingresada[][3]);
void suma_matrices(float matriz_resultante[][3], float matriz_a[][3], float matriz_b[][3]);
void multiplicacion_matrices(float matriz_resultante[][3], float matriz_a[][3], float matriz_b[][3]);
float determinante_matriz(float matriz[][3]);
void transpuesta_matriz(float matriz_resultante[][3], float matriz[][3]);
void inversa_matriz(float matriz_resultante[][3], float matriz[][3]);
void reduccion_gauss(float matriz_resultante[][3], float matriz[][3]);

int main()
{
	float A[3][3];
	float B[3][3];
	float R[3][3]; //Almacena resultados y valores intermedios.
	float k;
	printf("Ingrese la matriz A:\n");
	leer_matriz(A);
	printf("Ingrese la matriz B:\n");
	leer_matriz(B);
	printf("Ingrese la constante k:");
	scanf("%f",&k);
	printf("El resultado de kA es: \n");
	matriz_por_constante(R, k, A);
	imprimir_matriz(R);
	printf("El resultado de A+B es:\n");
	suma_matrices(R,A,B);
	imprimir_matriz(R);
	printf("El resultado de A-B es: \n");
	matriz_por_constante(R, -1.0F, B);
	suma_matrices(R,A,R);
	imprimir_matriz(R);
	printf("El resultado de A*B es: \n");
	multiplicacion_matrices(R,A,B);
	imprimir_matriz(R);
	printf("El resultado de det(A) es %f.\n", determinante_matriz(A));
	printf("El resultado de trans(B) es: \n");
	transpuesta_matriz(R,B);
	imprimir_matriz(R);
	printf("El resultado de inv(A) es:\n");
	inversa_matriz(R, A);
	imprimir_matriz(R);
	printf("El resultado de triangular A es:\n");
	reduccion_gauss(R,A);
	imprimir_matriz(R);
	printf("El resultado de triangular B es:\n");
	reduccion_gauss(R,B);
	imprimir_matriz(R);
}

void imprimir_matriz(float matriz[][3])
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

void leer_matriz(float matriz_resultante[][3])
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

void matriz_por_constante(float matriz_resultante[][3], float constante, float matriz[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matriz_resultante[i][j] = constante*matriz[i][j];
		}
	}
}

void suma_matrices(float matriz_resultante[][3], float matriz_a[][3], float matriz_b[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matriz_resultante[i][j] = matriz_a[i][j] + matriz_b[i][j];
		}
	}
}

void multiplicacion_matrices(float matriz_resultante[][3], float matriz_a[][3], float matriz_b[][3])
{
	float temporal[3][3] = {{0.0F, 0.0F,0.0F}, {0.0F, 0.0F,0.0F}, {0.0F, 0.0F,0.0F}};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				temporal[i][j] += matriz_a[i][k]*matriz_b[k][j];
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matriz_resultante[i][j] = temporal[i][j];
		}
	}
}

float determinante_matriz(float matriz[][3])
{
	return matriz[0][0]*(matriz[1][1]*matriz[2][2]-matriz[1][2]*matriz[2][1]) - matriz[0][1]*(matriz[1][0]*matriz[2][2]-matriz[1][2]*matriz[2][0]) + matriz[0][2]*(matriz[1][0]*matriz[2][1]-matriz[1][1]*matriz[2][0]);
}

void transpuesta_matriz(float matriz_resultante[][3], float matriz[][3])
{
	float temporal[3][3] = {{0.0F, 0.0F,0.0F}, {0.0F, 0.0F,0.0F}, {0.0F, 0.0F,0.0F}};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			temporal[i][j] = matriz[j][i];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matriz_resultante[i][j] = temporal[i][j];
		}
	}
}

void inversa_matriz(float matriz_resultante[][3], float matriz[][3])
{
	//Calculo cofactores fila 1
	float M00 = matriz[1][1]*matriz[2][2]-matriz[1][2]*matriz[2][1];
	float M01 = -(matriz[1][0]*matriz[2][2]-matriz[1][2]*matriz[2][0]);
	float M02 = matriz[1][0]*matriz[2][1]-matriz[1][1]*matriz[2][0];
	//Calculo cofactores fila 2
	float M10 = -(matriz[0][1]*matriz[2][2]-matriz[0][2]*matriz[2][1]);
	float M11 = matriz[0][0]*matriz[2][2]-matriz[0][2]*matriz[2][0];
	float M12 = -(matriz[0][0]*matriz[2][1]-matriz[0][1]*matriz[2][0]);
	//Calculo cofactores fila 3
	float M20 = matriz[0][1]*matriz[1][2]-matriz[0][2]*matriz[1][1];
	float M21 = -(matriz[0][0]*matriz[1][2]-matriz[0][2]*matriz[1][0]);
	float M22 = matriz[0][0]*matriz[1][1]-matriz[0][1]*matriz[1][0];
	//Escribiendo la matriz inversa:
	float e = 1.0F/determinante_matriz(matriz);
	matriz_resultante[0][0] = e*M00;
	matriz_resultante[0][1] = e*M10;
	matriz_resultante[0][2] = e*M20;
	matriz_resultante[1][0] = e*M01;
	matriz_resultante[1][1] = e*M11;
	matriz_resultante[1][2] = e*M21;
	matriz_resultante[2][0] = e*M02;
	matriz_resultante[2][1] = e*M12;
	matriz_resultante[2][2] = e*M22;
}

void reduccion_gauss(float matriz_resultante[][3], float matriz[][3])
{
	float temporal[3][3] = {{0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			temporal[i][j] = matriz[i][j];
		}
	}
	//Obtención de matriz triangular.
	float escala = -temporal[1][0]/temporal[0][0];
	for (int j = 0; j < 3; j++)
	{
		temporal[1][j] += escala* temporal[0][j];
	}
	escala = -temporal[2][0]/temporal[0][0];
	for (int j = 0; j < 3; j++)
	{
		temporal[2][j] += escala* temporal[0][j];
	}
	escala = -temporal[2][1]/temporal[1][1];
	for (int j = 0; j < 3; j++)
	{
		temporal[2][j] += escala* temporal[1][j];
	}
	//Retorno de la matriz triangular.
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matriz_resultante[i][j] = temporal[i][j];
		}
	}
}
