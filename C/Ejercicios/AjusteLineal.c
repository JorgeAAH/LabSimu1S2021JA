/*
Autor: jorgeaah
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 Copyright (C) 2019 Free Software Foundation, Inc. This is free software; see the source for copying conditions. There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
Compilado:
Fecha: dom 02 may 2021 11:43:55 CST
Librerias: stdio,
Resumen: Programa que a partir de unos datos bivariados genera una recta de ajuste lineal y su grafica.
Entrada:
Salida:
*/

//Librerias
#include <stdio.h>
#include <stdlib.h>
//Definiciones de constantes
#define NUMEROPARES 8

float suma_arreglo(float *arreglo, int numero_elementos);
float suma_cuadrado_arreglo(float *arreglo, int numero_elementos);
float suma_multiplicacion_arreglos(float *arreglo_1, float *arreglo_2, int numero_elementos);
float calcular_m(float *x, float *y, int numero_elementos);
float calcular_b(float *x, float *y, int numero_elementos);

int main()
{
	int numero_pares = NUMEROPARES;
	float x[NUMEROPARES] = {1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F, 7.0F, 8.0F};
	float y[NUMEROPARES] = {0.01F, 0.03F, 0.09F, 0.13F, 0.19F, 0.22F, 0.37F, 0.43F};
	float incerteza = 0.01F;
	float m = calcular_m(x, y, numero_pares);
	float b = calcular_b(x,y, numero_pares);
	//Mostrando los valores de salida
	printf("Valor de m: %f. Valor de b: %f. \n",m,b);
	printf("Estimacion despues de 23 semanas: %f. \n", b+m*23.0F);
	//Escribiendo el script para gnuplot
	FILE *fp;
	fp = fopen("ajustelineal", "w+");
	fprintf(fp, "set terminal wxt \n");
	fprintf(fp, "set title \"Crecimiento de una planta\" \n");
	fprintf(fp, "set xlabel \"Tiempo [semanas] \n");
	fprintf(fp, "set xrange [0: 9] \n");
	fprintf(fp, "set ylabel \"Altura [m]\" \n");
	fprintf(fp, "set yrange [0: 0.5] \n");
	fprintf(fp, "ajuste(x) = %f + %f*x \n", b,m);
	fprintf(fp, "plot \"ajustelineal.dat\" using 1:2:3 with yerrorbars title \"Altura vrs tiempo\", ajuste(x) with lines title \"Ajuste lineal\" \n");
	fclose(fp);
	//Escribiendo el archivo .dat para gnuplot
	fp = fopen("ajustelineal.dat", "w+");
	for (int i = 0;  i < numero_pares; i++)
	{
		fprintf(fp, "%f	%f	0.01\n", x[i], y[i]);
	}
	fclose(fp);
	//Llamando a gnuplot
	system("gnuplot --persist ajustelineal");
	return 0;
}

float suma_arreglo(float *arreglo, int numero_elementos)
{
	float variable_retorno = 0.0F;
	for (int i = 0;  i < numero_elementos; i++)
	{
		variable_retorno += arreglo[i];
	}
	return variable_retorno;
}

float suma_cuadrado_arreglo(float *arreglo, int numero_elementos)
{
	float variable_retorno = 0.0F;
	for (int i = 0; i < numero_elementos; i++)
	{
		variable_retorno += arreglo[i]*arreglo[i];
	}
	return variable_retorno;
}

float suma_multiplicacion_arreglos(float *arreglo_1, float *arreglo_2, int numero_elementos)
{
	float variable_retorno = 0.0F;
	for (int i = 0; i < numero_elementos; i++)
	{
		variable_retorno += arreglo_1[i]*arreglo_2[i];
	}
	return variable_retorno;
}

float calcular_m(float *x, float *y, int numero_elementos)
{
	float suma_x = suma_arreglo(x, numero_elementos);
	float suma_y = suma_arreglo(y, numero_elementos);
	float suma_xx = suma_cuadrado_arreglo(x, numero_elementos);
	float suma_xy = suma_multiplicacion_arreglos(x, y, numero_elementos);
	return (numero_elementos*suma_xy-suma_x*suma_y)/(numero_elementos*suma_xx-suma_x*suma_x);
}

float calcular_b(float *x, float *y, int numero_elementos)
{
	float suma_x = suma_arreglo(x, numero_elementos);
	float suma_y = suma_arreglo(y, numero_elementos);
	float suma_xx = suma_cuadrado_arreglo(x, numero_elementos);
	float suma_xy = suma_multiplicacion_arreglos(x, y, numero_elementos);
	float m = (numero_elementos*suma_xy-suma_x*suma_y)/(numero_elementos*suma_xx-suma_x*suma_x);
	return (suma_y-m*suma_x)/numero_elementos;
}
