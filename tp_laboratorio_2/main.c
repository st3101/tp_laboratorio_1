
///LEONARDI SANTIAGO TOMÁS- TRABAJO PRACTICO N°2-


#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"
#include "biblioteca.h"
#define NUMBER_EMPLOYEES 1000



int main()
{
    eEmployee anEmployee[NUMBER_EMPLOYEES];
    initEmployees(anEmployee,NUMBER_EMPLOYEES);

    int opcion;
    int flag=0;


    do
    {
        opcion=menu();

        switch(opcion)
        {
        case 1:
            flag=addEmployees(anEmployee,NUMBER_EMPLOYEES);
            break;
        case 2:
            if(flag==1)
            {

            }
            else
            {
                printf("\nNo se cargo ni un empleado empleados!\n\n");
            }
            break;
        case 3:
            if(flag==1)
            {

            }
            else
            {
                printf("\nNo se cargo ni un empleado empleados!\n\n");
            }
            break;
        case 4:
            if(flag==1)
            {
                printfEmployees(anEmployee,NUMBER_EMPLOYEES);
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


