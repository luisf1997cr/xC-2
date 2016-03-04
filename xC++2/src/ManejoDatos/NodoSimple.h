/*
 * NodoSimple.h
 *
 *  Created on: 4 de mar. de 2016
 *      Author: gabriel
 */

#ifndef SRC_MANEJODATOS_NODOSIMPLE_H_
#define SRC_MANEJODATOS_NODOSIMPLE_H_

#include <iostream>
#include <string>
using namespace std;

class NodoSimple {
public:
	string key;

	NodoSimple * next;

	NodoSimple(string clave, NodoSimple * siguiente);
	virtual ~NodoSimple();
};

#endif /* SRC_MANEJODATOS_NODOSIMPLE_H_ */
