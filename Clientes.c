#include <string.h>
#include "Clientes.h"

/// MODIFICAR CLIENTES
void modificarNombre(char nombre[])
{
    char nom[30];
    printf("Ingrese nombre.\n");
    fflush(stdin);
    gets(nom);
    strcpy(nombre, nom);
}

void modificarApellido(char apellido[])
{
    char ape[30];
    printf("Ingrese el apellido.\n");
    fflush(stdin);
    gets(ape);
    strcpy(apellido, ape);
}

void modificarTelefono(char telefono[])
{
    char tel[20];
    printf("Ingrese el telefono.\n");
    fflush(stdin);
    gets(tel);
    strcpy(telefono, tel);
}

void modificarBarrio(char barrio[])
{
    char ba[20];
    printf("Ingrese el barrio.\n");
    fflush(stdin);
    gets(barrio);
    strcpy(barrio, ba);
}

void modificarCalle(char calle[])
{
    char direccion[20];
    printf("Ingrese la calle.\n");
    fflush(stdin);
    gets(direccion);
    strcpy(calle, direccion);
}

void modificarAltura(char altura[])
{
    char alt[5];
    printf("Ingrese la altura.\n");
    fflush(stdin);
    gets(alt);
    strcpy(altura, alt);
}

void modificarDireccion(char direccion[])
{
    char calle[20];
    char altura[5];
    modificarCalle(calle);
    modificarAltura(altura);
    direccion[25] = strcat(calle, altura);
}

void cambiarPassword(char password[])
{
    char pass[8];
    printf("Ingrese la nueva password.\n");
    fflush(stdin);
    gets(pass);
    strcpy(password, pass);
}

/// === CARGA CLIENTE MANUAL
STCliente CargarUnCliente()
{
    STCliente ClienteNuevo;
    ClienteNuevo.Dato = cargaDatosPersonales();
    ClienteNuevo.Servicio = CargaServicio();

    return ClienteNuevo;
}

STPersonal cargaDatosPersonales()
{
    STPersonal dato;
    printf("Ingrese el DNI.\n");
    fflush(stdin);
    gets(dato.DNI);
    modificarNombre(dato.Nombre);
    modificarApellido(dato.Apellido);
    modificarTelefono(dato.NumeroCel);
    // modificarDomicilio(dato.direccion);
    return dato;
}

STLogin cargaLogin(STPersonal cliente)
{
    STLogin login;
    login.id = cliente.id;
    strcpy(login.pass, cliente.DNI);

    return login;
}

STServicio CargaServicio()
{
    STServicio Servicio;
    int flag = 0;
    int Seleccion = -1;
    printf("\nSeleccione 1- Para contratar el servicio de internet con un costo de $1000\nSeleccione 2- Para contratar el servicio de cable con un costo de $600\nSeleccione 3- Para contratar nuestro combro de internet mas cable con un costo de $1300\nSeleccione 4- Para no contratar ninguno\n");
    Seleccion = -1;
    scanf("%i", &Seleccion);
    while (flag == 0)
    {
        switch (Seleccion)
        {
        case 1:
            printf("\nUsted contrato nuestro servicio de inernet, en breve recibira un llamado telefonico con las instrucciones pertinentes\n");
            Servicio.Internet = 1;
            flag = 1;
            break;
        case 2:
            printf("\nUsted contrato nuestro servicio de cable, en breve recibira un llamado telefonico con las instrucciones pertinentes\n");
            Servicio.Cable = 1;
            flag = 1;
            break;
        case 3:
            printf("\nUsted contrato nuestro combo servicio de inernet mas cable, en breve recibira un llamado telefonico con las instrucciones pertinentes\n");
            Servicio.Internet = 1;
            Servicio.Cable = 1;
            flag = 1;
            break;
        case 4:
            printf("\nSu usuario quedo registrado, cuando guste podra ingresar nuevamente a nuestra pagina y contratar el servicio deseado \n");
            flag = 1;
            break;
        default:
            printf("\nSeleccion invalida\n");
            break;
        }
    }

    return Servicio;
}

