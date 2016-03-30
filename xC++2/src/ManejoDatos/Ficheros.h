/*
 * Ficheros.h
 *
 *  Created on: 4 de mar. de 2016
 *      Author: gabriel
 */

#ifndef SRC_MANEJODATOS_FICHEROS_H_
#define SRC_MANEJODATOS_FICHEROS_H_

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"

#include <sys/types.h>
#include <dirent.h>


class Ficheros {
public:
	Ficheros();
	bool cadenaDentroDeOtra(char pline[], char pBuscar[]);

	void leerEnFichero(char pnameArchive[]);

	void escribirEnFicheroExistente(char nameArchive[], char pEscribir[]);

	void escribirEnFicheroNuevo(char nameArchive[], char pEscribir[]);

	char* extraerParametrosInclude(char pline[], int plarge);

	void leerEnFicheroPrepro(char pnameArchive[], char pBuscar[]);

	void LogicaDeIncludeSerializar(char pline[]);

	void LogicaDeIncludeDesserializar(char pline[]);

	int BuscarArchivosEnFolder(char pSourceDir[], char pBusscar[]);

	virtual ~Ficheros();
};

#endif /* SRC_MANEJODATOS_FICHEROS_H_ */
