/*
 * xObject.h
 *
 *  Created on: 2 de mar. de 2016
 *      Author: gabriel
 */

#ifndef SRC_XCLASS_XOBJECT_H_
#define SRC_XCLASS_XOBJECT_H_
#include <stdio.h>
#include <iostream>
#include <iomanip>

class xObject {
public:
	xObject();
/*
	xJson* serialize();
	bool deserialize (xJson*);
*/	char* getClassName(void);
	virtual ~xObject();
	ID* HOLA = new ID();


};


#endif /* SRC_XCLASS_XOBJECT_H_ */

