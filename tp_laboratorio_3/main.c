#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

#include "string.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

void mostrarEmpleado(Employee* unEmpleado);

int main()
{
    int opcion;
    int salir=0;
    int bandera=0;

    LinkedList* lista;

    lista = ll_newLinkedList();



    do
    {
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
        printf("3. Alta de empleado\n");
        printf("4. Modificar datos de empleado\n");
        printf("5. Baja de empleado\n");
        printf("6. Listar empleados\n");
        printf("7. Ordenar empleados\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
        printf("10. Salir\n\n");
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
                if(bandera==0)
                {

                    if(controller_loadFromText("data.csv",lista)==0)
                    {
                       printf("Cargo correctamente\n");
                       bandera = 1;
                    }
                    else
                    {
                        printf("No existe el DATA.CSV 404!\n");
                    }
                }
                else
                {
                        printf("ya hay datos cargados \n");
                }
            break;
        case 2:
               if(bandera==0)
                {
                    if(0==controller_loadFromBinary("data.bin",lista))
                    {
                        printf("Cargo correctamente\n");
                        bandera = 1;
                    }
                    else
                    {
                        printf("No existe el DATA.BIN 404!\n");
                    }
                }
                else
                {
                    printf("ya hay datos cargados\n");
                }
            break;
        case 3:
            if(bandera==1)
            {
                controller_addEmployee(lista);

            }
            else
            {
                printf("No se cargo ningun archivo\n ");
            }
            break;
        case 4:
                if(bandera==1)
            {
                controller_editEmployee(lista);
            }
            else
            {
                printf("No se cargo ningun archivo\n ");
            }

            break;
        case 5:
              if(bandera==1)
            {
                controller_removeEmployee(lista);
            }
            else
            {
                printf("No se cargo ningun archivo\n ");
            }
            break;
        case 6:
            if(bandera==1)
            {
                controller_ListEmployee(lista);
            }
            else
            {
                printf("No se cargo ningun archivo\n ");
            }


            break;
        case 7:
             if(bandera==1)
            {
                controller_sortEmployee(lista);
            }
            else
            {
                printf("No se cargo ningun archivo\n ");
            }

            break;
        case 8:
            if(bandera==1)
            {
                controller_saveAsText("data.csv",lista);
            }
            else
            {
                printf("No se cargo ningun archivo\n ");
            }
            break;
        case 9:
            if(bandera==1)
            {
                controller_saveAsBinary("data.bin",lista);
            }
            else
            {
                printf("No se cargo ningun archivo\n ");
            }
            break;

        case 10:

                bandera=controller_liberar(lista);
                salir=1;
                if(bandera==0)
                {
                    printf("Saliste y se libero memoria\n");
                }
                else
                {
                    printf("Salis y no se libero nada en memoria");
                }


            break;

        default:
            printf("Error. ingrese una opcion valida\n");

        }

        system("pause");
        system("cls");

    }
    while(salir==0);
}
