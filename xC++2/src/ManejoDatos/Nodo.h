/*
 * Nodo.h
 *
 *  Created on: 3 de mar. de 2016
 *      Author: gabriel
 */

#ifndef SRC_MANEJODATOS_NODO_H_
#define SRC_MANEJODATOS_NODO_H_

#include <iostream>

class Nodo {
public:
public:
    Nodo(int v, Nodo *sig = NULL, Nodo *ant = NULL) :
       valor(v), siguiente(sig), anterior(ant) {}

   private:
    int valor;
    Nodo *siguiente;
    Nodo *anterior;

   friend class lista;
	Nodo();
	virtual ~Nodo();
};

#endif /* SRC_MANEJODATOS_NODO_H_ */
