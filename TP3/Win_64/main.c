#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option;

    LinkedList* pArrayListEmployee = ll_newLinkedList();
    do{
         system("cls");
         printf(	 "Menu:\n\n"
			 "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
			 "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n"
			 "3. Alta de empleado\n"
			 "4. Modificar datos de empleado\n"
			 "5. Baja de empleado\n"
			 "6. Listar empleados\n"
			 "7. Ordenar empleados\n"
			 "8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
			 "9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n"
			"10. Salir\n");
    getInt(&option,"Elija una opcion\n","Opcion invalida\n",0,10,2);

        switch(option)
        {
            case 1:
                if(controller_loadFromText("data.csv",pArrayListEmployee)==0)
                {
                  printf("Lista cargada con exito\n");
                  system("pause");
                }
                system("cls");
                break;
            case 2:

                system("cls");
            	break;
            case 3:
                if(controller_addEmployee(pArrayListEmployee)==0)
                {
                    printf("Se cargo el nuevo empleado\n");
                    system("pause");
                }
                system("cls");
            	break;
            case 4:
                controller_editEmployee(pArrayListEmployee);
                break;
            case 5:
                controller_removeEmployee(pArrayListEmployee);
                break;
            case 6:
                controller_ListEmployee(pArrayListEmployee);
                system("pause");

                break;
            case 7:

                controller_sortEmployee(pArrayListEmployee);

                break;
            case 8:

                break;
            case 9:

                break;

        }
    }while(option != 10);
    return EXIT_SUCCESS;
}
