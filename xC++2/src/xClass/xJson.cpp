/*
 * xJson.cpp
 *
 *  Created on: 5 de mar. de 2016
 *      Author: steven
 */

#include "xJson.h"
using namespace std;



xJson::xJson(string pString) {
	this->_StringJson = pString;

}

xJson::~xJson() {
	// TODO Auto-generated destructor stub
}

string xJson::getString(){
	return xJson::_StringJson;
}
