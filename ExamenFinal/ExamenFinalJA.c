/*
Autor: jorgeaah
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 Copyright (C) 2019 Free Software Foundation, Inc. This is free software; see the source for copying conditions. There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
Compilado: gcc ExamenFinal.c -lm
Fecha: jue 13 may 2021 10:34:08 CST
Librerias: stdio, math, stdlib
Resumen: El programa simula el movimiento de 3 cohetes.
Entrada: Conjunto de constantes para cada cohete.
Salida: Un archivo .dat para cada cohete con los datos necesarios para graficar y la información básica de la simulación.
*/

//Librerias
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Constantes "universales"
const float G = 6.693e-11F;
const float R_T = 6.378e6F;
const float M_T = 5.9736e24F;
const float R = 287.06F;
const float L = 6.5e-3F;
const float g_0 = 9.81F;
const float T_0 = 288.15F;
const float P_0 = 101325.0F;

//Método único de simulación para los tres cohetes.
void simulacion_cohete(char *nombre, float E_0, float TSFC, float CD, float A, float m_0, float m_f0);

//Método para calcular la masa del cohete.
float masa_cohete(float t, float m_0, float m_f0, float TSFC, float E_0);

//Método para calcular la gravedad.
float gravedad(float y);

//Método para calcular la fuerza de fricción.
float friccion(float y, float derivative_y, float CD, float A);

//Método para calcular la densidad del aire.
float densidad(float y);

int main()
{
	printf("Bienvenido!!!\n");
	char nombre1[20] = "Ah Mun";
	char nombre2[20] = "Ahua Kin";
	char nombre3[20] = "Chac";
	simulacion_cohete(nombre1, 3e7F, 3.248e-4F, 61.27F, 201.06F, 1.1e5F, 1.5e6F);
	simulacion_cohete(nombre2, 2.7e7F, 2.248e-4F, 61.27F, 201.06F, 1.1e5F, 1.5e6F);
	simulacion_cohete(nombre3, 2.5e7F, 2.248e-4F, 70.25F, 215.00F, 1.8e5F, 2.1e6F);
	return 0;
}

//Código función para calcular la densidad del aire.
float densidad(float y)
{
	if (y > (T_0/L))
	{
		return 0.0F;
	}
	return (P_0/(R*T_0))*pow(1.0F-L*y/T_0, g_0/(R*L));
}

//Código función para calcular la fuerza de fricción.
float friccion(float y, float derivative_y, float CD, float A)
{
	return 0.5F*densidad(y)*CD*A*derivative_y*abs(derivative_y);
}

//Código función para calcular la gravedad.
float gravedad(float y)
{
	return G*M_T/pow(R_T+y, 2.0F);
}

//Código para calcular la masa del cohete.
float masa_cohete(float t, float m_0, float m_f0, float TSFC, float E_0)
{
	//Se calcula la masa del combustible con una integral.
	float masa_combustible = m_f0 - TSFC*E_0*t;
	//Comprobación de que no sea una masa negativa.
	if (masa_combustible < 0.0F)
	{
		masa_combustible = 0.0F;
	}
	return masa_combustible + m_0;
}

void simulacion_cohete(char *nombre, float E_0, float TSFC, float CD, float A, float m_0, float m_f0)
{
	//Valores iniciales en el método de Euler.
	float derivative_y = 0.0F; //O velocidad...
	float y = 0.57F;
	float t = 0.0F;
	//Apertura del fichero para mostrar resultados.
	FILE *fp;
	fp = fopen(nombre, "w+");
	//Guardando los datos iniciales.
	fprintf(fp, "%.10ef	%.10ef	%.10ef\n", t, y, derivative_y);
	//Duración del empuje (Calculado mediante integracion):
	float t_empuje = m_f0/(TSFC*E_0);
	//Variable para almacenar la altura máxima.
	float altura_maxima = 0.0F;
	//Presentación de los datos del cohete en consola.
	printf("-------------------------------------------------------------------\n");
	printf("Nombre del cohete: %s\n", nombre);
	printf("Empuje del cohete [N]: %.2ef\n", E_0);
	printf("Consumo especifico del empuje [kg/N*s]: %.2ef\n", TSFC);
	printf("Coeficiente de forma: %.2f\n", CD);
	printf("Sección transversal del cohete [m^2]: %.2f\n", A);
	printf("Masa del cohete vacío [kg]: %.2ef\n", m_0);
	printf("Masa inicial del combustible [kg]: %.2ef\n", m_f0);
	//Comienzo del bucle del Euler.
	for(;;)
	{
		//La fuerza total según la ecuación de las leyes de Newton.
		float fuerza = -friccion(y, derivative_y, CD, A);
		fuerza -= masa_cohete(t, m_0, m_f0, TSFC, E_0)*gravedad(y);
		//Agregando el término del empuje. ¡Debe ser condicional al combustible!
		if (t < t_empuje)
		{
			fuerza += E_0;
		}
		//Calculando la aceleración.
		float aceleracion = fuerza/masa_cohete(t, m_0, m_f0, TSFC, E_0);
		//Calculando los nuevos valores. Este es el paso de Euler.
		float promedio_derivative_y = derivative_y;
		//Nueva velocidad.
		derivative_y += aceleracion*0.1F;
		promedio_derivative_y += derivative_y;
		promedio_derivative_y = promedio_derivative_y*0.5F;
		//Nueva altura, para ser más exactos usamos el promedio de la velocidad.
		y += promedio_derivative_y*0.1F;
		//Condición para mejorar la "altura maxima".
		if (y > altura_maxima)
		{
			altura_maxima = y;
		}
		//Nuevo tiempo.
		t += 0.1F;
		//Almacenamiento de los nuevos datos.
		fprintf(fp, "%.10ef	%.10ef	%.10ef", t, y, derivative_y);
		//Condición de regreso a tierra.
		if (y < 0.0F)
		{
			printf("Altura máxima [m]: %.2ef\n", altura_maxima);
			printf("Tiempo de empuje [s]: %.2ef\n", t_empuje);
			printf("Tiempo hasta impacto [min]: %i\n", (int) (t/60.0F));
			fclose(fp);
			return;
		}
		else
		{
			fprintf(fp,"\n"); 
			//Esto se hace para evitar un problema con una linea vacía en gnuplot.
			//Solo se corre sino es el final de la simulación.
		}
	}
}
