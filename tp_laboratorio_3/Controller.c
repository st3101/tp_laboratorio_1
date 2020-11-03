#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "inPut.h"
int controller_buscarExistenciaId(LinkedList* pArrayListEmployee,char* id)
{
    int i;
    int auxId;
    int len;
    int idInt;

    idInt=atoi(id);

    Employee* pEmpleado;

    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);

        for(i=0; i<len; i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&auxId);

            if(auxId==idInt)
            {
                return 1;
            }
        }
    }

    return 0;

}

int controller_buscarIdLibre(LinkedList* pArrayListEmployee)
{
    int i;
    int auxId;
    int len;
    int bandera=1;
    int retorno=-1;

    Employee* pEmpleado;

    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);

        for(i=0; i<len; i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&auxId);

            if(auxId!=i+1)
            {
                retorno=i+1;

                bandera=0;

                break;
            }
        }

        if(bandera==1)
        {
            retorno=len+1;

        }
    }

    return retorno;

}

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = 1;

    pArchivo=fopen(path,"r");

    if(pArchivo!=NULL)
    {

        parser_EmployeeFromText(pArchivo,pArrayListEmployee);
        retorno = 0;

    }

    fclose(pArchivo);

    return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = 1;

    pArchivo=fopen(path,"rb");

    if(pArchivo!=NULL)
    {
        parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);

        retorno = 0;
    }

    fclose(pArchivo);

    return retorno;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;

    pEmpleado = employee_new();

    char auxSueldo[50];
    char auxHora[50];
    char nombre[50];

    int id;
    int sueldo;
    int hora;

    int retorno=1;

    if(pArrayListEmployee!=NULL&&pEmpleado!=NULL)
    {
        while(!getStringLetras("Ingrese nombre: ",nombre))
        {
            printf("Error, ingrese solo letras, ");
        }

        while(!getStringNumeros("Ingrese sueldo: ",auxSueldo))
        {
            printf("Error, ingrese solo numero, ");
        }
        sueldo=atoi(auxSueldo);

        while(!getStringNumeros("Ingrese horas: ",auxHora))
        {
            printf("Error, ingrese solo numero, ");
        }
        hora=atoi(auxHora);

        id=controller_buscarIdLibre(pArrayListEmployee);

        employee_setId(pEmpleado,id);
        employee_setNombre(pEmpleado,nombre);
        employee_setSueldo(pEmpleado,sueldo);
        employee_setHorasTrabajadas(pEmpleado,hora);


        ll_add(pArrayListEmployee,pEmpleado);
        retorno= 0;
    }

    return retorno;
}
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;

    int i;
    int retorno = -1;

    int auxId;
    char auxNombre[50];
    int auxHoras;
    int auxSueldo;

    if(pArrayListEmployee != NULL)
    {

        printf("%5s%15s%15s%15s\n","ID","NOMBRE","HORAS","SUELDO");
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);

            employee_getId(pEmpleado,&auxId);
            employee_getNombre(pEmpleado,auxNombre);
            employee_getHorasTrabajadas(pEmpleado,&auxHoras);
            employee_getSueldo(pEmpleado,&auxSueldo);



            if(pEmpleado!=NULL)
            {
                printf("%5d%15s%15d%15d\n",auxId,auxNombre,auxHoras,auxSueldo);
                retorno = 0;
            }

        }

    }
    return retorno;
}



