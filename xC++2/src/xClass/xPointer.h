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
#include "../xDataTypes/xObject.h"

using namespace std;

class xPointer{
public:
	xPointer();
	virtual ~xPointer();

	void operator=(const xPointer pXPointer);
	//void operator=(AnyType pData);
	xObject* operator->();
	void operator++();
	void operator--();
	void operator-(int pCant);
	void operator+(int pCant);
	void operator-=(int pCant);
	void operator+=(int pCant);
	bool operator==(xPointer pXPointer);
	bool operator!=(xPointer pXPointer);
	xObject operator*();

	void setTopPointer(void* pTopPointer);
	void setLimitPointer(void* pLimitPointer);
	void setReference(int pReference);

	void* getTopPointer();
	void* getLimitPointer();
	int getReference();

private:
	void* _TopPointer;
	void* _LimitPointer;
	int _Reference;
};

#endif /* XPOINTER_H_ */
