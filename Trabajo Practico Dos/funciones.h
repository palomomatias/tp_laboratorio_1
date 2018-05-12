#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

char auxiliar[];
/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[],int limite);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[],int limite,int dni);
/** \brief ordena por nombre
 *
 * \param [] EPersona listado
 * \param limite int
 * \param flag int
 * \return void
 *
 */
void ordenarPorNombre(EPersona listado [],int limite,int flag);
/** \brief muestra las personas
 *
 * \param epersona mostrar
 * \param int limite
 * \return
 *
 */
void mostrarPersonas (EPersona mostrar [],int limite);
/** \brief busco persona
 *
 * \param listado[] EPersona
 * \param limite int
 * \param id int
 * \return int
 *
 */
int buscarPorPersona(EPersona listado[],int limite, int id);
/** \brief inicializo los estados
 *
 * \param listado[] EPersona
 * \param limite int
 * \return int
 *
 */
int inicializadorEstadoUsuario(EPersona listado[],int limite);
/** \brief valido palabra
 *
 * \param palabra[] char
 * \return int
 *
 */
int validarPalabra(char palabra[]);
/** \brief valido numero
 *
 * \param numero[] char
 * \return int
 *
 */
int validar_numero(char numero[]);
/** \brief  doy de baja
 *
 * \param [] EPersona listado
 * \param limite int
 * \return void
 *
 */
void darDebaja(EPersona listado [],int limite,int flag);
/** \brief realizo el grafico
 *
 * \param lista[] EPersona
 * \param limite int
 * \return void
 *
 */
void grafico(EPersona lista[] );
#endif // FUNCIONES_H_INCLUDED
