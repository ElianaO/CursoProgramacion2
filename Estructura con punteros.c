
/*********************************/
/*  Libros, Libros y mas Libros  */
/*Creado por:Liseth Eliana Osorio*/
/* Estructura Libro con Punteros */
/*********************************/

/*introduccion de librerias*/

#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>


/*definicion de enumeradores*/

enum Nro_Edicion {Primera_Edicion=1,Segunda_Edicion,Tercera_Edicion,Cuarta_Edicion};
enum Clase_Pasta {Pasta_Dura=1,Pasta_Blanda};
enum Clase_Edicion {Economico=1,Lujo,Libro_Electronico};
enum Clase_Posgrados {Especializacion=1,Maestria,PhD,Pos_PhD,Todos};
enum Meses {Enero=1,Febrero,Marzo,Abril,Mayo,Juni,Julio,Agosto,Septiembre,Octubre,Noviembre,Diciembre};

/*definicion de estructuras necesarias para Libro*/

typedef struct{
        unsigned short int Dia;
        enum Meses Mes;
        unsigned int Anio;
        }Fecha;

typedef struct{
        char Nombre [30];
        char Direccion[20];
        char Pagina_Web[30];
        char Correo_Electronico[30];
        unsigned int Telefono;
        }Datos_Editorial;

typedef struct{
       char Nombre [30];
       char Titulacion [20];
       enum Clase_Posgrados PosGrados;
       Fecha Fecha_Nacimiento;
       char Direccion [20];
       unsigned int Telefono;
       char E_Mail[30];
       }Datos_Autor;

/*Estructura Principal*/

struct Libro{
       struct Libro *sgt;
        char Titulo [40];
        enum Nro_Edicion Edicion;
        Datos_Editorial Editorial;
        Datos_Autor Autor;
        enum Clase_Pasta Pasta;
        enum Clase_Edicion Tipo_Edicion;
        char ISBN [40];
        Fecha Fecha_Edicion;
        };


                      /* Funciones*/

/*Funcion para ingresar los datos.*/

void LeerDatos (struct Libro *Libros, int Nro_Libros)
{

            if(Nro_Libros==0)Libros->sgt=NULL;
            else{


            printf("Titulo del Libro:\n\n");
             fflush(stdin);
            scanf("%[^\n]s",&Libros->Titulo);
            printf("\n\n");

            printf("Edicion del Libro: \n\n");
            printf("Numero de la Edicion : \n1:Primera Edicion\n 2: Segunda Edicion\n  3: Tercera Edicion\n   4 : ultima edicion  \n\n");
             fflush(stdin);
            scanf("%d",&Libros->Edicion);



            /*DATOS EDITORIAL*/

            printf("\n\n");
            printf("EDITORIAL \n\n");

            printf(" Nombre de la Editorial: \n\n");
             fflush(stdin);
            scanf("%[^\n]s",&Libros->Editorial.Nombre);
            printf("\n\n");

             printf("  Telefono de la Editorial:\n\n");
             fflush(stdin);
             scanf("%d",&Libros->Editorial.Telefono);
             printf("\n\n");

            printf("  Direccion de la Editorial: \n\n");
             fflush(stdin);
            scanf("%[^\n]s",&Libros->Editorial.Direccion);
            printf("\n\n");

            printf(" Pagina Web de la editorial: \n\n");
             fflush(stdin);
            scanf("%[^\n]s",&Libros->Editorial.Pagina_Web);
            printf("\n\n");

            printf(" Email de la Editorial: \n\n");
             fflush(stdin);
            scanf("%[^\n]s",&Libros->Editorial.Correo_Electronico);
            printf("\n\n");



            /*DATOS AUTOR*/

            printf("  AUTOR \n\n");

            printf("  Nombre del Autor : \n\n");
             fflush(stdin);
            scanf("%[^\n]s",&Libros->Autor.Nombre);
            printf("\n\n");

            printf("  Titulacion del autor:  \n\n");
             fflush(stdin);
            scanf("%[^\n]s",&Libros->Autor.Titulacion);
            printf("\n\n");

            printf("  PosGrados del autor :  \n\n");
            printf("Seleccione el nivel de Posgrados del Autor :  \n1: Especializacion\n 2: Maestria\n 3: PhD\n 4: Pos PhD \n\n");
             fflush(stdin);
            scanf("%d",&Libros->Autor.PosGrados);
            printf("\n\n");

            printf("Fecha De Nacimiento del Autor: \n\n");
            printf("    Dia : ");
             fflush(stdin);
            scanf("%d",&Libros->Autor.Fecha_Nacimiento.Dia);
            printf("\n\n");

            printf("    Mes : ");
             fflush(stdin);
            scanf("%d",&Libros->Autor.Fecha_Nacimiento.Mes);
            printf("\n\n");

            printf("    Año : ");
             fflush(stdin);
            scanf("%d",&Libros->Autor.Fecha_Nacimiento.Anio);
            printf("\n\n");

            printf("  Direccion del Autor :  \n\n");
             fflush(stdin);
            scanf("%[^\n]s",&Libros->Autor.Direccion);
            printf("\n\n");

            printf("  Telefono del Autor :  \n\n");
             fflush(stdin);
            scanf("%d",&Libros->Autor.Telefono);
            printf("\n\n");

            printf("  Email del Autor :  \n\n");
             fflush(stdin);
            scanf("%[^\n]s",&Libros->Autor.E_Mail);


            /*TIPO DE PASTA DEL LIBRO*/

            printf("\n\n");
            printf("  Tipo De Pasta: \n\n");
            printf("Seleccione: 1: Pasta Dura, 2: Pasta Blanda \n\n");
             fflush(stdin);
            scanf("%d",&Libros->Pasta);
            printf("\n\n");


            /*TIPO DE EDICION DEL LIBRO*/

            printf("  Tipo De Edicion  \n\n");
            printf("Escoja el tipo de Edicion :\n  1: Edicion Economica\n  2: Edicion de Lujo\n  3: Libro Electronico \n\n");
             fflush(stdin);
            scanf("%d",&Libros->Tipo_Edicion);
            printf("\n\n");

            printf("  ISBN del Libro :  \n\n");
             fflush(stdin);
            scanf("%[^\n]s",&Libros->ISBN);
            printf("\n\n");


            /*FECHA  DE EDICION  DEL LIBRO*/

            printf("Fecha De Edicion del Libro :  \n\n");
            printf("    Dia : ");
             fflush(stdin);
            scanf("%d",&Libros->Fecha_Edicion.Dia);
            printf("\n\n");

            printf("    Mes : ");
             fflush(stdin);
            scanf("%d",&Libros->Fecha_Edicion.Mes);
            printf("\n\n");

            printf("    Año : ");
             fflush(stdin);
            scanf("%d",&Libros->Fecha_Edicion.Anio);
            printf("\n\n");


            printf("Siguiente Libro: \n\n\n\n");

            Libros->sgt=(struct Libro *)malloc(sizeof(struct Libro));
            Nro_Libros--;
           LeerDatos(Libros->sgt,Nro_Libros);
           }

    system("pause");
    exit(0);

}


