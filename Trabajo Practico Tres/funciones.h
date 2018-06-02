typedef struct{
    int id;
    char titulo[50];
    char genero[50];
    int duracion;
    char descripcion[700];
    int puntaje;
    char linkImagen[700];
    int estado;
}EMovie;


char auxiliar [];
/** \brief inicializo el estado de los usuarios
 *
 * \param estructura usuario
 * \param limite del usurario
 * \return
 *
 */
 int inicializadorEstadoPelicula(EMovie*listado,int limite);
 /** \brief busco un lugar libre
 *
 * \param listado[] ePropetarios
 * \param limite int limite
 * \return int
 *
 */
 int buscarLugarLibre(EMovie *listado,int limite);


/** \brief muestro toda
 *
 * \param estructura usuario
 * \param limite
 * \return void
 *
 */
 void mostrarPersonas (EMovie*mostrar,int limite);
 /** \brief busco el siguiente id autoincremental
 *
 * \param listado[] ePropetarios
 * \param limite int
 * \return int
 *
 */
 int siguienteId(EMovie*listado,int limite);
 /** \brief pido un string
 *
 * \param
 * \param
 * \return
 *
 */
char pedirMensaje (char mensaje[], char auxiliarChar[]);
/** \brief valido que sean solo palabras
 *
 * \param palabra[] char
 * \return int
 *
 */
int validarPalabra(char palabra[]);
/** \brief valido que sean solos numeros
 *
 * \param numero[] char
 * \return int
 *
 */
int validar_numero(char numero[]);
int cargar(EMovie* movie, int limite);
int guardar(EMovie* movie, int limite);
int buscarPorId(EMovie *listado,int limite, int id);
void modificar(EMovie *listado,int limite);
void darDebaja(EMovie *listado,int limite);
void pagina(EMovie *listado, int limite);
