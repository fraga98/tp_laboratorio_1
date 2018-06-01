#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include "utilesV2.h"

#define SLEEP_TIME 1400

/** \brief Pregunta al usuario si desea continuar.
 *
 * \return (int) [0]=Usuario eligio NO CONTINUAR / [1]=Usuario eligió CONTINUAR.
 *
 */
int preguntarDeseaContinuar()
{
    char respuesta; //Respuesta que ingresa el usuario
    int contador = 0;


    do{
        if(contador==0)
        {
            printf("Desea continuar? (s/n)");
        }
        else
        {
            printf("ERROR! Desea continuar? (s/n) ");
        }
        fflush(stdin);
        scanf("%c", &respuesta);
        respuesta=tolower(respuesta);
        contador++;
    }while( respuesta!='s' && respuesta!='n');

    switch(respuesta)
    {
        case 's':
            return 1;
            break;
        case 'n':
            return 0;
            break;
    }
    return 0;
}


/** \brief Valida si una variable float es tiene o no decimal.
 *
 * \param numero (float) Número a analizar.
 *
 * \return (int) [1]=El número NO TIENE decimales / [0]=El número TIENE decimales [0].
 *
 */
int esEntero(float numero)
{
    float auxiliar;
    auxiliar = numero - (int)numero;
    if(auxiliar == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/** \brief Analiza una cádena de caracteres y nos dice si dicha cádena es exactamente igual a "0".
 *
 * \param cadena (char[]) Cádena a analizar.
 *
 * \return (int) [0]=NO es una cadena de la forma "0" / [1]=La cadena es igual a "0".
 *
 */
int esStringCero(char* cadena)
{
    if(cadena[0]=='0' && cadena[1]=='\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/** \brief Imprime un menú y pide el ingreso de opción la cantidad de veces indicada.
 *
 * \param menu (char[]) Opciones del menú, separadas por '\n', no debe pasarse el mensaje que pide el ingreso de la opción.
 * \param opcionMin (int) Opción mínima del menú.
 * \param opcionMax (int) Opción máxima del menú.
 * \param cantidadPreguntas (int) Cantidad de veces que se le va a preguntar a la persona en caso de fallo.
 * \param mensajeError (char[]) Mensaje mostrado en caso de ingresar una opción inválida.
 * \return (int) Opción seleccionada por la persona, si ingreso una opción inválida en todos los intentos retorna [-1].
 *
 */
int buildMenu(char menu[], int opcionMin, int opcionMax, int cantidadPreguntas, char mensajeError[])
{
    int respuesta; //Almacenamiento de la respuesta obtenida.
    short int error; //Almacenamiento del error retornado para hacer validaciones.
    int contadorIntentos=0; //Cuenta intentos.

    do //Bucle que controla la cantidad de veces que se pide el ingreso.
    {
        system("cls");
        printf("%s", menu);
        printf("\n\nIngrese la opci""\xE0""n deseada: ");
        fflush(stdin);
        error = getInt(&respuesta, "", 1, 1, opcionMin, opcionMax, mensajeError, 1);

        if( error != -1)
        {
            return respuesta;
            break;
        }

        contadorIntentos++;
    }while( contadorIntentos < cantidadPreguntas );

    return -1;
}


/** \brief Muestra un mensaje, lee una entrada por teclado, valida que sea entero y que no sobrepase los límites dados.
 *
 * \param miEntero (int*) Dirección donde se almacena el entero, solo en caso de ingreso exitoso.
 * \param mensaje (char[]) Mensaje mostrado al usuario cuando se pide el ingreso.
 * \param tieneMinimo (short int) Si NO tiene mínimo debe pasarse [0], si tiene mínimo debe pasarse [1].
 * \param tieneMaximo ( short int) Si NO tiene máximo debe pasarse [0], si tiene máximo debe pasarse [1].
 * \param minimo (int) Límite inferior INCLUSIVO, en caso de no tenerlo se debe pasar [0].
 * \param maximo (int) Límite superior INCLUSIVO, en caso de no tenerlo se debe pasar [0].
 * \param msjError (char[]) Mensaje mostrado al usuario en caso de ingreso incorrecto.
 *
 * \return (short int) [0]=Ingreso exitoso / [-1]=Ingreso no validado.
 *
 */
short int getInt(int* miEntero, char mensaje[], short int tieneMinimo, short int tieneMaximo, int minimo, int maximo, char msjError[], int intentos)
{
    short int retorno = -1;
    int contadorIntentos = 0;
    char buffer[601]; //Buffer para lectura de la entrada por teclado del usuario.
    int aux; //Auxiliar utilizado para analizar maximos y minimos sin asignar.
    short int verificaMaxYMin;

    do
    {
        printf("%s", mensaje);
        fflush(stdin);
        gets(buffer); //Se lee el ingreso del usuario.

        if(!esStringCero(buffer)) //Si el usuario NO ingresó "0" se usa atoi (ya que atoi retorna [0] como código de error y no se puede diferenciar error del ingreso de "0").
        {
            aux = atoi(buffer);
            if(aux != 0) //Si no es error se chequean maximos y minimos, etc.
            {
                verificaMaxYMin = verificarMaxYMinEntero(&aux, &tieneMinimo, &tieneMaximo, &minimo, &maximo);
                if(verificaMaxYMin)
                {
                    *miEntero = aux;
                    retorno = 0;
                    break;
                }
                else
                {
                    printf("\n%s\n", msjError);
                    Sleep(SLEEP_TIME);
                    system("cls");
                }
            }
            else //Si 'aux' es igual a [0] significa que hay error (porque ya se validó que sea !=0).
            {
                system("cls");
                printf("\n%s\n", msjError);
                Sleep(SLEEP_TIME);
                system("cls");
            }
        }
        else //Si el usuario ingreso "0".
        {
            //Se verifica Maximos y Minimos.
            aux = 0;
            verificaMaxYMin = verificarMaxYMinEntero(&aux, &tieneMinimo, &tieneMaximo, &minimo, &maximo);
                if(verificaMaxYMin)
                {
                    *miEntero = aux;
                    retorno = 0;
                    break;
                }
                else
                {
                    system("cls");
                    printf("\n%s\n", msjError);
                    Sleep(SLEEP_TIME);
                    system("cls");
                }
        }

        contadorIntentos++;

    }while( contadorIntentos < intentos );

    return retorno;
}


/** \brief (Función de uso interno de "getInt") Verifica que un número se encuentre entre el minimo y el máximo dado.
 *
 * \param numero (int*) Numero a evaluar.
 * \param tieneMinimo (short int*) [0]=No tiene minimo [1]=Tiene minimo.
 * \param tieneMaximo (short int*) [0]=No tiene máximo [1]=Tiene máximo.
 * \param minimo (int) Minimo a evaluar.
 * \param maximo (int) Máximo a evaluar.
 *
 * \return (short int) [0]=No cumple con los límites / [1]=Cumple con los límites.
 *
 */
short int verificarMaxYMinEntero(int* numero, short int* tieneMinimo, short int* tieneMaximo, int* minimo, int* maximo)
{
    //Si NO tiene minimo NI máximo.
    if(!*tieneMinimo && !*tieneMaximo)
    {
        return 1;
    }

    //Si tiene minimo y tiene maximo.
    else if(*tieneMinimo && *tieneMaximo)
    {
        if(*numero >= *minimo && *numero <= *maximo)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    //Si tiene minimo y NO tiene maximo.
    else if(*tieneMinimo && !*tieneMaximo)
    {
        if(*numero >= *minimo)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    //Si NO tiene minimo y tiene maximo.
    else if(!*tieneMinimo && *tieneMaximo)
    {
        if(*numero <= *maximo)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}




/** \brief Muestra un mensaje, lee una entrada por teclado, valida que sea float y que no sobrepase los límites dados.
 *
 * \param miFloat (float*) Dirección donde se almacena el float, solo en caso de ingreso exitoso.
 * \param mensaje (char[]) Mensaje mostrado al usuario cuando se pide el ingreso.
 * \param tieneMinimo (short int) Si NO tiene mínimo debe pasarse [0], si tiene mínimo debe pasarse [1].
 * \param tieneMaximo ( short int) Si NO tiene máximo debe pasarse [0], si tiene máximo debe pasarse [1].
 * \param minimo (float) Límite inferior INCLUSIVO, en caso de no tenerlo se debe pasar [0].
 * \param maximo (float) Límite superior INCLUSIVO, en caso de no tenerlo se debe pasar [0].
 * \param msjError (char[]) Mensaje mostrado al usuario en caso de ingreso incorrecto.
 *
 * \return (short int) [0]=Ingreso exitoso / [-1]=Ingreso no validado.
 *
 */

short int getFloat(float* miFloat, char mensaje[], short int tieneMinimo, short int tieneMaximo, float minimo, float maximo, char msjError[])
{
    char buffer[601]; //Buffer para lectura de la entrada por teclado del usuario.
    float aux; //Auxiliar utilizado para analizar maximos y minimos sin asignar.
    short int verificaMaxYMin;

    printf("%s", mensaje);
    fflush(stdin);
    gets(buffer); //Se lee el ingreso del usuario.

    if(!esStringCero(buffer)) //Si el usuario NO ingresó "0" se usa atoi (ya que atoi retorna [0] como código de error y no se puede diferenciar error del ingreso de "0").
    {
        aux = atof(buffer);
        if(aux == 0) //Si 'aux' es igual a [0] significa que hay error (porque ya se validó que sea !=0).
        {
            system("cls");
            printf("%s\n", msjError);
            Sleep(SLEEP_TIME);
            return -1;
        }
        else //Si no es error se chequean maximos y minimos, etc.
        {
            verificaMaxYMin = verificarMaxYMinFloat(&aux, &tieneMinimo, &tieneMaximo, &minimo, &maximo);
            if(verificaMaxYMin)
            {
                *miFloat = aux;
                return 0;
            }
            else
            {
                system("cls");
                printf("%s\n", msjError);
                Sleep(SLEEP_TIME);
                return -1;
            }
        }
    }
    else //Si el usuario ingreso "0".
    {
        //Se verifica Maximos y Minimos.
        aux = 0;
        verificaMaxYMin = verificarMaxYMinFloat(&aux, &tieneMinimo, &tieneMaximo, &minimo, &maximo);
            if(verificaMaxYMin)
            {
                *miFloat = aux;
                return 0;
            }
            else
            {
                system("cls");
                printf("%s\n", msjError);
                Sleep(SLEEP_TIME);
                return -1;
            }
    }
    return -1;
}


/** \brief (Función de uso interno de "getFloat") Verifica que un número se encuentre entre el minimo y el máximo dado.
 *
 * \param numero (float*) Numero a evaluar.
 * \param tieneMinimo (short int*) [0]=No tiene minimo [1]=Tiene minimo.
 * \param tieneMaximo (short int*) [0]=No tiene máximo [1]=Tiene máximo.
 * \param minimo (float) Minimo a evaluar.
 * \param maximo (float) Máximo a evaluar.
 *
 * \return (short int) [0]=No cumple con los límites / [1]=Cumple con los límites.
 *
 */
short int verificarMaxYMinFloat(float* numero, short int* tieneMinimo, short int* tieneMaximo, float* minimo, float* maximo)
{
    //Si NO tiene minimo NI máximo.
    if(!*tieneMinimo && !*tieneMaximo)
    {
        return 1;
    }

    //Si tiene minimo y tiene maximo.
    else if(*tieneMinimo && *tieneMaximo)
    {
        if(*numero >= *minimo && *numero <= *maximo)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    //Si tiene minimo y NO tiene maximo.
    else if(*tieneMinimo && !*tieneMaximo)
    {
        if(*numero >= *minimo)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    //Si NO tiene minimo y tiene maximo.
    else if(!*tieneMinimo && *tieneMaximo)
    {
        if(*numero <= *maximo)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}



/** \brief Muestra un mensaje, lee una entrada por teclado, valida que sea string del largo permitido y en caso de error muestra un mensaje.
 *
 * \param miCadena (char[]) Cadena de caracteres donde voy a almacenar el ingreso en caso exitoso.
 * \param largoMiCadena (int) Largo de 'miCadena'.
 * \param mensaje (char[]) Mensaje que se muestra al usuario al pedir el ingreso.
 * \param msjError (char[]) Mensaje mostrado al usuario en caso de ingreso erroneo.
 * \return [0]=Se obtubo exitosamente el string / [-1]=Error al obtener el string.
 *
 */
short int getString(char *miCadena, int largoMiCadena, char *mensaje, char *msjError)
{
    char buffer[601];
    int largoAux;
    printf("%s", mensaje);
    fflush(stdin);

    gets(buffer);

    largoAux = strlen(buffer);

    if( largoAux >= largoMiCadena || largoAux <= 0)
    {
        system("cls");
        printf("%s", msjError);
        Sleep(SLEEP_TIME);
        return -1;
    }
    else
    {
        strcpy(miCadena, buffer);
        return 0;
    }
}


/** \brief Muestra un mensaje, lee una entrada por teclado, valida que sea string del largo permitido y en caso de error muestra un mensaje.
 *
 * \param miCadena (char[]) Cadena de caracteres donde voy a almacenar el ingreso en caso exitoso.
 * \param largoMiCadena (int) Largo de 'miCadena'.
 * \param mensaje (char[]) Mensaje que se muestra al usuario al pedir el ingreso.
 * \param msjError (char[]) Mensaje mostrado al usuario en caso de ingreso erroneo.
 * \param intentos (int) Cantidad de intentos para pedir el string al usuario.
 * \return [0]=Se obtubo exitosamente el string / [-1]=Error al obtener el string.
 *
 */
short int getStringConIntentos(char* miCadena, int largoMiCadena, char* mensaje, char* msjError, short int intentos)
{
    short int retorno = -1;
    char buffer[601];
    int contadorIntentos = 0;
    int largoLectura;

    if( miCadena!=NULL && intentos>0 && largoMiCadena>0 )
    {
        do{
            printf("%s", mensaje);
            fflush(stdin);

            gets(buffer);

            largoLectura = strlen(buffer);

            if( largoLectura < largoMiCadena && largoLectura > 0)
            {
                strcpy(miCadena, buffer);
                retorno = 0;
                break;
            }
            else
            {
                system("cls");
                printf("%s", msjError);
                Sleep(SLEEP_TIME);
                system("cls");
            }

            contadorIntentos++;

        }while( contadorIntentos < intentos );
    }

    return retorno;
}


/** \brief Normaliza el formato de una cadena de caracteres.
 *
 * \param miCadena (char[]) Cadena de caracteres a normalizar.
 * \param largoMiCadena (int) Largo de 'miCadena'.
 * \param tipoNormalizacion (int)  ['1']=Lleva todo el string a minúsculas.
                                    ['2']=Lleva todo el string a mayúsculas.
                                    ['3']=Primera letra en mayúscula, las demás en minúsculas.
 * \return [0]=Normalización exitosa / [-1]=Error en la normalización.
 *
 */
short int normalizarString(char miCadena[], int largoMiCadena, int tipoNormalizacion)
{
    int i=0;
    int largo;

    largo = strlen(miCadena);

    if( largo > (largoMiCadena-1))
    {
        return -1;
    }
    else
    {
        switch(tipoNormalizacion)
        {
            case 1:
                for( i=0 ; i<(largoMiCadena-1) ; i++ )
                {
                    miCadena[i] = tolower(miCadena[i]);
                }
                return 0;
                break;

            case 2:
                for( i=0 ; i<(largoMiCadena-1) ; i++ )
                {
                    miCadena[i] = toupper(miCadena[i]);
                }
                return 0;
                break;

            case 3:
                for( i=0 ; i<(largoMiCadena-1) ; i++ )
                {
                    if( i == 0 )
                    {
                        miCadena[i] = toupper(miCadena[i]);
                    }
                    else if( miCadena[i] == ' ')
                    {
                        miCadena[(i+1)] = toupper(miCadena[(i+1)]);
                        i++;
                    }
                    else
                    {
                        miCadena[i] = tolower(miCadena[i]);
                    }
                }
                return 0;
                break;

            default:
                return -1;
                break;
        }
    }
}

/** \brief Pregunta algo al usuario donde puede responder por Si o por No.
 *
 * \param mensaje (char[]) Mensaje que se le muestra al usuario al pedir la respuesta.
 * \param msjError (char[]) Mensaje que se le muestra al usuario en caso de respuesta incorrecta.
 *
 * \return (short int) [0]=Usuario eligio NO / [1]=Usuario eligió SI / [-1]=Respuesta incorrecta.
 *
 */
short int preguntarPorSiOPorNo(char* mensaje, char* msjError, int intentos)
{
    short int retorno = -1;
    int contadorIntentos = 0;
    char buffer[601]; //Buffer donde se lee la respuesta.
    short int error; //Almacenamiento de el error retornado.

    if( mensaje!=NULL && intentos>0 )
    do
    {
        //Se pide ingreso de 's' o 'n' al usuario.
        error = getString(buffer, 601, mensaje, msjError);

        if( error == 0 )
        {
            //Se convierte la respuesta a minúsculas para evaluarla.
            normalizarString(buffer, 601, 1);

            //Se analiza la respuesta obtenida.
            if( buffer[1] == '\0' )
            {
                if( buffer[0] == 's' )
                {
                    retorno = 1;
                    break;
                }
                else if( buffer[0] == 'n' )
                {
                    retorno = 0;
                    break;
                }
                else
                {
                    system("cls");
                    printf("%s",msjError);
                    Sleep(SLEEP_TIME);
                    system("cls");
                }
            }
            else
            {
                system("cls");
                printf("%s",msjError);
                Sleep(SLEEP_TIME);
                system("cls");
            }
        }

        contadorIntentos++;

    }while( contadorIntentos < intentos );

    return retorno;
}