/*Funciones para la impresion de los datos del libro en Pantalla*/

int ImprimirDatos(struct Libro *Libros, int Nro_Libros)
{
        printf("Titulo :  %s \n",Libros->Titulo);
        printf("Edicion :  %d \n",Libros->Edicion);

/*DATOS EDITORIAL*/

        printf("Editorial:  \n  Nombre:  %s \n",Libros->Editorial.Nombre);
        printf("  Direccion: %s \n",Libros->Editorial.Direccion);
        printf("  Pagina Web: %s \n",Libros->Editorial.Pagina_Web);
        printf("  Email: \n",Libros->Editorial.Correo_Electronico);
        printf("  Telefono: %d \n",Libros->Editorial.Telefono);


                       /*DATOS AUTOR*/

        printf("Autor: \n  Nombre:  %s \n",Libros->Autor.Nombre);
        printf("  Titulacion: %s \n",Libros->Autor.Titulacion);
        printf("  PosGrados: %d \n",Libros->Autor.PosGrados);

                 /*FECHA DE NACIMIENTO DEL AUTOR*/

        printf("Fecha Nacimiento: \n  Dia: %d   ",Libros->Autor.Fecha_Nacimiento.Dia);
        printf("  Mes: %d   ",Libros->Autor.Fecha_Nacimiento.Mes);
        printf("  Anyo: %d \n",Libros->Autor.Fecha_Nacimiento.Anio);

        printf("Direccion: %s \n",Libros->Autor.Direccion);
        printf("Telefono: %d \n",Libros->Autor.Telefono);
        printf("E-Mail: %s \n",Libros->Autor.E_Mail);

        printf("Pasta: %d \n",Libros->Pasta);
        printf("Edicion: %d \n",Libros->Tipo_Edicion);
        printf("ISBN: %s \n",Libros->ISBN);


                     /*FECHA  DE EDICION DEL LIBRO*/

        printf("Fecha Edicion :  \n Dia: %d   ",Libros->Fecha_Edicion.Dia);
        printf("  Mes: %d   ",Libros->Fecha_Edicion.Mes);
        printf("  Anio %d \n\n\n\n\n",Libros->Fecha_Edicion.Anio);


        ImprimirDatos(Libros->sgt,Nro_Libros);


}


                /*Programa Principal*/

main()
{

      int Nro_Libros;
      struct Libro *Lib;
      printf("Bienvenido a Libros y mas Libros \n");
      printf("\n ");
      printf("\n  Ingrese la cantidad de libros que desea registrar : ");
      scanf ("%d",&Nro_Libros);
      printf("\n\n");

                /* Funcion que asigna memoria.*/

      Lib=(struct Libro *)malloc(sizeof(struct Libro));          //Funcion que asigna memoria.
      if(Lib==NULL)                                              //Verifica si pudo separar la memora suficiente.
      {
      printf("error en el proceso"); //Mensaje De error
      exit(0);
      }

      LeerDatos(Lib, Nro_Libros);
      ImprimirDatos(Lib,Nro_Libros);

}
