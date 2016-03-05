/*
 * NodoSimple.cpp
 *
 *  Created on: 4 de mar. de 2016
 *      Author: gabriel
 */

#include "NodoSimple.h"

NodoSimple::NodoSimple(string clave, void* valor, NodoSimple * siguiente) {
	// TODO Auto-generated constructor stub

	key = clave;
	val = valor;
	next = siguiente;
}

NodoSimple::~NodoSimple() {
	// TODO Auto-generated destructor stub
	key.erase();
	delete val;
	delete next;
}

