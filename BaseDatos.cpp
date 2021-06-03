/*
 * BaseDatos.cpp
 *
 *  Created on: 18 may. 2021
 *      Author: Julen
 */
#include "BaseDatos.h"
#include <stdio.h>
#include "sqlite3.h"
#include <string.h>
#include <iostream>

#include <string>
using namespace std;

#include "Tarea.h";

int insertarTareas(sqlite3 *db, Tarea *tarea) {
	sqlite3_stmt *stmt;

	char sql[] = "insert into tareas (id, fecha, importancia, duracion, titulo, Descripcion) values (NULL, ?, ?, ?, ?, ?)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ; // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		//cout<<"Error preparando la sentencia (INSERT)\n");
		//cout<<"%s\n", sqlite3_errmsg(db)); // @suppress("Invalid arguments")
		return result;
	}

	//cout<<"consulta SQL preparada (INSERT)\n");

	result = sqlite3_bind_text(stmt, 1, tarea->getFecha(), strlen(tarea->getFecha()), SQLITE_STATIC); // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		//cout<<"Error introduciendo los parametros\n");
		//cout<<"%s\n", sqlite3_errmsg(db)); // @suppress("Invalid arguments")
		return result;
	}

	result = sqlite3_bind_int(stmt, 2, tarea->getImportancia()); // // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		//cout<<"Error introduciendo los parametros\n");
		//cout<<"%s\n", sqlite3_errmsg(db)); // @suppress("Invalid arguments")
		return result;
	}

	result = sqlite3_bind_int(stmt, 3, tarea->getDuracion()); // // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		//cout<<"Error introduciendo los parametros\n");
		//cout<<"%s\n", sqlite3_errmsg(db)); // @suppress("Invalid arguments")
		return result;
	}

	result = sqlite3_bind_text(stmt, 4, tarea->getTitulo(), strlen(tarea->getTitulo()), SQLITE_STATIC); // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		//cout<<"Error introduciendo los parametros\n");
		//cout<<"%s\n", sqlite3_errmsg(db)); // @suppress("Invalid arguments")
		return result;
	}

	result = sqlite3_bind_text(stmt, 5, tarea->getDescripcion(), strlen(tarea->getDescripcion()), SQLITE_STATIC); // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		//cout<<"Error introduciendo los parametros\n");
		//cout<<"%s\n", sqlite3_errmsg(db)); // @suppress("Invalid arguments")
		return result;
	}

	result = sqlite3_step(stmt); // @suppress("Invalid arguments")
	if (result != SQLITE_DONE) {
		//cout<<"Error insertando table\n");
		return result;
	}

	result = sqlite3_finalize(stmt); // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		//cout<<"Error finalizando consulta (INSERT)\n");
		//cout<<"%s\n", sqlite3_errmsg(db)); // @suppress("Invalid arguments")
		return result;
	}

	//cout<<"Consulta finalizada (INSERT)\n");

	return SQLITE_OK;
}
int borrarTareas(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "delete from tareas";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ; // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		//cout<<"Error preparando la sentencia (DELETE)\n");
		//cout<<"%s\n", sqlite3_errmsg(db)); // @suppress("Invalid arguments")
		return result;
	}

	//cout<<"consulta SQL preparada (DELETE)\n");

	result = sqlite3_step(stmt); // @suppress("Invalid arguments")
	if (result != SQLITE_DONE) {
		//cout<<"Error borrando datos\n");
		//cout<<"%s\n", sqlite3_errmsg(db)); // @suppress("Invalid arguments")
		return result;
	}

	result = sqlite3_finalize(stmt); // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		//cout<<"Error finalizando consulta (DELETE)\n");
		//cout<<"%s\n", sqlite3_errmsg(db)); // @suppress("Invalid arguments")
		return result;
	}

	//cout<<"Consulta finalizada (DELETE)\n");

	return SQLITE_OK;
}