int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;
    int opcion;

    char indexChar[50];
    int indexInt;

    int controlEsNumeros;
    int controlIdExistencia;

    char auxNombre[50];
    char auxSueldo[50];
    int auxSueldoInt;
    char auxHoras[50];
    int auxHorasInt;

    int retorono=1;

    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        controlEsNumeros=getStringNumeros("Ingrese el ID del empleado a modificar: ",indexChar);
        controlIdExistencia=controller_buscarExistenciaId(pArrayListEmployee,indexChar);


        while(!controlEsNumeros||!controlIdExistencia)
        {
            controlEsNumeros=getStringNumeros("Error ingrese un ID valido de empleado a modificar: ",indexChar);
            controlIdExistencia=controller_buscarExistenciaId(pArrayListEmployee,indexChar);
        }

        indexInt=atoi(indexChar);
        indexInt=indexInt-1;


        pEmpleado=ll_get(pArrayListEmployee,indexInt);

        printf("1)Nombre\n2)Horas Trabajadas\n3)Sueldo\nIngrese campo a modificar: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            while(!getStringLetras("Ingrese un nuevo nombre: ",auxNombre))
            {
                printf("Error, solo letras, ");
            }
            employee_setNombre(pEmpleado,auxNombre);
            break;
        case 2:
            while(!getStringNumeros("Ingrese nuevas horas de trabajo: ",auxHoras))
            {
                printf("Error, solo numero, ");
            }
            auxHorasInt=atoi(auxHoras);
            employee_setHorasTrabajadas(pEmpleado,auxHorasInt);
            break;
        case 3:
            while(!getStringNumeros("Ingrese nuevas horas de trabajo: ",auxSueldo))
            {
                printf("Error, solo numero, ");
            }
            auxSueldoInt=atoi(auxSueldo);
            employee_setSueldo(pEmpleado,auxSueldoInt);
            break;
        default:
            printf("Ingrese una opcion valida\n");

        }

        retorono=0;
    }

    return retorono;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;

    char indexChar[50];
    int indexInt;

    int controlEsNumeros;
    int controlIdExistencia;

    int retorno=1;

    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        controlEsNumeros=getStringNumeros("Ingrese el ID del empleado a DAR DE BAJA: ",indexChar);
        controlIdExistencia=controller_buscarExistenciaId(pArrayListEmployee,indexChar);


        while(!controlEsNumeros||!controlIdExistencia)
        {
            controlEsNumeros=getStringNumeros("Error ingrese un ID valido de empleado a DAR DE BAJA: ",indexChar);
            controlIdExistencia=controller_buscarExistenciaId(pArrayListEmployee,indexChar);
        }

        indexInt=atoi(indexChar);
        indexInt=indexInt-1;



        printf("Esta seguro que quieres DARLO DE BAJA? \n1)Si\n2)No\nOPCION: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            printf("BORRADO\n");
            ll_remove(pArrayListEmployee,indexInt);
            break;
        case 2:
            printf("No BORRADO");
            break;

        default:
            printf("Ingrese una opcion valida\n");

            retorno=0;
        }
    }
    return retorno;
}



int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int continuar=0;

    int retorno=1;

    if(pArrayListEmployee!=NULL)
    {


        do
        {
            printf("ORDENAR\n1)ID\n2)NOMBRE\n2)SALIR\nIngrese una opcion: ");
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                printf("Trabajando\n");
                if(ll_sort(pArrayListEmployee,employee_CompareById,0)==0)
                {
                    printf("Ordenado exitosamente!\n");
                }
                else
                {
                    printf("Error ordenando!\n");
                }

                break;
            case 2:
                printf("Trabajando\n");
                if(ll_sort(pArrayListEmployee,employee_CompareByName,1)==0)
                {
                    printf("Ordenado exitosamente!\n\n");
                }
                else
                {
                    printf("Error ordenando!\n\n");
                }
                break;
            case 3:
                continuar=1;
                break;
            default:
                printf("Ingrese una opcion valida: ");

                break;
            }
        }
        while(continuar==0);
        retorno=0;
    }
    return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* pEmpleado;

    int len;
    int i;

    int auxId;
    char auxNom[50];
    int auxHora;
    int auxSueldo;

    int retono = 1;

    pArchivo=fopen(path,"w");

    if(pArchivo!=NULL&& pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);

        for(i=0; i<len; i++)
        {
            pEmpleado=ll_get(pArrayListEmployee,i);

            employee_getId(pEmpleado,&auxId);
            employee_getNombre(pEmpleado,auxNom);
            employee_getSueldo(pEmpleado,&auxSueldo);
            employee_getHorasTrabajadas(pEmpleado,&auxHora);


            fprintf(pArchivo,"%d,%s,%d,%d\n",auxId,auxNom,auxHora,auxSueldo);
        }
        retono = 0;
    }
    fclose(pArchivo);

    return retono;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* pEmpleado;

    int len;
    int i;

    int retorno = 1;

    pArchivo=fopen(path,"wb");

    if(pArchivo!=NULL&& pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);

        for(i=0; i<len; i++)
        {
            pEmpleado=ll_get(pArrayListEmployee,i);
            fwrite(pEmpleado,sizeof(Employee),1,pArchivo);
        }
    }
    retorno=0;
    fclose(pArchivo);
    return retorno;
}

int controller_liberar(LinkedList* pArrayListEmployee)
{
    int i;
    int len;
    int retorno= 1;

    Employee* pEmpleado;

    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);

        for(i=0;i<len;i++)
        {
            pEmpleado=ll_get(pArrayListEmployee,i);

            if(pEmpleado!=NULL)
            {
                employee_delete(pEmpleado);
            }
        }

        ll_deleteLinkedList(pArrayListEmployee);
        retorno=0;
    }

    return retorno;
}
