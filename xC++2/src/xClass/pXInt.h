/**
 * @file pXInt.h
 * @date 20/3/16
 * @author Jose Eduardo Jimenez A 2014072577
 * @title pXInt
 * @brief Puntero de tipo pXInt
 */

#ifndef PXINT_H_
#define PXINT_H_

#include <iostream>
#include "../xDataTypes/wrapper.h"
#include "../xMemoryManager/xMemoryManager.h"

using namespace std;

class pXInt : public xPointer, public xMemoryManager{
public:
	/**
	 * @brief Metodo constructor de pXInt
	 * @param pDato
	 */
	pXInt(int pDato);
	/**
	 * @brief Metodo destructor de pXInt
	 */
	virtual ~pXInt();

	/**
	 * @brief Metodo sobreescribe operator =
	 * @param pPuntero
	 */
	void operator=(xInt* pPuntero);
	/**
	 * @brief Metodo sobreescribe operator ->
	 * @return xInt*
	 */
	xInt* operator->();
	/**
	 * @brief Metodo sobreescribe operator *
	 * @return int
	 */
	int operator*();

	/**
	 * @breif Metodo imprime el puntero pXInt
	 */
	void print();

};

#endif /* PXINT_H_ */
