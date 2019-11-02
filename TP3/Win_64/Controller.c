#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
	FILE* pFile;
	pFile = fopen(path, "r");

	if(pFile != NULL)
	{
		retorno = parser_EmployeeFromText(pFile,pArrayListEmployee);
	}
	fclose(pFile);
	//pFile = NULL;
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* auxEmp;

	char id[4096];
	char nombre[4096];
	char horasTrabajadas[4096];
	char sueldo[4096];
	int idAux;
	int largo;

    if(pArrayListEmployee != NULL)
    {
      getString(nombre,"Ingrese el nombre:\n","Dato ingresado incorrecto\n",0,50,2);
      getString(horasTrabajadas,"Ingrese las horas trabajadas:\n","Dato ingresado incorrecto\n",0,50,2);
      getString(sueldo,"Ingrese el sueldo:\n","Dato ingresado incorrecto\n",0,50,2);
      largo = ll_len(pArrayListEmployee);
      idAux = largo+1;
      sprintf(id,"%d",idAux);

      auxEmp = employee_newParametros(id,nombre,horasTrabajadas,sueldo);

      if(auxEmp != NULL)
       {
          ll_add(pArrayListEmployee,auxEmp);
          retorno = 0;
       }
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    Employee* this;

    if(pArrayListEmployee != NULL)
    {
        printf("%5s %10s %10s %10s\n\n","ID","NOMBRE","HORAS TRABAJADAS","SUELDO");
        for(i=0 ; i<ll_len(pArrayListEmployee); i++)
        {
            if(i%150 == 0 && i != 0)
            {
                system("pause");
            }
          this = ll_get(pArrayListEmployee,i);
          employee_imprimirEmpleado(this);
          retorno = 0;
        }
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int opcion;
    if(pArrayListEmployee != NULL)
    {
        do
        {
            printf("-------------MENU DE ORDENAMIENTO-------------\n"
                   "1-Ordenar por nombre(ascendente)\n"
                   "2-Ordenar por nombre(descendente)\n\n\n"
                   "3-Ordenar por sueldo(ascendente)\n"
                   "4-Ordenar por sueldo(descendente)\n\n\n"
                   "5-Ordenar por horas trabajadas(ascendente)\n"
                   "6-Ordenar por horas trabajadas(descendente)\n\n\n"
                   "7-Salir:\n");

            getInt(&opcion,"Seleccione el criterio de orden\n","Opcion invalida\n",1,7,2);
            switch(opcion)
            {
            case 1:
                printf("Procesando...");
                ll_sort(pArrayListEmployee,employee_ordenarPorNombre,1);
                opcion = 7;
                break;
            case 2:
                printf("Procesando...");
                ll_sort(pArrayListEmployee,employee_ordenarPorNombre,0);
                break;
            case 3:
                printf("Procesando...");
                ll_sort(pArrayListEmployee,employee_ordenarPorSueldo,1);
                break;
            case 4:
                printf("Procesando...");
                ll_sort(pArrayListEmployee,employee_ordenarPorSueldo,0);
                break;
            case 5:
                printf("Procesando...");
                ll_sort(pArrayListEmployee,employee_ordenarPorHoras,1);
                break;
            case 6:
                printf("Procesando...");
                ll_sort(pArrayListEmployee,employee_ordenarPorHoras,0);
                break;

            }

        }while(opcion!=7);

       retorno = 0;
    }



    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

