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


/**
 * Clase wrapper de un entero
 * @param Recibe un entero para su constructor
 */

class xInt {

private:
	int* valor;

public:

	xInt(int* val) {
		this->valor = val;
	}

	int* intValue() {
		return valor;
	}

	~xInt(){
		delete this->valor;
	}
};

class xFloat {

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

class xLong {

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

class xShort {

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

class xBool {

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

class xDouble {

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

class xChar {

private:
	char* valor;

public:

	xChar(char* val) {
		this->valor = val;
	}

	char* intValue() {
		return valor;
	}

	~xChar(){
		delete this->valor;
	}

};
#endif /* SRC_XCLASS_WRAPPER_H_ */
