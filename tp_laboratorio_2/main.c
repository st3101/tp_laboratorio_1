
///LEONARDI SANTIAGO TOMÁS- TRABAJO PRACTICO N°2-


#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"
#include "biblioteca.h"
#define NUMBER_EMPLOYEES 10


int main()
{
    eEmployee arrayEmployee[NUMBER_EMPLOYEES];
    initEmployees(arrayEmployee,NUMBER_EMPLOYEES);

    int opcion;
    int flag=0;

    do
    {
        opcion=menu();

        switch(opcion)
        {
        case 1:
            if(addEmployees(arrayEmployee,NUMBER_EMPLOYEES))
            {
                flag=1;
            }
            else
            {
                printf("\nNo hay mas espacio\n\n");
            }

            break;
        case 2:
            if(flag==1)
            {
                modifyEmployee(arrayEmployee,NUMBER_EMPLOYEES);
            }
            else
            {
                printf("\nNo se cargo ni un empleado empleados!\n\n");
            }
            break;
        case 3:
            if(flag==1)
            {
                removeEmployee(arrayEmployee,NUMBER_EMPLOYEES);
            }
            else
            {
                printf("\nNo se cargo ni un empleado empleados!\n\n");
            }
            break;
        case 4:
            if(flag==1)
            {

                sortEmployees(arrayEmployee,NUMBER_EMPLOYEES);
                printfEmployees(arrayEmployee,NUMBER_EMPLOYEES);
                average_employees(arrayEmployee,NUMBER_EMPLOYEES);
            }

            else
            {
                printf("\nNo se cargo ni un empleado empleados!\n\n");
            }
            break;
        default:
            printf("\nOpcion Invalida!\n\n");
            }


        system("pause");
        system("cls");





    }while(1==1);

    return 0;
}


