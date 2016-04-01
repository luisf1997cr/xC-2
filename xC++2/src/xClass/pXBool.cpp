/*
 * pXBool.cpp
 *
 *  Created on: 28 de mar. de 2016
 *      Author: jose
 */

#include "pXBool.h"

pXBool::pXBool(bool pDato) {
	xPointer ptr = xMemoryManager::Instance()->xMalloc(sizeof(xBool));
	xBool* Bool = new(ptr.getTopPointer()) xBool(pDato);
	this->setTopPointer((void*)Bool);
	this->setPointerSize(sizeof(xBool));
}

pXBool::~pXBool() {
}

xBool* pXBool::operator ->(){
	void* ptr = this->getTopPointer();
	xBool* dato = (xBool*) ptr;
	return dato;
}

void pXBool::operator =(xBool* pPuntero){
	this->setTopPointer(pPuntero);
	this->setPointerSize(sizeof(xBool));
}

bool pXBool::operator *(){
	void* ptr = this->getTopPointer();
	xBool dato = *(xBool*) ptr;
	return dato.boolValue();
}

void pXBool::print(){
	xPointer::print();
	cout << "Tamaño: " << this->getPointerSize() << " Valor: " << (*this)->boolValue() << endl;
}

