/*
 * pXDouble.cpp
 *
 *  Created on: 28 de mar. de 2016
 *      Author: jose
 */

#include "pXDouble.h"

pXDouble::pXDouble(double pDato) {
	xPointer ptr = xMemoryManager::Instance()->xMalloc(sizeof(xDouble));
	xDouble* Double = new(ptr.getTopPointer()) xDouble(pDato);
	this->setTopPointer((void*) Double);
	this->setPointerSize(sizeof(xDouble));
}

pXDouble::~pXDouble() {
}

xDouble* pXDouble::operator->(){
	void* ptr = this->getTopPointer();
	xDouble* dato = (xDouble*) ptr;
	return dato;
}

void pXDouble::operator =(xDouble* pPuntero){
	this->setTopPointer(pPuntero);
	this->setPointerSize(sizeof(xDouble));
}

double pXDouble::operator *(){
	void* ptr = this->getTopPointer();
	xDouble dato = *(xDouble*) ptr;
	return dato.doubleValue();
}

void pXDouble::print(){
	xPointer::print();
	cout << xPointer::SIZE << this->getPointerSize() << xPointer::VALOR << (*this)->doubleValue() << endl;
}
