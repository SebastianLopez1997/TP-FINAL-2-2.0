#include <string.h>
#include "Menu.h"
arbolClientes * Menu(arbolClientes *arbolPrincipal)
{
    int opcion = 1;
    char seguir = 's';
    int flag;
    arbolClientes *Cliente = inicArbol();

    while (opcion != 1 || opcion != 2 || opcion != 3)
    {
        {
            printf("Seleccione 1 para ingresar a panel de usuario\nPrecione 2 para ingresar como administrador (Solo personal autorizado)\nPrecione 3 para crear un nuevo usuario");
            scanf("%i", &opcion);
        }
    }

    while (seguir == 's')
    {
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
                printf("Seleccione 1_Para ver sus datos\nSeleccione 2_Para ver las facturas\nSeleccione 3_Para modificar datos personales\nSeleccione 4_Para dar la baja de los servicios");
                scanf("%i", &opcionCliente);
                /// FUNCION LOGIN DE USUARIO

                switch (opcionCliente)
                {
                case 1:
                    mostrarDatosdeClienteXID(ID, arbolPrincipal);
                    break;
                case 2:
                    MostrarTodasLasFacturasDeUnCliente(Cliente->Factura);
                    break;
                case 3:
                    Cliente = modificarDatosPersonalesCliente(Cliente);
                    break;
                case 4:
                    DarmeLaBaja(Cliente->Cliente);
                    break;
                default:
                    printf("\nSelecciono una opcion invalida\n");
                    break;

                    printf("Presione 0 para salir o 1 para volver al menu");
                    scanf("%i", &opcionCliente);
                }
            }
        case 2:
            printf("Un gusto verlo nuevamente, ingrese los datos personales solicitados");
            menuAdministrador(arbolPrincipal);
            generarArchivoRandom("Clientes.bin");
            archivoTOADL(arbolPrincipal, "Clientes.bin");
            break;
        case 3:
            printf("Bienvenido, te deseamos que tengas la mejor experiencia con nuestro servicios, a continuacion se te ofrecera servicios y planes para que puedas solicitar el que desee, al finalizar se le solocitara sus datos personales para poder realizar la instalacion de los servicios");
            STCliente nuevoCliente = CargarUnCliente();
            arbolClientes *Nuevo = crearNodoArbol(nuevoCliente);
            arbolPrincipal = agregarNodoArbol(arbolPrincipal, Nuevo);
            break;
        default:
            printf("\nOpcion invalida\n");
            seguir = confirmacionBucle();
            break;
        }
    }
    return arbolPrincipal;
}
