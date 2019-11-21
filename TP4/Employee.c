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

/**
*\brief Solicita memoria para un bloque de estructura la estructura Employee
*\return Retorna la posicion de memoria a la estructura
*/

Employee* employee_new()
{
	return malloc(sizeof(Employee));
}

/**
*\brief Transforma y establece todos los datos de la estructura con los parametros recibidos
*\param char* idStr id del empleado
*\param char* nombreStr nombre del empleado
*\param char* horasTrabajadasStr cantidad de horas trabajadas del empleado
*\param char* sueldoStr sueldo del empleado
* \return Retorna la posicion de memoria a la estructura
*/
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

/**
*\brief imprime un empleado que se encuentra cargado en la estructura Employee
*\param Employee* this puntero a la estructura Employee
*/
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

/**
*\brief libera el espacio de memoria que ocupaba la estructura de Employee
*\param Employee* this puntero a la estructura Employee
*/
void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

/**
*\brief setea un ID a un elemento de la estructura Employee
*\param Employee* this puntero a la estructura Employee
*\param  int id el entero que se establecera como id
*\return retorna 0 si salio OK -1 si fallo
*/

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

/**
*\brief obtiene un ID de un elemento de la estructura Employee
*\param Employee* this puntero a la estructura Employee
*\param  int id el entero al que se le pasara el id obtenido
*\return retorna 0 si salio OK -1 si fallo
*/
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

/**
*\brief Valida que el entero ingresado como id sea numerico
*\param  int id el entero que se validara
*\return retorna 1 si salio OK -1 si fallo
*/
static int employee_isValidId(int* id)
{
     int retorno =-1;
     int i=0;

     if(id != NULL)
     {
        while(id[i] != '\0')
        {
        if(id[i]<'0' || id[i]>'9')
        break;
        i++;
     }
        if(id[i] == '\0')
        retorno = 1;
     }

	return retorno;
}

/**
*\brief carga un nombre a un elemento de la estructura Employee
*\param Employee* this puntero a la estructura Employee
*\param  char* nombre es el string de caracteres que se pasara como nombre
*\return retorna 0 si salio OK -1 si fallo
*/

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

/**
*\brief obtiene un nombre de un elemento de la estructura Employee
*\param Employee* this puntero a la estructura Employee
*\param  char* nombre es el string de caracteres al que se le pasara el nombre obtenido
*\return retorna 0 si salio OK -1 si fallo
*/
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

/**
*\brief valida un nombre de un elemento de la estructura Employee
*\param  char* nombre es el string de caracteres que se le pasara
*\return retorna 1 si salio OK -1 si fallo
*/
static int employee_isValidNombre(char* nombre)
{
	return 1;
}


/**
*\brief setea las horas trabajadas a un elemento de la estructura Employee
*\param Employee* this puntero a la estructura Employee
*\param  int horasTrabajadas el entero que se establecera como horas trabajadas para ese empleado
*\return retorna 0 si salio OK -1 si fallo
*/
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

/**
*\brief obtiene las horas trabajadas de un elemento de la estructura Employee y se las pasa a una variable
*\param Employee* this puntero a la estructura Employee
*\param  int horasTrabajadas el entero al que se le pasaras las horas trabajadas de ese empleado
*\return retorna 0 si salio OK -1 si fallo
*/
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

/**
*\brief valida que las horas trabajadas sean numeros validos
*\param  int horasTrabajadas el entero que se validara
*\return retorna 1 si salio OK -1 si fallo
*/
static int employee_isValidHorasTrabajadas(int* horasTrabajadas)
{
	int retorno =-1;
    int i=0;

     if(horasTrabajadas != NULL)
     {
        while(horasTrabajadas[i] != '\0')
        {
        if(horasTrabajadas[i]<'0' || horasTrabajadas[i]>'9')
        break;
        i++;
     }
        if(horasTrabajadas[i] == '\0')
        retorno = 1;
     }

	return retorno;
}

