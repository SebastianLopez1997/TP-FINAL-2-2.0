#include <stdlib.h>
#include <stdio.h>
#include "Menu.h"

int main()
{
    arbolClientes *arbol = inicArbol();
    arbol = Menu(arbol);
    /// generarArchivoRandom("Clientes.bin");
    /// archivoTOADL(arbol, "Clientes.bin");
    mostrarArbol(arbol);

    return 0;
}
