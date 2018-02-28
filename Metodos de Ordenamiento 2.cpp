/*           Algoritmos de ordenamiento          */
/*   Programa por el cual se pretende mostrar
  los diferentes tipos de algoritmos ordenamiento
   y comprombar su tiempo de ejecucion
       Por: Liseth Eliana Osorio Rendon          */




#include <stdio.h>
#include <windows.h>
#include <string.h>


void imprimir (int *v, int n)
{
     int i;
     for(i=0;i<n;i++)
       printf("%d ",v[i]);
}

double tiempo_ejecucion(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(b->QuadPart - a->QuadPart) / (double)freq.QuadPart;
}

int burbuja (int *v, int n, double *t_burbuja, int *comp_burbuja, int *inter_burbuja)
{
    int i, j, temp;
    LARGE_INTEGER T1,T2;
    QueryPerformanceCounter(&T1);
    for (i=1; i<n; i++)
         for (j=0 ; j<n - 1; j++)
         {
             (*comp_burbuja)++;
             if (v[j] > v[j+1])
             {
                   (*inter_burbuja)++;
                   temp = v[j];
                   v[j] = v[j+1];
                   v[j+1] = temp;
             }
         }
    QueryPerformanceCounter(&T2);
    *t_burbuja=tiempo_ejecucion(&T1, &T2)*1000;
    printf("\nEl Vector ha sido ordenado por Metodo BURBUJA\n\n");
 imprimir(v, n);
    printf("\n\nEste es el analisis de la funcion:\n\nNro Comparaciones = %d\nNro Intercambios = %d\nTiempo de ejecucion = %.16f milisegundos\n",
               *comp_burbuja, *inter_burbuja, *t_burbuja);
//    printf( "prueba de formatos\n%.16f = con f\n%.16e = con e\n%.16g = con g\n", sec*1000,sec*1000,sec*1000);
}

/* ordenación ascendente de la lista por Shell*/

int shell(int *v1, int n, double *t_shell, int *comp_shell, int *inter_shell)
{
    int i, j, inc, temp;
    LARGE_INTEGER T1,T2;
    QueryPerformanceCounter(&T1);
    for(inc=1; inc<n; inc=inc*3+1);
      while (inc>0)
       {
          for (i=inc; i<n; i++)
          {
               (*comp_shell)++;
                j=i;
                temp=v1[i];
                while ((j>=inc) && (v1[j-inc]>temp))
                {
                    v1[j]=v1[j - inc];
                    j=j-inc;
               (*comp_shell)++;
                (*inter_shell)++;
                }
                v1[j]=temp;

          }
          inc/=2;
       }
    QueryPerformanceCounter(&T2);
    *t_shell=tiempo_ejecucion(&T1, &T2)*1000;
    printf("\nEl Vector ha sido ordenado por Metodo SHELL\n\n");
  imprimir(v1, n);
    printf("\n\nEste es el analisis de la funcion:\n\nNro Comparaciones = %d\nNro Intercambios = %d\nTiempo de ejecucion = %.16f milisegundos\n",
               *comp_shell, *inter_shell, *t_shell);
}

/*ordenacion ascendente de lsita por Quicksort*/
int quicksort(int ini,int fin,int *V, int *comp_quicksort, int *inter_quicksort)
{
    int izq=ini,der=fin,pos=ini,aux;
    int band=1;
      while (band==1)
       {
         band=0;

         while ((V[pos]<V[der]) && (pos!=der))
         {
               (*comp_quicksort)++;
               der=der-1;
         }

         if (pos!=der)
         {
            aux=V[pos];
            V[pos]=V[der];
            V[der]=aux;
            pos=der;
            (*inter_quicksort)++;


              while ((V[pos]>=V[izq]) && (pos!=izq))
               {
                    (*comp_quicksort)++;
                    izq=izq+1;
               }

              if (pos!=izq)
           {
                band=1;
                aux=V[pos];
                V[pos]=V[izq];
                V[izq]=aux;
                pos=izq;
                (*inter_quicksort)++;
           }
        }
   }
    if (pos-1>ini)
    {
     quicksort(ini,pos-1,V, comp_quicksort, inter_quicksort);
    }

    if (fin>pos+1)
    {
        quicksort(pos+1,fin,V, comp_quicksort, inter_quicksort);
    }
}

