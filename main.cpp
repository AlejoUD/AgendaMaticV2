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
	cout << "Bienvenid@ a AgendaMatic! (V 2.0)\n";
    cout << "Por favor, haz tu seleccion:\n";
    cout << "1 - Leer fichero\n";
    cout << "2 - Y\n";
    cout << "3 - Salir\n";
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
            	   	   cout << "Has elegido la opcion: 2\n";
            	   	   cout << "Introduce un numero para continuar: ";
            	   	   choice = GetInput();
                       break;
               case 3:
                       cout << "Gracias por usar AgendaMatic, nos vemos!\n";
                       break;

               default:
                       break;
              }
      } while(choice!=3);
    system("PAUSE");
    return EXIT_SUCCESS;
}
