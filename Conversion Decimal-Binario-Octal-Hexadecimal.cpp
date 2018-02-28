/*********************************/
/*    Conversion Numerica        */
/*Creado por: Herzon Spartan Cruz*/
/*   y Liseth Eliana Osorio R.   */
/*********************************/

/*  Llamado de librerias */
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

main() /*  Funcion Principal */
{
      printf("::CONVERSION NUMERICA::\n");
      printf("\n");
        printf("::BASE DECIMAL A BINARIA, OCTAL O HEXADECIMAL::\n");
        printf("\n");

int Base[16]; /*  Indica el tamaño maximo del vector, o el tamaño maximo q puede alcanzar la conversion */

int Cont=15,Numero,Opcion, NumMaximo; /*  Declaramos la variables Cont: Largo de la cadena, Numero:numero a convertir, Opcion:base a convertir, NumMaximo:maximo numero a convertir; como enteros */

NumMaximo=(int)pow(2,4*(sizeof(int))); /* */
printf("Digite un numero en decimal menor a %d:\n",NumMaximo); /* Solicitud del Valor a convertir, con la restriccion del NumMaximo */
scanf("%d",&Numero); /* Ingreso del Numero a convertir, se guarde en la variable Numero */
printf("\n");
printf("Seleccione la base a la que desea convertir el numero decimal: \n\n0:Base Binaria \n1: Base Octal \nCualquier otro numero:Base Hexadecimal\n");/* Solicitud de ingreso de la base a la cual se desea convertir el Valor Decimal */
scanf("%d",&Opcion); /* Ingreso de la opcion de base a la cual se deesea convertir el valor decimal, se guarda o toma la variable Opcion*/
printf("\n El numero convertido a la base que solicito es:\n");

if(Opcion==0) /* Ciclo para Opcion 0, Convertir a Binario */
{
  do
  {

    Base[Cont]=Numero%2;
    Numero=Numero/2; /* Procedimiento matematico para llevar el Valor a la base solicitada (en este caso base 2, binaria) */
    Cont--; /* Decrementa el contador para reiniciar el ciclo y el procedimiento matematico*/
  }
  while((Cont>=0)&&(Numero>=0)); /* Ciclo para imprimir en orden el valor convertido a la base solicitada,
                                  Mientras el contador sea mayor o igual a cero y el Numero sea mayor o igual a cero,
                                  se haran las operaciones para la impresion de el valor convertiido */
  do
  {
  Cont++; /* Aumenta el contador  */
  if(Base[Cont]<=1)
  printf("%d",Base[Cont]);
  }
  while(Cont<16);
}
  else if(Opcion==1) /* Ciclo para Opcion 1, Convertir a Octal*/
     {
       do
       {
         Base[Cont]=Numero%8;  /* Procedimiento matematico para llevar el Valor a la base solicitada (en este caso base 8, octal)*/
         Numero=Numero/8;
         Cont--; /* Decremento en la variable contador */
       }
       while((Cont>=0)&&(Numero>=0));
       do                       /*Ciclo para imprimir en orden el valor convertido a la base solicitada,
                                  Mientras el contador sea mayor o igual a cero y el Numero sea mayor o igual a cero,
                                  se haran las operaciones para la impresion de el valor convertido*/
       {
       Cont++;
       if(Base[Cont]<=7)
       printf("%d",Base[Cont]);
       }
       while(Cont<16);
     }
     else   /* Ciclo para Cualquier otra Opcion , que indica Convertir a Hexadecimal */
       {
        do
        {
          Base[Cont]=Numero%16; /* Procedimiento matematico para llevar el Valor a la base solicitada (en este caso base 16, hexadecimal)*/
          Numero=Numero/16;
          Cont--; /* Decremeto en la variable contador */
        }
        while((Cont>=0)&&(Numero>=0));
        do
        {
        Cont++;
        if(Base[Cont]<=15) /* Ciclo para imprimir en orden el valor convertido a la base solicitada,
                                  Mientras el contador sea mayor o igual a cero y el Numero sea mayor o igual a cero,
                                  se haran las operaciones para la impresion de el valor convertido*/
        if(Base[Cont]==10)
        {
        printf("A");
        Cont++;
        }
        else if (Base[Cont]==11)
          {
          printf("B");
          Cont++;
          }
          else if(Base[Cont]==12)
             {
             printf("C");
             Cont++;
             }
             else if(Base[Cont]==13)
                {
                printf("D");
                Cont++;
                }
                else if(Base[Cont]==14)
                   {
                   printf("E");
                   Cont++;
                   }
                   else if(Base[Cont]==15)
                      {
                      printf("F");
                      Cont++;
                      }
                      else if (Base[Cont]<=9)
                      printf("%d",Base[Cont]);
     }


     while(Cont<16);

      }

      getch();
}

