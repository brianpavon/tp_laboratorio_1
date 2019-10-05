#define CANTIDAD_EMPLEADOS 1000
#define CANTIDAD_SECTORES 3
#define VACIO 0
#define OCUPADO 1

typedef struct
{
    int id;
    int status;
    char name[51];
    char lastName[51];
    int sector;
    float salario;
}sEmpleado;

typedef struct
{
    int id;
    char descripcion[50];
}sSector;

int initEmployees(sEmpleado *empleado,int cantEmp);
int buscarLugarLibre(sEmpleado *empleado,int cantEmp);
sSector obtenerSector(sSector sector[], int cantSec, sEmpleado empleado[]);
int addEmployees(sEmpleado empleado[],int cantEmp,sSector sector[],int cantSector,int id);
int mostrarUnEmpleado(sEmpleado unEmpleado,sSector sector[], int cantSec);
int imprimirTodosLosEmpleados(sEmpleado *empleado, int cantEmp,sSector *sector,int cantSec);
int imprimirEmpleados(sEmpleado *empleado, int cantEmp);
int buscarEmpleadPorId(sEmpleado *empleado, int cantEmp, sSector *sector, int cantSec);
void menuModificacionEmpleados(sEmpleado *empleado, int cantEmp, sSector *sector, int cantSec);
int bajaEmpleadoPorId(sEmpleado *empleado, int cantEmp, sSector *sector, int cantSec);
int ordenarEmpleados(sEmpleado *empleado,int cantEmp);
float totalSalariosEmpleados(sEmpleado *empleado, int cantEmp);
void salarioPromedioEmpleados(sEmpleado *empleado,int cantEmp);
void menuReportes(sEmpleado *empleado, int cantEmp, sSector *sector, int cantSec);
