/*
 * xPointer.h
 *
 *  Created on: 2 de mar. de 2016
 *      Author: gabriel
 */

#ifndef SRC_XCLASS_XPOINTER_H_
#define SRC_XCLASS_XPOINTER_H_


template<typename T>

class xPointer {
	T* ptr;
public:
	xPointer();

	explicit xPointer(T* ptr = 0) : ptr(ptr) {}
	virtual ~xPointer(){
		delete ptr;
	}

	T& operator*() { return *ptr; }
	T* operator->() { return ptr; }
};

#endif /* SRC_XCLASS_XPOINTER_H_ */
