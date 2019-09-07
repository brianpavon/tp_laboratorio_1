#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "calc.h"

int main()
{
    float num1=0;
	float num2=0;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicar;
	float resultadoDividir;
	float resultadoFact1;
	float resultadoFact2;

	int flag = 0;
	int flag1 = 0;
	int flag2 = 0;

	char salir;
	char opcion;

    do
    {
            system("cls");
            printf("-----Menu de Opciones----- \n\n");
            printf("a-Ingresar primer operando(A=%.2f) \n",num1);
            printf("b-Ingresar segundo operando(B=%.2f) \n",num2);
            printf("c-Calcular todas las operaciones\n");
            printf("--- Sumar\n");
            printf("--- Restar\n");
            printf("--- Multiplicar\n");
            printf("--- Dividir\n");
            printf("--- Factorial\n");
            printf("d-Informar los resultados: \n");
            printf("e- Salir\n\n");
            printf("Indique opcion: ");
            fflush(stdin);
            opcion = getchar();
        switch(opcion)
        {
        case 'a':
            system("cls");
            printf("a-Ingresar primer operando: \n");
            scanf("%f",&num1);
            flag = 1;
            break;
        case 'b':
            system("cls");
            printf("b-Ingresar segundo operando: \n");
            scanf("%f",&num2);
            flag1 = 1;
            break;
        case 'c':
            if(flag == 1 && flag1 == 1)
            {
                resultadoSuma = suma(num1,num2);
                resultadoResta = resta(num1,num2);
                resultadoMultiplicar = multiplicar(num1,num2);
                resultadoDividir = dividir(num1,num2);
                resultadoFact1 = factorial(num1);
                resultadoFact2 = factorial(num2);
                flag2 = 1;
                break;
            }
            else
            {
                system("cls");
                printf("No se puede realizar esta operacion,porque no ingreso los dos valores\n");
                system("pause");
                break;
            }
        case 'd':
            system("cls");
            if(flag2 == 1)
            {
                printf("El resultado de %.2f+%.2f es: %.2f\n",num1,num2,resultadoSuma);
                printf("El resultado de %.2f-%.2f es: %.2f\n",num1,num2,resultadoResta);
                printf("El resultado de %.2f*%.2f es: %.2f\n",num1,num2,resultadoMultiplicar);
                printf("El resultado de %.2f/%.2f es: %.2f\n",num1,num2,resultadoDividir);
                printf("El factorial de %.2f es: %.2f y El factorial de %.2f es: %.2f\n",num1,resultadoFact1,num2,resultadoFact2);
                system("pause");
                num1=0;
                num2=0;
                flag = 0;
                flag1 = 0;
                flag2 = 0;
                break;
            }
            else
            {
                system("cls");
                printf("No se puede realizar esta operacion,porque no ingreso los dos valores\n");
                system("pause");
                break;
            }
        case 'e':
            system("cls");
            salir = 's';
            break;
        default:
            printf("Opcion invalida\n\n");
            system("pause");
            break;
        }
    }while(salir != 's');
    return 0;
}
