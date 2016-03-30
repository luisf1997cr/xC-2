/*
 * wrapper.cpp
 *
 *  Created on: 21 de mar. de 2016
 *      Author: jose
 */
#include "wrapper.h"



xInt::xInt() {
	this->valor = 0;
}

int xInt::intValue() {
	return this->valor;
}

void* xInt::operator new(size_t pSize) {
	xPointer ptr = xMemoryManager::Instance()->xMalloc(pSize);
	cout << "hola"  << endl;
	int* Int = new(ptr.getTopPointer()) int();
	cout << "xMalloc: " << ptr.getTopPointer() << endl;
	return ptr.getTopPointer();
}

xInt::~xInt(){
	delete &this->valor;
}

