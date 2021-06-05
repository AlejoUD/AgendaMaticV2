/*
 * BaseDatos.h
 *
 *  Created on: 18 may. 2021
 *      Author: Julen
 */
#include <stdio.h>
#include "sqlite3.h"
#include <string.h>
#include "Tarea.h"

#ifndef BASEDATOS_H_
#define BASEDATOS_H_


int insertarTareas(sqlite3 *db, Tarea *tarea);
int borrarTareas(sqlite3 *db);
int ordenarTareasImp(sqlite3 *db);
int ordenarTareasDur(sqlite3 *db);
int buscarTareaTitulo(const char* titulo, sqlite3 *db);
int tareasDuracion(sqlite3 *db, int minutos, int opcion);
int tareasImportancia(sqlite3 *db, int importanciaR, int opcion);
int mostrarTodasTareas(sqlite3 *db);
int mostrarTareasSinCompletar(sqlite3 *db);


#endif /* BASEDATOS_H_ */
