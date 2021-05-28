/*
 * prueba.h
 *
 *  Created on: 15 may. 2021
 *      Author: Julen
 */

#ifndef TAREA_H_
#define TAREA_H_

class Tarea
{
public:

	char *fecha;
	int duracion;
	int importancia;
	char *titulo;
	char *descripcion;

public:
	Tarea(char *fecha, int duracion, int importancia, char *titulo, char *descripcion);
	~Tarea();
	Tarea(const Tarea &t);

	char* getDescripcion();

	void setDescripcion(char *descripcion);

	int getDuracion();

	void setDuracion(int duracion);

	char* getFecha();

	void setFecha(char *fecha);

	int getImportancia();

	void setImportancia(int importancia);

	char* getTitulo();

	void setTitulo(char *titulo);

};


#endif /* TAREA_H_ */
