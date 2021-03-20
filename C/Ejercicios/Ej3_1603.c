/*
Autor: jorgeaah
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 Copyright (C) 2019 Free Software Foundation, Inc. This is free software; see the source for copying conditions. There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
Compilado:
Fecha: sáb 20 mar 2021 11:22:32 CST
Librerias: stdio,
Resumen:
Entrada:
Salida:
*/

//Librerias
#include <stdio.h>

int main()
{
	printf("Programa que detecta si un numero es primo.\n");
	int N;
	printf("Ingrese el numero: ");
	scanf("%d", &N);
	int i = 2;
	int primo = 1;
	while ((i < N-1) && (1 == primo))
	{
		if (0 == N%i)
		{
			primo = 0;
		}
		i++;
	}
	if (0 == primo)
	{
		printf("El número no es primo. \n");
	}
	else
	{
		printf("El número es primo. \n");
	}
	return 0;
}
