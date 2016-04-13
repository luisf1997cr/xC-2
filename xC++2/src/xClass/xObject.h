/**
 * @file xObject.h
 * @date 9/3/16
 * @author Jose Eduardo Jimenez A 2014072577
 * @title xObject
 * @brief Abstracion de un objeto del tipo Object para el proyecto xC++2
 */

#ifndef XOBJECT_H_
#define XOBJECT_H_

#include "ID.h"
#include <iostream>
using namespace std;

class xObject{
public:
	/**
	 * @brief Metodo costructor de xObject
	 */
	xObject();
	/**
	 * @brief Metodo destructor de xObject
	 */
	virtual ~xObject();

	/**
	 * @brief Metodo define el argumento Id
	 * @param pID
	 */
	void setId(long int pID);

	/**
	 * @brief Metodo devuelve el argumento Id
	 * @return long int ID
	 */
	long int getId();

	xJson* serialize();
	
	bool deserialize(xJson* pJson);
	
private:
	static long int _Id;
};


#endif /* XOBJECT_H_ */
