#include <windows.h>
#include <cstdlib>
#include <iostream>


#include "Fichero.h"
#include "BaseDatos.h"

using namespace std;

int GetInput()
{
   int choice;
   cin >> choice;
   return choice;
}


void MostrarMenuPrincipal()
{
    cout << "Bienvenid@ a AgendaMatic! (V 2.0) \n";
    cout << "Por favor, haz tu seleccion: \n";
    cout << "1 - Ordenar tareas por importancia. \n";
    cout << "2 - Ordenar tareas por duracion. \n";
    cout << "3 - Buscar una tarea por el titulo. \n";
    cout << "4 - Ver tareas de una duracion determinada. \n";
    cout << "5 - Ver tareas de una importancia determinada. \n";
    cout << "6 - Ver tareas con una duracion menor a una determinada. \n";
    cout << "7 - Ver tareas con una importancia mayor a una determinada. \n";
    cout << "8 - Mostrar todas las tareas (incluyendo las completadas). \n";
    cout << "9 - Mostrar tareas sin completar. \n";
    cout << "10 - Ver tareas de una fecha determinada. \n";
    cout << "11 - Salir. \n";
    cout << "Opcion: ";
}


int main(void)
{
	sqlite3 *db;
	int result = sqlite3_open("Bd.sqlite", &db); // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		//printf("Error abriendo la base de datos\n");
		return result;
	}
	borrarTareas(db); // @suppress("Invalid arguments")
	leerFichero(db);// @suppress("Invalid arguments")

    int choice = 0;

    do
    {
       system("cls");
       MostrarMenuPrincipal();
       choice = GetInput();
       switch(choice) {

               case 1:
            	   cout << "Has elegido Ordenar Tareas por Importancia \n";

            	   ordenarTareasImp(db); // @suppress("Invalid arguments")
            	   system("PAUSE");
            	   break;
               case 2:
            	   cout << "Has elegido Ordenar Tareas por Duración \n";

            	   ordenarTareasDur(db); // @suppress("Invalid arguments")
            	   system("PAUSE");
            	   break;
               case 3:
                   cout << "Has elegido Buscar tarea por título \n";

                   cout << "Introduce el titulo a buscar: \n";
                   char titulo[50];
                   cin >> titulo;

                   buscarTareaTitulo(titulo, db); // @suppress("Invalid arguments")
                   system("PAUSE");
                   break;
               case 4:
                   cout << "Has elegido ver tareas de una duracion determinada \n";

                   cout << "Introduce la duracion en minutos: \n";
                   int minutos;
                   cin >> minutos;

                   tareasDuracion(db,minutos,0); // @suppress("Invalid arguments")
                   system("PAUSE");
                   break;
               case 5:
                   cout << "Has elegido ver tareas de una importancia determinada \n";

                   cout << "Introduce la importancia del 1 al 10 \n";
                   int importanciaR;
                   cin >> importanciaR;

                   tareasImportancia(db,importanciaR,0); // @suppress("Invalid arguments")
                   system("PAUSE");
                   break;
               case 6:
                   cout << "Has elegido ver tareas con una duracion menor a una determinada \n";

                   cout << "Introduce la duracion en minutos: \n";
                   int minutosM;
                   cin >> minutosM;

                   tareasDuracion(db,minutosM,1); // @suppress("Invalid arguments")
                   system("PAUSE");
                   break;
               case 7:
                   cout << "Has elegido ver tareas con una importancia mayor a una determinada \n";

                   cout << "Introduce la importancia del 1 al 10 \n";
                   int importanciaRM;
                   cin >> importanciaRM;

                   tareasImportancia(db,importanciaRM,1); // @suppress("Invalid arguments")
                   system("PAUSE");
                   break;
               case 8:
                   cout << "Has elegido ver todas la tareas (incluyendo las COMPLETADAS)\n";

                   mostrarTodasTareas(db); // @suppress("Invalid arguments")
                   system("PAUSE");
                   break;

               case 9:
            	   cout << "Has elegido ver las tareas sin completar. \n";

            	   mostrarTareasSinCompletar(db); // @suppress("Invalid arguments")

            	   system("PAUSE");

            	   break;

               case 10:
            	   cout << "Has elegido Buscar tarea por fecha \n";

            	   cout << "Introduce la fecha a buscar: \n";
            	   char fecha[50];
            	   cin >> fecha;

            	   buscarTareasFecha(db, fecha); // @suppress("Invalid arguments")
            	   system("PAUSE");
            	   break;

               case 11:
            	   cout << "Gracias por usar AgendaMatic, nos vemos!\n";
            	   break;

               default:
                       break;
              }
      } while(choice!=11);
    system("PAUSE");
    return 0;
}
