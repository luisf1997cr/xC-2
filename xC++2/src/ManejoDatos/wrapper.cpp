/*
 * wrapper.cpp
 *
 *  Created on: 21 de mar. de 2016
 *      Author: jose
 */
#include "wrapper.h"


//INT
xInt::xInt(int pDato) {
	this->_Valor = pDato;
}

int xInt::intValue() {
	return this->_Valor;
}


xInt::~xInt(){
	//memset(this, 0, sizeof(xInt));
}

//FLOAT
xFloat::xFloat(float pDato){
	this->_Valor = pDato;
}

float xFloat::floatValue(){
	return this->_Valor;
}

xFloat::~xFloat(){
	delete &this->_Valor;
}

//LONG
xLong::xLong(long pDato){
	this->_Valor = pDato;
}

long xLong::longValue(){
	return this->_Valor;
}

xLong::~xLong(){
	delete &this->_Valor;
}

//SHORT
xShort::xShort(short pDato){
	this->_Valor = pDato;
}

short xShort::shortValue(){
	return this->_Valor;
}

xShort::~xShort(){
	delete &this->_Valor;
}


//BOOL
xBool::xBool(bool pDato){
	this->_Valor = pDato;
}

bool xBool::boolValue(){
	return this->_Valor;
}

xBool::~xBool(){
	delete &this->_Valor;
}

//DOUBLE
xDouble::xDouble(double pDato){
	this->_Valor = pDato;
}

double xDouble::doubleValue(){
	return this->_Valor;
}

xDouble::~xDouble(){
	delete &this->_Valor;
}

//CHAR
xChar::xChar(char pDato){
	this->_Valor = pDato;
}

char xChar::charValue(){
	return this->_Valor;
}

xChar::~xChar(){
	delete &this->_Valor;
}
