/*
 * wrapper.h
 *
 *  Created on: 15 de mar. de 2016
 *      Author: gabriel
 *
 *      Se encarga de los wrappers de los primitivos
 */

#ifndef SRC_XCLASS_WRAPPER_H_
#define SRC_XCLASS_WRAPPER_H_

#include <new>
#include "xObject.h"
#include "../xMemoryManager/xMemoryManager.h"


/**
 * Clase wrapper de un entero
 * @param Recibe un entero para su constructor
 */

class xInt : public xObject, public xMemoryManager{

private:
	int valor;

public:

	void* operator new(size_t pSize);

	xInt();

	int intValue();

	~xInt();
};

class xFloat : public xObject{

private:
	float* valor;

public:

	xFloat(float* val) {
		this->valor = val;
	}

	float* intValue() {
		return valor;
	}

	~xFloat(){
		delete this->valor;
	}

};

class xLong : public xObject{

private:
	long* valor;

public:

	xLong(long* val) {
		this->valor = val;
	}

	long* intValue() {
		return valor;
	}

	~xLong(){
		delete this->valor;
	}
};

class xShort : public xObject{

private:
	short* valor;

public:

	xShort(short* val) {
		this->valor = val;
	}

	short* intValue() {
		return valor;
	}

	~xShort(){
		delete this->valor;
	}

};

class xBool : public xObject{

private:
	bool* valor;

public:

	xBool(bool* val) {
		this->valor = val;
	}

	bool* intValue() {
		return valor;
	}

	~xBool(){
		delete this->valor;
	}

};

class xDouble : public xObject{

private:
	double* valor;

public:

	xDouble(double* val) {
		this->valor = val;
	}

	double* intValue() {
		return valor;
	}

	~xDouble(){
		delete this->valor;
	}

};

class xChar : public xObject{

private:
	char* valor;

public:

	xChar(char* val) {
		this->valor = val;
	}

	char* intValue() {
		cout << valor << endl;
		return valor;
	}

	~xChar(){
		delete this->valor;
	}
};
#endif /* SRC_XCLASS_WRAPPER_H_ */


