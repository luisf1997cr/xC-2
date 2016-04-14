/*
 * pXFloat.cpp
 *
 *  Created on: 26 de mar. de 2016
 *      Author: jose
 */

#include "pXFloat.h"

pXFloat::pXFloat(float pDato) {
	xPointer ptr = xMemoryManager::Instance()->xMalloc(sizeof(xFloat));
	xFloat* Float = new(ptr.getTopPointer()) xFloat(pDato);
	this->setTopPointer((void*)Float);
	this->setPointerSize(sizeof(xFloat));

}

pXFloat::~pXFloat() {
}

xFloat* pXFloat::operator ->(){
	void* ptr = this->getTopPointer();
	xFloat* dato = (xFloat*) ptr;
	return dato;
}

void pXFloat::operator =(xFloat* pPuntero){
	this->setTopPointer(pPuntero);
	this->setPointerSize(sizeof(xFloat));
}

float pXFloat::operator *(){
	void* ptr = this->getTopPointer();
	xFloat dato = *(xFloat*) ptr;
	return dato.floatValue();
}

void pXFloat::print(){
	xPointer::print();
	cout << xPointer::SIZE << this->getPointerSize() << xPointer::VALOR << (*this)->floatValue() << endl;
}

