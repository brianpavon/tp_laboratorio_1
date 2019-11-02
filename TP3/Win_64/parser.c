#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

    int retorno = -1;

	Employee* auxEmployee;
	char id[QTY_CARACTERES];
	char nombre[QTY_CARACTERES];
	char horasTrabajadas[HORA_MAXIMA];
	char sueldo[SUELDO_MAXIMO];

	pFile = fopen("data.csv","r");
	if(pArrayListEmployee != NULL && pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

		do
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
			auxEmployee = employee_newParametros(id,nombre,horasTrabajadas,sueldo);
			//llamar al new empleados y pasarle todos los parametros
			//auxEmployee = employee_newParametros();
			//verifico lo anterior,
			if(auxEmployee != NULL)
			  {
			  	 ll_add(pArrayListEmployee,auxEmployee);
			  	 retorno = 0;
			  }
            else
                break;

		}while(!feof(pFile));
    }

		fclose(pFile);
		pFile = NULL;

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
