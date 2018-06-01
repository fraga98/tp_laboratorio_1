#include "funciones.h"


int main()
{
    int error;
    int opcion;

    sMovie peliculas[LENGTH];

    initMovies(peliculas, LENGTH);

    error = cargarDesdeArchivo( peliculas, LENGTH );

    switch( error )
    {
        case 0:
            printf("\nSe cargaron las estructuras exitosamente.\n\n");
            break;
        case -1:
            printf("\nNo se pudo abrir el fichero.\n\n");
            break;
        case -2:
            initMovies( peliculas, LENGTH );
            //chargeWithFakeData( peliculas, LENGTH );
            printf("\nNo existe el archivo de datos, se cre""\xA2"" exitosamente.\n\n");
            break;
    }

    system("pause");

    do
    {
        opcion = buildMenu("1)Agregar pel""\xA1""cula\n"
                          "2)Borrar pel""\xA1""cula\n"
                          "3)Modificar pel""\xA1""cula\n"
                          "4)Generar p""\xA0""gina web\n"
                          "5)Salir\n"
                          "6)Imprimir lista peliculas", 1, 6, 3, "Error! Opci""\xA2""n inv""\xA0""lida.");

        switch(opcion)
        {
            case 1:
                agregarPelicula( peliculas, LENGTH );
                break;
            case 2:
                borrarPelicula( peliculas, LENGTH );
                break;
            case 3:
                modificarPelicula( peliculas, LENGTH );
               break;
            case 4:
                generarPagina( peliculas, LENGTH );
                break;
            case 5:
                doExit( peliculas, LENGTH );
                break;
            case 6:
                imprimirListaPeliculas( peliculas, LENGTH );
                break;
        }



    }while( opcion != 5 );

    return 0;
}
