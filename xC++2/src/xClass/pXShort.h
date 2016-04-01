/**
 * @file pXShort.h
 * @date 26/3/16
 * @author Jose Eduardo Jimenez A 2014072577
 * @title pXShort
 * @brief Puntero de tipo pXShort
 */

#ifndef PXSHORT_H_
#define PXSHORT_H_

#include <iostream>
#include "../xDataTypes/wrapper.h"
#include "../xMemoryManager/xMemoryManager.h"

using namespace std;

class pXShort : public xPointer, public xMemoryManager{
public:
	/**
	 * @brief Metodo constructor de pXShort
	 * @param pDato
	 */
	pXShort(short pDato);
	/**
	 * @brief Metodo destructor de pXShort
	 */
	virtual ~pXShort();

	/**
	 * @brief Metodo sobreescribe operator =
	 * @param pPuntero
	 */
	void operator=(xShort* pPuntero);
	/**
	 * @brief Metodo sobreescribe operator ->
	 * @return xShort*
	 */
	xShort* operator->();
	/**
	 * @brief Metodo sobreescribe operator *
	 * @return short
	 */
	short operator*();

	/**
	 * @breif Metodo imprime el puntero pXShort
	 */
	void print();
};

#endif /* PXSHORT_H_ */
