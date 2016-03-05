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

template <class AnyType>
class NodoSimple {
public:
	string key;
	AnyType* val;
	NodoSimple * next;

	NodoSimple(string clave, AnyType* valor, NodoSimple * siguiente);
	virtual ~NodoSimple();
};

template <class AnyType>
NodoSimple<AnyType>::NodoSimple(string clave, AnyType* valor, NodoSimple* siguiente){
	key = clave;
	val = valor;
	next = siguiente;
}

template<class AnyType>
NodoSimple<AnyType>::~NodoSimple() {
	key.erase();
	delete val;
	delete next;
}

#endif /* SRC_MANEJODATOS_NODOSIMPLE_H_ */
