#include <stdio.h>
#include <stdlib.h>
#include "Clientes.h"
#include <time.h>
char confirmacionBucle()
{
    char seguir;
    printf("Presione 's' para continuar.\n");
    fflush(stdin);
    scanf("%c", &seguir);
    return seguir;
}

int solicitarIdCliente()
{
    int idCliente; /// SOLICITAR ID CLIENTE
    printf("\nIngrese ID de cliente a buscar: ");
    scanf("%d", &idCliente);
    return idCliente;
}
/// ESTO ES PARA VER EL ARCHIVO SIN NECESIDAD DE PASARLO AL ARBOL (SOLO DESCOMENTAR PARA TESTEAR) debugger
/*STRegistroCliente a;
FILE * fp=fopen("Clientes.bin", "rb");
if(fp){
    while(fread(&a, sizeof(STRegistroCliente), 1, fp)>0){
        printf("Barrio: %s \n", a.Barrio);
    }
}*/
void CrearFechaActual()
{
    // Tiempo actual
    time_t t = time(NULL);
    struct tm tiempoLocal = *localtime(&t);
    // El lugar en donde se pondrá la fecha y hora formateadas
    char fechaHora[70];
    // El formato.
    char *formato = "%Y-%m-01";
    // Intentar formatear
    int bytesEscritos =
        strftime(fechaHora, sizeof fechaHora, formato, &tiempoLocal);
    if (bytesEscritos != 0)
    {
        // Si no hay error, los bytesEscritos no son 0
        printf("Fecha y hora: %s", fechaHora);
    }
    else
    {
        printf("Error formateando fecha");
    }
}
