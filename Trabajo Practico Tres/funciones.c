#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LIBRE 1
#define OCUPADO 2
#define BORRADO 3
int validar_numero(char numero[])
{
    int i;
    for(i=0; i<strlen(numero); i++)

    {
        if(isdigit(numero[i])==0||numero[i]==' ')
        {


            do
            {
                printf("\nError solo numero reingrese\n");
                gets(numero);
                fflush(stdin);
            }
            while(isdigit(numero[i])==0);

        }
    }
    return 1;
}



int validarPalabra(char palabra[])
{
    int i;
    for(i=0; i<strlen(palabra); i++)
    {

        if(isalpha(palabra[i])==0)
        {
            do
            {
                printf("\nError solo palabra reingrese \n");
                gets(palabra);

                fflush(stdin);
            }
            while(isalpha(palabra[i])==0);


        }
    }
    return 1;
}
int cargar(EMovie* movie, int limite)
{
    FILE* peliculas;
    int i=0, retorno=0;
    peliculas = fopen("peliculas.dat", "rb");
    if(peliculas==NULL)
    {
        retorno=-1;
    }
    if(retorno!=-1)
    {
        while(!feof(peliculas))
        {
            fread(&movie[i], sizeof(EMovie), 1,peliculas);
            i++;
        }
        fclose(peliculas);
    }

    return retorno;
}
int guardar(EMovie* movie, int limite)
{
    FILE* pelicula;
    int i;
    pelicula = fopen("peliculas.dat", "wb");
    if(pelicula == NULL)
    {
        printf("\n No se pudo guardar el archivo");
        system("pause");
        return 0;
    }
    for(i=0; i<limite; i++)
    {
        if(movie[i].estado==OCUPADO)
        {
            fwrite(&movie[i], sizeof(EMovie), 1, pelicula);
        }

    }

    fclose(pelicula);
    return 1;
}


char pedirMensaje (char mensaje[], char auxiliarChar[])
{
    printf("%s",mensaje);
    gets(auxiliarChar);
    fflush(stdin);




    return auxiliarChar;
}



