/*
 * pXInt.cpp
 *
 *  Created on: 20 de mar. de 2016
 *      Author: jose
 */

#include "pXInt.h"

pXInt::pXInt(int pDato) {
	xPointer ptr = xMemoryManager::Instance()->xMalloc(sizeof(xInt));
	xInt* Int = new(ptr.getTopPointer()) xInt(pDato);
	this->setTopPointer((void*)Int);
	this->setPointerSize(sizeof(xInt));
}

pXInt::~pXInt() {
	xMemoryManager::Instance()->xFree(this->super());
}

xInt* pXInt::operator ->(){
	void* ptr = this->getTopPointer();
	xInt* dato = (xInt*) ptr;
	return dato;
}

void pXInt::operator =(xInt* pPuntero){
	this->setTopPointer(pPuntero);
	this->setPointerSize(sizeof(xInt));
}

int pXInt::operator *(){
	void* ptr = this->getTopPointer();
	xInt dato = *(xInt*) ptr;
	return dato.intValue();
}

void pXInt::print(){
	xPointer::print();
	cout << "Tamaño: " << this->getPointerSize() << " Valor: " << (*this)->intValue() << endl;
}
