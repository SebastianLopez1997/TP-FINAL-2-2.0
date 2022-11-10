#ifndef _FACTURAS_H_
#define _FACTURAS_H_
#pragma once
#include "Clientes.h"

/// === Estructuras.
typedef struct
{
    int id;
    int fecha;
    int Total;
    char Nombre[30];
    char DNI[8];
} STFactura;

typedef struct
{
    int id;
    STFactura Factura;
    struct nodoFactura *sig;
    struct nodoFactura *ante;
} nodoFactura;

/// === Prototipados.
STFactura crearFactura(int id, int fecha, char nombre[], char DNI[], int total);
nodoFactura *inicLista();
nodoFactura *CrearFacturaNodo(STFactura factura);
nodoFactura *agregarAlPrincipio(nodoFactura *lista, nodoFactura *nuevoNodo);


void MuestraUnicaFactura(STFactura Factura);
void MostrarTodasLasFacturasDeUnCliente(nodoFactura *Lista);
void AbrirArchiFacturasYleer(char ArchiFacturas[]);


#endif
