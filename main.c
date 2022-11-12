#include <stdlib.h>
#include <stdio.h>
#include "Menu.h"
#include <time.h>

int main()
{

    arbolClientes *arbol = inicArbol();
    // generarArchivoRandom("Clientes.bin");
    arbol = archivoTOADL(arbol, "Clientes.bin");
    arbol = Menu(arbol);
    mostrarArbol(arbol);

    return 0;
}