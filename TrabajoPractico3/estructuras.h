#ifndef ESTRUCTURAS
#define ESTRUCTURAS

//Estructuras

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[150];
    int estado; //[0]=No hay data cargada /[1]=Hay datos cargados.
}sMovie;

#endif
