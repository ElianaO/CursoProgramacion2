/*********************************/
/***Libros, Libros y mas Libros***/
/*Creado por: Herzon Spartan Cruz
        y Liseth Eliana Osorio*/
/*********************************/





/*introduccion de librerias*/

#include <conio.h>
#include <iostream>
#include <stdio.h>

/*definicion de enumeradores*/

typedef enum TipoNroEdicion {Primera=1, Segunda, Tercera, Cuarta};
typedef enum DefTipoPasta {TapaDura, TapaBlanda};
typedef enum DefTipoEdicion {Economica, DeLujo, ElectroLibro};
typedef enum TipoPosgrado {Especializacion, Maestria, PhD, PosPhD};
typedef enum Meses {Enero=1,Febrero, Marzo, Abril, Mayo, Junio, Julio, Agosto, Septiembre, Octubre, Noviembre, Diciembre};

/*definicion de estructuras necesarias para Libro*/

typedef struct{
        unsigned short int Dia:5;
        Meses Mes;
        unsigned int Anio;
        } TipoFecha;

typedef struct{
        char Nombre       [40];
        char Titulacion   [25];
        TipoPosgrado Posgrados;
        TipoFecha FechaNacimiento;
        char Direccion    [40];
        char Telefono  [4][15];
        char E_Mail       [25];
        } Autor;

typedef struct{
        char NombreEdit   [30];
        char DireccionEdit[30];
        char WebPage      [40];
        char E_Mail       [40];
        char TelefonoEdit [15];
        } Editorial;

/*Estructura Principal*/

 struct{
        char TituloLibro [30];
        TipoNroEdicion NroEdicion;
        Editorial EditorialLibro;
        Autor Autores;
        DefTipoPasta TipoPasta;
        DefTipoEdicion TipoEdicion;
        char ISBN       [20];
        TipoFecha FechaEdicion;
        } Libro;

/*funcion principal*/

