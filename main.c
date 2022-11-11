#include <stdlib.h>
#include <stdio.h>
#include "Menu.h"

int main()
{
    arbolClientes *arbol = inicArbol();
    generarArchivoRandom("Clientes.bin");
    STRegistroCliente a;
    FILE * fp=fopen("Clientes.bin", "rb");
    if(fp){
        while(fread(&a, sizeof(STRegistroCliente), 1, fp)>0){
            printf("Barrio: %s \n", a.Barrio);
        }
    }
    /*arbol = archivoTOADL(arbol, "Clientes.bin");
    arbol = Menu(arbol);
    mostrarArbol(arbol);
    printf("FINAL");*/
    return 0;
}
