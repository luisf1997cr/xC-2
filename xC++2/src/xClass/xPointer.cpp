/*
 * xPointer.cpp
 *
 *  Created on: 20 de mar. de 2016
 *      Author: jose
 */

#include "xPointer.h"

xPointer::xPointer(){
	this->_Reference = 1;
	this->_LimitPointer = NULL;
}
void xPointer::operator =(const xPointer pXPointer){
	this->_TopPointer = pXPointer._TopPointer;
	this->_LimitPointer = pXPointer._LimitPointer;
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
	int size = ((int*)this->_LimitPointer - (int*)this->_TopPointer) * 4;
	this->_TopPointer = this->_TopPointer + size;
	this->_LimitPointer = this->_LimitPointer + size;
}
void xPointer::operator --(){
	int size = ((int*)this->_LimitPointer - (int*)this->_TopPointer) * 4;
	this->_TopPointer = this->_TopPointer - size;
	this->_LimitPointer = this->_LimitPointer - size;
}
void xPointer::operator -(int pCant){
	int size = ((int*)this->_LimitPointer - (int*)this->_TopPointer) * 4;
	this->_TopPointer = this->_TopPointer - size * pCant;
	this->_LimitPointer = this->_LimitPointer - size * pCant;
}
void xPointer::operator +(int pCant){
	int size = ((int*)this->_LimitPointer - (int*)this->_TopPointer) * 4;
	this->_TopPointer = this->_TopPointer + size * pCant;
	this->_LimitPointer = this->_LimitPointer + size * pCant;
}
void xPointer::operator -=(int pCant){
	int size = ((int*)this->_LimitPointer - (int*)this->_TopPointer) * 4;
	this->_TopPointer = this->_TopPointer - size * pCant;
	this->_LimitPointer = this->_LimitPointer - size * pCant;
}
void xPointer::operator +=(int pCant){
	int size = ((int*)this->_LimitPointer - (int*)this->_TopPointer) * 4;
	this->_TopPointer = this->_TopPointer + size * pCant;
	this->_LimitPointer = this->_LimitPointer + size * pCant;
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
void xPointer::setLimitPointer(void* pLimitPointer){
	this->_LimitPointer = pLimitPointer;
}
void* xPointer::getLimitPointer(){
	return this->_LimitPointer;
}
void xPointer::setReference(int pReference){
	this->_Reference = pReference;
}
int xPointer::getReference(){
	return this->_Reference;
}
xPointer::~xPointer(){
	// TODO Auto-generated destructor stub
}