int buscarPorId(EMovie *listado,int limite, int id)
{
    int retorno = -1;
    int i;

    for(i=0; i<limite; i++)
    {
        if((listado+i)->estado == OCUPADO && (listado+i)->id == id)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}
int buscarLugarLibre(EMovie *listado,int limite)

{
    int i;
    int indice=-1;
    for(i=0; i<limite; i++)
    {
        if((listado+i)->estado==LIBRE)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
void mostrarPersonas (EMovie*mostrar,int limite)
{
    int i;
    printf("id:\t  titulo:\t  genero:\t  puntaje:\t ");
    for(i=0; i<limite; i++)
    {
        if((mostrar+i)->estado==OCUPADO)
        {

            printf("\n%d\t %s\t           %s\t          %d\t",(mostrar+i)->id,(mostrar+i)->titulo,(mostrar+i)->genero,(mostrar+i)->puntaje);

        }
    }

}

int siguienteId(EMovie*listado,int limite)
{
    int retorno = 0;
    int i;



    for(i=0; i<limite; i++)
    {
        if((listado+i)->estado == OCUPADO||(listado+i)->estado==BORRADO)
        {
            if((listado+i)->id>retorno)
            {
                retorno=(listado+i)->id;
            }

        }
    }


    return retorno+1;
}
int inicializadorEstadoPelicula(EMovie*listado,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            (listado+i)->estado = LIBRE;
        }
    }
    return retorno;
}
int alta(EMovie * listado,int limite)
{
    int retorno = -1;
    int indice;
    int duracion;
    int puntaje;




    indice=buscarLugarLibre(listado,limite);
    if(indice >= 0)
    {

        pedirMensaje("ingrese titulo \n",auxiliar);
        strcpy((listado+indice)->titulo,auxiliar);
        pedirMensaje("ingrese genero de la pelicula \n",auxiliar);
        strcpy((listado+indice)->genero,auxiliar);
        (listado+indice)->id=siguienteId(listado,limite);
        pedirMensaje("ingrese el link de la imagen\n",auxiliar);
        strcpy((listado+indice)->linkImagen,auxiliar);
        pedirMensaje("ingrese la duracion \n",auxiliar);
        validar_numero(auxiliar);
        duracion=atoi(auxiliar);
        (listado+indice)->duracion=duracion;
        pedirMensaje("ingrese la descripcion \n",auxiliar);
        strcpy((listado+indice)->descripcion,auxiliar);
        do
        {
            pedirMensaje("ingrese nuevo puntaje de 1 a 10 \n",auxiliar);
            validar_numero(auxiliar);
            puntaje=atoi(auxiliar);

        }
        while(puntaje<0||puntaje>11);
        (listado+indice)->puntaje=puntaje;
        (listado+indice)->estado=OCUPADO;



    }
    else
    {
        printf(" no hay lugar");
        getch();
    }

    return retorno;
}
void modificar(EMovie *listado,int limite)
{
    int opcion ;
    int i;
    int opcion2;
    int duracion;
    int puntaje;
    mostrarPersonas(listado, limite);
    pedirMensaje("\ningrese el id que quiere modificar\n",auxiliar);
    validar_numero(auxiliar);
    opcion=atoi(auxiliar);
    opcion=buscarPorId(listado,limite,opcion);


    if (opcion!=-1)
    {
        pedirMensaje("que desea modificar ? \n 1-Titulo\n2-Genero\n3-link imagen\n4-Duracion\n5-Descripcion\n6-puntaje",auxiliar);
        validar_numero(auxiliar);
        opcion2=atoi(auxiliar);

        switch(opcion2)
        {
        case 1:

            pedirMensaje("iingrese nuevo titulo\n",auxiliar);
            strcpy((listado+opcion)->titulo,auxiliar);
            break;
        case 2:
            pedirMensaje("ingrese nuevo genero de la pelicula \n",auxiliar);

            strcpy((listado+opcion)->genero,auxiliar);
            break;
        case 3:
            pedirMensaje("ingrese el nuevo link de la imagen\n",auxiliar);
            strcpy((listado+opcion)->linkImagen,auxiliar);
            break;
        case 4:
            pedirMensaje("ingrese la nueva duracion de la pelicula \n",auxiliar);
            validar_numero(auxiliar);
            duracion=atoi(auxiliar);
            (listado+opcion)->duracion=duracion;
            break;
        case 5:
            pedirMensaje("ingrese nueva descripcion \n",auxiliar);
            strcpy((listado+opcion)->descripcion,auxiliar);
            break;
        case 6:
            do
            {
                pedirMensaje("ingrese nuevo puntaje de 1 a 10 \n",auxiliar);
                validar_numero(auxiliar);
                puntaje=atoi(auxiliar);

            }
            while(puntaje<0||puntaje>11);
            (listado+opcion)->puntaje=puntaje;
            break;
        }

    }
    else
    {
        printf("el id no existe");
        getch();

    }

}

void darDebaja(EMovie *listado,int limite)
{
    int opcion;
    int i;
    int opcion2;
    mostrarPersonas(listado,limite);
    pedirMensaje("\ningrese el id que quiere dar de baja\n",auxiliar);
    validar_numero(auxiliar);
    opcion=atoi(auxiliar);
    opcion=buscarPorId(listado,limite,opcion);
    if(opcion!=-1)
    {
        pedirMensaje("esta seguro que quiere dar de baja?\n 1-para dar de baja \n 2-para cancelar ?\n",auxiliar);
        validar_numero(auxiliar);
        opcion2=atoi(auxiliar);
        if(opcion2==1)
        {

            (listado+opcion)->estado=BORRADO;
            printf("SE A DADO DE BAJA \n");
            getch();
        }

        else
        {
            printf("NO SE A DADO DE BAJA \n");
            getch();
        }

    }
    else
    {
        printf("id no existe \n");
        getch();
    }

}
void pagina(EMovie *listado, int limite)
{
    int i;
    FILE *pelicula;
    pelicula=fopen("pagina.html", "w");

    if(pelicula == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        fprintf(pelicula,"<!DOCTYPE html><!-- Template by Quackit.com --><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible'content='IE=edge'><meta name='viewport'content='width=device-width, initial-scale=1'><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><title>Lista peliculas</title><!-- Bootstrap Core CSS --><link href='css/bootstrap.min.css'rel='stylesheet'><!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --><link href='css/custom.css'rel='stylesheet'><!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --><!-- WARNING: Respond.js doesn't work if you view the page via file:// --><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head><body><div class='container'><div class='row'>");
        for(i=0; i<limite; i++)
        {
            if((listado+i)->estado==OCUPADO)
            {
                fprintf(pelicula,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s'alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Genero:%s</li><li>Puntaje:%d</li><li>Duracion:%d</li></ul><p>%s</p></article>",(listado+i)->linkImagen,(listado+i)->titulo,(listado+i)->genero,(listado+i)->puntaje,(listado+i)->duracion,(listado+i)->descripcion);
            }

        }
        fprintf(pelicula,"</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script><!-- Placeholder Images --><script src='js/holder.min.js'></script></body></html>");
        printf("Pagina  creada\n");

    }
    fclose(pelicula);
}
