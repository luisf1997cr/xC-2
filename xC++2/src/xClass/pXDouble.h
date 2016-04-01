/**
 * @file pXDouble.h
 * @date 28/3/16
 * @author Jose Eduardo Jimenez A 2014072577
 * @title pXDouble
 * @brief Puntero del tipo xDouble
 */

#ifndef PXDOUBLE_H_
#define PXDOUBLE_H_

#include <iostream>
#include "../xDataTypes/wrapper.h"
#include "../xMemoryManager/xMemoryManager.h"

class pXDouble : public xPointer, public xMemoryManager{
public:

	/**
	 * @brief Metodo constructor de pXDouble
	 * @param pDato
	 */
	pXDouble(double pDato);
	/**
	 * @brief Metodo destructor de pXDouble
	 */
	virtual ~pXDouble();

	/**
	 * @brief Metodo sobreescribe el operador =
	 * @param pPuntero
	 */
	void operator=(xDouble* pPuntero);
	/**
	 * @brief Metodo sobreescribe el operador ->
	 * @return xDouble*
	 */
	xDouble* operator->();
	/**
	 * @brief Metodo sobreescribe el operador *
	 * @return double
	 */
	double operator*();

	/**
	 * @brief Metodo imprime el pXDouble
	 */
	void print();
};

#endif /* PXDOUBLE_H_ */
