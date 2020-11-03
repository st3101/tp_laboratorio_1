#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include <string.h>


Employee* employee_new()
{
    Employee* pEmpleado;
    pEmpleado = (Employee*) malloc(sizeof(Employee));

    if(pEmpleado == NULL)
    {
        printf("No hay mas lugar");
    }

   return pEmpleado;

}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{

    Employee* pEmpleado;
    pEmpleado = employee_new();

    int auxId;
    int auxHorasTrabajadas;
    int auxSueldo;

    auxId=atoi(idStr);
    auxHorasTrabajadas=atoi(horasTrabajadasStr);
    auxSueldo=atoi(sueldoStr);


    if(pEmpleado != NULL)
    {
        employee_setId(pEmpleado,auxId);
        employee_setHorasTrabajadas(pEmpleado,auxHorasTrabajadas);
        employee_setSueldo(pEmpleado,auxSueldo);
        employee_setNombre(pEmpleado,nombreStr);

    }
    else
    {
        printf("No hay mas lugar");
    }

   return pEmpleado;


}

int employee_setId(Employee* this,int id)
{
    if(this!=NULL)
    {
        this->id=id;
        return 0;
    }

    return -1;
}

int employee_setHorasTrabajadas(Employee* this,int horasTranajadas)
{
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTranajadas;
        return 0;
    }

    return -1;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        return 0;
    }

    return -1;
}

int employee_setNombre(Employee* this,char* nombre)
{
    if(this!=NULL)
    {
        strcpy(this->nombre,nombre);
        return 0;
    }

    return -1;
}

int employee_getId(Employee* this,int* id)
{

    if(this!=NULL && id!=NULL)
    {
        *id = this->id;
        return 0;
    }

    return -1;
}
int employee_getNombre(Employee* this,char* nombre)
{
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        return 0;
    }

    return -1;

}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    if(this!=NULL&&horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        return 0;
    }

    return -1;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    if(this!=NULL&&sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        return 0;
    }

    return -1;
}
int employee_CompareById(void* e1, void* e2)
{
    int numeroUno;
    int numeroDos;
    int retorno = 0;

    Employee* empleado1;
    Employee* empleado2;

    empleado1=(Employee*)e1;
    empleado2=(Employee*)e2;

    employee_getId(empleado1,&numeroUno);
    employee_getId(empleado2,&numeroDos);

    if(numeroUno > numeroDos)
    {
        retorno = 1;
    }
    else if(numeroUno < numeroDos)
    {
        retorno = -1;
    }

    return retorno;
}

int employee_CompareByName(void* e1, void* e2)
{
    char nombre1[50];
    char nombre2[50];

    int retorno=0;

    Employee* pEmpleado1;
    Employee* pEmpleado2;

    pEmpleado1=(Employee*)e1;
    pEmpleado2=(Employee*)e2;

    employee_getNombre(pEmpleado1,nombre1);
    employee_getNombre(pEmpleado2,nombre2);

     if(strcmp(nombre1,nombre2) > 0)
     {
        retorno = 1;
     }
     else if (strcmp(nombre2,nombre1) < 0)
     {
         retorno = -1;
     }

     return retorno;
}

void employee_delete(Employee* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}
