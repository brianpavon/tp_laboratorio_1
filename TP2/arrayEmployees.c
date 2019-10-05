#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utn.h"
#include "arrayEmployees.h"

#define STATUS_VACIO 0
#define STATUS_OCUPADO 1
#define cantEmp_EMPLEADOS 1000
#define cantEmp_SECTORES 3

int initEmployees(sEmpleado *empleado,int cantEmp)
{
    int i;//variable de control
	int retorno = -1;
	if(empleado != NULL && cantEmp > 0)
	{

		for(i=0;i<cantEmp;i++)
		{
			empleado[i].status = STATUS_VACIO;

		}
		retorno = 0;
	}
	return retorno;
}
int buscarLugarLibre(sEmpleado *empleado,int cantEmp)
{
    int index = -1;
	int i;
	if(empleado != NULL && cantEmp > 0)
	{

		for(i=0;i<cantEmp;i++)
		{
			if(empleado[i].status == STATUS_VACIO)
			{
				index = i;
				break;
			}
		}

	}
	return index;

}

int addEmployees(sEmpleado empleado[],int cantEmp,sSector sector[],int cantSector,int id)
{
    int i;
    int retorno = -1;
    char respuesta;
    sEmpleado auxEmpleado;
    sSector auxSector;
    i=buscarLugarLibre(empleado,cantEmp_EMPLEADOS);

    if(i!=-1)
    {
            auxEmpleado.id = id+1;
            getString(auxEmpleado.name,"Ingrese el nombre del empleado:\n","DATO INCORRECTO\n",0,60,2);
            getString(auxEmpleado.lastName,"Ingrese el apellido del empleado:\n","DATO INCORRECTO\n",0,60,2);
            auxSector = obtenerSector(sector,cantSector,empleado);
            auxEmpleado.sector = auxSector.id;
            getFloat(&auxEmpleado.salario,"Ingrese el salario del empleado: \n","VALOR INCORRECTO\n",0,200000,2);

            printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
            printf("\n\n%3s %20s %20s %20s %20s\n\n","ID","Sector","Nombre","Apellido","Salario");
            mostrarUnEmpleado(auxEmpleado,sector,cantSector);
            printf("\n\n------------------------------------------------------------\n\n");
            getChar(&respuesta,"Confirma el nuevo empleado?Ingrese s para confirmar o n para cancelar\n","El empleado no fue dado de alta\n",'s','z',1);
                if(respuesta == 's')
                {
                    retorno = 0;
                    empleado[i].id = auxEmpleado.id;
                    strncpy(empleado[i].name,auxEmpleado.name,51);
                    strncpy(empleado[i].lastName,auxEmpleado.lastName,51);
                    empleado[i].sector = auxSector.id;
                    empleado[i].salario = auxEmpleado.salario;
                    empleado[i].status = STATUS_OCUPADO;
                }

        else
        {
            printf("No hay lugar disponible\n");
        }



    }
    return retorno;

}

sSector obtenerSector(sSector sector[], int cantSec, sEmpleado empleado[])
{
    int i;
    int sectors;
    sSector sectorRetorno;
    sectorRetorno.id = -1;

    do
    {
        for (i=0; i<cantSec; i++)
        {
            printf("ID %d: %s\n", sector[i].id, sector[i].descripcion);
        }

        getInt(&sectors,"El sector que corresponde al ID: \n","ERROR",0,CANTIDAD_SECTORES,2);

        for (i=0; i<cantSec; i++)
        {
            if (sector[i].id==sectors)
            {
                sectorRetorno = sector[i];
            }
        }

        if (sectorRetorno.id==-1)
        {
            printf("\nEl sector no existe\n\n");
        }
    }

    while(sectorRetorno.id==-1);
    return sectorRetorno;
}

