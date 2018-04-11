#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"


int main()

  {

    char seguir='s';
    int opcion=0;
    float numeroUno , numeroDos , resultado;
    int elResultado;
    int flagOp1=0;
    int flagOp2=0;

do
 {

if(flagOp1==0)
        {
            printf("\nUsted debe ingresar los valores con los que desea trabajar!!\n\n");
            printf("\nIngrese un primer numero: ");
            scanf("%f", &numeroUno);
            flagOp1=1;
        }

if(flagOp2==0)
        {
            printf("\nIngrese un segundo numero: ");
            scanf("%f", &numeroDos);
            flagOp2=1;
            printf("\n\nCarga efectuada con exito!!\n\n");
            system("pause");
        }

     system("cls");
     system("COLOUR E4");
     printf("\n\n        *******BIENVENIDO*******\n");
     printf("\n      Indique una opcion del menu  \n\n");

     printf(" 1-    Ingresar 1er operando (VALORES INGRESADOS A=%.2f)\n",numeroUno);
     printf(" 2-    Ingresar 2do operando (VALORES INGRESADOS B=%.2f)\n",numeroDos);
     printf(" 3-    Calcular la suma (A+B)\n");
     printf(" 4-    Calcular la resta (A-B)\n");
     printf(" 5-    Calcular la division (A/B)\n");
     printf(" 6-    Calcular la multiplicacion (A*B)\n");
     printf(" 7-    Calcular el factorial (A!)\n");
     printf(" 8-    Calcular todas las operacione\n");
     printf(" 9-    Salir");
     printf("\n\n");

            scanf("%d",&opcion);

switch(opcion)
{

      case 1:
             printf("\nIngrese un primer numero: ");
             fflush(stdin);
             scanf("%f", &numeroUno);
             break;

      case 2:
             printf("\nIngrese un segundo numero: ");
             fflush(stdin);
             scanf("%f", &numeroDos);
             break;

      case 3:
             resultado = laSuma(numeroUno,numeroDos); //LLAMADA
             printf("\nEl resultado de la suma es: %.2f\n\n",resultado);
             break;

      case 4:
             resultado = laResta(numeroUno , numeroDos);
             printf("\nEl resultado de la resta es: %.2f\n\n",resultado);
             break;

      case 5:
             resultado = (float)laDivision(numeroUno , numeroDos);

             if(numeroDos!=0)
                {
                printf("\nEl resultado de la division es: %.2f\n\n",resultado);
                }
             else
                {
                printf("\nERROR... no se puede dividir con cero!!\n\n",resultado);
                }
             break;


      case 6:
             resultado = laMultiplicacion(numeroUno , numeroDos);
             printf("\nEl resultado de la multiplicacion es: %.2f\n\n",resultado);
             break;

      case 7:
             elResultado = elfactorial(numeroUno);
             printf("\nEl resultado del factorial es: %d\n\n",elResultado);
             break;

      case 8:
             resultado = laSuma(numeroUno,numeroDos);
             printf("\nEl resultado de la suma es: %.2f\n\n",resultado);

             resultado = laResta(numeroUno , numeroDos);
             printf("\nEl resultado de la resta es: %.2f\n\n",resultado);

             resultado = (float)laDivision(numeroUno , numeroDos);

             if(numeroDos!=0)
                {
                printf("\nEl resultado de la division es: %.2f\n\n",resultado);
                }
             else
                {
                printf("\nERROR... no se puede dividir con cero!!!\n\n",resultado);
                }

             resultado = laMultiplicacion(numeroUno , numeroDos);
             printf("\nEl resultado de la multiplicacion es: %.2f\n\n",resultado);

             elResultado = elfactorial(numeroUno);
             printf("\nEl resultado del factorial es: %d\n\n",elResultado);
             break;

       case 9:
              seguir ='n';
              break;
 }
             printf("\nDesea seguir? s/n: ");
             seguir=getche();
             seguir=tolower(seguir);
             system("pause");

 }while(seguir=='s');

   return 0;

 }
