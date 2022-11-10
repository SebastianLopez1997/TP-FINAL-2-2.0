#include <stdio.h>
#include <string.h>
#include "Admin.h"

int ComprobarAdmin(char usuario[20], char contrasena[20])
{
    int flag = 0;
    if ((strcmpi(usuario, "Administrador") == 0) && (strcmpi(contrasena, "Administrador") == 0))
    {
        flag = 1;
    }
    return flag;
}

int ComprobarUsuario(arbolClientes *arbol, char usuario[20], char contrasena[20])
{
    int flag = 0;
    if ((strcmpi(usuario, arbol->Cliente.Login.id) == 0) && (strcmpi(contrasena, arbol->Cliente.Login.pass) == 0))
    {
        flag = 1;
    }
    else
    {
        printf("\nDatos ingresador incorrectos\n");
    }
    return flag;
}

int LoginDeUsuario(arbolClientes *Arbol)
{
    char DNI[10];
    char Contrasena[10];
    printf("\nIngrese su DNI\n");
    fflush(stdin);
    scanf("%s", &DNI);
    printf("\nIngrese Su contraseña\n");
    fflush(stdin);
    scanf("%s", &Contrasena);
    int id = buscarNodoClientePorDNI(Arbol,DNI);
    return id;
}

void menuAdministrador(arbolClientes *arbol)
{
    char user[20];
    char password[20];
    char seguir = 's';

    while (seguir == 's')
    {
        printf("Bienvenido.\n");
        printf("Ingrese el nombre de usuario.\n");
        gets(user);
        printf("Ingrese la contraseña.\n");
        gets(password);
        if (ComprobarAdmin(user, password) == 1)
        {
            funcionesAdministrador(arbol);
        }
        else
        {
            printf("Los datos ingresados son incorrectos.\n");
            seguir = confirmacionBucle();
        }
    }
}

void funcionesAdministrador(arbolClientes *arbol)
{
    char seguir = 's';
    int opcion;
    int idCliente;
    printf("Bienvenido Administrador.\n");
    while (seguir == 's')
    {
        printf("Ingrese la opcion que desea realizar.\n");
        printf("1. Mostrar clientes.\n");
        printf("2. Buscar cliente.\n");
        printf("3. Finalizar sesion.\n");
        scanf("%i", opcion);
    }
    switch (opcion)
    {
    case 1:

        /// Llamada a la función despersistirRegistros en Arboles de listas.
        /// Llamada a la función mostrar Arbol.
        break;
    case 2:
        idCliente = solicitarIdCliente();
        arbolClientes *buscado = buscarNodoCliente(arbol, idCliente);
        {
            if (buscado)
            {
                mostrarNodoArbol(buscado);
                MostrarTodasLasFacturasDeUnCliente(arbol->Factura);
            }
            else
            {
                printf("\nCliente no encontrado.\n");
            }
        }
        break;
    case 3:

        break;
    }
}
