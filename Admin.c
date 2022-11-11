#include <stdio.h>
#include <string.h>
#include "Admin.h"

int ComprobarAdmin(char usuario[20], char contrasena[20])
{
    int flag = 0;
    if ((strcmpi(usuario, "admin") == 0) && (strcmpi(contrasena, "admin") == 0))
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
    printf("\nIngrese su password\n");
    fflush(stdin);
    scanf("%s", &Contrasena);
    int id = buscarNodoClientePorDNI(Arbol, DNI);
    return id;
}

void menuAdministrador(arbolClientes *arbol)
{
    char user[20];
    char password[20];
    char seguir = 's';
    printf("Bienvenido al bug.\n");
    printf("Ingrese el nombre de usuario.\n");
    fflush(stdin);
    gets(user);
    printf("Ingrese su password.\n");
    fflush(stdin);
    gets(password);
    while (seguir == 's')
    {
        if (ComprobarAdmin(user, password) == 1)
        {
            funcionesAdministrador(arbol);
            seguir = 'n';
        }
        else
        {
            printf("Los datos ingresados son incorrectos.\n");
            printf("Ingrese el nombre de usuario.\n");
            fflush(stdin);
            gets(user);
            printf("Ingrese su password.\n");
            fflush(stdin);
            gets(password);
            seguir = confirmacionBucle();
        }
    }
}

void funcionesAdministrador(arbolClientes *arbol)
{
    int flag = 0;
    int opcion;
    int cable;
    int internet;
    int idCliente;
    arbolClientes *buscado;
    printf("Bienvenido Administrador.\n");
    do
    {
        printf("Ingrese la opcion que desea realizar.\n");
        printf("1. Mostrar clientes.\n");
        printf("2. Buscar cliente: \n");
        printf("3. Modificar precios.\n");
        printf("4. Finalizar sesion.\n");
        scanf("%i", &opcion);
        switch (opcion)
        {
        case 1:
            mostrarArbol(arbol);
            system("pause");
            system("cls");
            break;
        case 2:
            idCliente = solicitarIdCliente();
            buscado = buscarNodoCliente(arbol, idCliente);
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
            cable = ModificarServicioCable();
            system("cls");
            system("pause");
            internet = ModificarServicioInternet();
            break;
        default:
            printf("\nHasta luego\n");
            break;
        }
    } while (opcion != 4);
}
