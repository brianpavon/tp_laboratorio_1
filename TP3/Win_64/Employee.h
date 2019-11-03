#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "utn.h"
#include "LinkedList.h"
#define HORA_MAXIMA 250
#define SUELDO_MAXIMO 100000
#define ID_MAXIMO 10000
typedef struct
{
    int id;
    char nombre[50];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

void employee_imprimirEmpleado(Employee* this);
int employee_ordenarPorNombre(void* empleadoUno, void* empleadoDos);
int employee_ordenarPorHoras(void* empleadoUno, void* empleadoDos);
int employee_ordenarPorSueldo(void* empleadoUno, void* empleadoDos);
int employee_imprimirTodosLosEmpleados(LinkedList* pArrayListEmployee);
int employee_buscarPorId(LinkedList* pAarrayEmployeeList);
void employee_menuModificacion(LinkedList* pAarrayEmployeeList);
int employee_modificarNombre(Employee* this);
int employee_modificarSueldo(Employee* this);
int employee_modificarHorasTrabajadas(Employee* this);

#endif // employee_H_INCLUDED
