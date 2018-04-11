#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
/** \brief Suma de dos variables
 *
 * \param recibe una variable
 * \param recibe otra variable
 * \return la suma de las dos variables
 *
 */

int Suma(int x , int y)
{
    int suma;

    return suma = x + y;
}
/** \brief Resta de dos variables
 *
 * \param recibe una variable
 * \param recibe otra variable
 * \return la resta de las dos variables
 *
 */
int Resta(int x , int y)
{
    int resta;
    return resta = x - y;
}
/** \brief division de  dos variables
 *
 * \param recibe una variable
 * \param recibe otra variable
 * \return la division de las dos variables
 *
 */
float Division(int x , int y)
{
    float division;
    if(y != 0)
    {
        division =(float)  x / y;
    }
    else
    {
     printf("Error no es divisible por 0.Reingresar  el segundo numero\n\a");
    }
 return division;
}
/** \brief Mltiplicacion de dos variables
 *
 * \param Recibe una variable
 * \param Recibe otra variable
 * \return La multiplicacion de las dos variables
 *
 */
int Multiplicacion(int x, int y)
{
    int multiplicacion;
 return multiplicacion = x * y;

}
/** \brief Factorial de una variable
 *
 * \param recibe una variable
 * \return El factorial de la variable
 *
 */
int Factorial(int x)
{

    if(x<1)
    {
        return 0;
    }
    else if(x>1)
    {
        return x*Factorial(x-1);
    }
    else
    {
        return 1;
    }
}
