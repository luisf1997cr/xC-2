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
#include "jsoncpp/json.h"

class xObject {
public:
	xObject();

	//xJson* serialize();
	bool deserialize (xJson*);
	char* getClassName(void);
	virtual ~xObject();
	void setId(long int pID);
	long int getId();


private:
	static long int _Id;


};


#endif /* SRC_XCLASS_XOBJECT_H_ */

