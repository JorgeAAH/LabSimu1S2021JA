/*
Autor: jorgeaah
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 Copyright (C) 2019 Free Software Foundation, Inc. This is free software; see the source for copying conditions. There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
Compilado: gcc Lab4Pro3.c -lm
Fecha: mar 04 may 2021 10:31:40 CST
Librerias: stdio, math
Resumen: El programa acepta dos vectores en 3D y realiza las operaciones más comunes entre ellos.
Entrada: Dos vectores en 3D.
Salida: Magnitud de los vectores, suma de los vectores, producto escalar y producto vectorial.
*/

//Librerias
#include <stdio.h>
#include <math.h>

int main()
{
	struct vector3D
	{
		float x;
		float y;
		float z;
	} vector_1, vector_2;
	printf("Ingrese la coordenada x del primer vector:");
	scanf("%f", &vector_1.x);
	printf("Ingrese la coordenada y del primer vector:");
	scanf("%f", &vector_1.y);
	printf("Ingrese la coordenada z del primer vector:");
	scanf("%f", &vector_1.z);
	printf("Ingrese la coordenada x del segundo vector:");
	scanf("%f", &vector_2.x);
	printf("Ingrese la coordenada y del segundo vector:");
	scanf("%f", &vector_2.y);
	printf("Ingrese la coordenada z del segundo vector:");
	scanf("%f", &vector_2.z);
	float magnitud_1 = sqrt(vector_1.x*vector_1.x + vector_1.y*vector_1.y + vector_1.z*vector_1.z);
	float magnitud_2 = sqrt(vector_2.x*vector_2.x + vector_2.y*vector_2.y + vector_2.z*vector_2.z);
	printf("---RESULTADOS---\n");
	printf("La magnitud del primer vector es %f.\n", magnitud_1);
	printf("La magnitud del psegundo vector es %f.\n", magnitud_2);
	printf("El resultado de la suma es (%f,%f,%f).\n", vector_1.x + vector_2.x, vector_1.y + vector_2.y, vector_1.z + vector_2.z);
	printf("El resultado del producto escalar es %f.\n", vector_1.x*vector_2.x + vector_1.y*vector_2.y + vector_1.z*vector_2.z);
	printf("El resultado del producto vectorial es (%f,%f,%f).\n", vector_1.y*vector_2.z - vector_1.z*vector_2.y, -(vector_1.x*vector_2.z - vector_1.z*vector_2.x), vector_1.x*vector_2.y - vector_1.y*vector_2.x);
	return 0;
}
