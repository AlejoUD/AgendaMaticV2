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
    cout << "1 - Leer tareas. \n";
    cout << "2 - Insertar tareas. \n";
    cout << "3 - Borrar tareas. \n";
    cout << "4 - Ordenar tareas por importancia. \n";
    cout << "5 - Ordenar tareas por duración. \n";
    cout << "6 - Salir. \n";
    cout << "Opcion: ";
}


int main(int argc, char *argv[])
{
	sqlite3 *db;
	int result = sqlite3_open("Bd.sqlite", &db); // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		printf("Error abriendo la base de datos\n");
		return result;
	}

    int choice = 0;

    do
    {
       system("cls");
       MostrarMenuPrincipal();
       choice = GetInput();
       switch(choice) {
               case 1:
            	   cout << "Has elegido la opción de Leer Fichero: \n";
            	   leerFichero(db);// @suppress("Invalid arguments")
            	   break;
               case 2:
            	   cout << "Has elegido Insertar Tarea \n";

            	   break;
               case 3:
            	   cout << "Has elegido Borrar Tareas \n";
            	   borrarTareas(db); // @suppress("Invalid arguments")
                   break;
               case 4:
            	   cout << "Has elegido Ordenar Tareas por Importancia \n";
            	   ordenarTareasImp(db); // @suppress("Invalid arguments")
            	   break;
               case 5:
            	   cout << "Has elegido Ordenar Tareas por Duración \n";
            	   ordenarTareasDur(db); // @suppress("Invalid arguments")
            	   break;
               case 6:
            	   cout << "Gracias por usar AgendaMatic, nos vemos!\n";
            	   break;

               default:
                       break;
              }
      } while(choice!=6);
    system("PAUSE");
    return EXIT_SUCCESS;
}
