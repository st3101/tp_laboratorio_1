#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int initEmployees(eEmployee array[],int limite)
{
    int i;


      for(i=0;i<limite;i++)
    {
        array[i].isEmpty=-1;
    }
    return 0;
}
int addEmployees(eEmployee array[],int limite)
{
    int i;
    float auxSa;
    int auxSe;
    int funciono;

    for(i=0;i<limite;i++)
    {
        if(array[i].isEmpty==-1)
        {
            printf("Ingrese el nombre: ");
            gets(array[i].name);
            funciono=esSoloLetras(array[i].name);
            while(funciono==0)
            {
                printf("Error ingrese solo letras, Ingrese el nombre: ");
                gets(array[i].name);
                funciono=esSoloLetras(array[i].name);
            }

            printf("Ingrese el apellido: ");
            gets(array[i].lastName);
            funciono=esSoloLetras(array[i].lastName);
            while(funciono==0)
            {
                printf("Error ingrese solo letras, Ingrese el apellido: ");
                gets(array[i].lastName);
                funciono=esSoloLetras(array[i].lastName);
            }
            printf("Ingrese el salario: ");
            scanf("%f",&auxSa);
            printf("Ingrese el sector: ");
            scanf("%d",&auxSe);
            array[i].id=i;
            array[i].salary=auxSa;
            array[i].sector=auxSe;
            array[i].isEmpty=1;
            break;
        }
    }
    return 0;
}
int findEmployeeById(eEmployee array[],int limite,int*aux)
{
    //agregar funcion mostrar
    int i;
    int parametro;


    printf("Ingrese el ID: ");
    scanf("%d",&parametro);

    for(i=0;i<limite;i++)
    {
        if(array[i].id==parametro)
        {
            *aux = parametro;
        }

    }
return 0;
}

int editEmplotee(eEmployee array[],int*aux)
{


    int i=*aux;
    int auxInt;
    float auxFloat;
    int opcion;
    printf("Modificar\n1)Nombre\n2)Apellido\n3)Salario\n4)Sector\n\nOpcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    fflush(stdin);

    switch(opcion)
    {
    case 1:
        printf("Ingrese el nuevo nombre: ");
        gets(array[i].name);
        break;
    case 2:
        printf("Ingrese el nuevo apellido: ");
        gets(array[i].lastName);
        break;
    case 3:
        printf("Ingrese el nuevo salario: ");
        scanf("%f",&auxFloat);
        array[i].salary=auxFloat;
        break;
    case 4:
        printf("Ingrese el nuevo sector: ");
        scanf("%d",&auxInt);
        array[i].sector=auxInt;
        break;
    default:
        printf("opcion invalida, saliste.");
        system("pause");
        break;
        }
        return 0;
    }
    int printEmployees(eEmployee array[],int limite)
    {
        int i;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                printf("ID: %d Nombre: %s Apellido: %s Salario: $%.2f Sector: %d\n",array[i].id,array[i].name,array[i].lastName,array[i].salary,array[i].sector);
            }
        }
        return 0;
    }
    int removeEmployee(eEmployee array[],int limite,int*aux)
    {
        int parametro =*aux;
        int i;
        for(i=0;i<limite;i++)
        {
            if(array[i].id==parametro)
            {
                array[i].isEmpty=-1;
            }
        }
        return 0;
    }
int informeEmpoyee(eEmployee array[],int limite)
{

    int i;
    int j;
    int bufferId;
    char bufferName[51];
    char bufferLastName[51];
    float bufferSalary;
    int bufferSector;
    int bufferIsEmpty;
    int flag=0;

    if(array!=NULL && limite>=0)
    {
        for (i = 1; i < limite; i++)
        {
            strcpy(bufferName,array[i].name);
            strcpy(bufferLastName,array[i].lastName);
            bufferId=array[i].id;
            bufferSalary=array[i].salary;
            bufferSector=array[i].sector;
            bufferIsEmpty=array[i].isEmpty;




            j = i - 1;
            while ((j >= 0) && strcmp(bufferLastName,array[j].lastName)<0)
            {


                strcpy(array[j + 1].name,array[j].name);
                strcpy(array[j + 1].lastName,array[j].lastName);
                array[j + 1].id=array[j].id;
                array[j + 1].isEmpty=array[j].isEmpty;
                array[j + 1].salary=array[j].salary;
                array[j + 1].sector=array[j].sector;
                j--;
            }
            strcpy(array[j + 1].name,bufferName);
            strcpy(array[j + 1].lastName,bufferLastName);
            array[j + 1].id=bufferId;
            array[j + 1].isEmpty=bufferIsEmpty;
            array[j + 1].salary=bufferSalary;
            array[j + 1].sector=bufferSector;

           flag=1;
        }
    }
    if(flag==0)
    {
        if(array!=NULL && limite>=0)
    {
        for (i = 1; i < limite; i++)
        {
            strcpy(bufferName,array[i].name);
            strcpy(bufferLastName,array[i].lastName);
            bufferId=array[i].id;
            bufferSalary=array[i].salary;
            bufferSector=array[i].sector;
            bufferIsEmpty=array[i].isEmpty;




            j = i - 1;
            while ((j >= 0) && (bufferSector<=array[j].sector))
            {


                strcpy(array[j + 1].name,array[j].name);
                strcpy(array[j + 1].lastName,array[j].lastName);
                array[j + 1].id=array[j].id;
                array[j + 1].isEmpty=array[j].isEmpty;
                array[j + 1].salary=array[j].salary;
                array[j + 1].sector=array[j].sector;
                j--;
            }
            strcpy(array[j + 1].name,bufferName);
            strcpy(array[j + 1].lastName,bufferLastName);
            array[j + 1].id=bufferId;
            array[j + 1].isEmpty=bufferIsEmpty;
            array[j + 1].salary=bufferSalary;
            array[j + 1].sector=bufferSector;

           flag=1;
        }
    }

}
 return 0;
}
int promedioSalary(eEmployee array[],int limite)
{
    int i;
    float acumulador = 0.00;
    float promedio;
    int interaciones=0;
    int interacionesSupPromedio=0;
        for(i=0;i<limite;i++)
    {
        if(array[i].isEmpty==1)
            acumulador=acumulador+array[i].salary;
            interaciones++;
    }

    promedio=acumulador/interaciones;

    for(i=0;i<limite;i++)
    {
        if(array[i].salary>promedio)
        {
            interacionesSupPromedio++;
        }
    }
    printf("El total de salario es: %.2f  El promedio de los salario es: %.2f  Los empleados que superan el promedio son %d \n" ,acumulador,promedio,interacionesSupPromedio);
    return 0;
}
int esSoloLetras(char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        return 0;
        i++;
    }
    return 1;
}
int esAlfaNumerico(char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
        return 0;
        i++;
    }
    return 1;
}