/*ordenacion ascendente de lsita por Quicksort*/
int OrdenQuick(int n,int s,int *v2, double *t_quicksort, int *comp_quicksort, int *inter_quicksort)
{
    LARGE_INTEGER T1,T2;
    QueryPerformanceCounter(&T1);
    quicksort(n, s, v2, comp_quicksort, inter_quicksort);
    QueryPerformanceCounter(&T2);
    *t_quicksort=tiempo_ejecucion(&T1, &T2)*1000;
    printf("\nEl Vector ha sido ordenado por Metodo QuickSort\n\n");
   imprimir(v2, s+1);
    printf("\n\nEste es el analisis de la funcion:\n\nNro Comparaciones = %d\nNro Intercambios = %d\nTiempo de ejecucion = %.16f milisegundos\n",
               *comp_quicksort, *inter_quicksort, *t_quicksort);
}


/* Generar Vector Aleatoriamente*/
int llenarvector(int *v, int *v1, int *v2, int n)
{
    int i,j;
    for (i=0;i<n;i++)
    {
        j=rand() % 1000;
        v[i]=j;
        v1[i]=j;
        v2[i]=j;
    }
}

int sort(int *v, int n)
{
    int i,j=0;
    for(i=0;i<n;i++)
    {
       if(v[i]<=v[i+1])
          j++;
    }
    if (j==n)
        return 1;
    else
        return 0;
}


void analisis(int *v, int *v1, int *v2, int n, double *t_burbuja, double *t_shell, double *t_quicksort, int *comp_burbuja,
     int *comp_shell, int *comp_quicksort, int *inter_burbuja, int *inter_shell, int *inter_quicksort)
{
     printf("\nAqui encontrara el numero de Comparaciones, Intercambios y el Tiempo\n empleado por cada uno de los metodos de ordenamiento que haya usado\n");
     printf("\nPara N=%d\n",n);
     printf("\nMetodo\tComparaciones\tIntercambios\tTiempo\n");

     if (sort(v,n-1))
        printf("\nBurbuja\t\t%d\t%d\t%.16f milisegundos\n",*comp_burbuja, *inter_burbuja, *t_burbuja);

     if (sort(v1,n-1))
        printf("\nShell\t\t%d\t%d\t%.16f milisegundos\n",*comp_shell, *inter_shell, *t_shell);

      if (sort(v2,n-1))
         printf("\nQuickSort\t%d\t%d\t%.16f milisegundos\n",*comp_quicksort, *inter_quicksort, *t_quicksort);
}




           /* Programa Principal*/

int main ()
{
    int n=5,r;      /* n= numero de elementos del vector */
    int v[n], v1[n], v2[n];
    double t_burbuja, t_shell, t_quicksort;
    int comp_burbuja=0, comp_shell=0, comp_quicksort=0;
    int inter_burbuja=0, inter_shell=0, inter_quicksort=0;



    while (r!=0)
  {
      system("cls");
      printf("                  Bienvenido!          \n\n");

      printf ("               Que desea hacer?:      \n\n");
      printf("Escoja una de las siguientes opciones:\n");
      printf (" 1. Generar vector aleatorio\n");
      printf (" 2. Ordenar Vector (Generado Automaticamente) por metodo Burbuja\n");
      printf (" 3. Ordenar Vector (Generado Automaticamente) por metodo Shell\n");
      printf (" 4. Ordenar Vector (Generado Automaticamente) por metodo QuickSort\n");
      printf (" 5. Mostrar analisis de los metodos de ordenamiento usados\n");
      printf (" 0. Salir\n");
      fflush(stdin);
      printf ("\nIngrese la opcion deseada: ");
      scanf("%d",&r);

  switch  (r)
      {
         case 1:
              r=1;  {llenarvector(v,v1,v2, n);
                    printf("\nEste es el Vector generado:\n\n");
                    imprimir(v, n);
                       printf("El vector ha sido generado");
                     getchar ();
                     break; }
         case 2:
              r=2;  {burbuja(v, n, &t_burbuja, &comp_burbuja, &inter_burbuja);
                     getchar ();
                     break; }
         case 3:
              r=3;  {shell(v1, n, &t_shell, &comp_shell, &inter_shell);
                     getchar ();
                     break; }
         case 4:
              r=4;  {OrdenQuick(0,n-1,v2, &t_quicksort, &comp_quicksort, &inter_quicksort);
                     getchar ();
                     break; }
         case 5:
              r=5;  {analisis(v, v1, v2, n, &t_burbuja, &t_shell, &t_quicksort, &comp_burbuja, &comp_shell, &comp_quicksort,
                              &inter_burbuja, &inter_shell, &inter_quicksort);
                     getchar ();
                     break; }
      }
    getchar();
}

}

