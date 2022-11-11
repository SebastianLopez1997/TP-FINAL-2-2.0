#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arbolClientes.h"

/// === GESTION ARBOL.

arbolClientes *inicArbol()
{
    return NULL;
}

arbolClientes *crearNodoArbol(STCliente cliente)
{
    arbolClientes *nuevo = (arbolClientes *)malloc(sizeof(arbolClientes));
    nuevo->Cliente = cliente;
    nuevo->Factura = inicLista();
    nuevo->der = NULL;
    nuevo->izq = NULL;
    return nuevo;
}

arbolClientes *agregarNodoArbol(arbolClientes *arbol, arbolClientes *nuevoNodo)
{
    if (arbol == NULL)
    {
        arbol = nuevoNodo;
    }
    else
    {
        if (arbol->Cliente.Login.id > nuevoNodo->Cliente.Login.id)
        {
            arbol->izq = agregarNodoArbol(arbol->izq, nuevoNodo);
        }
        else
        {
            arbol->der = agregarNodoArbol(arbol->der, nuevoNodo);
        }
    }
    return arbol;
}

void mostrarArbol(arbolClientes *arbol)
{
    if (arbol)
    {
        mostrarArbol(arbol->izq);
        mostrarNodoArbol(arbol);
        mostrarArbol(arbol->der);
    }
    else
    {
        printf("No se puede mostrar el arbol\n");
    }
}

void mostrarNodoArbol(arbolClientes *nodo)
{
    if (nodo)
    {
        MostrarUncliente(nodo->Cliente);
    }
    else
    {
        printf("No se puede mostrar el cliente error 404");
    }
}

arbolClientes *borrarCliente(arbolClientes *arbol, arbolClientes *borrado)
{
    if (arbol)
    {
        if (borrado->Cliente.Dato.DNI == arbol->Cliente.Dato.DNI)
        {
            if (arbol->izq)
            {
                arbolClientes *masDerecha = nodoMasDerecha(arbol->izq);
                arbol = masDerecha;
                arbol->izq = borrarCliente(arbol->izq, masDerecha);
            }
            else if (arbol->der)
            {
                arbolClientes *masIzquierda = nodoMasIzquierda(arbol->izq);
                arbol = masIzquierda;
                arbol->der = borrarCliente(arbol->der, masIzquierda);
            }
            else
            { // En caso de que sea hoja.
                free(arbol);
                arbol = NULL;
            }
        }
        else if (borrado->Cliente.Dato.DNI > arbol->Cliente.Dato.DNI)
        {
            arbol->der = borrarCliente(arbol->der, borrado);
        }
        else
        {
            arbol->izq = borrarCliente(arbol->izq, borrado);
        }
    }
    return arbol;
}

arbolClientes *nodoMasDerecha(arbolClientes *arbol)
{
    if (arbol->der)
    {
        arbol = nodoMasDerecha(arbol->der);
    }
    return arbol;
}

arbolClientes *nodoMasIzquierda(arbolClientes *arbol)
{
    if (arbol->izq)
    {
        arbol = nodoMasIzquierda(arbol->izq);
    }
    return arbol;
}

/// === GESTION CLIENTE EN ARBOL.
arbolClientes *buscarNodoCliente(arbolClientes *arbol, int idCliente)
{
    arbolClientes *aux = inicArbol();
    if (arbol)
    {
        if (arbol->Cliente.Dato.id == idCliente)
        {
            aux = arbol;
        }
        else
        {
            if (idCliente < arbol->Cliente.Dato.id)
            {
                aux = buscarNodoCliente(arbol->izq, idCliente);
            }
            else
            {
                aux = buscarNodoCliente(arbol->der, idCliente);
            }
        }
    }
    return aux;
}

arbolClientes *buscarNodoClientePorDNI(arbolClientes *arbol, char DNI[])
{
    arbolClientes *aux = inicArbol();
    int IdEncontrado = -1;
    if (arbol)
    {
        if (strcmpi(arbol->Cliente.Dato.DNI, DNI) == 0)
        {
            IdEncontrado = arbol->Cliente.Dato.id;
        }
        else
        {
            if (DNI < arbol->Cliente.Dato.DNI)
            {
                IdEncontrado = buscarNodoClientePorDNI(arbol->izq, DNI);
            }
            else
            {
                IdEncontrado = buscarNodoClientePorDNI(arbol->der, DNI);
            }
        }
    }
    return IdEncontrado;
}

