#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#define TAM 10
#define TAMSEC 3
#define TAMALM 20
#define TAMCOM 14

//------------------------------------------structs
typedef struct
{
    int id;
    char description[30];
}eSector;

typedef struct
{
    int dia;
    int mes;
    int anio;
}fFecha;

typedef struct
{
    char description[20];
    int id;

}eComida;

typedef struct
{
    int id;
    int idComida;
    int idEmpleado;
    fFecha fecha;
}eAlmuerzo;

typedef struct
{
    int legajo;
    char nombre[20];
    int sec;

    char sexo;

    float sueldo;
    int ocupado;
    fFecha ingreso;
} eEmpleado;
//--------------------------------funtions-------------------------



