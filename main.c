#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#define TAM 25
#define TAMSEC 5
#define TAMALM 20
#define TAMCOM 7


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
}eFecha;

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
    eFecha fecha;
}eAlmuerzo;

typedef struct
{
    int legajo;
    char nombre[20];
    int sec;
    char sexo;
    float sueldo;
    int ocupado;
    eFecha ingreso;
} eEmpleado;

//Harcodeos
void hardcodeoAlmuerzo(eAlmuerzo almuerzo[], int x);
void hardcodeoComida (eComida comida[], int x);
void hardcodeoEmpleado(eEmpleado emp[], int x);
void hardcodeoSec(eSector vec[], int x);
//Menues
int menu(void);
int menuSector(void);
void menuSectorOpciones(eEmpleado emp[], int tam, eSector sector[], int tamSec, int opc);
//Input de datos (alta, baja, modificar,etc)
void altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector);
void bajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector);
//Buscadores
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);
int buscarLibre(eEmpleado vec[], int tam);
//Validaciones
void validarAnio(eEmpleado validation);
void validarMes(eEmpleado validation);
void validarDia(eEmpleado validation);
char validarChar(char a);
//Mostradores
void mostrarAlmuerzo(eAlmuerzo almuerzo, eEmpleado emp[], int tamEmp, eComida comidas[], int tamCom);
void mostrarAlmuerzoXComidas(eEmpleado empleado[], int tamEmp, eComida comida[], int tamCom, eAlmuerzo almuerzo[], int tamAlm, eSector sector[], int tamSec);
void mostrarAlmuerzoXSector (eEmpleado empleado[], int tamEmp, eComida comida[], int tamCom, eAlmuerzo almuerzo[], int tamAlm, eSector sector[], int tamSec);
void mostrarComida (eEmpleado empleado[], int tamEmp, eComida comida[], int tamCom, eAlmuerzo almuerzo[], int tamAlm);
void mostrarEmpleado(eSector sectores[], int tam, eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector);
void mostrarFemeninosXAlmuerzo(eEmpleado empleado[], int tamEmp, eComida comida[], int tamCom, eAlmuerzo almuerzo[], int tamAlm);
//Obtener
int obtenerSector(eSector sectores[], int tam, int idSector, char desc[]);
//-----------------------------main----------------------------