void mostrarDatosdeClienteXID(int idCliente, arbolClientes *arbol)
{
    arbolClientes *aux = inicArbol();
    aux = buscarNodoCliente(arbol, idCliente);
    MostrarUncliente(aux->Cliente);
}

arbolClientes *modificarDatosPersonalesCliente(arbolClientes *arbol)
{
    char seguir = 's';
    int opcion, flag = 1, idBuscado;
    arbolClientes *modificado = inicArbol();
    STCliente nuevo;

    while (seguir == 's')
    {
        printf("Ingrese el ID del cliente.\n");
        scanf("%i", &idBuscado);
        modificado = buscarNodoCliente(arbol, idBuscado);
        if (modificado != NULL)
        {
            nuevo = modificado->Cliente;
            seguir = 'n';
        }
        else
        {
            printf("El DNI ingresado no ha sido encontrado.\n");
            seguir = confirmacionBucle();
        }
    }

    seguir = 's';

    while (seguir == 's')
    {

        printf("Que valor desea modificar?\n");
        printf("1. Nombre.\n");
        printf("2. Apellido.\n");
        printf("3. Telefono.\n");
        printf("4. Barrio.\n");
        printf("5. Calle.\n");
        printf("6. Password.\n");

        scanf("%i", opcion);
        switch (opcion)
        {
        case 1:
            printf("Ha seleccionado la opcion 1.\n");
            seguir = confirmacionBucle();
            if (seguir == 's')
            {
                modificarNombre(nuevo.Dato.Nombre);
                flag = 0;
                system("cls");
            }
            break;
        case 2:
            printf("Ha seleccionado la opcion 2.\n");
            seguir = confirmacionBucle();
            if (seguir == 's')
            {
                modificarApellido(nuevo.Dato.Apellido);
                flag = 0;
                system("cls");
            }
            break;
        case 3:
            printf("Ha seleccionado la opcion 3.\n");
            seguir = confirmacionBucle();
            if (seguir == 's')
            {
                modificarTelefono(nuevo.Dato.NumeroCel);
                flag = 0;
                system("cls");
            }
            break;
        case 4:
            printf("Ha seleccionado la opcion 4.\n");
            seguir = confirmacionBucle();
            if (seguir == 's')
            {
                modificarBarrio(nuevo.Dato.direccion.Barrio);
                flag = 0;
                system("cls");
            }
            break;
        case 5:
            printf("Ha seleccionado la opcion 5.\n");
            seguir = confirmacionBucle();
            if (seguir == 's')
            {
                modificarDireccion(nuevo.Dato.direccion.Direccion);
                flag = 0;
                system("cls");
            }
            break;
        case 6:
            printf("Ha seleccionado la opcion 6.\n");
            seguir = confirmacionBucle();
            if (seguir == 's')
            {
                cambiarPassword(arbol->Cliente.Login.pass);
                flag = 0;
                system("cls");
            }
            break;
        default:
            printf("Ha ingresado una opcion invalida.\n");
            seguir = confirmacionBucle();
            break;
        }
        seguir = confirmacionBucle();
        system("cls");
    }

    if (flag == 0)
    { /*Hubo modifiación, entonces procede a la sustitución de la estructura.*/
        modificado->Cliente = nuevo;
    }

    return arbol;
}

/// PERSISTENCIA ARBOL Y CLIENTE.

void PersistirCliente(arbolClientes *cliente, FILE *fp)
{
    if (fp)
    {
        STRegistroCliente aux;
        aux = crearRegistroCliente(cliente);
        fwrite(&aux, sizeof(STRegistroCliente), 1, fp);
    }
}

