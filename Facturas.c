#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "Facturas.h" ///Posiblie bug
#include <time.h>
/// === Desarrollo funciones.
STFactura crearFactura(int id, char fecha[], char nombre[], char DNI[], int internet, int cable)
{
    STFactura nueva;
    nueva.id = id;
    strcpy(nueva.DNI, DNI);
    strcpy(nueva.Nombre, nombre);
    //nueva.fecha = fecha;
    nueva.Total = 0;
    if (internet == 1)
    {
        nueva.Total += PrecioInternet();
    }
    if (cable == 1)
    {
        nueva.Total += PrecioCable();
    }
    nueva.Paga = 1;

    return nueva;
}

nodoFactura *inicLista()
{
    return NULL;
}

nodoFactura *CrearFacturaNodo(STFactura factura)
{
    nodoFactura *nueva = (nodoFactura *)malloc(sizeof(nodoFactura));
    nueva->Factura = factura;
    nueva->sig = NULL;
    nueva->ante = NULL;
    return nueva;
}

nodoFactura *agregarAlPrincipio(nodoFactura *lista, nodoFactura *nuevoNodo)
{
    if (lista)
    {
        lista->sig = nuevoNodo;
        nuevoNodo->ante = lista;
    }
    lista = nuevoNodo;
    return lista;
}

void MuestraUnicaFactura(STFactura Factura)
{
    printf("\nDNI: %c\n", Factura.DNI);
    printf("\nNombre: %s\n", Factura.Nombre);
    printf("\nNombre: %i\n", Factura.fecha);
    printf("\nNombre: %i\n", Factura.Total);
    printf("<------------------------------>");
}

void MostrarTodasLasFacturasDeUnCliente(nodoFactura *Lista)
{
    while (Lista != NULL)
    {
        MuestraUnicaFactura(Lista->Factura);
        Lista = Lista->sig;
    }
    printf("\nNo se detectaron mas facturas para mostrar\n");
}

void AbrirArchiFacturasYleer(char ArchiFacturas[])
{
    FILE *BUFFER = fopen(ArchiFacturas, "rb");
    STFactura Aux;
    while (fread(&Aux, sizeof(STFactura), 1, BUFFER) > 0)
    {
        MuestraUnicaFactura(Aux);
    }
    fclose(BUFFER);
}
int PrecioCable()
{
    return 600;
}

int PrecioInternet()
{
    return 1000;
}

int ModificarServicioCable()
{
    printf("\nIngrese el nuevo precio para el Cable\n");
    int Nuevo;
    scanf("%i", &Nuevo);
    return Nuevo;
}

int ModificarServicioInternet()
{
    printf("\nIngrese el nuevo precio para el Internet\n");
    int Nuevo;
    scanf("%i", &Nuevo);
    return Nuevo;
}

int FacturasTotales(nodoFactura *Factura)
{
    nodoFactura *NewFac = NULL;
    NewFac = Factura;
    int Cantidad = 0;
    while (NewFac)
    {
        Cantidad++;
        NewFac->sig;
    }
    return Cantidad;
}

int FacturasTotalesInpagas(nodoFactura *Factura)
{
    nodoFactura *NewFac = NULL;
    NewFac = Factura;
    int Cantidad = 0;

    while (NewFac)
    {
        if (NewFac->Factura.Paga == 0)
        {
            Cantidad++;
            NewFac->sig;
        }
    }
    return Cantidad;
}

void generarFacturaRandom(char archivo[])
{
    STRegistroCliente aux;
    STFactura facturita;
    int anio, mes;
    char a[4];
    char m[2];
    FILE *fp = fopen(archivo, "rb");
    if (fp)
    {
        while (fread(&aux, sizeof(STRegistroCliente), 1, fp) > 0)
        {
            anio = anioRandom();
            mes = mesRandom();

            while (anio <= 2022)
            {
                while (mes <= 12)
                {

                    // factura = crearFactura(/*cosas*/);
                    // itoa(anio, DNI, 10);
                }
            }
        }
        fclose(fp);
    }
}