int main()
{


    int  sector;


    char seguir='s';
    char confirm;

    eEmpleado lista[TAM];
    eSector sectores[TAMSEC];
    eAlmuerzo almuerzo[TAMALM];
    eComida comida[TAMCOM];

    hardcodeoAlmuerzo(almuerzo,TAMALM);
    hardcodeoComida(comida,TAMCOM);
    hardcodeoEmpleado(lista,TAM);
    hardcodeoSec(sectores, TAMSEC);

    do
    {
        switch(menu())
        {

        case 1:
            altaEmpleado(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;
        case 2:
            bajaEmpleado(lista, TAM, sectores, TAMSEC);
            break;
        case 3:
//          modificacionEmpleado(lista,TAM);
            system("pause");
            break;
        case 4:
            break;
        case 5:
            mostrarEmpleados(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;
        case 6:
            sector=menuSector();

            if(sector==0)
            {
                system("pause");
                break;
            }
            else
            {
                menuSectorOpciones(lista, TAM, sectores, TAMSEC, sector);
                break;
            }
        case 7:
            mostrarComida(lista,TAM,comida,TAMCOM,almuerzo,TAMALM);
            break;
        case 8:
            //elegir un sector y mostrar los almuerzos de la gente de ese sector (nombre comida y fecha)
            mostrarAlmuerzoXSector(lista,TAM,comida,TAMCOM,almuerzo,TAMALM,sectores,TAMSEC);
            system("pause");
            break;
        case 9:
            mostrarAlmuerzoXComidas(lista,TAM,comida,TAMCOM,almuerzo,TAMALM,sectores,TAMSEC);
            break;
        case 10:
            mostrarFemeninosXAlmuerzo(lista,TAM,comida,TAMCOM,almuerzo,TAMALM);
            break;
        case 0:
            printf("\nConfirma salida s/n?: ");
            fflush(stdin);
            confirm = getche();
            confirm =validarChar(confirm);
            if( tolower(confirm) == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("\n Opcion invalida\n\n");
            system("pause");
            break;
        }
    }
    while(seguir == 's');

    return 0;
}

//------------------------------------------Harcodeos--------------------------------------------------------

void hardcodeoAlmuerzo(eAlmuerzo almuerzo[], int x)
{
    /*int id;
    int idComida;
    int idEmpleado;
    fFecha fecha;*/
    eAlmuerzo aux[]={
    {1  ,1, 1001,   {25  , 4 , 2019}},
    {2  ,2, 1001,   {25  , 4 , 2019}},
    {3  ,3, 1001,   {25  , 4 , 2019}},
    {4  ,4, 1004,   {25  , 4 , 2019}},
    {5  ,1, 1005,   {25  , 4 , 2019}},
    {6  ,1, 1006,   {25  , 4 , 2019}},
    {7  ,3, 1007,   {25  , 4 , 2019}},
    {8  ,3, 1008,   {25  , 4 , 2019}},
    {9  ,3, 1009,   {25  , 4 , 2019}},
    {10 ,4, 1010,   {25  , 4 , 2019}},
    {11 ,4, 1011,   {25  , 4 , 2019}},
    {12 ,4, 1012,   {25  , 4 , 2019}},
    {13 ,4, 1013,   {25  , 4 , 2019}},
    {14 ,4, 1014,   {25  , 4 , 2019}},
    {15 ,5, 1015,   {25  , 4 , 2019}},
    {16 ,5, 1016,   {25  , 4 , 2019}},
    {17 ,8, 1017,   {25  , 4 , 2019}},
    {18 ,8, 1018,   {25  , 4 , 2019}},
    {19 ,9, 1019,   {25  , 4 , 2019}},
    {20 ,10,1020,   {25  , 4 , 2019}},
    {21 ,13,1021,   {25  , 4 , 2019}},
    };
    for (int i=0; i<x; i++)
    {
        almuerzo[i]=aux[i];
    }
}

void hardcodeoComida (eComida comida[], int x)
{

    eComida aux[]={
    {"Fideos", 1},
    {"Milanesa", 2},
    {"Pescado",3},
    {"Pizza",4},
    {"Pollo al horno",5},
    {"Sopa",6},
    {"Pastel de papa",7},
    {"Cerdo",8},
    {"Bondiola",9},
    {"Guizo",10},
    {"Estofado",11},
    {"Locro",12},
    {"Ensalada",13},
    {"Atun",14},
    /*
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    */
    };

    for (int i=0; i<x; i++)
    {
        comida[i]=aux[i];
    }

}


void hardcodeoEmpleado(eEmpleado emp[], int x)
{

    eEmpleado aux[]={
    {1001 , "david"         ,  1    ,   'm' ,   15000   ,   1    ,{15  ,  4 , 2019}},
    {1002 , "cristian"      ,  3    ,   'm' ,   20000   ,   0    ,{24  ,  8 , 1990}},
    {1003 , "clara"         ,  3    ,   'f' ,   35800   ,   1    ,{30  , 11 , 1999}},
    {1004 , "hernan"        ,  3    ,   'm' ,   42560   ,   1    ,{18  ,  2 , 1986}},
    {1005 , "cintia"        ,  3    ,   'f' ,   36100   ,   1    ,{18  ,  2 , 1988}},
    {1006 , "carlos"        ,  3    ,   'f' ,   15000   ,   1    ,{25  ,  5 , 1990}},
    {1007 , "manuel"        ,  3    ,   'm' ,   18000   ,   1    ,{12  ,  9 , 1995}},
    {1008 , "hector"        ,  3    ,   'm' ,   19300   ,   1    ,{14  ,  8 , 1999}},
    {1009 , "dylan"         ,  3    ,   'm' ,   40000   ,   1    ,{05  , 10 , 2005}},
    {1010 , "damian"        ,  3    ,   'm' ,   80000   ,   1    ,{26  , 12 , 2007}},
    {1011 , "rodrigo"       ,  2    ,   'f' ,   19990   ,   0    ,{27  , 11 , 2010}},
    {1012 , "braian"        ,  2    ,   'm' ,   40500   ,   1    ,{13  ,  2 , 2019}},
    {1013 , "carolina"      ,  2    ,   'f' ,   28400   ,   1    ,{21  ,  5 , 1989}},
    {1014 , "laura"         ,  3    ,   'f' ,   19000   ,   0    ,{29  ,  4 , 1999}},
    {1015 , "analia"        ,  4    ,   'f' ,   24000   ,   1    ,{30  ,  4 , 1997}},
    {1016 , "yesica"        ,  4    ,   'f' ,   17500   ,   0    ,{30  ,  3 , 2001}},
    {1017 , "Pedro"         ,  3    ,   'm' ,   18900   ,   0    ,{31  ,  8 , 2002}},
    {1018 , "javier"        ,  3    ,   'm' ,   80000   ,   1    ,{30  , 11 , 1997}},
    {1019 , "Roberto"       ,  3    ,   'm' ,   35000   ,   1    ,{18  ,  1 , 1991}},
    {1020 , "carlos"        ,  1    ,   'm' ,   22000   ,   1    ,{11  ,  5 , 1997}},
    {1021 , "fabio"         ,  3    ,   'm' ,   19500   ,   1    ,{ 8  ,  4 , 2004}},
    {1022 , "leo"           ,  2    ,   'm' ,   32000   ,   1    ,{23  , 10 , 2008}},
    {1023 , "marcos"        ,  1    ,   'm' ,   28000   ,   1    ,{17  ,  9 , 2005}},
    {1024 , "mariela"       ,  3    ,   'f' ,   27500   ,   1    ,{12  ,  7 , 2010}},
    {1025 , "elisabet"      ,  2    ,   'f' ,   18000   ,   1    ,{ 4  , 12 , 2010}},
    };

    for (int i=0; i<x; i++)
    {
        emp[i]=aux[i];
    }

}

void hardcodeoSec(eSector vec[], int x)
{
    eSector aux[]={
    {1,"Sistemas"},{2,"RRHH"},{3,"Produccion"},{4,"Ventas"},{5,"Mantenimiento"},{8,"Montaje"},{9,"Forros"},{10,"Sobadores"}
    };
     for (int i=0; i<x; i++)
    {
        vec[i]=aux[i];
    }
}

//--------------------------------------------Menues------------------------------------------------------


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
    printf("8- Mostrar almuerzos por sector\n");
    printf("9-Mostrar almuerzos por comida\n");
    printf("10-Mostrar cantidad de mujeres por comida\n");
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
  //          mostrarEmpleadosPorSectores(emp, tam, sector, tamSec);
            printf("\n\n");
            system("pause");
            break;
        case 3:
            printf("Mostrar empleados por sus secotres");
            system("pause");
            break;
        case 4:
  //          mostrarEmpleadosPorSectores(emp, tam, sector, tamSec);
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

//-----------------------------------------Input--------------------------------------------------------------

void altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{
    int indice;
    int legajo;
    int esta;

    indice = buscarLibre(vec, tam);

    if(indice == -1)
    {
        printf("No hay lugar\n");
    }
    else
    {

        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(vec, tam, legajo);

        if( esta == -1)
        {
            vec[indice].legajo = legajo;

            printf("Ingrese fecha de ingreso dd mm aaaa: ");
            scanf("%d %d %d",&vec[indice].ingreso.dia,&vec[indice].ingreso.mes,&vec[indice].ingreso.anio);
            validarAnio(vec[indice]);
            validarMes(vec[indice]);
            validarDia(vec[indice]);

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(vec[indice].nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &vec[indice].sexo);

            printf("Ingrese sueldo: ");
            scanf("%f", &vec[indice].sueldo);

            printf("Ingrese id del sector: ");
            scanf("%d", &vec[indice].sec);


            vec[indice].ocupado = 1;

            printf("\nEl empleado ha sido registrado con exito!!!\n\n");

        }
        else
        {

            printf("Ya existe un empleado con el legajo %d\n", legajo);

            mostrarEmpleado(sectores, tamSector, vec[esta]);
        }
    }
}


void bajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{

    int legajo;
    char confirma;
   // int nuevoSueldo;
    int esta;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    esta = buscarEmpleado(vec, tam, legajo);

    if( esta == -1)
    {
        printf("\nEl legajo %d no esta registrado en el sistema\n", legajo);
        system("pause");
    }
    else
    {
        mostrarEmpleado(sectores, tamSector, vec[esta]);

        printf("\nConfirma la eliminacion? s/n ");
        fflush(stdin);
        confirma = tolower(getche());
        confirma = validarChar(confirma);
        if(confirma == 's')
        {
            vec[esta].ocupado = 0;
            printf("\nLa eliminacion se realizo correctamente\n");
            system("pause");
        }
        else
        {
            printf("\nLa eliminacion ha sido cancelada\n");
            system("pause");
        }
    }
}

//-----------------------------------------Buscadores---------------------------------------------------------


int buscarLibre(eEmpleado vec[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].legajo == legajo && vec[i].ocupado == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

//-----------------------------------Validaciones----------------------------

void validarAnio(eEmpleado validation)
{
    //Validacion del año
    while(validation.ingreso.anio<1990 || validation.ingreso.anio>2019)
    {
        printf("Anio equivocado, reingrese los anio: ");
        scanf("%d",&validation.ingreso.anio);
    }
}
void validarMes(eEmpleado validation)
{
    //validacion del mes
    while(validation.ingreso.mes<1 || validation.ingreso.mes>12)
    {
        printf("Error al ingresar mes, modifique el valor: ");
        scanf("%d",&validation.ingreso.mes);
    }
}
void validarDia(eEmpleado validation)
{
    //validacion del dia segun el mes
    switch(validation.ingreso.mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
            while(validation.ingreso.dia<1 || validation.ingreso.dia>31)
            {
                printf("El mes ingresado tiene de 1 a 31 dias, reingrese el dia: ");
                fflush(stdin);
                scanf("%d",&validation.ingreso.dia);
            }
            break;
    case 4:
    case 6:
    case 9:
    case 11:
            while(validation.ingreso.dia<1 || validation.ingreso.dia>30)
            {
                printf("El mes ingresado tiene de 1 a 30 dias, reingrese: ");
                fflush(stdin);
                scanf("%d",&validation.ingreso.dia);
            }
            break;
    default:
            while(validation.ingreso.dia<1 || validation.ingreso.dia>28)
            {
                printf("El mes ingresado tiene de 1 a 28 dias, reingrese: ");
                fflush(stdin);
                scanf("%d",&validation.ingreso.dia);
            }
            break;
    }
}

//------------------------OutPut---------------------------------
void mostrarAlmuerzo(eAlmuerzo almuerzo, eEmpleado emp[], int tamEmp, eComida comidas[], int tamCom)
{
    char nombreEmpleado[20];
    char nombreComida[20];

    int flag=0;
    int legajo;
    int dia;
    int mes;
    int anio;

    for(int i=0; i<tamEmp; i++)
    {

        if(almuerzo.idEmpleado == emp[i].legajo && emp[i].ocupado == 1)
        {
            strcpy(nombreEmpleado, emp[i].nombre);
            legajo=emp[i].legajo;
            dia=almuerzo.fecha.dia;
            mes=almuerzo.fecha.mes;
            anio=almuerzo.fecha.anio;
            flag=1;
            break;
        }
    }
    for(int j=0; j<tamCom; j++)
    {
        if(almuerzo.idComida == comidas[j].id )
        {
            strcpy(nombreComida, comidas[j].description);
        }
    }
    if(flag==1)
    printf("%20s        %15s     %d     %2d/%2d/%d\n",  nombreEmpleado, nombreComida, legajo,dia,mes,anio);
}

void mostrarAlmuerzoXSector (eEmpleado empleado[], int tamEmp, eComida comida[], int tamCom, eAlmuerzo almuerzo[], int tamAlm, eSector sector[], int tamSec)
{
    int sectorOK=0;
    int auxSector;
    int legajo;
    int dia;
    int mes;
    int anio;
    int flag=0;

    char nombreComida[20];
    char descSector[20];
    char nombreEmpleado[20];

    system("cls");
    printf("Sectores:\n");
    printf("id      Sector\n");
    for (int i=0; i<tamSec;i++)
    {
        printf("%d-     %s\n",sector[i].id,sector[i].description);
    }
    printf("Ingrese sector: ");
    scanf("%d",&auxSector);
    sectorOK=obtenerSector(sector,tamSec,auxSector,descSector);

    if(sectorOK!=0)
    {
        printf("id: %d\nSector: %s\n\n",auxSector,descSector);




        for(int k=0;k<tamAlm;k++)
        {

        for(int i=0; i<tamEmp; i++)
        {
            flag=0;
            if(almuerzo[k].idEmpleado == empleado[i].legajo && empleado[i].ocupado == 1 && auxSector== empleado[i].sec)
            {
            strcpy(nombreEmpleado, empleado[i].nombre);
            legajo=empleado[i].legajo;
            dia=almuerzo[k].fecha.dia;
            mes=almuerzo[k].fecha.mes;
            anio=almuerzo[k].fecha.anio;
            flag=1;
            break;
            }
        }
        for(int j=0; j<tamCom; j++)
        {
            if(almuerzo[k].idComida == comida[j].id )
            {
            strcpy(nombreComida, comida[j].description);
            }
        }
    if(flag==1 )
    printf("%20s        %15s     %d     %2d/%2d/%d\n",  nombreEmpleado, nombreComida, legajo,dia,mes,anio);
        }

        }

    else
    {
        printf("El sector no corresponde, reingrese\n");
    }
}


void mostrarComida (eEmpleado empleado[], int tamEmp, eComida comida[], int tamCom, eAlmuerzo almuerzo[], int tamAlm)
{

        system ("cls");
        printf ("-----Lista de Comidas-----\n\n");
        printf ("Id   Legajo        Nombre                  Comida              Fecha\n\n");

        for (int i=0;i<tamAlm;i++)
        {
            mostrarAlmuerzo(almuerzo[i],empleado,tamEmp,comida,tamCom);
        }

    system ("pause");
}


void mostrarEmpleado(eSector sectores[], int tam, eEmpleado emp)
{
    char nombreSector[20];
    int consigioNombre;

   consigioNombre =  obtenerSector(sectores, tam, emp.sec, nombreSector);

    if( !consigioNombre){
         strcpy(nombreSector, "Sin definir");
     }
    printf("   %d   %15s        %c     %.2f     %02d/%02d/%4d    %s\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, emp.ingreso.dia, emp.ingreso.mes, emp.ingreso.anio, nombreSector);
}

void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{
    int contador = 0;

    system("cls");

    printf(" Legajo      Nombre             Sexo    Sueldo     FechaIngreso   Sector\n");
    printf(" ------      ------             ----    ------     ------------   ------\n");

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarEmpleado(sectores, tamSector, vec[i]);
            contador++;
        }
    }
    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNo hay empleados que mostrar\n");
    }
}

char validarChar(char a)
{
    while(a!='s' && a!='n')
    {
        printf("\nTecla incorrecta, para confirmar precione 's', para cancelar precione 'n': ");
        a = tolower(getche());
    }
    return a;
}
//-----------------------------Obtener----------------------

int obtenerSector(eSector sectores[], int tam, int idSector, char desc[])
{

    int todoOk = 0;

    for(int i=0; i < tam; i++)    {

        if(idSector == sectores[i].id)
        {

            strcpy(desc, sectores[i].description);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

void mostrarAlmuerzoXComidas(eEmpleado empleado[], int tamEmp, eComida comida[], int tamCom, eAlmuerzo almuerzo[], int tamAlm, eSector sector[], int tamSec)
{
    eEmpleado auxEmpl;
    int aux;
    int flag;
    char auxComida[tamCom];

    system("cls");
    printf("Comidas\n");
    printf("id  Comidas\n\n");
    for(int i=0;i<tamCom;i++)
    {
        printf("%d  %s\n",comida[i].id,comida[i].description);
    }
    scanf("%d",&aux);

    for(int i=0;i<tamAlm;i++)
    {
        for(int j=0;j<tamEmp;j++)
        {
            flag=0;
            if(empleado[j].ocupado==1 && almuerzo[i].idEmpleado==empleado[j].legajo && almuerzo[i].idComida==aux)
                {
                    auxEmpl=empleado[j];
                    flag=1;
                    break;
                }
        }
        for(int k=0;k<tamCom;k++)
        {
            if (comida[k].id==aux)
                {strcpy(auxComida,comida[k].description);
                break;}
        }
        if(flag)
        printf("%d  %10s  %d  %10s\n",aux,auxComida,auxEmpl.legajo,auxEmpl.nombre);
    }
    system("pause");
}

void mostrarFemeninosXAlmuerzo(eEmpleado empleado[], int tamEmp, eComida comida[], int tamCom, eAlmuerzo almuerzo[], int tamAlm)
{
    int contador=0;
    int aux;
    char auxComida[tamCom];

    system("cls");
    printf("Comidas\n");
    printf("id  Comidas\n\n");
    for(int i=0;i<tamCom;i++)
    {
        printf("%d  %s\n",comida[i].id,comida[i].description);
    }
    scanf("%d",&aux);
    for(int i=0;i<tamAlm;i++)
    {
        for(int j=0;j<tamEmp;j++)
        {
            if(empleado[j].ocupado==1 && almuerzo[i].idEmpleado==empleado[j].legajo && almuerzo[i].idComida==aux && empleado[j].sexo=='f')
                {
                    contador++;
                    break;
                }
        }
        for(int k=0;k<tamCom;k++)
        {
            if (comida[k].id==aux)
                {strcpy(auxComida,comida[k].description);
                break;}
        }

    }
    if(contador!=0)
    printf("%d mujeres comieron %s\n",contador, auxComida);
    else
        printf("Ninguna yegua comio\n");
    system("pause");
}

