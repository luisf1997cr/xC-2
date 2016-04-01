/*
 * pXShort.cpp
 *
 *  Created on: 26 de mar. de 2016
 *      Author: jose
 */

#include "pXShort.h"

pXShort::pXShort(short pDato) {
	xPointer ptr = xMemoryManager::Instance()->xMalloc(sizeof(xShort));
	xShort* Short = new(ptr.getTopPointer()) xShort(pDato);
	this->setTopPointer((void*)Short);
	this->setPointerSize(sizeof(xShort));
}

pXShort::~pXShort() {
}

xShort* pXShort::operator ->(){
	void* ptr = this->getTopPointer();
	xShort* dato = (xShort*) ptr;
	return dato;
}

void pXShort::operator =(xShort* pPuntero){
	this->setTopPointer(pPuntero);
	this->setPointerSize(sizeof(xShort));
}

short pXShort::operator *(){
	void* ptr = this->getTopPointer();
	xShort dato = *(xShort*) ptr;
	return dato.shortValue();
}

void pXShort::print(){
	xPointer::print();
	cout << "Tamaño: " << this->getPointerSize() << " Valor: " << (*this)->shortValue() << endl;
}

