#ifndef _CLEINTES_H_
#define _CLIENTES_H_
#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "Utilidades.h"

typedef struct RegistroCliente
{
    /// Datos personales
    int id;
    char DNI[8];
    char pass[8];
    char Nombre[30];
    char Apellido[30];
    char NumeroCel[20];
    /// Direccion
    char Direccion[20];
    char Barrio[20];
    /// Servicios activo o no
    int Internet;
    int Cable;
} STRegistroCliente;

typedef struct
{
    char Direccion[20];
    char Barrio[20];
} STDireccion;

typedef struct
{
    int id;
    char pass[10];
} STLogin;

typedef struct
{
    int id;
    char DNI[20];
    char Nombre[30];
    char Apellido[30];
    char NumeroCel[20];
    STDireccion direccion;
} STPersonal;

typedef struct
{
    int Internet;
    int Cable;
} STServicio;

typedef struct
{
    STLogin Login;
    STPersonal Dato;
    STServicio Servicio;
} STCliente;

/// MODIFICAR DATOS CLIENTE.
void modificarNombre(char nombre[]);
void modificarApellido(char apellido[]);
void modificarTelefono(char telefono[]);
void modificarBarrio(char barrio[]);
void modificarDireccion(char direccion[]);
void cambiarPassword(char password[]);
STCliente DarmeLaBaja(STCliente aux);

/// CARGA CLIENTE.
STCliente CargarUnCliente();
STPersonal cargaDatosPersonales();
STServicio CargaServicio();
STLogin cargaLogin(STPersonal cliente);
STRegistroCliente crearRegistroRand(int id, char archivo[]);
STCliente registroToSTCLiente(STRegistroCliente p);
int retornaUltimoId(char archivo[]);
void generarArchivoRandom(char archivo[]);

STRegistroCliente crearRegistroRand(int id, char archivo[]);
int funcionComprobarDNI(char dni[], char archivo[]);

/// MOSTRAR CLIENTE
void MostrarUncliente(STCliente aux);

/// Comprobar estado del cliente
STCliente DarmeLaBaja(STCliente aux);
int EstadoClienteServicios(STCliente Aux);
int funcionComprobarDNI(char dni[], char archivo[]);

#endif // CLIENTES_H_INCLUDED
