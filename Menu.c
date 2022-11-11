#include <string.h>
#include "Menu.h"
arbolClientes *Menu(arbolClientes *arbolPrincipal)
{
    int numerillo = 1;
    int opcion = 1;
    char seguir = 's';
    int flag;
    arbolClientes *Cliente = inicArbol();
    do
    {
        {
            printf("\nSeleccione 1 para ingresar a panel de usuario\nPrecione 2 para ingresar como administrador (Solo personal autorizado)\nPrecione 3 para crear un nuevo usuario\n");
            scanf("%i", &opcion);
            system("cls");
        }

        int ID = -1;
        switch (opcion)
        {
        case 1:
            flag = 0;
            while (flag == 0)
            {
                ID = LoginDeUsuario(arbolPrincipal);
                if (ID != -1)
                {
                    flag = 1;
                }
            }
            Cliente = buscarNodoCliente(arbolPrincipal, ID);
            int opcionCliente = 1;
            while (opcionCliente > 0 && opcionCliente < 5)
            {
                printf("\nSeleccione 1_Para ver sus datos\nSeleccione 2_Para ver las facturas\nSeleccione 3_Para modificar datos personales\nSeleccione 4_Para dar la baja de los servicios\n");
                scanf("%i", &opcionCliente);
                /// FUNCION LOGIN DE USUARIO

                switch (opcionCliente)
                {
                case 1:
                    mostrarDatosdeClienteXID(ID, arbolPrincipal);
                    break;
                case 2:
                    // MostrarTodasLasFacturasDeUnCliente(Cliente->Factura);
                    break;
                case 3:
                    Cliente = modificarDatosPersonalesCliente(Cliente);
                    break;
                case 4:
                    DarmeLaBaja(Cliente->Cliente);
                    /// Funcion eliminar nodo.
                    arbolPrincipal = borrarCliente(arbolPrincipal, Cliente);
                    break;
                default:
                    printf("\nSelecciono una opcion invalida\n");
                    break;

                    printf("\nPresione 0 para salir o 1 para volver al menu\n");
                    scanf("%i", &opcionCliente);
                }
            }
        case 2:
            printf("\nUn gusto verlo nuevamente, ingrese los datos personales solicitados\n");
            menuAdministrador(arbolPrincipal);
            printf("\n Desea reliazar otra accion? presione 1 para seguir u otro numero para volver al menu principal \n");
            break;
        case 3:
            printf("\nBienvenido, te deseamos que tengas la mejor experiencia con nuestro servicios, a continuacion se te ofrecera servicios y planes para que puedas solicitar el que desee, al finalizar se le solocitara sus datos personales para poder realizar la instalacion de los servicios\n");
            STCliente nuevoCliente = CargarUnCliente();
            arbolClientes *Nuevo = crearNodoArbol(nuevoCliente);
            persistirNuevoNodo(Nuevo, "Clientes.bin");
            arbolPrincipal = agregarNodoArbol(arbolPrincipal, Nuevo);
            break;
        default:
            printf("\nOpcion invalida\n");
            seguir = confirmacionBucle();
            numerillo = 1;
            break;
        }
        system("cls");
        printf("\nDesea salir del prigrama 0 para salir 1 para volver al menu\n");
        scanf("%i", &numerillo);
    } while (numerillo = 1);
    return arbolPrincipal;
}
