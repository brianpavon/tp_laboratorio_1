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
