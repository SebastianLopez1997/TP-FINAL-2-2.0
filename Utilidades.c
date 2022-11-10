#include <stdio.h>
#include <stdlib.h>
#include "Clientes.h"

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
    printf("\nIngrese ID de cliente a buscar");
    scanf("%d", idCliente);
    return idCliente;
}
