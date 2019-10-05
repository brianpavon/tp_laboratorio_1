#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "empleados.h"

#define CANTIDAD_EMPLEADOS 1000
#define CANTIDAD_SECTORES 4

int main()
{
    struct sEmpleado aEmpleado[CANTIDAD_EMPLEADOS];
    int opcionMenu;
    initLugarLibreEmpleado(aEmpleado,CANTIDAD_EMPLEADOS);
    int i =0;
    do
    {
        printf("****MENU DE OPCIONES****\n");
        getInt(&opcionMenu,"1-Alta: \n2-Baja: \n3-Modificacion: \n4-Informes: \n5-Salir \n","OPCION INVALIDA",0,5,2);
        switch(opcionMenu)
        {
        case 1:
            altaEmpleadoPorId(aEmpleado,CANTIDAD_EMPLEADOS);
            printf("SOS PIOLA");
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        }

    }while(opcionMenu != 5);

    return 0;
}
