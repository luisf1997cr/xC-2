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
class Ficheros {
public:
	Ficheros();
	bool cadenaDentroDeOtra(char pline[], char pBuscar[]);

	int leerEnFichero(char nameArchive[]);

	int escribirEnFichero(char nameArchive[]);

	char* extraerParametrosInclude(char line[], int plarge);

	virtual ~Ficheros();
};

#endif /* SRC_MANEJODATOS_FICHEROS_H_ */
