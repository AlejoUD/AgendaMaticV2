#include "Fichero.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

#include "BaseDatos.h"
#include "Tarea.h"
#include <String.h>

void leerFichero(sqlite3 *db)
{
	string linea1;
	char valor1[linea1.size() + 1];

	string linea2;
	char valor2[linea2.size() + 1];

	string linea3;
	char valor3[linea3.size() + 1];

	string linea4;
	char valor4[linea4.size() + 1];

	string linea5;
	char valor5[linea5.size() + 1];


	Tarea *t = new Tarea("", 0, 0, "", "");
	ifstream fichero("Tareas.txt");
	if( fichero.fail() )
	{
	   cout << "No existe el fichero!" << endl;
	   exit(1);
	}

	while (!fichero.eof())
	{
		int i=0;
		for (i = 0; i < 5; i++)
		{
			if (!fichero.eof())
			{
				if(i==4)
				{
					getline(fichero,linea1);


					strcpy(valor1, linea1.c_str()); // @suppress("Invalid arguments")
					t->setDescripcion(valor1);

				}else
				{

					if(i==0)
					{
						fichero >> linea2;


						strcpy(valor2, linea2.c_str());
						t->setFecha(valor2);
					}
					if(i==1)
					{
						fichero >> linea4;



						strcpy(valor4, linea4.c_str());
						t->setDuracion(atoi(valor4));
					}
					if(i==2)
					{
						fichero >> linea5;



						strcpy(valor5, linea5.c_str());
						t->setImportancia(atoi(valor5));
					}
					if(i==3)
					{
						fichero >> linea3;


						strcpy(valor3, linea3.c_str());
						t->setTitulo(valor3);
					}

				}

			}
		}
		insertarTareas(db, t); // @suppress("Invalid arguments")

	}
	fichero.close();
}

