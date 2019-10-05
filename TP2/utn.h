#include <stdio.h>
#include <stdlib.h>

#define QTY_CARACTERES 50

int getInt(	int *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos);

int getFloat(	float *resultado,
				char *mensaje,
				char *mensajeError,
				float minimo,
				float maximo,
				int reintentos);

int getChar(	char *resultado,
				char *mensaje,
				char *mensajeError,
				char minimo,
				char maximo,
				int reintentos);

int initArrayInt(int array[],int limite,int valor );

int imprimeArrayInt(int array[],int limite );

int getArrayInt(	int array[],
					int limite,
					char *pMensaje,
					char *pMensajeError,
					int minimo,
					int maximo,
					int reintentos);

int maximoArrayInt(int array[],int limite,int *pResultado);
int minimoArrayInt(int array[],int limite,int *pResultado);

int ordenarArrayInt(int array[],int limite );

int getString(	char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos);

int imprimirArrayString(char aNombres[][QTY_CARACTERES], int cantidad);
int ordenarArrayString(char aNombres[][QTY_CARACTERES], int cantidad);
