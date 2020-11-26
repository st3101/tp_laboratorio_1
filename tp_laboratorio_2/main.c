#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define CANTIDAD 2

int main()
{
    int opcion;
    int flag=1;
    int aux;
    char continuar='s';

    eEmployee listemployee[CANTIDAD];
    initEmployees(listemployee,CANTIDAD);

    do
    {
        printf(" 1)ALTA \n 2)MODIFICACION \n 3)BAJA \n 4)INFORMAR \n 5)SALIR \n \n OPCION: ");
        scanf("%d",&opcion);
        fflush(stdin);

        switch(opcion)
        {
            case 1:
            printf("ENTRASTE A ALTA\n");
            flag=addEmployees(listemployee,CANTIDAD);

            break;
        case 2:
            if(flag==0)
            {
                printf("ENTRASTE A MODIFICAR\n");
                printEmployees(listemployee,CANTIDAD);
                findEmployeeById(listemployee,CANTIDAD,&aux);
                editEmplotee(listemployee,&aux);
            }
            else
            {
                printf("Error, Ingrese un empleado\n");
            }


            break;
        case 3:
             if(flag==0)
             {
                 printf("ENTRASTE A BAJA\n");
                printEmployees(listemployee,CANTIDAD);
                findEmployeeById(listemployee,CANTIDAD,&aux);
                removeEmployee(listemployee,CANTIDAD,&aux);
             }
             else
             {
                  printf("Error, Ingrese un empleado\n");
             }

            break;
        case 4:
            if(flag==0)
            {
                printf("ENTRASTE A INFORMAR\n");
                informeEmpoyee(listemployee,CANTIDAD);
                printEmployees(listemployee,CANTIDAD);
                promedioSalary(listemployee,CANTIDAD);
            }
            else
            {
                printf("Error, Ingrese un empleado\n");
            }


            break;
        case 5:
            printf("  -SALIENDO-\n");
            continuar='n';

            break;
        default:
            printf("ERROR, Ingrese un opcion valida\n");
            break;
        }

        system("pause");
        system("cls");

    }while(continuar=='s');


}


