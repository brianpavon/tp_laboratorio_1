#define QTY_NOMBRES 10
#define QTY_CARACTERES 50

#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1


struct sEmpleado
{
	int idEmpleado;
	int status;
	//***************
	char nombre[50];
	char apellido[50];
};
int initLugarLibreEmpleado(struct sEmpleado aEmpleado, int cantidad);

int imprimirArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad);
int ordenarArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad);

int buscarLugarLibreEmpleado(struct sEmpleado aEmpleado, int cantidad);
int buscarEmpleadoPorId(struct sEmpleado aEmpleado, int cantidad,int id);
int bajaEmpleadoPorId(struct sEmpleado aEmpleado, int cantidad,int id);
int modificarEmpleadoPorId(struct sEmpleado aEmpleado, int cantidad,int id);
int altaEmpleadoPorId(struct sEmpleado aEmpleado, int cantidad,int id);
int altaForzadaEmpleados(struct sEmpleado aEmpleado, int cantidad);