int ordenarTareasImp(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "select id, fecha, importancia, duracion, titulo, Descripcion from tareas where Descripcion NOT LIKE '%Completada%' order by importancia asc";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ; // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		//cout<<"Error preparando la sentencia (SELECT)\n");
		//cout<<"%s\n", sqlite3_errmsg(db)); // @suppress("Invalid arguments")
		return result;
	}

	//cout<<"consulta SQL preparada (SELECT)\n");

	int id;
	char fecha[10];
	int duracion;
	int importancia;
	char titulo[50];
	char descripcion[250];

	cout<<endl;
	cout<<endl;
	cout<<"Mostrando tareas ordenadas por importancia:"<<endl;
	do {
		result = sqlite3_step(stmt) ; // @suppress("Invalid arguments")
		if (result == SQLITE_ROW) {
			//id = sqlite3_column_int(stmt, 0); // @suppress("Invalid arguments")
			strcpy(fecha, (char *) sqlite3_column_text(stmt, 1)); // @suppress("Invalid arguments")
			importancia= sqlite3_column_int(stmt, 2); // @suppress("Invalid arguments")
			duracion= sqlite3_column_int(stmt, 3); // @suppress("Invalid arguments")
			strcpy(titulo, (char *) sqlite3_column_text(stmt,4 )); // @suppress("Invalid arguments")
			strcpy(descripcion, (char *) sqlite3_column_text(stmt, 5)); // @suppress("Invalid arguments")
			cout << "Fecha: "<< fecha<< " Duracion: "<<duracion<< " Importancia: "<<importancia<< " Titulo: "<<titulo<< " Descripcion: " <<descripcion<< endl;
		}
	} while (result == SQLITE_ROW);

	cout<<endl;
	cout<<endl;

	result = sqlite3_finalize(stmt); // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		//cout<<"Error finalizando consulta (SELECT)\n");
		//cout<<"%s\n", sqlite3_errmsg(db)); // @suppress("Invalid arguments")
		return result;
	}

	//cout<<"Consulta finalizada (SELECT)\n");

	return SQLITE_OK;
}

int ordenarTareasDur(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "select id, fecha, importancia, duracion, titulo, Descripcion from tareas where Descripcion NOT LIKE '%Completada%' order by duracion asc";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ; // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		//cout<<"Error preparando la sentencia (SELECT)\n");
		//cout<<"%s\n", sqlite3_errmsg(db)); // @suppress("Invalid arguments")
		return result;
	}

	//cout<<"consulta SQL preparada (SELECT)\n");

	int id;
	char fecha[10];
	int duracion;
	int importancia;
	char titulo[50];
	char descripcion[250];

	cout<<endl;
	cout<<endl;
	cout<<"Mostrando tareas ordenadas por duracion:"<<endl;
	do {
		result = sqlite3_step(stmt) ; // @suppress("Invalid arguments")
		if (result == SQLITE_ROW) {
			//id = sqlite3_column_int(stmt, 0); // @suppress("Invalid arguments")
			strcpy(fecha, (char *) sqlite3_column_text(stmt, 1)); // @suppress("Invalid arguments")
			importancia= sqlite3_column_int(stmt, 2); // @suppress("Invalid arguments")
			duracion= sqlite3_column_int(stmt, 3); // @suppress("Invalid arguments")
			strcpy(titulo, (char *) sqlite3_column_text(stmt,4 )); // @suppress("Invalid arguments")
			strcpy(descripcion, (char *) sqlite3_column_text(stmt, 5)); // @suppress("Invalid arguments")
			cout << "Fecha: "<< fecha<< " Duracion: "<<duracion<< " Importancia: "<<importancia<< " Titulo: "<<titulo<< " Descripcion: " <<descripcion<< endl;
		}
	} while (result == SQLITE_ROW);

	cout<<endl;
	cout<<endl;

	result = sqlite3_finalize(stmt); // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		//cout<<"Error finalizando consulta (SELECT)\n");
		//cout<<"%s\n", sqlite3_errmsg(db)); // @suppress("Invalid arguments")
		return result;
	}

	//cout<<"Consulta finalizada (SELECT)\n");

	return SQLITE_OK;
}

