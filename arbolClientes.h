#ifndef _ARBOLCLIENTES_H_
#define _ARBOLCLIENTES_H_
#pragma once
#include "Facturas.h"

/// Estructuras.
typedef struct arbolClientes
{
    STCliente Cliente;
    struct nodoFactura *Factura;
    struct arbolClientes *izq;
    struct arbolClientes *der;
} arbolClientes;

/// Prototipados.
/// === GESTION ARBOL.
arbolClientes *inicArbol();
arbolClientes *crearNodoArbol(STCliente cliente);
arbolClientes *agregarNodoArbol(arbolClientes *arbol, arbolClientes *nuevoNodo);
void mostrarArbol(arbolClientes *arbol);
void mostrarNodoArbol(arbolClientes *nodo);
arbolClientes *borrarCliente(arbolClientes *arbol, arbolClientes *borrado);
arbolClientes *nodoMasDerecha(arbolClientes *arbol);
arbolClientes *nodoMasIzquierda(arbolClientes *arbol);

/// === GESTION CLIENTE EN ARBOL.
arbolClientes *buscarNodoCliente(arbolClientes *arbol, int idCliente);
arbolClientes *modificarDatosPersonalesCliente(arbolClientes *arbol);
void mostrarDatosdeClienteXID(int idCliente, arbolClientes *arbol);
arbolClientes *buscarNodoClientePorDNI(arbolClientes *arbol, char DNI[]);

/// PERSISTENCIA ARBOL Y CLIENTE.
void PersistirCliente(arbolClientes *cliente, FILE *fp);
STRegistroCliente crearRegistroCliente(arbolClientes *cliente);
void persistirArbol(char archivo[], arbolClientes *arbol);
void recorrerYGuardar(arbolClientes *arbol, FILE *fp);
void archivoTOADL(arbolClientes * arbol, char archivo[]);

/// GESTION ARBOL Y FACTURAS.
void PersistenciaDeFactura(char ArchiFacturas[], arbolClientes *Arbol);
void mostrarFactura(arbolClientes *arbol);
int SacarTotal(arbolClientes *Arbol);
void DespersistenciaDeFacturas(char ArchiFacturas[], arbolClientes *arbol);
void DespersistirFacturasClienteEspecifico(char ArchiFacturas[], arbolClientes *cliente);

#endif // ARBOLCLIENTES_H_INCLUDED
