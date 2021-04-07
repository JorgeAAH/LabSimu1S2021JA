/*
Autor: jorgeaah
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 Copyright (C) 2019 Free Software Foundation, Inc. This is free software; see the source for copying conditions. There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
Compilado:
Fecha: sáb 20 mar 2021 09:49:29 CST
Librerias: stdio,
Resumen:
Entrada:
Salida:
*/

//Librerias
#include <stdio.h>

void suma();
void resta();
void multiplicacion();
void division();

int main()
{
    printf("Bienvenido a CALCULADORA!!!\n");
    int opcion;
    do {
        printf("Ingrese la opcion deseada: Salir (0), sumar(1), restar (2), multiplicar (3) o dividir (4). \n");
        scanf("%i", &opcion);
        switch (opcion){
        case 0:
            return 0;
        case 1:
            suma();
            break;
        case 2:
            resta();
            break;
        case 3:
            multiplicacion();
            break;
        case 4:
            division();
        }
    } while (0 != opcion);
    return 0;
}

void suma(){
    float sumando_uno;
    float sumando_dos;
    printf("Ingrese el primer sumando: ");
    scanf("%f", &sumando_uno);
    printf("Ingrese el segundo sumando: ");
    scanf("%f", &sumando_dos);
    float resultado = sumando_uno + sumando_dos;
    printf("El resultado de la suma es: %f \n", resultado);
}

void resta(){
    float minuendo;
    float sustraendo;
    printf("Ingrese el minuendo: ");
    scanf("%f", &minuendo);
    printf("Ingrese el sustraendo: ");
    scanf("%f", &sustraendo);
    float resultado = minuendo - sustraendo;
    printf("El resultado de la resta es: %f \n", resultado);
}

void multiplicacion(){
    float factor_uno;
    float factor_dos;
    printf("Ingrese el primer factor: ");
    scanf("%f", &factor_uno);
    printf("Ingrese el segundo factor: ");
    scanf("%f", &factor_dos);
    float resultado = factor_uno * factor_dos;
    printf("El resultado de la multiplicacion es: %f \n", resultado);
}

void division(){
    float dividendo;
    float divisor;
    printf("Ingrese el dividendo: ");
    scanf("%f", &dividendo);
    printf("Ingrese el divisor: ");
    scanf("%f", &divisor);
    float resultado = dividendo / divisor;
    printf("El resultado de la division es: %f \n", resultado);
}
