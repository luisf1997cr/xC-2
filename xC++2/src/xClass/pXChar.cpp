/*
 * pXChar.cpp
 *
 *  Created on: 28 de mar. de 2016
 *      Author: jose
 */

#include "pXChar.h"

pXChar::pXChar(char pDato) {
	xPointer ptr = xMemoryManager::Instance()->xMalloc(sizeof(xChar));
	xChar* Char = new(ptr.getTopPointer()) xChar(pDato);
	this->setTopPointer((void*)Char);
	this->setPointerSize(sizeof(xChar));
}

pXChar::~pXChar() {
}

xChar* pXChar::operator ->(){
	void* ptr = this->getTopPointer();
	xChar* dato = (xChar*) ptr;
	return dato;
}

void pXChar::operator =(xChar* pPuntero){
	this->setTopPointer(pPuntero);
	this->setPointerSize(sizeof(xChar));
}

char pXChar::operator *(){
	void* ptr = this->getTopPointer();
	xChar dato = *(xChar*) ptr;
	return dato.charValue();
}

void pXChar::print(){
	xPointer::print();
	cout << "Tamaño: " << this->getPointerSize() << " Valor: " << (*this)->charValue() << endl;
}


