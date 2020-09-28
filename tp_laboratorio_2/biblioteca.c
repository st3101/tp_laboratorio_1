#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int menu()
{
    int retorno;

    retorno=getInt(1,4,"1)Alta\n2)Modificar\n3)Baja\n4)Informe\n\nOPCION: ");

    return retorno;
}

int getInt(int min,int max,char pregunta[])
{
    int retorno;

    printf("%s",pregunta);
    fflush(stdin);
    scanf("%d",&retorno);


    while(retorno>max || retorno<min)
    {
        printf("Error Ingrese un valor valido: ");
        fflush(stdin);
        scanf("%d",&retorno);

    }

    return retorno;
}

float getFloat(float min,float max,char pregunta[])
{
    float retorno;

    printf("%s",pregunta);
    fflush(stdin);
    scanf("%f",&retorno);


    while(retorno>max || retorno<min)
    {
        printf("Error Ingrese un valor valido: ");
        fflush(stdin);
        scanf("%f",&retorno);

    }

    return retorno;
}

void getString(char respuesta[],char pregunta[])
{
    printf("%s",pregunta);
    fflush(stdin);
    scanf("%[^\n]",respuesta);
}
