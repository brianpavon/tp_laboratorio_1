#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "empleados.h"

int ordenarArrayEmpleados(struct sEmpleado aEmpleado, int cantidad)
{
	int i;
	int retorno = -1;
	struct sEmpleado bEmpleado;
	int fSwap;
	if(aEmpleado != NULL && cantidad>0)
	{
		retorno = 0;
		do
		{
			fSwap = 0;
			for(i=0;i<cantidad-1;i++)
			{
				if(strncmp(aEmpleado[i].nombre,aEmpleado[i+1].nombre,QTY_CARACTERES)>0)
				{
					fSwap = 1;
					bEmpleado = aEmpleado[i];
					aEmpleado[i]=aEmpleado[i+1];
					aEmpleado[i+1]=bEmpleado;
				}
				else if(strncmp(aEmpleado[i].nombre,aEmpleado[i+1].nombre,QTY_CARACTERES)==0)
				{
					if(strncmp(aEmpleado[i].apellido,aEmpleado[i+1].apellido,QTY_CARACTERES)>0)
					{
						fSwap = 1;
						bEmpleado = aEmpleado[i];
						aEmpleado[i]=aEmpleado[i+1];
						aEmpleado[i+1]=bEmpleado;
					}
				}
			}
		}while(fSwap);
	}
	return retorno;
}

/** PARA PROBAR/HARDCODEAR
*
*/

int altaForzadaEmpleados(struct sEmpleado aEmpleado, int cantidad)
{
	int retorno = -1;
	int id[]={1,5,6,7,8};
	char nombre[][25]={"Juan","Pedro","Maria","Abraham","Eva"};
	char apellido[][25]={"Gomez","Perez","Lopez","Rodriguez","Peron"};

	int i;
	for(i=0;i<5;i++)
	{
		aEmpleado[i].status = STATUS_NOT_EMPTY;
		aEmpleado[i].idEmpleado = id[i];
		strncpy(aEmpleado[i].nombre,nombre[i],25);
		strncpy(aEmpleado[i].apellido,apellido[i],25);
		retorno = 0;
	}
	return retorno;
}

int imprimirArrayEmpleados(struct sEmpleado aEmpleado, int cantidad){
	int i;
	int retorno = -1;
	if(aEmpleado != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			if(aEmpleado[i].status == STATUS_NOT_EMPTY)
			{
				printf("-ID %d - Nombre: %s - Apellido: %s \n",aEmpleado[i].idEmpleado,aEmpleado[i].nombre,aEmpleado[i].apellido);
			}

		}
	}
	return retorno;
}
/**
 *
*/

int initLugarLibreEmpleado(struct sEmpleado aEmpleado, int cantidad)
{
	int i;//variable de control
	int retorno = -1;
	if(aEmpleado != NULL && cantidad > 0)
	{

		for(i=0;i<cantidad;i++)
		{
			aEmpleado[i].status = STATUS_EMPTY;

		}
		retorno = 0;
	}
	return retorno;
}

int buscarLugarLibreEmpleado(struct sEmpleado aEmpleado, int cantidad)
{
	int index = -1;
	int i;
	if(aEmpleado != NULL && cantidad > 0)
	{

		for(i=0;i<cantidad;i++)
		{
			if(aEmpleado[i].status == STATUS_EMPTY)
			{
				index = i;
				break;
			}
		}

	}
	return index;
}

int altaEmpleadoPorId(struct sEmpleado aEmpleado, int cantidad,int id)
{
	int retorno = -1;
	int i = 0;
	if(aEmpleado != NULL && cantidad > 0)
	{

		i = buscarLugarLibreEmpleado(aEmpleado,cantidad);
		if(i>=0)
		{
			empleado.status = STATUS_NOT_EMPTY;
			aEmpleado[i]=empleado;
			retorno = 0;
		}
		/*else
		{
			printf("No hay lugar disponible");
		}*/

	}
	return retorno;
}

int bajaEmpleadoPorId(struct sEmpleado aEmpleado, int cantidad,int id)//es igual que modificacion
{
	/*mostrar los empleados
	 * llama a buscar por id
	 * si existe,muestro y pregunto si estas seguro, ahi si cambio el estado
	 * si no existe, digo el retorno
	 */

	int retorno = -1;
	if(aEmpleado != NULL && cantidad > 0)
	{

	}
	return retorno;
}

/*int buscarEmpleadoPorId(struct sEmpleado aEmpleado, int cantidad,int id)
{
	int retorno = -1;
	int i;
	if(aEmpleado != NULL && cantidad >0)
	{
		for(i=0;i<cantidad;i++)
		{
		}
	}
	return retorno;
}*/