int imprimirTodosLosEmpleados(sEmpleado *empleado, int cantEmp,sSector *sector,int cantSec)
{
	int i;
	int j;
    int retorno = -1;
	if(empleado != NULL && cantEmp>0)
	{
		for(i=0;i<cantSec;i++)
		{
		    printf("**-------------------------------------------------------------------------**\n\n");
		    printf("%s\n",sector[i].descripcion);
		    printf("\n\n%3s %20s %20s %20s %20s\n\n","ID","Sector","Nombre","Apellido","Salario");
		    for(j=0; j<cantEmp; j++)
            {
                if(empleado[j].status == STATUS_OCUPADO)
                {
                    retorno = 0;
                    if(empleado[j].sector == sector[i].id)
                    mostrarUnEmpleado(empleado[j],sector,cantSec);
                }

            }
		}
		printf("**-------------------------------------------------------------------------**\n\n");
	}
    return retorno;
}
int imprimirEmpleados(sEmpleado *empleado, int cantEmp)
{
	int j;
	int retorno = -1;
	if(empleado != NULL && cantEmp>0)
	{

		    printf("**-------------------------------------------------------------------------**\n\n");
		    printf("\n\n%3s %20s %20s %20s %20s\n\n","ID","Sector","Nombre","Apellido","Salario");
		    for(j=0; j<cantEmp; j++)
            {
                if(empleado[j].status == STATUS_OCUPADO)
                {
                    retorno = 0;
                    printf("\n\n%3d %20d %20s %20s %20.2f\n\n",empleado[j].id,empleado[j].sector,empleado[j].name,empleado[j].lastName,empleado[j].salario);
                }

            }

		printf("**-------------------------------------------------------------------------**\n\n");
	}
    return retorno;
}

int mostrarUnEmpleado(sEmpleado unEmpleado,sSector sector[], int cantSec)
{
    char descripcionSector[51];
    int i;
    int retorno = -1;
    for(i=0; i<cantSec; i++)
    {
        if(unEmpleado.sector==sector[i].id)
        {
            retorno=0;
            strncpy(descripcionSector, sector[i].descripcion,51);
            break;
        }
    }
    printf("%3d %20s %20s %20s %20.2f\n", unEmpleado.id, descripcionSector, unEmpleado.name, unEmpleado.lastName, unEmpleado.salario);

	return retorno;

}
int buscarEmpleadPorId(sEmpleado *empleado, int cantEmp, sSector *sector, int cantSec)
{
	int retorno = -1;
	int i;
	int id;
	if(empleado != NULL && cantEmp >0)
	{
        imprimirTodosLosEmpleados(empleado,cantEmp,sector,cantSec);
        getInt(&id,"Ingrese el ID que desea buscar\n","El ID no existe\n",0,1000,1);

		for(i=0;i<cantEmp;i++)
		{
			if(empleado[i].status == STATUS_OCUPADO)
			{
				if(empleado[i].id == id)
				{
					retorno = i; //devuelvo la posicion
					break;
				}

			}

		}
	}
	return retorno;
}

void menuModificacionEmpleados(sEmpleado *empleado, int cantEmp, sSector *sector, int cantSec)
{
    int opcion;
    int i;
    char rta;
    sEmpleado auxEmpleado;
    sSector auxSector;

    i = buscarEmpleadPorId(empleado, cantEmp, sector, cantSec);
    if(i != -1)
    {
        do
        {
            system("pause");
            system("cls");
            printf("\n\n\n******---MENU DE MODIFICACION DE EMPLEADOS******---\n\n\n");
            imprimirTodosLosEmpleados(empleado, cantEmp, sector, cantSec);
            printf("1-Modificar el nombre\n2-Modificar el apellido\n3-Modificar el sector\n4-Modificar el salario\n5-Volver al menu anterior\n");
            getInt(&opcion,"Ingrese el dato a modificar\n","No es una opción válida",1,5,2);
            switch(opcion)
            {
                case 1:
                    system("cls");
                    getString(auxEmpleado.name,"Ingrese el nuevo nombre del empleado:\n","DATO INCORRECTO\n",0,60,2);
                    getChar(&rta,"El nombre se modificara. Ingrese s para continuar...\n","El nombre no se modifica",'s','z',2);
                    if(rta == 's')
                    {
                        strncpy(empleado[i].name,auxEmpleado.name,51);
                    }
                    break;
                case 2:
                    system("cls");
                    getString(auxEmpleado.lastName,"Ingrese el nuevo apellido del empleado:\n","DATO INCORRECTO\n",0,60,2);
                    getChar(&rta,"El apellidp se modificara. Ingrese s para continuar...\n","El apellido no se modifica",'s','z',2);
                    if(rta == 's')
                    {
                        strncpy(empleado[i].lastName,auxEmpleado.lastName,51);
                    }
                    break;
                case 3:
                    system("cls");
                    auxSector = obtenerSector(sector,cantSec,empleado);
                    auxEmpleado.sector = auxSector.id;
                    getChar(&rta,"El sector se modificara. Ingrese s para continuar...\n","El sector no se modifica",'s','z',2);
                    if(rta == 's')
                    {
                        empleado[i].sector = auxSector.id;
                    }
                    break;
                case 4:
                    system("cls");
                    getFloat(&auxEmpleado.salario,"Ingrese el nuevo salario del empleado: \n","VALOR INCORRECTO\n",0,200000,2);
                    getChar(&rta,"El salario se modificara. Ingrese s para continuar...\n","El salario no se modifica",'s','z',2);
                    if(rta == 's')
                    {
                        empleado[i].salario = auxEmpleado.salario;
                    }
                    break;
            }

        }while(opcion != 5);
    }
}

