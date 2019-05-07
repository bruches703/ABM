#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "menu.h"


int menu()
{
    int opcion;

    system("cls");
    printf("            *** ABM Empleados ***\n\n");
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificacion Empleado\n");
    printf("4- Ordenar Empleados\n");
    printf("5- Listar Empleados\n");
    printf("6- Menu de SECTOR\n");
    printf("7- Mostrar comida\n");
    printf("0- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuSector(void)
{
    int opcion;

    system("cls");
    printf("            *** ABM Empleados ***\n\n");
    printf("1-Lista de empleados por sector\n");
    printf("2-Cantidad de empleados por sector\n");
    printf("3-Empleados por sus sectores\n");
    printf("4-Listado de empleados por sector\n");
    printf("5-Datos de el/los empleados que mas ganan por sector\n");
    printf("6-El o los sectores con mas empleados\n");
    printf("0-Volver al menu anterior\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}

void menuSectorOpciones(eEmpleado emp[], int tam, eSector sector[], int tamSec, int opc)
{
    int aux;
    char exit=0;
    do
    {
        switch(opc)
        {
        case 1:
            printf("Ingrese id del sector para ordenar: ");
            scanf("%d",&aux);
            break;
        case 2:
            mostrarEmpleadosPorSectores(emp, tam, sector, tamSec);
            printf("\n\n");
            system("pause");
            break;
        case 3:
            printf("Mostrar empleados por sus secotres");
            system("pause");
            break;
        case 4:
            mostrarEmpleadosPorSectores(emp, tam, sector, tamSec);
            system("pause");
            break;
        case 5:
            printf("Empleado que mas gana");
            system("pause");
            break;
        case 6:
            printf("Listado de empleados por sector");
            system("pause");
            break;
        case 7:

        case 0:
            exit=1;
            break;
        }
    }while(exit==1);
}

//------------------------------------------------------------------------------------------------------------
