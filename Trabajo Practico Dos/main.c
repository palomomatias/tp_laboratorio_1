#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 20


int main()
{
    char seguir='s';
    int opcion=0;
    int flag=0;
EPersona listaPersona[TAM];
inicializadorEstadoUsuario(listaPersona,TAM);
    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
               alta(listaPersona,TAM);
               flag=1;
                break;
            case 2:
                darDebaja(listaPersona,TAM,flag);
                break;
            case 3:
                ordenarPorNombre(listaPersona,TAM,flag);
                getch();
                break;
            case 4:
                grafico(listaPersona);
                getch();
                break;
            case 5:
                seguir = 'n';
                break;
        }
         system("cls");
    }

    return 0;
}
