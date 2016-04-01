/*
 * xPointer.cpp
 *
 *  Created on: 20 de mar. de 2016
 *      Author: jose
 */

#include "xPointer.h"

xPointer::xPointer(){
	this->_Reference = 1;
	this->_TopPointer = (void*)0;
	this->_PointerSize = new long int(0);
}


void xPointer::operator =(xPointer pXPointer){
	this->_TopPointer = pXPointer._TopPointer;
	this->_PointerSize = pXPointer._PointerSize;
	pXPointer.setReference(pXPointer.getReference()+1);
}
//template<class AnyType>
//void xPointer<AnyType>::operator =(AnyType pData){
//	xMemoryManager MM;
//	MM.xSet(*this,pData);
//	//xMemoryManager::xSet(*this,pData);
//}
xObject* xPointer::operator ->(){
	void* ptr = this->_TopPointer;
	xObject* dato = (xObject*) ptr;
	return dato;
}
void xPointer::operator ++(){
	int size = ((int*)this->_PointerSize - (int*)this->_TopPointer) * 4;
	this->_TopPointer = this->_TopPointer + size;
	this->_PointerSize = this->_PointerSize + size;
}
void xPointer::operator --(){
	int size = ((int*)this->_PointerSize - (int*)this->_TopPointer) * 4;
	this->_TopPointer = this->_TopPointer - size;
	this->_PointerSize = this->_PointerSize - size;
}
void xPointer::operator -(int pCant){
	int size = ((int*)this->_PointerSize - (int*)this->_TopPointer) * 4;
	this->_TopPointer = this->_TopPointer - size * pCant;
	this->_PointerSize = this->_PointerSize - size * pCant;
}
void xPointer::operator +(int pCant){
	int size = ((int*)this->_PointerSize - (int*)this->_TopPointer) * 4;
	this->_TopPointer = this->_TopPointer + size * pCant;
	this->_PointerSize = this->_PointerSize + size * pCant;
}
void xPointer::operator -=(int pCant){
	int size = ((int*)this->_PointerSize - (int*)this->_TopPointer) * 4;
	this->_TopPointer = this->_TopPointer - size * pCant;
	this->_PointerSize = this->_PointerSize - size * pCant;
}
void xPointer::operator +=(int pCant){
	int size = ((int*)this->_PointerSize - (int*)this->_TopPointer) * 4;
	this->_TopPointer = this->_TopPointer + size * pCant;
	this->_PointerSize = this->_PointerSize + size * pCant;
}
bool xPointer::operator ==(xPointer pXPointer){
	if(this->_TopPointer == pXPointer.getTopPointer()){
		return true;
	}
	return false;
}
bool xPointer::operator !=(xPointer pXPointer){
	if(this->_TopPointer == pXPointer.getTopPointer()){
		return false;
	}
	return true;
}
xObject xPointer::operator *(){
	void* ptr = this->_TopPointer;
	xObject dato = *(xObject*) ptr;
	return dato;
}
void xPointer::setTopPointer(void* pTopPointer){
	this->_TopPointer = pTopPointer;
}
void* xPointer::getTopPointer(){
	return this->_TopPointer;
}
void xPointer::setPointerSize(long int pPointerSize){
	this->_PointerSize = new long int(pPointerSize);
}
long int xPointer::getPointerSize(){
	return *this->_PointerSize;
}
void xPointer::setReference(int pReference){
	this->_Reference = pReference;
}
int xPointer::getReference(){
	return this->_Reference;
}

void xPointer::print(){
	cout << "Dirrecion: " << this->_TopPointer << " Referencia: " << this->_Reference << endl;
}

xPointer xPointer::super(){
	return *this;
}

xPointer::~xPointer(){
	//memset(this->_TopPointer, 0, *(int*)this->_PointerSize);
}