int buscarTareaTitulo(const char* tituloSeleccionado, sqlite3 *db) {

	// Cargar base de datos
	sqlite3_stmt *stmt;

	// Crear string para cambiarlo
	char sqlf[] = "select id, fecha, importancia, duracion, titulo, Descripcion from tareas where titulo LIKE '%";
	strncat(sqlf, tituloSeleccionado, strlen(tituloSeleccionado)+1);
	strncat(sqlf, "%'", 3);

	// Copiar el string cambiado al bueno
	char sql[] = "select id, fecha, importancia, duracion, titulo, Descripcion from tareas where titulo LIKE '%titulo%'";
	strcpy(sql, sqlf);

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ; // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		//cout<<"Error preparando la sentencia (SELECT)\n");
		//cout<<"%s\n", sqlite3_errmsg(db)); // @suppress("Invalid arguments")
		return result;
	}

	//cout<<"consulta SQL preparada (SELECT)\n");

	char fecha[10];
	char titulo[50];
	int duracion;
	int importancia;
	char descripcion[250];

	cout<<endl;
	cout<<endl;
	cout<<"Mostrando las tareas:"<<endl;
	do {
		result = sqlite3_step(stmt) ; // @suppress("Invalid arguments")
		if (result == SQLITE_ROW) {
			strcpy(titulo, (char *) sqlite3_column_text(stmt,4 )); // @suppress("Invalid arguments")
				strcpy(fecha, (char *) sqlite3_column_text(stmt, 1)); // @suppress("Invalid arguments")
				importancia= sqlite3_column_int(stmt, 2); // @suppress("Invalid arguments")
				duracion= sqlite3_column_int(stmt, 3); // @suppress("Invalid arguments")
				strcpy(titulo, (char *) sqlite3_column_text(stmt,4 )); // @suppress("Invalid arguments")
				strcpy(descripcion, (char *) sqlite3_column_text(stmt, 5)); // @suppress("Invalid arguments")
				cout << "Fecha: "<< fecha<< " Duracion: "<<duracion<< " Importancia: "<<importancia<< " Titulo: "<<titulo<< " Descripcion: " <<descripcion<< endl;
		}
	} while (result == SQLITE_ROW);

	cout<<endl;
	cout<<endl;

	// Cerrar base de datos
	result = sqlite3_finalize(stmt); // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		//cout<<"Error finalizando consulta (SELECT)\n");
		//cout<<"%s\n", sqlite3_errmsg(db)); // @suppress("Invalid arguments")
		return result;
	}

	return SQLITE_OK;
}
int tareasDuracion(sqlite3 *db, int minutos, int opcion) {
	sqlite3_stmt *stmt;

	char sql[] = "select id, fecha, importancia, duracion, titulo, Descripcion from tareas where Descripcion NOT LIKE '%Completada%' ";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ; // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		//cout<<"Error preparando la sentencia (SELECT)\n");
		//cout<<"%s\n", sqlite3_errmsg(db)); // @suppress("Invalid arguments")
		return result;
	}

	//cout<<"consulta SQL preparada (SELECT)\n");

	int id;
	char fecha[10];
	int duracion;
	int importancia;
	char titulo[50];
	char descripcion[250];

	cout<<endl;
	cout<<endl;
	cout<<"Mostrando las tareas de la duracion introducida:"<<endl;
	do {
		result = sqlite3_step(stmt) ; // @suppress("Invalid arguments")
		if (result == SQLITE_ROW) {
			//id = sqlite3_column_int(stmt, 0); // @suppress("Invalid arguments")
			strcpy(fecha, (char *) sqlite3_column_text(stmt, 1)); // @suppress("Invalid arguments")
			importancia= sqlite3_column_int(stmt, 2); // @suppress("Invalid arguments")
			duracion= sqlite3_column_int(stmt, 3); // @suppress("Invalid arguments")
			strcpy(titulo, (char *) sqlite3_column_text(stmt,4 )); // @suppress("Invalid arguments")
			strcpy(descripcion, (char *) sqlite3_column_text(stmt, 5)); // @suppress("Invalid arguments")
			if((minutos==duracion)&&opcion==0)
			{
				cout << "Fecha: "<< fecha<< " Duracion: "<<duracion<< " Importancia: "<<importancia<< " Titulo: "<<titulo<< " Descripcion: " <<descripcion<< endl;
			}else if((duracion<minutos)&&opcion==1)
			{
				cout << "Fecha: "<< fecha<< " Duracion: "<<duracion<< " Importancia: "<<importancia<< " Titulo: "<<titulo<< " Descripcion: " <<descripcion<< endl;
			}

		}
	} while (result == SQLITE_ROW);

	cout<<endl;
	cout<<endl;

	result = sqlite3_finalize(stmt); // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		//cout<<"Error finalizando consulta (SELECT)\n");
		//cout<<"%s\n", sqlite3_errmsg(db)); // @suppress("Invalid arguments")
		return result;
	}

	//cout<<"Consulta finalizada (SELECT)\n");

	return SQLITE_OK;
}
int tareasImportancia(sqlite3 *db, int importanciaR, int opcion) {
	sqlite3_stmt *stmt;

	char sql[] = "select id, fecha, importancia, duracion, titulo, Descripcion from tareas where Descripcion NOT LIKE '%Completada%' ";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ; // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		//cout<<"Error preparando la sentencia (SELECT)\n");
		//cout<<"%s\n", sqlite3_errmsg(db)); // @suppress("Invalid arguments")
		return result;
	}

	//cout<<"consulta SQL preparada (SELECT)\n");

	int id;
	char fecha[10];
	int duracion;
	int importancia;
	char titulo[50];
	char descripcion[250];

	cout<<endl;
	cout<<endl;
	cout<<"Mostrando las tareas de la importancia introducida: "<<endl;
	do {
		result = sqlite3_step(stmt) ; // @suppress("Invalid arguments")
		if (result == SQLITE_ROW) {
			//id = sqlite3_column_int(stmt, 0); // @suppress("Invalid arguments")
			strcpy(fecha, (char *) sqlite3_column_text(stmt, 1)); // @suppress("Invalid arguments")
			importancia= sqlite3_column_int(stmt, 2); // @suppress("Invalid arguments")
			duracion= sqlite3_column_int(stmt, 3); // @suppress("Invalid arguments")
			strcpy(titulo, (char *) sqlite3_column_text(stmt,4 )); // @suppress("Invalid arguments")
			strcpy(descripcion, (char *) sqlite3_column_text(stmt, 5)); // @suppress("Invalid arguments")
			if((importanciaR==importancia)&&opcion==0)
			{
				cout << "Fecha: "<< fecha<< " Duracion: "<<duracion<< " Importancia: "<<importancia<< " Titulo: "<<titulo<< " Descripcion: " <<descripcion<< endl;
			}else if((importancia>importanciaR)&&opcion==1)
			{
				cout << "Fecha: "<< fecha<< " Duracion: "<<duracion<< " Importancia: "<<importancia<< " Titulo: "<<titulo<< " Descripcion: " <<descripcion<< endl;
			}

		}
	} while (result == SQLITE_ROW);

	cout<<endl;
	cout<<endl;

	result = sqlite3_finalize(stmt); // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		//cout<<"Error finalizando consulta (SELECT)\n");
		//cout<<"%s\n", sqlite3_errmsg(db)); // @suppress("Invalid arguments")
		return result;
	}

	//cout<<"Consulta finalizada (SELECT)\n");

	return SQLITE_OK;
}

