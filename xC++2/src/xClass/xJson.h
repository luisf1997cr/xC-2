/**
 * @file xJson.h
 * @date 15/3/16
 * @author Maider Steven Sánchez González
 * @title xJson
 * @brief Clase que crea los objetos xJson cuando se serializa un objeto 
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
	/**
	 * @brief Metodo costructor de xJson
	 * @param string pString
	 */
	xJson(string pString);
	
	/**
	 * @brief Metodo costructor de xInt
	 */
	virtual ~xJson();
	
	/**
	 * @brief Metodo que devuelve el string en formato Json 
	 * @return string _StringJson
	 */
	string getString();
};

#endif /* SRC_XCLASS_XJSON_H_ */