main()
{
  int Opcion, ContadorLibro=0, ContadorAutores=0, DatoNumero;
  char DatoCadena[40];
  Opcion=0;
  printf("Digite la accion a realizar:\n 1: Leer Datos de Libro\n 2: Escribir nuevos datos de Libros\n 3: Salir\n");
  scanf("%d",&Opcion);
  if (Opcion==1)
     {

       do
          {
             printf("Nombre del libro N° %d: %s \n", (ContadorLibro++), (Libro.TituloLibro));
             printf("Numero de edicion de Libro: %d°\n\n", (Libro.NroEdicion));
             printf("Nombre de la editorial: %s\n", (Libro.EditorialLibro.NombreEdit));
             printf("Direccion de la Editorial: %s\n", (Libro.EditorialLibro.DireccionEdit));
             printf("Pagina Web de la Editorial: %s\n", (Libro.EditorialLibro.WebPage));
             printf("E-Mail de la Editorial: %s\n", (Libro.EditorialLibro.E_Mail));
             printf("Telefono(s) de la Editorial: %s\n\n", (Libro.EditorialLibro.TelefonoEdit));
               do
                 {
					printf("Nombre del Autor: %s\n", (Libro.Autores.Nombre));
					printf("Titulacion del Autor: %s\n", (Libro.Autores.Titulacion));
					printf("Posgrado(s) del Autor:\n0: Especializacion\n1: Maestria \n2: PhD \n3:PosPhD \n%d", (Libro.Autores.Posgrados));
					printf("Fecha de nacimiento del Autor: %d - %d - %d \n", (Libro.Autores.FechaNacimiento.Dia), (Libro.Autores.FechaNacimiento.Mes), (Libro.Autores.FechaNacimiento.Anio));
					ContadorAutores++;
               }
               while (ContadorAutores<4);
               printf("Tipo de Pasta del Libro: \n0: Tapa Dura \n1: Tapa Blanda \n %d\n", (Libro.TipoPasta));
               printf("Tipo de Edicion del Libro: \n0: Economica \n1: De Lujo \n2: Libro Electronico \n %d\n", (Libro.TipoEdicion));
               printf("Codigo ISBN: %s \n",(Libro.ISBN));
               printf("Fecha de edicion del Libro: %d - %d - %d\n", (Libro.FechaEdicion.Dia), (Libro.FechaEdicion.Mes), (Libro.FechaEdicion.Anio));
               ContadorLibro++;
       }
       while (ContadorLibro<1);
       return(main());
     }
     else if (Opcion==2)
          {
           do
          {
             printf("\nDigite nombre del libro y Presione Enter: \n");
             scanf("%s", &DatoCadena);
             strcpy(Libro.TituloLibro, DatoCadena);
             printf("Digite Numero de edicion del Libro en numeros y Presione Enter:\n");
             scanf("%d", &DatoNumero);
             Libro.NroEdicion= (TipoNroEdicion)DatoNumero;
             printf("Digite Nombre de la editorial y Presione Enter: \n");
             scanf("%s", &DatoCadena);
             strcpy(Libro.EditorialLibro.NombreEdit, DatoCadena);
             printf("Digite Direccion de la Editorial y Presione Enter: \n");
             scanf("%s", &DatoCadena);
             strcpy(Libro.EditorialLibro.DireccionEdit, DatoCadena);
             printf("Digite Pagina Web de la Editorial y Presione Enter:\n");
             scanf("%s", &DatoCadena);
             strcpy(Libro.EditorialLibro.WebPage, DatoCadena);
             printf("Digite E-Mail de la Editorial y Presione Enter:\n");
             scanf("%s", &DatoCadena);
             strcpy(Libro.EditorialLibro.E_Mail, DatoCadena);
             printf("Digite Telefono de la Editorial y Presione Enter: \n");
             scanf("%s", &DatoCadena);
             strcpy(Libro.EditorialLibro.TelefonoEdit, DatoCadena);
               do
                 {

                    printf("\nDigite Nombre del Autor y Presione Enter:\n");
                    scanf("%s", &DatoCadena);
                    strcpy(Libro.Autores.Nombre, DatoCadena);
					printf("Digite Titulacion del Autor y Presione Enter: \n");
                    scanf("%s", &DatoCadena);
                    strcpy(Libro.Autores.Titulacion,DatoCadena);
					printf("Digite Posgrado(s) del Autor y Presione Enter:\n0: Especializacion\n1: Maestria \n2: PhD \n3:PosPhD \n");
                    scanf("%d", &DatoNumero);
                    Libro.Autores.Posgrados=(TipoPosgrado)DatoNumero;
					printf("Digite Fecha de nacimiento del Autor y Presione Enter: \n");
                    printf("Dia de Nacimiento:\n");
                    scanf("%d", &DatoNumero);
                    Libro.Autores.FechaNacimiento.Dia=DatoNumero;
                    printf("Mes de Nacimiento: \n");
                    scanf("%d", &DatoNumero);
                    Libro.Autores.FechaNacimiento.Mes=(Meses)DatoNumero;
                    printf("Año de Nacimiento: \n");
                    scanf("%d", &DatoNumero);
                    Libro.Autores.FechaNacimiento.Anio=DatoNumero;
					printf("Desea introducir un nuevo Autor?: \n0: Si \nCualquier otro numero: No\n");
                    scanf("%d", &Opcion);
					ContadorAutores++;
               }
               while ((Opcion==0)&&(ContadorAutores<4));
               printf("Digite Tipo de Pasta del Libro en numero y Presione Enter: \n0: Tapa Dura \n1: Tapa Blanda \n");
               scanf("%d", &DatoNumero);
               Libro.TipoPasta=(DefTipoPasta)DatoNumero;
               printf("Digite Tipo de Edicion del Libro en numero y Presione Enter: \n0: Economica \n1: De Lujo \n2: Libro Electronico \n");
               scanf("%d", &DatoNumero);
               Libro.TipoEdicion=(DefTipoEdicion)DatoNumero;
               printf("Digite Codigo ISBN y Presione Enter: \n");
               scanf("%s", &DatoCadena);
               strcpy(Libro.ISBN,DatoCadena);
               printf("Digite Fecha de edicion del libro y Presione Enter: \n");
               printf("Dia de edicion: \n");
               scanf("%d",&DatoNumero);
               Libro.FechaEdicion.Dia=DatoNumero;
               printf("Mes de edicion: \n");
               scanf("%d", &DatoNumero);
               Libro.FechaEdicion.Mes=(Meses)DatoNumero;
               printf("Año de edicion: \n");
               scanf("%d", &DatoNumero);
               Libro.FechaEdicion.Anio=DatoNumero;
               printf("Desea introducir un nuevo Libro?: \n0: Si \nCualquier otro numero: No");
               scanf("%d", &Opcion);
			   ContadorLibro++;
          }
          while ((Opcion==0)&&(ContadorLibro<1));
          return(main());
     }
     else
     {
         printf("Gracias por confiar en Spartan-Tec");
         getch();
         }
     }

