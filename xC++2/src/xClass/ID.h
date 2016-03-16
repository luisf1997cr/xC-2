/*
 * ID.h
 *
 *  Created on: 11 de mar. de 2016
 *      Author: acacia
 */

#ifndef SRC_XCLASS_ID_H_
#define SRC_XCLASS_ID_H_
#include <stdio.h>

class ID {
public:
	static long int id=0;
	ID();
	virtual ~ID(){delete ID::id;}
	int getID(){return ID::id;}

};
ID::ID(){
	ID::id++;
}

#endif /* SRC_XCLASS_ID_H_ */

