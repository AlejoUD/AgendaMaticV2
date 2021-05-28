/*
 * prueba.cpp
 *
 *  Created on: 15 may. 2021
 *      Author: Julen
 */
#include "Tarea.h"
#include <string.h>
Tarea::Tarea(char *fecha, int duracion, int importancia, char *titulo, char *descripcion)
{
	this->fecha = new char[strlen(fecha) + 1];
	strcpy(this->fecha, fecha);
	this->duracion = duracion;
	this->importancia = importancia;
	this->titulo = new char[strlen(titulo) + 1];
	strcpy(this->titulo, titulo);
	this->descripcion = new char[strlen(descripcion) + 1];
	strcpy(this->descripcion, descripcion);

}
Tarea::~Tarea()
{
	delete[] fecha;
	delete[] titulo;
	delete[] descripcion;
}
Tarea::Tarea(const Tarea &t)
{
	this->fecha = new char[strlen(t.fecha) + 1];
	strcpy(this->fecha, t.fecha);
	this->duracion = t.duracion;
	this->importancia = t.importancia;
	this->titulo = new char[strlen(t.titulo) + 1];
	strcpy(this->titulo, t.titulo);
	this->descripcion = new char[strlen(t.descripcion) + 1];
	strcpy(this->descripcion, t.descripcion);
}

char* Tarea::getDescripcion()
{
	return descripcion;
}

void Tarea::setDescripcion(char *descripcion)
{
	this->descripcion = descripcion;
}

int Tarea::getDuracion()
{
	return duracion;
}

void Tarea::setDuracion(int duracion)
{
	this->duracion = duracion;
}

char* Tarea::getFecha()
{
	return fecha;
}

void Tarea::setFecha(char *fecha)
{
	this->fecha = fecha;
}

int Tarea::getImportancia()
{
	return importancia;
}

void Tarea::setImportancia(int importancia)
{
	this->importancia = importancia;
}

char* Tarea::getTitulo()
{
	return titulo;
}

void Tarea::setTitulo(char *titulo)
{
	this->titulo = titulo;
}



