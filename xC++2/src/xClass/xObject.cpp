/*
 * xObject.cpp
 *
 *  Created on: 2 de mar. de 2016
 *      Author: gabriel
 */

#include "xObject.h"

long int xObject::_Id = 0;

xObject::xObject(){
	this->_Id++;
}

void xObject::setId(long int pID){
	this->_Id = pID;
}

long int xObject::getId(){
	return this->_Id;
}

xObject::~xObject(){

}

//xJson* xObject::serialize(){
//	//Json::Value valorJson;
//	Json::StyledWriter escritor;
//
//
//}
