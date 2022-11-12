#ifndef _FACTURAS_H_
#define _FACTURAS_H_
#pragma once
#include "Clientes.h"
#include "Random.h"

/// === Estructuras.
typedef struct
{
    int id;
    char fecha[8];
    int Total;
    int Paga; /// 1 para paga --- 0 para impaga boolean
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
STFactura crearFactura(int id, char fecha[], char nombre[], char DNI[], int internet, int cable);
nodoFactura *inicLista();
nodoFactura *CrearFacturaNodo(STFactura factura);
nodoFactura *agregarAlPrincipio(nodoFactura *lista, nodoFactura *nuevoNodo);
int FacturasTotales(nodoFactura *Factura);
int FacturasTotalesInpagas(nodoFactura *Factura);
void generarFacturaRandom(char archivo[]);

/// MUESTRA FACTURAS
void MuestraUnicaFactura(STFactura Factura);
void MostrarTodasLasFacturasDeUnCliente(nodoFactura *Lista);
void AbrirArchiFacturasYleer(char ArchiFacturas[]);

/// MODIFICAR FACTURA
int ModificarServicioInternet();
int ModificarServicioCable();

#endif
