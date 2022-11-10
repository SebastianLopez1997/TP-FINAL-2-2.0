#include <stdlib.h>
#include <stdio.h>
#include "arbolClientes.h"

int main(){
    arbolClientes * arbol=inicArbol();
    generarArchivoRandom("Clientes.bin");
    archivoTOADL(arbol, "Clientes.bin");
    //mostrarArbol(arbol);
    return 0;
}