/**
*\brief carga un sueldo a un elemento de la estructura Employee
*\param Employee* this puntero a la estructura Employee
*\param  int sueldo es el sueldo que se cargara al elemento de la estructura
*\return retorna 0 si salio OK -1 si fallo
*/
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

/**
*\brief obtine un sueldo de un elemento de la estructura Employee
*\param Employee* this puntero a la estructura Employee
*\param  int sueldo es el sueldo al que se le cargara el sueldo del elemento de la estructura
*\return retorna 0 si salio OK -1 si fallo
*/
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

/**
*\brief valida que el sueldo sea un entero valido
*\param  int sueldo es el sueldo es el elemento que se validara
*\return retorna 1 si salio OK -1 si fallo
*/
static int employee_isValidSueldo(int* sueldo)
{
	int retorno =-1;
    int i=0;

     if(sueldo != NULL)
     {
        while(sueldo[i] != '\0')
        {
        if(sueldo[i]<'0' || sueldo[i]>'9')
        break;
        i++;
     }
        if(sueldo[i] == '\0')
        retorno = 1;
     }

	return retorno;
}

/**
*\brief compara los nombres de 2 empleados de la estructura Employee
*\param void* puntero a un empleado de la estructura employee
*\param void* puntero a un segundo empleado de la estructura employee
*\param return retorna 0 si los 2 empleados tienen el mismo nombre
*\param return retorna <0 si el nombre del primer empleado esta antes que el del segundo empleado
*\param return retorna >0 si el nombre del primer empleado esta despues que el del segundo empleado
*/
int employee_ordenarPorNombre(void* empleadoUno, void* empleadoDos)
{
    Employee* empUno;
    Employee* empDos;

    empUno = (Employee*)empleadoUno;
    empDos = (Employee*)empleadoDos;
    return  strcmp(empUno->nombre,empDos->nombre);

}

/**
*\brief compara los nombres de 2 empleados de la estructura Employee
*\param void* puntero a un empleado de la estructura employee
*\param void* puntero a un segundo empleado de la estructura employee
*\param return retorna 0 si los 2 empleados trabajaron las mismas horas
*\param return retorna 1 si el primer empleado trabajo menos horas que el segundo empleado
*\param return retorna -1 si el primer empleado trabajo mas horas que el segundo empleado
*/
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

/**
*\brief compara los nombres de 2 empleados de la estructura Employee
*\param void* puntero a un empleado de la estructura employee
*\param void* puntero a un segundo empleado de la estructura employee
*\param return retorna 0 si los 2 empleados tienen el mismo sueldo
*\param return retorna 1 si el primer empleado tiene un sueldo menor que el segundo empleado
*\param return retorna -1 si el primer empleado tiene un sueldo mayor que el segundo empleado
*/
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

/**
*\brief menu de modificacion de los parametros cargados de un empleado
*\param void* puntero a la lista cargada con la estructura Employee
*\param return void
*/
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

/**
*\brief menu de modificacion del nombre cargado de un empleado
*\param void* puntero a la estructura Employee
*\param return 0 si salio ok, -1 si fallo
*/
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

/**
*\brief menu de modificacion del sueldo cargado de un empleado
*\param void* puntero a la estructura Employee
*\param return 0 si salio ok, -1 si fallo
*/
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

/**
*\brief menu de modificacion de las horas cargadas de un empleado
*\param void* puntero a la estructura Employee
*\param return 0 si salio ok, -1 si fallo
*/
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

/**
*\brief busca un empleado por ID y devuelve su posicion
*\param void* puntero a la estructura Employee
*\param return la posicion del empleado si salio ok, -1 si fallo
*/
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

/**
*\brief imprime todos los elementos cargados en la lista de la estructura Employee
*\param void* puntero a la estructura Employee
*\param return 0 si salio ok, -1 si fallo
*/
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

