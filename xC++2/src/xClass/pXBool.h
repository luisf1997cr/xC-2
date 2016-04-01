/**
 * @file pXBool.h
 * @date 28/3/16
 * @author Jose Eduardo Jimenez A 2014072577
 * @title pXBool
 * @brief Puntero del tipo xBool
 */

#ifndef PXBOOL_H_
#define PXBOOL_H_

#include <iostream>
#include "../xDataTypes/wrapper.h"
#include "../xMemoryManager/xMemoryManager.h"

using namespace std;

class pXBool : public xPointer, public xMemoryManager{
public:
	/**
	 * @brief Metodo constructor de pXBool
	 * @param pDato
	 */
	pXBool(bool pDato);
	/**
	 * @brief Metodo destructor de pXBool
	 */
	virtual ~pXBool();

	/**
	 * @brief Sobreescritura del operator =
	 * @param pPuntero
	 */
	void operator=(xBool* pPuntero);
	/**
	 * @brief Sobreescritura del operator ->
	 * @return xBool*
	 */
	xBool* operator->();
	/**
	 * @brief Sobreescritura del operator *
	 * @return bool
	 */
	bool operator*();

	/**
	 * @brief Metodo imprime el pXBool
	 */
	void print();

};

#endif /* PXBOOL_H_ */
