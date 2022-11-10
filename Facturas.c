#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "Facturas.h"
/// === Desarrollo funciones.
STFactura crearFactura(int id, int fecha, char nombre[], char DNI[], int total)
{
    STFactura nueva;
    nueva.id = id;
    strcpy(nueva.DNI, DNI);
    strcpy(nueva.Nombre, nombre);
    nueva.fecha = fecha;
    nueva.Total = total;
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
