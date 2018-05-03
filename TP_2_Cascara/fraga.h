
typedef struct
{
    char nombre[50];
    int edad;
    int dni;
    int flagEstado;

}ePersona;


int validarPositivo(int x);
int validarRangoInt(int x, int inf, int sup);

void inicVec(ePersona vecPersona[], ePersona auxVecPersona[], int cantPersonas);
void cargarVecPersona(ePersona vecPersona[], int cantPersonas);
void eliminarVecPersona(ePersona vecPersona[], int cantPersonas);
void listarVecPersona(ePersona vecPersona[], int cantPersonas, int criterio);
void graficoEdades(ePersona vecPersona[],int cantPersonas);

