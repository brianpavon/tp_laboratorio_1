#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "arrayEmployees.h"
#define CANTIDAD_EMPLEADOS 1000
#define CANTIDAD_SECTORES 3

int main()
{
    sEmpleado empleado[CANTIDAD_EMPLEADOS];
    sSector sector[CANTIDAD_SECTORES]={{1,"RRHH"},{2,"Sistemas"},{3,"Contabilidad"}};
    int opcionMenu;
    int id = 0;
    do
    {
        system("cls");
        printf("****MENU DE OPCIONES****\n");
        getInt(&opcionMenu,"1-Alta: \n2-Baja: \n3-Modificacion: \n4-Informes: \n5-Salir \n","OPCION INVALIDA",0,5,2);
        switch(opcionMenu)
        {
        case 1:
            system("cls");
            addEmployees(empleado,CANTIDAD_EMPLEADOS,sector,CANTIDAD_SECTORES,id);
            id++;

            break;
        case 2:
            system("cls");
            bajaEmpleadoPorId(empleado, CANTIDAD_EMPLEADOS, sector, CANTIDAD_SECTORES);
            break;
        case 3:
            system("cls");
            menuModificacionEmpleados(empleado,CANTIDAD_EMPLEADOS,sector,CANTIDAD_SECTORES);

            break;
        case 4:
            system("cls");
            menuReportes(empleado, CANTIDAD_EMPLEADOS, sector, CANTIDAD_SECTORES);
            break;
        }

    }while(opcionMenu != 5);

    return 0;
}