STRegistroCliente crearRegistroCliente(arbolClientes *cliente)
{
    STRegistroCliente aux;
    strcpy(aux.Nombre, cliente->Cliente.Dato.Nombre);
    strcpy(aux.Apellido, cliente->Cliente.Dato.Apellido);
    strcpy(aux.DNI, cliente->Cliente.Dato.DNI);
    strcpy(aux.Direccion, cliente->Cliente.Dato.direccion.Direccion);
    strcpy(aux.Barrio, cliente->Cliente.Dato.direccion.Barrio);
    strcpy(aux.NumeroCel, cliente->Cliente.Dato.NumeroCel);
    aux.id = cliente->Cliente.Login.id;
    strcpy(aux.pass, cliente->Cliente.Login.pass);
    aux.Cable = cliente->Cliente.Servicio.Cable;
    aux.Internet = cliente->Cliente.Servicio.Internet;
    return aux;
}
void persistirArbol(char archivo[], arbolClientes *arbol)
{
    FILE *fp = fopen(archivo, "wb");
    if (fp)
    {
        recorrerYGuardar(arbol, &*fp);
        close(fp);
    }
}
void recorrerYGuardar(arbolClientes *arbol, FILE *fp)
{
    if (arbol)
    {
        recorrerYGuardar(arbol->izq, &*fp);
        PersistirCliente(arbol, &*fp);
        recorrerYGuardar(arbol->der, &*fp);
    }
}

void persistirNuevoNodo(arbolClientes *nodo, char archivo[])
{
    FILE *fp = fopen(archivo, "ab");
    if (fp)
    {
        MostrarUncliente(nodo->Cliente);
        PersistirCliente(nodo, &*fp);
        close(fp);
    }
}

arbolClientes *archivoTOADL(arbolClientes *arbol, char archivo[])
{
    STRegistroCliente a;
    STCliente nuevoCliente;
    arbolClientes *nuevoNodo = inicArbol();
    FILE *fp = fopen(archivo, "rb");
    if (fp)
    {
        while (fread(&a, sizeof(STRegistroCliente), 1, fp) > 0)
        {
            if (a.Internet == 1 || a.Cable == 1)
            {
                nuevoCliente = registroToSTCLiente(a);
                nuevoNodo = crearNodoArbol(nuevoCliente);
                arbol = agregarNodoArbol(arbol, nuevoNodo);
            }
        }
        fclose(fp);
    }
    return arbol;
}

/// GESTION ARBOL Y FACTURAS.
void PersistenciaDeFactura(char ArchiFacturas[], arbolClientes *Arbol)
{
    arbolClientes *aux = NULL;
    aux = Arbol;
    nodoFactura *listaAux = NULL;
    listaAux = Arbol->Factura;

    FILE *BUFFER = fopen(ArchiFacturas, "ab");

    while (listaAux != NULL)
    {
        fwrite(&listaAux, sizeof(STFactura), 1, BUFFER);
        listaAux = listaAux->sig;
    }
    fclose(BUFFER);
}
void mostrarFactura(arbolClientes *arbol)
{
    if (arbol)
    {
        mostrarArbol(arbol->izq);
        MostrarTodasLasFacturasDeUnCliente(arbol->Factura);
        mostrarArbol(arbol->der);
    }
}
int SacarTotal(arbolClientes *Arbol)
{
    int total = 0;
    int flag = 0;
    int cable = 1200;
    int internet = 1800;
    int descuento = 600;
    if (Arbol->Cliente.Servicio.Cable == 1)
    {
        total = total + cable;
        flag++;
    }
    if (Arbol->Cliente.Servicio.Internet == 1)
    {
        total += internet;
        flag++;
    }
    if (flag == 2)
    {
        total -= descuento;
    }
    return total;
}

void DespersistenciaDeFacturas(char ArchiFacturas[], arbolClientes *arbol)
{
    STFactura aux;
    FILE *fp = fopen(ArchiFacturas, "rb");
    if (fp)
    {
        while (fread(&aux, sizeof(STFactura), 1, fp) > 0)
        {
            nodoFactura *nuevo = CrearFacturaNodo(aux);
            arbolClientes *arbolAux = buscarNodoCliente(arbol, nuevo->id);
            if (arbolAux)
            {
                arbolAux->Factura = agregarAlPrincipio(arbolAux->Factura, nuevo);
            }
        }
        fclose(fp);
    }
}

void DespersistirFacturasClienteEspecifico(char ArchiFacturas[], arbolClientes *cliente)
{
    STFactura aux;
    FILE *fp = fopen(ArchiFacturas, "rb");
    if (fp)
    {
        while (fread(&aux, sizeof(STFactura), 1, fp) > 0)
        {
            if (aux.id == cliente->Cliente.Login.id)
            {
                nodoFactura *nuevo = CrearFacturaNodo(aux);
                cliente->Factura = agregarAlPrincipio(cliente->Factura, nuevo);
            }
        }
        fclose(fp);
    }
}
