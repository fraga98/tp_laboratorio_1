#include "funciones.h"
/**
 * \brief Se realisa la sumas de las variables x e y
 * \param x Variable ingresada a ser sumada
 * \param y Variable ingresada a ser sumada
 * \return Devuelve la suma de x e y como flotante
 *
 */
float laSuma(float x , float y)
{
    float resultado;

    resultado = x + y;

    return resultado;

}
/**
 * \brief Se realisa la resta de las variables x e y
 * \param x Variable ingresada a ser restada
 * \param y Variable ingresada a ser restada
 * \return Devuelve la resta de x e y como flotante
 *
 */
float laResta(float x , float y)
{
    float result;

    result = x - y;

    return result;

}
/**
 * \brief Se realisa la division de las variables x e y
 * \param x Variable ingresada a ser dividida
 * \param y Variable ingresada a ser dividida
 * \return Devuelve la division de x e y como flotante
 *
 */
float laDivision(float x , float y)
{

    float result;

    result =(float) x / y;

    return result;
}
/**
 * \brief Se realisa la multiplicacion de las variables x e y
 * \param x Variable ingresada a ser multiplicada
 * \param y Variable ingresada a ser multiplicada
 * \return Devuelve la multiplicacion de x e y como flotante
 *
 */
float laMultiplicacion(float x , float y)
{
   float result;

   result = x * y;

   return result;
}
/** \brief  Realiza el factoreo de la variable x
 *
 * \param x es la variable a ser factoreada
 * \return  devuelve el factorial entero de x como resultado
 *
 */
int elfactorial(int x)
{
int the_result;
if(x==0)
{
    return 1;
}
else
{
the_result = x * elfactorial(x-1);
return the_result;
}
}


