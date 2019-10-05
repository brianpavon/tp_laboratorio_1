#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#define QTY_CARACTERES 50

int getInt(	int *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
	int retorno = -1;
	int buffer;
	if(	resultado != NULL &&
		mensaje != NULL &&
		mensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
		{
			do
			{
				printf("%s",mensaje);
				fflush(stdin);//__fpurge(stdin);
				if(scanf("%d",&buffer)==1)
				{
					if(buffer >= minimo && buffer <= maximo)
					{
						retorno = 1;
						*resultado = buffer;
						break;
					}
				}
				printf("%s",mensajeError);
				reintentos--;
			}while(reintentos >= 0);
		}

		return retorno;
}

int getFloat(	float *resultado,
				char *mensaje,
				char *mensajeError,
				float minimo,
				float maximo,
				int reintentos)
{
	int retorno = -1;
	float buffer;
	if(	resultado != NULL &&
		mensaje != NULL &&
		mensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
		{
			do
			{
				printf("%s",mensaje);
				fflush(stdin);//__fpurge(stdin);
				if(scanf("%f",&buffer)==1)
				{
					if(buffer >= minimo && buffer <= maximo)
					{
						retorno = 1;
						*resultado = buffer;
						break;
					}
				}
				printf("%s",mensajeError);
				reintentos--;
			}while(reintentos >= 0);
		}

		return retorno;
}

int getChar(	char *resultado,
				char *mensaje,
				char *mensajeError,
				char minimo,
				char maximo,
				int reintentos)
{
	int retorno = -1;
	char buffer;
	if(	resultado != NULL &&
		mensaje != NULL &&
		mensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
		{
			do
			{
				printf("%s",mensaje);
				fflush(stdin);//__fpurge(stdin);
				if(scanf("%c",&buffer)==1)
				{
					if(buffer >= minimo && buffer <= maximo)
					{
						retorno = 1;
						*resultado = buffer;
						break;
					}
				}
				printf("%s",mensajeError);
				reintentos--;
			}while(reintentos >= 0);
		}

		return retorno;
}

int initArrayInt(int array[],int limite,int valor )
{
	int i;
	int retorno = -1;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			array[i]=valor+i;
		}

	}
	return retorno;
}

int imprimeArrayInt(int array[],int limite )
{
	int i;
	int retorno = -1;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		printf("\n\n-------\n");
		for(i=0;i<limite;i++)
		{
			printf("%d\n",array[i]);
		}

	}
	return retorno;
}

int getArrayInt(	int array[],
					int limite,
					char *pMensaje,
					char *pMensajeError,
					int minimo,
					int maximo,
					int reintentos)
{
	int i=0;
	int buffer;
	char respuesta = 'n';
	int retorno = -1;
	if(array != NULL && limite > 0)
	{
		do
		{
			if(getInt(	&buffer,
						pMensaje,
						pMensajeError,
						minimo,
						maximo,
						reintentos) == 0)
			{
				array[i] = buffer;
				i++;
				limite--;
			}
			printf("Continuar? (s/n)");
			fflush(stdin);//__fpurge(stdin);
			scanf("%c",&respuesta);
		}while(respuesta == 's' && limite > 0);
		retorno = i;
	}
	return retorno;
}


int maximoArrayInt(int array[],int limite,int *pResultado)
{
	int i;
	int retorno = -1;
	int maximo;
	int posMaximo;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		maximo = array[0];
		posMaximo = 0;
		for(i=1;i<limite;i++)
		{
			if(array[i]>maximo)
			{
				maximo = array[i];
				posMaximo=i;
			}
		}
		*pResultado = posMaximo;
	}
	return retorno;
}
int minimoArrayInt(int array[],int limite,int *pResultado)
{
	int i;
	int retorno = -1;
	int minimo;
	int posMinimo;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		minimo = array[0];
		posMinimo = 0;
		for(i=1;i<limite;i++)
		{
			if(array[i]<minimo)
			{
				minimo = array[i];
				posMinimo=i;
			}
		}
		*pResultado = posMinimo;
	}
	return retorno;
}

int ordenarArrayInt(int array[],int limite )
{
	int i;
	int flagSwap;
	int retorno = -1;
	int bufferInt;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		do
		{
			flagSwap=0;
			for(i=0;i<limite-1;i++)
			{
				if(array[i] > array[i+1])
				{
					flagSwap = 1;
					bufferInt = array[i];
					array[i] = array[i+1];
					array[i+1]=bufferInt;
				}
			}
		}while(flagSwap);
	}
	return retorno;
}


int getString(	char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno = -1;
	char buffer[4096];
	if(	pResultado != NULL &&
		pMensaje != NULL &&
		pMensajeError != NULL &&
		minimo <= maximo &&
		reintentos >= 0)
	{
		do
			{
				printf("%s",pMensaje);
				fflush(stdin);//__fpurge(stdin);
				fgets(buffer,sizeof(buffer),stdin);
				buffer[strlen(buffer)-1] = '\0';
				if(strlen(buffer)>=minimo && strlen(buffer) <= maximo)
				{
					strncpy(pResultado,buffer,maximo+1);
					retorno = 0;
				 	break;
				}
				printf("%s",pMensajeError);
				reintentos--;
			}while(reintentos >= 0);
	}
	return retorno;
}

int imprimirArrayString(char aNombres[][QTY_CARACTERES], int cantidad)
{
	int i;
	int retorno = -1;
	if(aNombres != NULL && cantidad>0)//SE PREGUNTA !=NULL para ver si hay algo en la direccion de memoria,se usa con punteros y array
	{
		retorno = 0;
		for(i=0;i<cantidad;i++){
			printf("Nombre: %s \n",aNombres[i]);
		}
	}
	return retorno;
}

int ordenarArrayString(char aNombres[][QTY_CARACTERES], int cantidad){
	int i;
	int retorno = -1;
	char buffer[QTY_CARACTERES];
	int fSwap;
	if(aNombres != NULL && cantidad>0)
	{
		retorno = 0;
		do
		{
			fSwap = 0;
			for(i=0;i<cantidad-1;i++)
			{
				if(strncmp(aNombres[i],aNombres[i+1],QTY_CARACTERES)>0)
				{
					fSwap = 1;
					strncpy(buffer,aNombres[i],QTY_CARACTERES);
					strncpy(aNombres[i],aNombres[i+1],QTY_CARACTERES);
					strncpy(aNombres[i+1],buffer,QTY_CARACTERES);
				}
			}
		}while(fSwap);
	}
	return retorno;
}
