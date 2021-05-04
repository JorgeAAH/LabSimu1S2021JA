/*
Autor: jorgeaah
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 Copyright (C) 2019 Free Software Foundation, Inc. This is free software; see the source for copying conditions. There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
Compilado: gcc Lab4Pro1.c
Fecha: mar 04 may 2021 09:40:42 CST
Librerias: stdio,
Resumen: Programa que muestra los números pares de manera ascendente o descendente según lo quiera el usuario. Protegido contra errores del usuario.
Entrada: Opción de mostrar ascendentes "a" o descendentes "d".
Salida: Numeros pares.
*/

//Librerias
#include <stdio.h>

int pares[] = {2,4,6,8,10,12,14,16,18,20};
int total_pares = 10;
void ascendentes();
void descendentes();

int main()
{
	while(1)
	{
		printf("Para ver a los numeros pares escriba la opción correcta.\n");
		printf("Ascendentes (a) o descendentes (d):");
		char respuesta[100];
		scanf("%s", respuesta);
		if ('a' == respuesta[0])
		{
			ascendentes();
			return 0;
		}
		else if ('d' == respuesta[0])
		{
			descendentes();
			return 0;
		}
		else
		{
			printf("Ha ingresado una opción inválida!!!\n");
			printf("Ingrese solamente la letra \"a\" o la letra \"d\"\n");
		}
	}
}

void ascendentes()
{
	printf("Los números pares en forma ascendente son:\n");
	for(int i = 0; i < total_pares; i++)
	{
		printf("%i\n", pares[i]);
	}
}

void descendentes()
{
	printf("Los números pares en forma descendente son:\n");
	for(int i = total_pares - 1; i>=0; i--)
	{
		printf("%i\n", pares[i]);
	}
}
