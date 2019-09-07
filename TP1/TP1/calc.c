#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/**
*\brief Pide dos numeros y los suma
*\param num1 Es el primer numero recibido
*\param num2 Es el segundo operando recibido
*\return El resultado de la suma
*
*/
float suma(float num1, float num2)
{
    float res;
    res = num1 + num2;
    return res;
}
/**
*\brief Pide dos numeros y los resta
*\param num1 Es el primer numero recibido
*\param num2 Es el segundo operando recibido
*\return El resultado de la resta
*
*/
float resta(float num1,float num2)
{
    float res;
    res = num1 - num2;
    return res;
}
/**
*\brief Pide dos numeros y los multiplica
*\param num1 Es el primer numero recibido
*\param num2 Es el segundo operando recibido
*\return El resultado de la multiplicacion
*
*/
float multiplicar(float num1, float num2)
{
    float res;
    res = num1 * num2;
    return res;
}
/**
*\brief Pide dos numeros y los divide
*\param num1 Es el primer numero recibido
*\param num2 Es el segundo operando recibido
*\return El resultado de la division
*
*/
float dividir(float num1, float num2)
{
    float res;
    if(num2 == 0)
    {
        printf("No se puede dividir por cero, ingrese un valor valido\n");
        system("pause");

    }
     res = num1 / num2;
    return res;
}
/**
*\brief Pide un numero y obtiene el factorial
*\param num Es numero recibido
*\return El resultado del factorial
*
*/
float factorial(float num)
{
    int res=1;
    int i;
    i=num;
    if(num<0)
    {
     printf("No se puede obtener este factorial");
    }
    for(i=1;i<=num;i++)
    {
        res=res*i;

    }
    return res;
}

