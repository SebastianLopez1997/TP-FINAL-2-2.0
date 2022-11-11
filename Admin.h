#ifndef _ADMIN_H_
#define _ADMIN_H_
#pragma once
#include "arbolClientes.h"

/// === Prototipados.
int ComprobarAdmin(char usuario[20], char contrasena[20]);
int ComprobarUsuario(arbolClientes *arbol, char usuario[20], char contrasena[20]);
void menuAdministrador(arbolClientes *arbol);
void funcionesAdministrador(arbolClientes *arbol);
int LoginDeUsuario(arbolClientes *Arbol);

#endif // ADMIN_H_INCLUDED
