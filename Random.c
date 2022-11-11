#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Random.h"
#define DIM 50

void nombreRandom(char nombre[])
{
    char nombres[][20] = {"JORGE", "MARIA", "MABEL", "MARIO", "ELENA", "JULIETA", "FERNANDO", "BENJAMIN", "BENICIO", "LORENA",
                          "LAURA", "CRISTIAN", "ALEJANDRA", "DENISSE", "CAREN", "DALILA", "RODRIGO", "SOFIA", "ALDANA", "MATIAS",
                          "JUAN", "FRANCO", "LUCAS", "LUCIO", "ROBERTO", "VALERIA", "NATALIA", "CRISTINA", "JESICA", "LUIS",
                          "GLADYS", "NAHUEL", "AYELEN", "CLAUDIA", "VERONICA", "BEATRIZ", "LEONOR", "VALENTINA", "PILAR", "DAVID",
                          "ESTELA", "JAVIER", "EZEQUIEL", "LORENZO", "MELINA", "DANIEL", "MAURICIO", "NICOLAS", "ISAIAS", "JACINTO"};

    int a = rand() % DIM;
    strcpy(nombre, nombres[a]);
}

void apellidoRandom(char apellido[])
{
    char apellidos[][40] = {"BENITEZ", "PALACIN", "BALMACEDA", "GONZALEZ", "BOLAJUZON", "PONS", "CARBALLEYRA", "FERNANDEZ", "ORTIZ", "AUSTEN",
                            "CATANEO", "BERMUDEZ", "AIRA", "SANTOS", "VILLAR", "BATAGLIA", "MENENDEZ", "CASTILLO", "OTALORA", "MAIRAL",
                            "ARGONZ", "PAZ", "OJEDA", "APARICIO", "SANCHEZ", "SANCHIS", "DE LA VEGA", "MARADONA", "ACEVEDO", "CERVANTES",
                            "URIARTE", "MARCHESAN", "MERCHAN", "PINEYRO", "CERANTES", "PEDRERO", "PADRON", "HARO", "INFANTE", "ESPEJO",
                            "ORTIGAS", "CONDE", "MACIA", "FLECHERO", "ALMEDIDA", "PALERMO", "GODOY", "VILLANUEVA", "ALI", "OROZCO"};

    int a = rand() % DIM;
    strcpy(apellido, apellidos[a]);
}

void movilRandom(char movil[])
{
    char moviles[][20] = {"2235896511", "2234896511", "2236896512", "2234896411", "2235896579", "2245895511", "2233896510", "2235826509", "2245176511", "2233123141",
                          "2245226510", "2238496551", "2236996512", "2234892617", "2235896579", "2245895511", "2233896510", "2235826509", "2245176511", "2233123141",
                          "2245226510", "2238496551", "2236996512", "2234892617", "2235896579", "2245895511", "2233896510", "2235826509", "2245176511", "2233123141",
                          "2245226510", "2238496551", "2236996512", "2234892617", "2235896579", "2245895511", "2233896510", "2235826509", "2245176511", "2233123141",
                          "2245226510", "2238496551", "2236996512", "2234892617", "2235896579", "2245895511", "2233896510", "2235826509", "2245176511", "2233123141"};

    int a = rand() % DIM;
    strcpy(movil, moviles[a]);
}

void domicilioRandom(char domicilio[])
{
    char domicilios[][20] = {"Brown ", "Falucho ", "Guemes ", "San Juan ", "Luro ", "Colon ", "Malvinas ", "San Martin ", "Constitucion ", "Peralta Ramos ",
                             "Bolivar ", "Moreno ", "San Luis ", "Belgrano ", "Jara ", "Francia ", "Don Bosco ", "Italia ", "Alberti ", "Rawson ",
                             "Libertad ", "Alio ", "Tucuman ", "Cordoba ", "Talcahuano ", "Mario Bravo", "Marconi ", "Jujuy ", "Salta ", "25 de mayo ",
                             "12 de Octubre ", "Juncal ", "Rivadavia ", "Catamarca ", "Independencia ", "Bronzini ", "Balcarce ", "Vieytes ", "Juan B Justo ", "Paso ",
                             "Mitre ", "9 de julio ", "Peru ", "Mexico ", "Gianelli ", "Mosconi ", "Garay ", "Avellaneda ", "Alvarado ", "La Pampa "};

    char numeraciones[][10] = {"5821", "1234", "558", "1231", "60", "5888", "2750", "3554", "5888", "2950",
                               "5897", "3214", "2000", "1324", "50", "3245", "3698", "14", "10000", "5687",
                               "654", "2159", "120", "2258", "3487", "1478", "3333", "546", "258", "35",
                               "1624", "951", "478", "325", "3668", "4789", "389", "12000 ", "101", "472",
                               "4763 ", "123", "9887", "10001", "20", "1287", "997", "876", "111", "9823"};

    int a = rand() % DIM;
    int b = rand() % DIM;
    strcpy(domicilio, strcat(domicilios[a], numeraciones[b]));
}

void barrioRandom(char barrio[])
{
    char barrios[][20] = {"Acantilados", "Aeroparque", "Alfar", "Caisamar", "Centenario", "Cerrito", "Constitucion", "Estrada", "Faro", "Juramento", "Libertad",
                         "Montemar", "Pueyrredon", "Sarmiento", "Zacagnini"};

    int a = rand() % 16;
    strcpy(barrio, barrios[a]);
}



int cableRandom(){
    int a= rand()%2;
    return a;
}
int internetRandom(){
    int a=rand()%2;
    return a;
}


void dniRandom(char DNI[])
{
    int opcion = rand() % 9;
    int num = rand() % 5000000 + 25000000;
    switch (opcion)
    {
    case 0:
        num += 11342685;
        break;
    case 1:
        num += 12751073;
        break;
    case 2:
        num += 6574321;
        break;
    case 3:
        num += 9574618;
        break;
    case 4:
        num += 5784165;
        break;
    case 5:
        num += 4895432;
        break;
    case 6:
        num += 13961259;
        break;
    case 7:
        num += 7547588;
        break;
    case 8:
        num += 8796112;
        break;
    }
    DNI[10];
    itoa(num, DNI, 10);
}