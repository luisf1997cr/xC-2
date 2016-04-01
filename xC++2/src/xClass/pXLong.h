/**
 * @file pXLong.h
 * @date 26/3/16
 * @author Jose Eduardo Jimenez A 2014072577
 * @title pXLong
 * @brief Puntero de tipo pXLong
 */

#ifndef PXLONG_H_
#define PXLONG_H_

#include <iostream>
#include "../xDataTypes/wrapper.h"
#include "../xMemoryManager/xMemoryManager.h"

using namespace std;

class pXLong : public xPointer, public xMemoryManager{
public:
	/**
	 * @brief Metodo constructor de pXLong
	 * @param pDato
	 */
	pXLong(long pDato);
	/**
	 * @brief Metodo destructor de pXLong
	 */
	virtual ~pXLong();

	/**
	 * @brief Metodo sobreescribe operator =
	 * @param pPuntero
	 */
	void operator=(xLong* pPuntero);
	/**
	 * @brief Metodo sobreescribe operator ->
	 * @return xLong*
	 */
	xLong* operator->();
	/**
	 * @brief Metodo sobreescribe operator *
	 * @return long
	 */
	long operator*();

	/**
	 * @breif Metodo imprime el puntero pXLong
	 */
	void print();
};

#endif /* PXLONG_H_ */
