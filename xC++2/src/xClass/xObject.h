/*
 * xObject.h
 *
 *  Created on: 2 de mar. de 2016
 *      Author: gabriel
 */

#ifndef SRC_XCLASS_XOBJECT_H_
#define SRC_XCLASS_XOBJECT_H_

class xObject {
public:
	xObject();

	xJson* serialize();
	bool deserialize (xJson*);
	char* getClassName();
	long getId();

	virtual ~xObject();
};

#endif /* SRC_XCLASS_XOBJECT_H_ */
