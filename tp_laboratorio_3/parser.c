#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pAuxEmpleado;

    char auxId[50];
    char auxNombre[50];
    char auxHorasTrabajadas[50];
    char auxSueldo[50];

    int retorno = -1;

    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);

        while(!feof(pFile))
        {

            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
            pAuxEmpleado = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
            if(pAuxEmpleado != NULL)
            {
                ll_add(pArrayListEmployee, pAuxEmpleado);
                retorno = 0;
            }

            if(feof(pFile))
            {
                break;
            }

        }

    }

    return retorno;

}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;
    int retorno = -1;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            pEmpleado = employee_new();
            fread(pEmpleado,sizeof(Employee),1,pFile);
            if(feof(pFile))
            {
                break;
            }
            ll_add(pArrayListEmployee,pEmpleado);
        }
        retorno = 0;

    }

    return retorno;
}
