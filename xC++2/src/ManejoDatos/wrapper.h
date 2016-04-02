/**
 * @file wrapper.h
 * @date 15/3/16
 * @author Gabriel Barboza Alvarez
 * @title Wrapper
 * @brief Abstracion de los primitivo para el proyecto xC++2
 */

#ifndef SRC_XCLASS_WRAPPER_H_
#define SRC_XCLASS_WRAPPER_H_

#include "xObject.h"
#include "../xMemoryManager/xMemoryManager.h"


//INT
class xInt : public xObject{
	int _Valor;

public:

	/**
	 * @brief Metodo costructor de xInt
	 * @param pData
	 */
	xInt(int pData);

	/**
	 * @brief Metodo devuelve el valor
	 * @return int
	 */
	int intValue();

	/**
	 * @brief Metodo destructor de xInt
	 */
	~xInt();
};

//FLOAT
class xFloat : public xObject{

private:
	float _Valor;

public:

	/**
	 * @brief Metodo costructor de xFloat
	 * @param pData
	 */
	xFloat(float pData);

	/**
	 * @brief Metodo devuelve el valor
	 * @return float
	 */
	float floatValue();

	/**
	 * @brief Metodo destructor de xFloat
	 */
	~xFloat();

};

//LONG
class xLong : public xObject{

private:

	long _Valor;

public:

	/**
	 * @brief Metodo costructor de xLong
	 * @param pData
	 */
	xLong(long pData);

	/**
	 * @brief Metodo devuelve el valor
	 * @return long
	 */
	long longValue();

	/**
	 * @brief Metodo destructor de xLong
	 */
	~xLong();
};

//SHORT
class xShort : public xObject{

private:
	short _Valor;

public:

	/**
	 * @brief Metodo costructor de xShort
	 * @param pData
	 */
	xShort(short pDato);

	/**
	 * @brief Metodo devuelve el valor
	 * @return short
	 */
	short shortValue();

	/**
	 * @brief Metodo destructor de xShort
	 */
	~xShort();

};

//BOOL
class xBool : public xObject{

private:
	bool _Valor;

public:

	/**
	 * @brief Metodo costructor de xBool
	 * @param pDato
	 */
	xBool(bool pDato);

	/**
	 * @brief Metodo devuelve el valor
	 * @return bool
	 */
	bool boolValue();

	/**
	 * @brief Metodo destructor de xBool
	 */
	~xBool();

};

//DOUBLE
class xDouble : public xObject{

private:
	double _Valor;

public:

	/**
	 * @brief Metodo costructor de xDouble
	 * @param pDato
	 */
	xDouble(double pDato);

	/**
	 * @brief Metodo devuelve el valor
	 * @return double
	 */
	double doubleValue();

	/**
	 * @brief Metodo destructor de xDouble
	 */
	~xDouble();

};

//CHAR
class xChar : public xObject{

private:
	char _Valor;

public:

	/**
	 * @brief Metodo costructor de xChar
	 * @param pDato
	 */
	xChar(char pDato);

	/**
	 * @brief Metodo devuelve el valor
	 * @return char
	 */
	char charValue();

	/**
	 * @brief Metodo destructor de xChar
	 */
	~xChar();
};
#endif /* SRC_XCLASS_WRAPPER_H_ */


