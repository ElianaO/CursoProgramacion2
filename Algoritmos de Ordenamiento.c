/* Algoritmos de ordenamiento */
/* Programa por el cual se pretende demostrar
  los diferentes tipos de algoritmos ordenamiento
   y comprombar su tiempo de ejecucion
    Por: Liseth Eliana Osorio Rendon*/



#include <stdio.h>
#define N 100
#include <time.h>

void ordInsercion (int a[], int n);
void entradaLista (int a[], int n);
void imprimirLista (int a[], int n);
void ordenacionShell(int a[], int n);
void OrdenacionRapida(int a[], int primero, int ultimo);
void Quicksort(int a[], int n);

int main()
{
int n;
int v[N];

 clock_t comienzo; /* inicio de el contador del tiempo */

   comienzo=clock();


do {
    printf("     Bienvenido! \n");
    printf("\n    Algoritmos de Ordenamiento.\n \n");
printf("\nIntroduzca el numero de elementos que hay en el vector: \n");
scanf("%d", &n);
} while ((n < 1) && (n > N));

entradaLista(v, n);
/* muestra lista original */
printf("\nEste es el vector original de %d elementos que usted ingreso \n", n);

imprimirLista(v, n);

{
         /* ordenación ascendente de la lista por Insercion*/

printf("\n \n                   Metodo de Organizacion de Insercion \n \n");

 clock_t comienzo1; /* inicio de el contador del tiempo */

   comienzo1=clock();

ordInsercion(v, n);
printf("\nEste es el vector de %d elementos organizado por Insercion \n", n);
imprimirLista(v, n);
printf( "\nNro de segundos transcurridos en la ejecucion de la Insercion : %f s\n\n", (clock()-comienzo1)/(double)CLOCKS_PER_SEC );
}


{
    /* ordenación ascendente de la lista por Shell*/
printf(" \n \n                    Metodo de Organizacion de Shell \n \n");

clock_t comienzo2; /* inicio de el contador del tiempo */
comienzo2=clock();


ordenacionShell(v, n);
printf("\nEste es el vector de %d elementos organizado por Shell \n", n);
imprimirLista(v, n);
 printf( "\n Nro de segundos transcurridos en la ejecucion de Shell : %f s\n\n", (clock()-comienzo2)/(double)CLOCKS_PER_SEC );
}

/*ordenacion ascendente de lsita por Quicksort*/
printf(" \n\n                     Metodo de Organizacion Quicksort \n \n");



clock_t comienzoQuicksort; /* inicio de el contador del tiempo */
comienzoQuicksort=clock();


Quicksort(v, n);
printf("\n Este es el vector de %d elementos organizado por Quicksort \n", n);
imprimirLista(v, n);
 printf( "\nNro de segundos transcurridos en la ejecucion Quicksort: %f s\n\n", (clock()-comienzoQuicksort)/(double)CLOCKS_PER_SEC );


printf( "\nNro de segundos transcurridos desde el inicio del programa : %f s\n\n", (clock()-comienzo)/(double)CLOCKS_PER_SEC );

printf(" \n     Fin del Programa! \n \n");

system("PAUSE");
}




void imprimirLista (int a[], int n)
{
int i;
for (i = 0 ; i < n ; i++)
{
char c;
c = (i%10==0)?'\n':' ';
printf("%c%d", c, a[i]);
}
}
void entradaLista (int a[], int n)
{
int i;
printf("\nIngrese los elementos del vector\n");
for (i = 0 ; i < n ; i++)
{

scanf("%d", a+i);
}
}


void ordInsercion (int a[], int n)
{
int i, j;
int aux;
for (i = 1; i < n; i++)
{
/* índice j explora la sublista a[i-1]..a[0] buscando la
posición correcta del elemento destino, lo asigna a a[j] */
j = i;
aux = a[i];
/* se localiza el punto de inserción explorando hacia abajo */
while (j > 0 && aux < a[j-1])
{
/* desplazar elementos hacia arriba para hacer espacio */
a[j] = a[j-1];
j--;
}
a[j] = aux;
}
}

void ordenacionShell(int a[], int n)
{
int intervalo, i, j, k;
intervalo = n / 2;
while (intervalo > 0)
{for (i = intervalo; i < n; i++)
{
j = i - intervalo;
while (j >= 0)
{
k = j + intervalo;
if (a[j] <= a[k])
j = -1; /* así termina el bucle, par ordenado */
else
{
double temp;
temp = a[j];
a[j] = a[k];
a[k] = temp;
j -= intervalo;
}
}
}
intervalo = intervalo / 2;
}
}


void Quicksort(int a[], int n)
{
    OrdenacionRapida(a, 0, n-1);
}

void OrdenacionRapida(int a[], int primero, int ultimo)
{
int i, j, central;
int pivote;
central = (primero + ultimo)/2;
pivote = a[central];
i = primero;
j = ultimo;
do {
while (a[i] < pivote) i++;
while (a[j] > pivote) j--;
if (i<=j)
{
int tmp;
tmp = a[i];
a[i] = a[j];
a[j] = tmp; /* intercambia a[i] con a[j] */
i++;
j--;
}
}while (i <= j);
if (primero < j)
OrdenacionRapida(a, primero, j);/* mismo proceso con sublista izqda */
if (i < ultimo)
OrdenacionRapida(a, i, ultimo); /* mismo proceso con sublista drcha */
}