int bajaEmpleadoPorId(sEmpleado *empleado, int cantEmp, sSector *sector, int cantSec)
{
    int retorno = -1;
    int i;
    char rta;

    system("cls");
    printf("Utilice el ID para dar la baja de empleado\n\n");
    i = buscarEmpleadPorId(empleado, cantEmp, sector, cantSec);
    if(empleado[i].status == STATUS_OCUPADO && i != -1)
    {
        getChar(&rta,"Esta seguro que desea borrar el empleado? Ingrese s para continuar o n para cancelar\n","No se dio de baja\n",'s','z',2);
        if(rta == 's')
        {
            empleado[i].status = STATUS_VACIO;
            printf("El empleado %s %s fue dado de baja\n",empleado[i].name,empleado[i].lastName);
        }

    }
    else
        {
            printf("El ID no corresponde a un empleado activo\n");
        }


    return retorno;
}

int ordenarEmpleados(sEmpleado *empleado,int cantEmp)
{
	int i;
	int retorno = -1;
	sEmpleado auxEmpleado;
	int fSwap;
	if(empleado != NULL && cantEmp>0)
	{
		retorno = 0;
		do
		{
			fSwap = 0;
			for(i=0;i<cantEmp-1;i++)
			{
				if(strncmp(empleado[i].name,empleado[i+1].name,51)>0)
				{
					fSwap = 1;
					auxEmpleado = empleado[i];
					empleado[i]= empleado[i+1];
					empleado[i+1]= auxEmpleado;
				}

			}
		}while(fSwap);
	}
	return retorno;
}

float totalSalariosEmpleados(sEmpleado *empleado, int cantEmp)
{
    int i;
    float totalSalarios = 0;
    for(i=0 ; i<cantEmp ; i++)
    {
        if(empleado[i].status == STATUS_OCUPADO)
        {
            totalSalarios+=empleado[i].salario;
        }
    }
    printf("La suma total de los salarios es: %.2f\n",totalSalarios);
    return totalSalarios;
}
 void salarioPromedioEmpleados(sEmpleado *empleado,int cantEmp)
 {
   float salarioTotal;
   float salarioPromedio;
   int i;
   salarioTotal = totalSalariosEmpleados(empleado,cantEmp);
   salarioPromedio = salarioTotal / cantEmp;

   printf("\n\nEl salario promedio es %.2f: \n\n",salarioPromedio);
   printf("Los empleados con el salario mas alto al promedio son: \n\n");
   for(i=0 ; i<cantEmp; i++)
   {
       if(empleado[i].salario>salarioPromedio && empleado[i].status == STATUS_OCUPADO)
       {
           printf("%s %s\n\n",empleado[i].name,empleado[i].lastName);
       }
   }

 }

 void menuReportes(sEmpleado *empleado, int cantEmp, sSector *sector, int cantSec)
 {
     int opcion;
     system("pause");
     system("cls");
     do
     {
         printf("*****MENU DE REPORTES*****\n");
         getInt(&opcion,"Ingrese la opcion deseada:\n\n1-Ordenar empleados\n2-Total y promedio de los salarios y cuantos lo superan\n3-Volver al menu anterior\n","Opcion Invalida",1,4,2);
         switch(opcion)
         {
            case 1:
                system("cls");
                ordenarEmpleados(empleado, cantEmp);
                imprimirTodosLosEmpleados(empleado, cantEmp, sector, cantSec);
                break;
            case 2:
                system("cls");
                salarioPromedioEmpleados(empleado,cantEmp);
                break;
         }
     }while(opcion != 3);
 }
