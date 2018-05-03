#include <stdio.h>
#include <stdlib.h>
//BIBLIOTECAS
#include <string.h>
#include "fraga.h"
#define CANTIDAD_PERSONAS 20
///*****************************************************************************
int main()
{
    int opcion;
    char seguir='s';

    ePersona vecPersona[CANTIDAD_PERSONAS];
    ePersona auxVecPersona[CANTIDAD_PERSONAS];

    inicVec(vecPersona,auxVecPersona, CANTIDAD_PERSONAS);

    do
    {
        fflush(stdin);
        system("cls");
        printf("\t\tTrabajo Practico N2.\n\n");
        printf("\nIndique una opcion\n\n");
        printf("1-- Agregar una persona\n");
        printf("2-- Borrar una persona\n");
        printf("3-- Imprimir lista ordenada por nombre\n");
        printf("4-- Imprimir grafico de edades\n");
        printf("\n5-- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        printf("\n");


        while(!validarRangoInt(opcion,1,5))
            {
                printf("\n¡¡¡ ERROR !!! Reingrese opcion, entre 1 y 5: ");
                scanf("%d", &opcion);
            }

        switch(opcion)
        {
            case 1:
                    cargarVecPersona(vecPersona, CANTIDAD_PERSONAS);
                    fflush(stdin);
                    break;
            case 2:
                    eliminarVecPersona(vecPersona,CANTIDAD_PERSONAS);
                    fflush(stdin);
                    break;
            case 3:
                    listarVecPersona(vecPersona, CANTIDAD_PERSONAS, 1);
                    fflush(stdin);
                    break;
            case 4:
                    graficoEdades(vecPersona,CANTIDAD_PERSONAS);
                    fflush(stdin);
                    break;
            case 5:
                    seguir='n';
                    break;
        }

    }while(seguir!='n');

return 0;
}
