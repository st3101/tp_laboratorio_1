#include "ArrayEmployees.h"
#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <limits.h>

int initEmployees(eEmployee list[], int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        list[i].isEmpty=0;
    }

    return 0;
}

int addEmployees(eEmployee list[],int len)
{
    int i;
    int retorno=0;

    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==0)
        {
            getString(list[i].name,"Ingrese un nombre: ");
            getString(list[i].lastName,"Ingrese un apellido: ");
            list[i].salary=getFloat(0,INT_MAX,"Ingrese el sueldo: ");
            list[i].sector=getInt(0,INT_MAX,"Ingrese el sector (numeros): ");
            list[i].id=i+1000;
            list[i].isEmpty=1;

            retorno=1;
            break;
        }

    }

    return retorno;
}

void printAnEmployees(eEmployee list)
{
    printf("\n%s %s %s %s %s","ID","SECTOR","SALARIO","NOMBRE","APELLIDO\n");
    printf("%d %d %.2f %s %s\n",list.id,list.sector,list.salary,list.name,list.lastName);
}
int printfEmployees(eEmployee list[],int len)
{
    int i;
    int retorno=0;

    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==1)
        {
            printAnEmployees(list[i]);
            retorno=1;
        }
    }

    return retorno;
}
