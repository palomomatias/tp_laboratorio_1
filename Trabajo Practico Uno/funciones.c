#include <stdio.h>
#include "funciones.h"



float numUno()
{
        float respuesta;
        printf("ingrese el primer numero operando:\n");
        scanf("%f",&respuesta);
        return respuesta;
}


float numDos()
{
        float respuesta;
        printf("ingrese el segundo numero operando:\n");
        scanf("%f",&respuesta);
        return respuesta;
}


float suma(float a,float b)
{
        float resultado;
        resultado=a+b;
        printf("la suma de %.2f y %.2f es: %.2f\n",a,b,resultado);
}

float resta(float a,float b)
{
        float resultado;
        resultado=a-b;
        printf("la resta de %.2f y %.2f es: %.2f\n",a,b,resultado);

}

float division(float a,float b)
{
    float resultado;
    if(b==0)
    {
        printf("no se puede dividir por cero\n");
    }
    else
    {
        resultado=a/b;
        printf("la division de %.2f y %.2f es: %.2f\n",a,b,resultado);
    }
}


float multiplicacion(float a,float b)
{
    float resultado;
    resultado=a*b;
    printf("la multiplicacion de %.2f y %.2f es: %.2f\n",a,b,resultado);


    }



int factorial(int a)
{
    int factor=a;
    int factorial=1;
    if(a<0)
    {
    printf("no se puede sacar factor numero negativo\n");
    }

    else
    {
    for(int i=1; i<=a; i++)
        {
            factorial *= i;
        }
         printf("El factorial de %d es: %d \n",a,factorial);
    }
}
