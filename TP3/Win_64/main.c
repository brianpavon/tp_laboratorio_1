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
    int flag = 0;
    int flagBinario = 0;
    //int prueba;

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
                if(controller_loadFromText("data.csv",pArrayListEmployee)==0 && flag == 0)
                {
                  printf("Lista cargada con exito\n");
                  flag = 1;
                  system("pause");
                }
                /*if(controller_loadFromText("data2.csv",pArrayListEmployee)==0 && flag == 0)
                {
                  printf("Lista cargada con exito\n");
                  flag = 1;
                  system("pause");
                }*/
                break;
            case 2:
                if(controller_loadFromBinary("dataB.csv",pArrayListEmployee)==0 && flagBinario == 0)
                {
                    printf("Archivo en binario cargado exitosamente\n");
                    flagBinario = 1;
                    system("cls");
                }

            	break;

            case 3:
                /*prueba = employee_generarId(pArrayListEmployee);
                printf("ID: %d\n",prueba);
                system("pause");*/
                system("cls");
                if(controller_addEmployee(pArrayListEmployee)==0 && flag != 0)
                {
                    printf("Se cargo el nuevo empleado\n");
                    system("pause");
                }
                else if(flag == 0)
                {
                    printf("Debe cargar primero un archivo\n");
                }
                //system("cls");
            	break;

            case 4:
                system("cls");
                if(flag != 0)
                {
                  controller_editEmployee(pArrayListEmployee);
                }
                else if(flag == 0)
                {
                   printf("Debe cargar primero un archivo\n");
                }
                break;

            case 5:
                system("cls");
                if(flag != 0)
                {
                  controller_removeEmployee(pArrayListEmployee);
                }

                else if(flag == 0)
                {
                   printf("Debe cargar primero un archivo\n");
                }
                break;

            case 6:
                system("cls");
                if(flag != 0)
                {
                 controller_ListEmployee(pArrayListEmployee);
                 system("pause");
                }
                else if(flag == 0)
                {
                   printf("Debe cargar primero un archivo\n");
                }

                break;

            case 7:
                system("cls");
                if(flag != 0)
                {
                 controller_sortEmployee(pArrayListEmployee);
                }

                else if(flag == 0)
                {
                   printf("Debe cargar primero un archivo\n");
                }
                break;

            case 8:
                if(flag != 0)
                {
                  controller_saveAsText("data2.csv",pArrayListEmployee);
                  printf("Guardado exitoso\n");
                  system("pause");
                }
                break;
            case 9:
                if(flagBinario != 0)
                {
                 controller_saveAsBinary("dataB2.csv",pArrayListEmployee);
                 printf("Guardado exitoso\n");
                }
                break;

        }
    }while(option != 10);
    return EXIT_SUCCESS;
}