int PedidoBin(char corte)
{
    int servicio = 0;
    if (strcmpi(corte, "s") == 0)
    {
        servicio = 1;
    }
    return servicio;
}

STCliente registroToSTCLiente(STRegistroCliente p)
{
    STCliente nuevo;
    nuevo.Login.id = p.id;
    nuevo.Dato.id = p.id;
    strcpy(nuevo.Dato.Nombre, p.Nombre);
    strcpy(nuevo.Dato.Apellido, p.Apellido);
    strcpy(nuevo.Dato.NumeroCel, p.NumeroCel);
    strcpy(nuevo.Login.pass, p.pass);
    strcpy(nuevo.Dato.direccion.Direccion, p.Direccion);
    strcpy(nuevo.Dato.direccion.Barrio, p.Direccion);
    nuevo.Servicio.Cable = p.Cable;
    nuevo.Servicio.Internet = p.Internet;
    strcpy(nuevo.Dato.DNI, p.DNI);
    strcpy(nuevo.Login.pass, p.pass);
    return nuevo;
}

/// ESTABA EN RANDOM.C
STRegistroCliente crearRegistroRand(int id, char archivo[])
{
    STRegistroCliente a;
    a.id = id;
    nombreRandom(a.Nombre);
    apellidoRandom(a.Apellido);
    movilRandom(a.NumeroCel);
    domicilioRandom(a.Direccion);
    barrioRandom(a.Barrio);
    a.Cable = cableRandom();
    a.Internet = internetRandom();
    while (a.Cable == 0 && a.Internet == 0) //Evita tener clientes inactivos.
    {
        a.Cable = cableRandom();
        a.Internet = internetRandom(); // Hay que modificar para que tome el servicio en conjunto y no por separado(cable e internet));
    }
    dniRandom(a.DNI);
    while (funcionComprobarDNI(a.DNI, archivo) == 1)
    {
        dniRandom(a.DNI);
    }

    return a;
}

void generarArchivoRandom(char archivo[], int *i)
{
    FILE *fp = fopen(archivo, "wb");
    STRegistroCliente a;
    if (fp)
    {
        while(*i<5000)
        {
            a = crearRegistroRand(i, archivo);
            fwrite(&a, sizeof(STRegistroCliente), 1, fp);
            (*i)++;
        }
        fclose(fp);
    }
    
}

/// Mostrar CLiente
void MostrarUncliente(STCliente aux)
{
    printf("Nombre: %s\n", aux.Dato.Nombre);
    printf("Apellido: %s\n", aux.Dato.Apellido);
    printf("Direccion: %s\n", aux.Dato.direccion.Direccion);
    printf("DNI: %s\n", aux.Dato.DNI);
    printf("ID: %i\n", aux.Dato.id);
    printf("Numero de contacto: %s\n", aux.Dato.NumeroCel);
    printf("\n--------------------------\n");
}

/// Comprobar estado del cliente
STCliente DarmeLaBaja(STCliente aux)
{
    aux.Servicio.Cable = 0;
    aux.Servicio.Internet = 0;
    printf("\n Usted fue dado de baja \n");
    return aux;
}

int EstadoClienteServicios(STCliente Aux)
{
    int flag = 0;
    if (Aux.Servicio.Cable == 1 || Aux.Servicio.Internet == 1)
    {
        flag = 1;
    }
    return flag;
}
int funcionComprobarDNI(char dni[], char archivo[])
{
    FILE *fp = fopen(archivo, "rb");
    int flag = 0;
    STRegistroCliente a;
    if (fp)
    {
        while (fread(&a, sizeof(STRegistroCliente), 1, fp) > 0 && flag == 0)
        {
            if (strcmpi(a.DNI, dni) == 0)
            {
                flag = 1; /// El dni ya está en uso.
                system("pause");
                system("cls");
            }
        }
        fclose(fp);
    }
    return flag;
}
