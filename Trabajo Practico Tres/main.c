#include <stdio.h>
#include <stdlib.h>
#define MOVIETAM 50
#include "funciones.h"
int main()
{
int cargado;
int guardado;
   EMovie listaMovie[MOVIETAM];
   inicializadorEstadoPelicula(listaMovie,MOVIETAM);
   cargado=cargar(listaMovie,MOVIETAM);

  if(cargado==0)
  {
      printf("se cargo el archivo");
  }
  else{
    printf("no se cargo el archivo");
  }
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {


        printf("\n");
        printf(" 1-  Agregar Pelicula\n");
        printf(" 2-  Borrar Pelicula\n");
        printf(" 3-  Modificar Pelicula\n");
        printf(" 4-  Generrar Pagina\n");
        printf(" 5-  Salir\n");

        pedirMensaje("elija una opcion\n",auxiliar);
        validar_numero(auxiliar);
        opcion=atoi(auxiliar);

        switch(opcion)
        {
        case 1:
alta(listaMovie,MOVIETAM);
guardado=guardar(listaMovie,MOVIETAM);
if(guardado!=0)
    {
      printf("se guardo el archivo");
getch();
  }

            break;
        case 2:
darDebaja(listaMovie,MOVIETAM);
guardado=guardar(listaMovie,MOVIETAM);
if(guardado!=0)
    {
      printf("se guardo el archivo");
getch();
  }
            break;
        case 3:
   modificar(listaMovie,MOVIETAM);
   guardado=guardar(listaMovie,MOVIETAM);
if(guardado!=0)
    {
      printf("se guardo el archivo");
getch();
  }
            break;
        case 4:

pagina(listaMovie,MOVIETAM);
  guardado=guardar(listaMovie,MOVIETAM);
if(guardado!=0)
    {
      printf("se guardo el archivo");
  }
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
