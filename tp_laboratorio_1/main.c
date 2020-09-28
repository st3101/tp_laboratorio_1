#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main()
{

    float n1=0;
    float n2=0;
    float rSuma;
    float rResta;
    float rDivision;
    float rMultiplicacion;
    float rFactorialN1;
    float rFactorialN2;
    int continuar=0;
    int opcion;
    int flag1=0;
    int flag2=0;
    int flag3=0;

    do
    {
      printf("------------- Calculadora -------------\n1)Ingrese el primer numero.  (A=%.2f)\n2)Ingrese el segundo numero. (B=%.2f)\n3)Calcular las operaciones.\n4)Informa resultados.\n5)Salir.\n---------------------------------------\nOpcion: ",n1,n2);
      fflush(stdin);
      scanf("%d",&opcion);

      while(opcion !=1 && opcion !=2 && opcion !=3 && opcion !=4 && opcion !=5)
      {
          printf("---------------------------------------\nError, ingrese una opcion valida: ");
          fflush(stdin);
          scanf("%d",&opcion);
      }

      switch(opcion)
      {
      case 1:
        printf("---------------------------------------\nIngrese el primer numero: ");
        scanf("%f",&n1);
        flag1=1;
        break;
      case 2:
        printf("---------------------------------------\nIngrese el segundo numero: ");
        scanf("%f",&n2);
        flag2=1;
        break;
      case 3:
           if(flag1==1 && flag2==1)
            {
                printf("---------------------------------------");
                if (n1<0)
                {
                    printf("\nAVISO: No se puede realizar el factorial de un numero negativo.\n");
                }
                if (n2<0)
                {
                    printf("AVISO: No se puede realizar el factorial o la division de un numero negativo. \n");
                }
                printf("\nSe han realizado los calculos.\n---------------------------------------\n");
                }
                else
                {
                printf("---------------------------------------\nAVISO: No se ha ingresado numero/s.\n---------------------------------------\n");
                system("pause");
                break;
                }
                 rSuma=suma(n1,n2);
                 rResta=resta(n1,n2);
                 rDivision=division(n1,n2);
                 rMultiplicacion=multiplicacion(n1,n2);
                 rFactorialN1=factorialN1(n1);
                 rFactorialN2=factorialN2(n2);
                 flag3=1;
                 system("pause");
                break;
      case 4:
          if(flag3==1)
          {
                 printf("---------------------------------------\nRESULTADOS:\n");
                 printf("El resultado de A+B es: %.2f\n",rSuma);
                 printf("El resultado de A-B es: %.2f\n",rResta);
                 printf("El resultado de A*B es: %.2f\n",rMultiplicacion);
                 if(n2==0)
                 {
                     printf("No se puede dividir por A\n");
                 }
                 else
                 {
                 printf("El resultado de A/B es: %.2f\n",rDivision);
                 }
                 if(n1<0)
                 {
                     printf("No se puede factorial el A\n");
                 }
                 else
                 {
                 printf("El factorial de A es: %.2f\n",rFactorialN1);
                 }

                 if(n2<0)
                 {
                     printf("No se puede factorial el B\n");
                 }
                 else
                 {
                 printf("El factorial de B es: %.2f\n",rFactorialN2);
                 }
                 printf("---------------------------------------\n");
                 }
                 else
                 {
                     printf("---------------------------------------\nError, no se calcularon las operaciones\n---------------------------------------\n");
                 }
                 system("pause");
                 break;
      case 5:
        continuar=1;
      }
      system("cls");

     }while(continuar==0);
      printf("Gracias por usar la calculadora.\n");
      system("pause");
}