int mostrarTodasTareas(sqlite3 *db) {

	// Cargar base de datos
	sqlite3_stmt *stmt;

	char sql[] = "select id, fecha, importancia, duracion, titulo, Descripcion from tareas";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ; // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		return result;
	}

	char fecha[10];
	char titulo[50];
	int duracion;
	int importancia;
	char descripcion[250];

	cout<<endl;
	cout<<endl;
	cout<<"Mostrando las tareas:"<<endl;
	do {
		result = sqlite3_step(stmt) ; // @suppress("Invalid arguments")
		if (result == SQLITE_ROW) {
			strcpy(titulo, (char *) sqlite3_column_text(stmt,4 )); // @suppress("Invalid arguments")
				strcpy(fecha, (char *) sqlite3_column_text(stmt, 1)); // @suppress("Invalid arguments")
				importancia= sqlite3_column_int(stmt, 2); // @suppress("Invalid arguments")
				duracion= sqlite3_column_int(stmt, 3); // @suppress("Invalid arguments")
				strcpy(titulo, (char *) sqlite3_column_text(stmt,4 )); // @suppress("Invalid arguments")
				strcpy(descripcion, (char *) sqlite3_column_text(stmt, 5)); // @suppress("Invalid arguments")
				cout << "Fecha: "<< fecha<< " Duracion: "<<duracion<< " Importancia: "<<importancia<< " Titulo: "<<titulo<< " Descripcion: " <<descripcion<< endl;
		}
	} while (result == SQLITE_ROW);

	cout<<endl;
	cout<<endl;

	// Cerrar base de datos
	result = sqlite3_finalize(stmt); // @suppress("Invalid arguments")
	if (result != SQLITE_OK) {
		return result;
	}


	return SQLITE_OK;
}
