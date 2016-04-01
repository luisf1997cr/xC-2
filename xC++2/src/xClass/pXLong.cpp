/*
 * pXLong.cpp
 *
 *  Created on: 26 de mar. de 2016
 *      Author: jose
 */

#include "pXLong.h"

pXLong::pXLong(long pDato) {
	xPointer ptr = xMemoryManager::Instance()->xMalloc(sizeof(xInt));
	xLong* Long = new(ptr.getTopPointer()) xLong(pDato);
	this->setTopPointer((void*)Long);
	this->setPointerSize(sizeof(xLong));
}

pXLong::~pXLong() {
}

xLong* pXLong::operator ->(){
	void* ptr = this->getTopPointer();
	xLong* dato = (xLong*) ptr;
	return dato;
}

void pXLong::operator =(xLong* pPuntero){
	this->setTopPointer(pPuntero);
	this->setPointerSize(sizeof(xLong));
}

long pXLong::operator *(){
	void* ptr = this->getTopPointer();
	xLong dato = *(xLong*) ptr;
	return dato.longValue();
}

void pXLong::print(){
	xPointer::print();
	cout << "Tamaño: " << this->getPointerSize() << " Valor: " << (*this)->longValue() << endl;
}
