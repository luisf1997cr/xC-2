/**
 * @file pXChar.h
 * @date 28/3/16
 * @author Jose Eduardo Jimenez A 2014072577
 * @title pXChar
 * @brief Puntero del tipo de dato pXChar
 */

#ifndef PXCHAR_H_
#define PXCHAR_H_

#include <iostream>
#include "../xDataTypes/wrapper.h"
#include "../xMemoryManager/xMemoryManager.h"

using namespace std;

class pXChar : public xPointer, public xMemoryManager{
public:
	/**
	 * @brief Metodo constructor de pXChar
	 * @param pDato
	 */
	pXChar(char pDato);
	/**
	 * @brief Metodo destructor de pXChar
	 */
	virtual ~pXChar();

	/**
	 * @brief Metodo sobreescribe operator =
	 * @param pPuntero
	 */
	void operator=(xChar* pPuntero);
	/**
	 * @brief Metodo sobreescribe operator ->
	 * @return xChar*
	 */
	xChar* operator->();
	/**
	 * @brief Metodo sobreescribe operator *
	 * @return char
	 */
	char operator*();

	/**
	 * @brief Metodo imprime el puntero pXChar
	 */
	void print();
};

#endif /* PXCHAR_H_ */
