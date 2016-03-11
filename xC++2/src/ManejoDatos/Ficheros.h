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

class Ficheros {
public:
	Ficheros();
	bool contiene(char line[]);
	int leer(char nameArchive[]);
	int escribir(char nameArchive[]);
	virtual ~Ficheros();
};

#endif /* SRC_MANEJODATOS_FICHEROS_H_ */
