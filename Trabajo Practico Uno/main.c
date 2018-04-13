#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float numeroUno;
    float numeroDos;
    int respuesta;

    while(seguir=='s')
    {

        printf("1- Ingresar 1er operando (A=%.2f)\n",numeroUno);
        printf("2- Ingresar 2do operando (B=%.2f)\n",numeroDos);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);
        system("cls");

        switch(opcion)
        {
            case 1:
                numeroUno=numUno();
                system("pause"),system("cls");
                 break;
            case 2:
                numeroDos=numDos();
                system("pause"),system("cls");
                break;
            case 3:
                respuesta=suma(numeroUno,numeroDos);
                system("pause"),system("cls");
                break;
            case 4:
                respuesta=resta(numeroUno,numeroDos);
                system("pause"),system("cls");
                break;
            case 5:
                respuesta=division(numeroUno,numeroDos);
                system("pause"),system("cls");
                break;
            case 6:
                respuesta=multiplicacion(numeroUno, numeroDos);
                system("pause"),system("cls");
                break;
            case 7:
                respuesta=factorial(numeroUno);
                system("pause"),system("cls");
                break;
            case 8:
                suma(numeroUno,numeroDos);
                resta(numeroUno,numeroDos);
                division(numeroUno,numeroDos);
                multiplicacion(numeroUno,numeroDos);
                factorial(numeroUno);

                system("pause"),system("cls");
                break;
            case 9:
                seguir = 'n';
                break;
        }

}
return 0;

}
