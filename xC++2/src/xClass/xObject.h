/*
 * xObject.h
 *
 *  Created on: 2 de mar. de 2016
 *      Author: gabriel
 */

#ifndef SRC_XCLASS_XOBJECT_H_
#define SRC_XCLASS_XOBJECT_H_
#include "ID.h"
class xObject {
public:
	xObject();
/*
	xJson* serialize();
	bool deserialize (xJson*);
*/	char* getClassName(void);
	ID valorID;
	virtual ~xObject();
};

#endif /* SRC_XCLASS_XOBJECT_H_ */
