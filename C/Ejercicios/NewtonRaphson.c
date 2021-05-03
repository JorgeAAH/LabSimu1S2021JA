/*
Autor: jorgeaah
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 Copyright (C) 2019 Free Software Foundation, Inc. This is free software; see the source for copying conditions. There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
Compilado: gcc NewtonRaphson.c
Fecha: lun 03 may 2021 10:31:55 CST
Librerias: stdio, stdlib,  math
Resumen: Programa que utiliza el metodo de la biseccion para encontrar la raíz de una ecuación dado un rango determinado.
Entrada:
Salida:
*/

//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float ecuacion(float x);
float biseccion(float x_inf, float x_sup, float error);

int main()
{
	float raiz = biseccion (0.0F, 100.0F, 0.001F);
	printf("La raiz de la ecuacion ingresada es %f con error de menos de una milésima. \n", raiz);
	//Escribiendo el script para gnuplot
	FILE *fp = fopen("NewtonRaphson", "w+");
	fprintf(fp, "set terminal wxt \n");
	fprintf(fp, "set title \"Raíz por el método de bisección\" \n");
	fprintf(fp, "set xlabel \"x\" \n");
	fprintf(fp, "set xrange [0: 10] \n");
	fprintf(fp, "set ylabel \"y\" \n");
	fprintf(fp, "set yrange [-1: 2] \n");
	fprintf(fp, "ecuacion(x) = sqrt(x*0.5)-1 \n");
	fprintf(fp, "set object circle at first %f,0 radius char 0.1 fillstyle empty border lc rgb \"#aa1100\" lw 2 \n", raiz);
	fprintf(fp, "plot ecuacion(x) with lines title \"sqrt(x/2)-1\" \n");
	fclose(fp);
	//Llamando a gnuplot
	system("gnuplot --persist NewtonRaphson");
	return 0;
}

float ecuacion(float x)
{
	return (float) sqrt((double) x*0.5F)-1.0F;
}

float biseccion(float x_inf, float x_sup, float error)
{
	float y_inf = ecuacion(x_inf);
	float y_sup = ecuacion(x_sup);
	while(1)
	{
		float x_med = 0.5F*(x_inf + x_sup);
		float y_med = ecuacion(x_med);
		if ((y_inf*y_med) > 0)
		{
			x_inf = x_med;
			y_inf = ecuacion(x_inf);
		}
		else
		{
			x_sup = x_med;
			y_sup = ecuacion(x_sup);
		}
		if ((x_sup-x_inf) < error)
		{
			return 0.5F*(x_sup+x_inf);
		}
	}
}
