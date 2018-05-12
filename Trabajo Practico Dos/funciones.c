#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#define LIBRE 1
#define OCUPADO 0
#include <ctype.h>
#include <conio.h>

int validar_numero(char numero[])
{
    int i;
    for(i=0; i<strlen(numero); i++)
    {
        if(!(isdigit(numero[i]))||(isspace(numero[i])))
        {
            printf("\nINGRESA SOLO NUMEROS\n");
            return 0;
        }
    }
    return 1;
}
int validarPalabra(char palabra[])
{
    int i;
    for(i=0; i<strlen(palabra); i++)
    {

        if(!(isalpha(palabra[i]))||(isspace(palabra[i]))||palabra[i]== ' \0')
        {
            printf("\nERROR SOLO PALABRA, REINGRESE");
            return 0;
        }



    }
    return 1;
}
int inicializadorEstadoUsuario(EPersona listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado = OCUPADO;
        }
    }
    return retorno;
}
int buscarPorPersona(EPersona listado[],int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == LIBRE && listado[i].dni == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int obtenerEspacioLibre(EPersona listado[],int limite)
{
    {
        int i;
        int indice=-1;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==0)
            {
                indice=i;
                break;
            }
        }
        return indice;
    }
}
int alta(EPersona  listado[],int limite)
{
    int retorno = -1;
    int indice;
    int dni;
    int edad;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = obtenerEspacioLibre(listado,limite);
        if(indice >= 0)
        {

                           do
    {

        printf("ingrese su dni: \n");
        fflush(stdin);
        gets(auxiliar);

    }
    while(!validar_numero(auxiliar));
dni=atoi(auxiliar);
listado[indice].dni=dni;

                         do
                {
                    printf("INGRESE SU NOMBRE: \n");
                    fflush(stdin);
                    gets(auxiliar);
                }
                while(!validarPalabra(auxiliar));
                strcpy(listado[indice].nombre,auxiliar);
                               do
    {

        printf("ingrese su edad: \n");
        fflush(stdin);
        gets(auxiliar);

    }
    while(!validar_numero(auxiliar));
edad=atoi(auxiliar);
listado[indice].edad=edad;
            listado[indice].estado = LIBRE;

        }
    }
    return retorno;
}
void mostrarPersonas (EPersona mostrar [],int limite)
{
    int i;
    for(i=0; i<limite; i++)
    {
        if(mostrar[i].estado==LIBRE)
        {
            printf("Id:%d NOMBRE: %s \n",mostrar[i].dni,mostrar[i].nombre);

        }
    }

}
void ordenarPorNombre(EPersona listado [],int limite,int flag)
{
    EPersona auxiliar;
    int i;
    int j;
   if (flag==1)
   {


    for(i=0; i<limite; i++)
    {
        for(j=i+1; j<limite; j++)
        {
            if(strcmp(listado[i].nombre,listado[j].nombre)>0)
            {

                auxiliar=listado[i];
                listado[i]=listado[j];
                listado[j]=auxiliar;
            }

        }
    }


    mostrarPersonas(listado,limite);
   }
else {
    printf("necesita tener un dato cargado\n");
}
}

void darDebaja(EPersona listado [],int limite,int flag)
{
    int opcion;
    int i;
    int opcion2;
    if (flag==1)
    {


    mostrarPersonas(listado,limite);
   do
    {

        printf("ingrese el dni que uqiere dar de baja:\n");
        fflush(stdin);
        gets(auxiliar);

    }
    while(!validar_numero(auxiliar));
    opcion=atoi(auxiliar);
    for(i=0; i<limite; i++)
    {
        fflush(stdin);
        if (opcion==listado[i].dni)
        {
            fflush(stdin);
            //mostrarUno(listado[i]);

             do
    {

       printf("esta seguro que quiere dar de baja ? \n aprete 1 para borrar 0 para cancelar\n ");
        fflush(stdin);
        gets(auxiliar);

    }
    while(!validar_numero(auxiliar));
    opcion2=atoi(auxiliar);

            if (opcion2==1)
            {
                fflush(stdin);
                printf("Se a dado de baja");
                listado[i].estado=2;
                break;
            }
            else
            {
                printf("no se a dado de baja");
            }

        }

    }
    }
    else
    {
        printf("no hay  datos cargados");
    }

}

void grafico(EPersona lista[])
{
    int flag;
    int menor=0;
    int mediano=0;
    int adulto=0;
    int mayor;
    int i;



    for(i=0; i<20; i++)
    {
        if(lista[i].estado==LIBRE)
        {


            if(lista[i].edad<18)
            {
                menor=++menor;
            }
            else if(lista[i].edad>18&&lista[i].edad<=35)
            {
                mediano=++mediano;
            }
            else if(lista[i].edad>35)
            {
                adulto=++adulto;
            }
        }
    }
    if(menor>=mediano&&menor>=adulto)
    {
        mayor=mediano;
    }
    else if(mediano>=menor&&mediano>=adulto)
    {
        mayor=mediano;
    }
    else
    {
        mayor=adulto;
    }
    for(i=mayor; i>0; i--)
    {
        flag=0;
        printf("\n");
        if(i<=menor)
        {
            printf("\t*");
            flag=1;
        }
        if(i<=mediano)
        {
            if(flag==1)
            {
                printf("\t  *");
                flag=2;
            }
            else if(flag==0)
            {
                printf("\t\t  *");
                flag=2;
            }

        }
        if(i<=adulto)
        {
            if(flag==0)
            {
                printf("\t\t\t    *");
            }
            else if(flag==1)
            {
                printf("\t\t    *");
            }
            else if(flag==2)
            {
                printf("\t    *");
            }
        }
    }
    if(mediano==0&&menor==0&&adulto==0)
    {
               printf("\nPara realizar el grafico es necesario ingresar algun usuario al sistema");
    }
    else
{


        printf("\n|      <18      19-35      >35      |");



        }

}

