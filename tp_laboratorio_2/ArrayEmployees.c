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
    printf("%15d%15d%15.2f%15s%14s\n",list.id,list.sector,list.salary,list.name,list.lastName);
}
int printfEmployees(eEmployee list[],int len)
{
    int i;
    int retorno=0;

    printf("\n%15s%15s%15s%15s%15s","ID","SECTOR","SALARIO","NOMBRE","APELLIDO\n");

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
int findEmployeeById(eEmployee list[], int len,int id)
{
    int i;
    int retorno=-1;

    for(i=0;i<len;i++)
    {
        if(list[i].id==id)
        {
            retorno=i;
            break;
        }
    }

    return retorno;
}
void modifyEmployee(eEmployee list[],int len)
{
    int indice;
    int opcion;
    int i;

    printfEmployees(list,len);

    indice=getInt(1000,2001,"\nIngrese el ID que desea modificar: ");

    while(findEmployeeById(list,len,indice)==-1)
    {
        indice=getInt(1000,2000,"\nError, ingrese un ID valido: ");
    }

    i=findEmployeeById(list,len,indice);

    opcion=getInt(1,4,"\nQue desea modificar \n1)Nombre\n2)Apellido\n3)Salario\n4)Sector\n\nOPCION: ");

    switch(opcion)
    {
        case 1:
            getString(list[i].name,"Ingrese el nuevo nombre: ");
            break;
        case 2:
            getString(list[i].lastName,"Ingrese el nuevo apellido: ");
            break;
        case 3:
            list[i].salary=getFloat(0,INT_MAX,"Ingrese el nuevo salario: ");
            break;
        case 4:
            list[i].sector=getInt(0,INT_MAX,"Ingrese el nuevo sector: ");
            break;

    }

}

int removeEmployee(eEmployee list[], int len)
{
    int i;
    int id;

    printfEmployees(list,len);

    id=getInt(1000,2000,"\ningrese el INDICE que desea DAR DE BAJA: ");

     while(findEmployeeById(list,len,id)==-1)
    {
        id=getInt(1000,2000,"ERROR, Ingrese un INDICE valido: ");
    }

    i=findEmployeeById(list,len,id);

    list[i].isEmpty=0;

    return 0;

}
int sortEmployees(eEmployee list[], int len)
{
    int i;
    int j;

    eEmployee auxEmpleado;

    for(i=0;i<len-1;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if((stricmp(list[i].lastName,list[j].lastName)==1)||((list[i].sector>list[j].sector)))
            {
                auxEmpleado = list[i];
                list[i] = list[j];
                list[j] = auxEmpleado;
            }
        }
    }
    return 0;
}
void average_employees(eEmployee list[],int len)
{
    float total=0;
    float pSalary=0;
    int superaPSalaty=0;
    int contador=0;
    int i;

    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==1)
        {
            total+=list[i].salary;
            contador++;
        }
    }

    pSalary=total/contador;

    for(i=0;i<len;i++)
    {
        if(list[i].salary>pSalary)
        {
            superaPSalaty++;
        }
    }

    printf("\n\nEl total de sueldos es: %.2f\nEl promedio de salarios es: %.2f\nLa cantidad de empleados que superar el promedio es: %d\n\n",total,pSalary,superaPSalaty);
}
