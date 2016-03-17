/*
 * xJson.cpp
 *
 *  Created on: 5 de mar. de 2016
 *      Author: steven
 */

#include "xJson.h"
using namespace std;

xJson::xJson() {

}

xJson::~xJson() {
	// TODO Auto-generated destructor stub
}

xJson* xJson::serialize(xObject pObjeto){
	Json::Value valorJson;
	Json::StyledWriter escritor;

	//valorJson["Valor"]= xObject.valor;
	//valorJson["ID"]= xObject.id;

	string sObjeto=escritor.write(valorJson);

}

bool xJson::deserialize(xJson* pJson){
	//string strJson= pJson;

	// Let's parse it
	Json::Value raiz;
	Json::Reader lector;
	//bool parsedSuccess = lector.parse(strJson,raiz,false);

	//if(not parsedSuccess){
	// Report failures and their locations
	// in the document.
	cout<<"Failed to parse JSON"<<endl
	<<lector.getFormatedErrorMessages()
	<<endl;
	return 1;
	}
}
