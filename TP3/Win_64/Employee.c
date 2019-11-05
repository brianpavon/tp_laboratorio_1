#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"
#include "utn.h"
#include "LinkedList.h"


static int employee_isValidNombre(char* nombre);
static int employee_isValidHorasTrabajadas(int* horasTrabajadas);
static int employee_isValidSueldo(int* sueldo);
static int employee_isValidId(int* id);


Employee* employee_new()
{
	return malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* retorno = NULL;
	Employee* this;
	this = employee_new();
	int id;
	int horasTrabajadas;
	int sueldo;

	id = atoi(idStr);
	horasTrabajadas = atoi(horasTrabajadasStr);
	sueldo = atoi(sueldoStr);

	if(this != NULL)
	{
		if( employee_setId(this,id)==0 &&
			employee_setNombre(this,nombreStr)==0 &&
			employee_setHorasTrabajadas(this,horasTrabajadas)==0 &&
			employee_setSueldo(this,sueldo)==0)
		{
			retorno = this;
		}
		else
		{
			employee_delete(this);
		}
	}
	return retorno;
}

void employee_imprimirEmpleado(Employee* this)
{

    int id;
    char nombre[QTY_CARACTERES];
    int horasTrabajadas;
    int sueldo;

    employee_getId(this,&id);
    employee_getNombre(this,nombre);
    employee_getHorasTrabajadas(this,&horasTrabajadas);
    employee_getSueldo(this,&sueldo);

    printf("%5d %10s %10d %10d\n",id,nombre,horasTrabajadas,sueldo);

}
void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int employee_setId(Employee* this,int id)
{
	int retorno = -1;
	if(this != NULL && employee_isValidId(&id))
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

static int employee_isValidId(int* id)
{
	return 1;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && employee_isValidNombre(nombre))
	{
		strcpy(this->nombre,nombre);
		retorno = 0;
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 0;
	}

	return retorno;
}

static int employee_isValidNombre(char* nombre)
{
	return 1;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && employee_isValidHorasTrabajadas(&horasTrabajadas))
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

static int employee_isValidHorasTrabajadas(int* horasTrabajadas)
{
	return 1;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	if(this != NULL && employee_isValidSueldo(&sueldo))
	{
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}

static int employee_isValidSueldo(int* sueldo)
{
	return 1;
}

int employee_ordenarPorNombre(void* empleadoUno, void* empleadoDos)
{
    Employee* empUno;
    Employee* empDos;

    empUno = (Employee*)empleadoUno;
    empDos = (Employee*)empleadoDos;
    return  strcmp(empUno->nombre,empDos->nombre);

}

int employee_ordenarPorHoras(void* empleadoUno, void* empleadoDos)
{
    int retorno = -1;
    Employee* empUno;
    Employee* empDos;

    empUno = (Employee*)empleadoUno;
    empDos = (Employee*)empleadoDos;
    if(empUno->horasTrabajadas < empDos->horasTrabajadas)
    {
        retorno = 1;
    }
    else if(empUno->horasTrabajadas == empDos->horasTrabajadas)
    {
        retorno = 0;
    }
    return retorno;
}

int employee_ordenarPorSueldo(void* empleadoUno, void* empleadoDos)
{
    int retorno = -1;
    Employee* empUno;
    Employee* empDos;

    empUno = (Employee*)empleadoUno;
    empDos = (Employee*)empleadoDos;
    if(empUno->sueldo < empDos->sueldo)
    {
        retorno = 1;
    }
    else if(empUno->sueldo == empDos->sueldo)
    {
        retorno = 0;
    }
    return retorno;

}

void employee_menuModificacion(LinkedList* pArrayListEmployee)
{
    int opcion;
    int index;
    Employee* auxEmpleado;


    if(pArrayListEmployee != NULL)
    {
            printf("--------------INGRESO AL MENU DE MODIFICACION DE DATOS--------------\n\n");
            system("pause");
            index = employee_buscarPorId(pArrayListEmployee);
            auxEmpleado = ll_get(pArrayListEmployee,index);
            system("pause");
            employee_imprimirEmpleado(auxEmpleado);
            printf(  "1-Modificar el nombre\n"
                     "2-Modificar las horas trabajadas\n"
                     "3-Modificar el sueldo\n"
                     "4-Salir\n");

            getInt(&opcion,"Ingrese la opcion a modificar:\n","ERROR OPCION INVALIDA\n",0,4,2);
            do
            {
                switch(opcion)
                {
                case 1:
                    employee_modificarNombre(auxEmpleado);
                    break;
                case 2:
                    employee_modificarHorasTrabajadas(auxEmpleado);
                    break;
                case 3:
                    employee_modificarSueldo(auxEmpleado);
                    break;
                }

            }while(opcion != 4);

    }

}



int employee_modificarNombre(Employee* this)
{
	int retorno = -1;
	Employee auxEmpleado;
	char respuesta;

	    getString(auxEmpleado.nombre,"Ingrese el nuevo nombre:\n","INGRESO INVALIDO\n",0,QTY_CARACTERES,2);
	    getChar(&respuesta,"Desea modificar el nombre? Ingrese s para modificar\n","NOMBRE INVALIDO\n",'s','z',2);
	    if(respuesta == 's')
        {
            strncpy(this->nombre,auxEmpleado.nombre,QTY_CARACTERES);
            //employee_setNombre(this,auxEmpleado.nombre);
            printf("Se modifico el nombre correctamente\n");
            retorno = 0;
        }
	return retorno;
}

int employee_modificarSueldo(Employee* this)
{
	int retorno = -1;
	Employee auxEmpleado;
	char respuesta;
	if(this != NULL)
	{
	    getInt(&auxEmpleado.sueldo,"Ingrese el nuevo sueldo:\n","INGRESO INVALIDO\n",0,SUELDO_MAXIMO,2);
	    getChar(&respuesta,"Desea modificar el sueldo? Ingrese s para modificar\n","SUELDO INVALIDO\n",'s','z',2);
	    if(respuesta == 's')
        {
            this->sueldo = auxEmpleado.sueldo;
            printf("Se modifico el sueldo correctamente\n");
            retorno = 0;
        }

	}

	return retorno;
}

int employee_modificarHorasTrabajadas(Employee* this)
{
	int retorno = -1;
	Employee auxEmpleado;
	char respuesta;
	if(this != NULL)
	{
	    getInt(&auxEmpleado.horasTrabajadas,"Ingrese las nuevas horas:\n","INGRESO INVALIDO\n",0,HORA_MAXIMA,2);
	    getChar(&respuesta,"Desea modificar el valor de horas trabajadas? Ingrese s para modificar\n","INGRESO INVALIDO\n",'s','z',2);
	    if(respuesta == 's')
        {
            this->horasTrabajadas = auxEmpleado.horasTrabajadas;
            printf("Se actualizaron las horas trabajadas\n");
            retorno = 0;
        }

	}

	return retorno;
}

int employee_buscarPorId(LinkedList* pAarrayEmployeeList)
{
    int retorno = -1;
    int id;
    int i;
    Employee* auxEmpleado;

    employee_imprimirTodosLosEmpleados(pAarrayEmployeeList);
    getInt(&id,"Indique el ID que desea modificar\n","ID INVALIDO",0,ID_MAXIMO,2);

    for(i=0; i<ll_len(pAarrayEmployeeList); i++)
    {
        auxEmpleado = ll_get(pAarrayEmployeeList,i);
        if(auxEmpleado->id == id)
        {
            retorno = i;
        }
    }

    return retorno;
}

int employee_imprimirTodosLosEmpleados(LinkedList* pArrayListEmployee)
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

