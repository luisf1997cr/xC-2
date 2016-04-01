/**
 * @file xPointer.h
 * @date 8/3/16
 * @author Jose Eduardo Jimenez A 2014072577
 * @title xPointer
 * @brief Abstracion de un puntero para el proyecto xC++2
 */
#ifndef XPOINTER_H_
#define XPOINTER_H_
#include <iostream>
#include <cstring>
#include "../xDataTypes/xObject.h"

using namespace std;

class xPointer{
public:
	/**
	 * @brief Metodo constructor de xPointer
	 */
	xPointer();
	/**
	 * @brief Metodo destructor de xPointer
	 */
	virtual ~xPointer();

	/**
	 * @brief Metodo sobreescribe operator =
	 * @param pPuntero
	 */
	void operator=(xPointer pXPointer);
	//void operator=(AnyType pData);
	/**
	 * @brief Metodo sobreescribe operator ->
	 * @return xObject*
	 */
	xObject* operator->();
	/**
	 * @brief Metodo sobreescribe operator +
	 */
	void operator++();
	/**
	 * @brief Metodo sobreescribe operator --
	 */
	void operator--();
	/**
	 * @brief Metodo sobreescribe operator -
	 * @param pCant
	 */
	void operator-(int pCant);
	/**
	 * @brief Metodo sobreescribe operator +
	 * @param pCant
	 */
	void operator+(int pCant);
	/**
	 * @brief Metodo sobreescribe operator -=
	 * @param pCant
	 */
	void operator-=(int pCant);
	/**
	 * @brief Metodo sobreescribe operator +=
	 * @param pCant
	 */
	void operator+=(int pCant);
	/**
	 * @brief Metodo sobreescribe operator ==
	 * @param pXPointer
	 * @return bool
	 */
	bool operator==(xPointer pXPointer);
	/**
	 * @brief Metodo sobreescribe operator !=
	 * @param pXPointer
	 * @return bool
	 */
	bool operator!=(xPointer pXPointer);
	/**
	 * @brief Metodo sobreescribe operator *
	 * @return xObject
	 */
	xObject operator*();

	/**
	 * @brief Metodo define el atributo _TopPointer
	 * @param pTopPointer
	 */
	void setTopPointer(void* pTopPointer);
	/**
	 * @brief Metodo define el atributo _PointerSize
	 * @param pPointerSize
	 */
	void setPointerSize(long int pPointerSize);
	/**
	 * @brief Metodo define el atributo _Reference
	 * @param pReference
	 */
	void setReference(int pReference);

	/**
	 * @brief Metodo devuelve el atributo _TopPointer
	 * @return void*
	 */
	void* getTopPointer();
	/**
	 * @brief Metodo devuelve el atributo _PointerSize
	 * @return long
	 */
	long int getPointerSize();
	/**
	 * @brief Metodo devuelve el atributo _Reference
	 * @return int
	 */
	int getReference();
	/**
	 * @brief Metodo devuelve el puntero xPointer
	 * @return xPointer
	 */
	xPointer super();

	/**
	 * @breif Metodo imprime el puntero
	 */
	void print();

private:
	void* _TopPointer;
	long int* _PointerSize;
	int _Reference;
};

#endif /* XPOINTER_H_ */
