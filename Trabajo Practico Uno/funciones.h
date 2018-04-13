#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


/** \brief pido el primer numero
 *
 * \return retorno el numero
 *
 */
float numUno();

/** \brief pido el segundo numero
 *
 * \return retorno el segundo numero
 *
 */
float numDos();

/** \brief sumo los 2 numeros
 *
 * \param a float primer numero
 * \param b float segundo numero
 *
 */
float suma(float a,float b);

/** \brief resto los 2 numeros
 *
 * \param a float primer numero
 * \param b float segundo numero
 *
 */

float resta(float a,float b);

/** \brief multiplico los 2 numeros
 *
 * \param a float primer numero
 * \param b float segundo numero
 * \return float
 *
 */

float multiplicacion(float a,float b);

/** \brief division y no se puede dividir por cero
 *
 * \param a float primer numero dividendo
 * \param b float segundo numero divisor
 * \return float
 *
 */

float division(float a,float b);


/** \brief saco el factor 0 y positivo
 *
 * \param a int numero a factorear
 * \return int
 *
 */
int factorial(int a);

#endif // FUNCIONES_H_INCLUDED
