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


#include "xObject.h"
#include "../xMemoryManager/xMemoryManager.h"


/**
 * Clase wrapper de un entero
 * @param Recibe un entero para su constructor
 */
//INT
class xInt : public xObject{
	int _Valor;

public:

	//void* operator new(size_t pSize);

	xInt(int pData);

	int intValue();

	~xInt();
};

//FLOAT
class xFloat : public xObject{

private:
	float _Valor;

public:

	xFloat(float pData);

	float floatValue();

	~xFloat();

};

//LONG
class xLong : public xObject{

private:
	long _Valor;

public:

	xLong(long pData);

	long longValue();

	~xLong();
};

//SHORT
class xShort : public xObject{

private:
	short _Valor;

public:

	xShort(short pDato);

	short shortValue();

	~xShort();

};

//BOOL
class xBool : public xObject{

private:
	bool _Valor;

public:

	xBool(bool pDato);

	bool boolValue();

	~xBool();

};

//DOUBLE
class xDouble : public xObject{

private:
	double _Valor;

public:

	xDouble(double pDato);

	double doubleValue();

	~xDouble();

};

//CHAR
class xChar : public xObject{

private:
	char _Valor;

public:

	xChar(char val);

	char charValue();

	~xChar();
};
#endif /* SRC_XCLASS_WRAPPER_H_ */


