/*
 * xJson.h
 *
 *  Created on: 5 de mar. de 2016
 *      Author: steven
 */

#include <string>
#include <sstream>
#include "jsoncpp/json.h"
#include "xObject.h"

#ifndef SRC_XCLASS_XJSON_H_
#define SRC_XCLASS_XJSON_H_

class xJson {
private:
	string _StringJson;
public:
	xJson(string pString);
	virtual ~xJson();
	string getString();
};

#endif /* SRC_XCLASS_XJSON_H_ */
