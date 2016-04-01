/**
 * @file pXFloat.h
 * @date 26/3/16
 * @author Jose Eduardo Jimenez A 2014072577
 * @title pXFloat
 * @brief Puntero de tipo pXFloat
 */

#ifndef PXFLOAT_H_
#define PXFLOAT_H_

#include <iostream>
#include "../xDataTypes/wrapper.h"
#include "../xMemoryManager/xMemoryManager.h"

using namespace std;

class pXFloat : public xPointer, public xMemoryManager{
public:
	/**
	 * @brief Metodo constructor de pXFloat
	 * @param pDato
	 */
	pXFloat(float pDato);
	/**
	 * @brief Metodo destructor de pXFloat
	 */
	virtual ~pXFloat();

	/**
	 * @brief Metodo sobreescribe operator =
	 * @param pPuntero
	 */
	void operator=(xFloat* pPuntero);
	/**
	 * @brief Metodo sobreescribe operator ->
	 * @return xFloat*
	 */
	xFloat* operator->();
	/**
	 * @brief Metodo sobreescribe operator *
	 * @return float
	 */
	float operator*();


	/**
	 * @breif Metodo imprime el puntero pXFloat
	 */
	void print();
};

#endif /* PXFLOAT_H_ */
