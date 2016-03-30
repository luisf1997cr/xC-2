/*
 * xJson.cpp
 *
 *  Created on: 5 de mar. de 2016
 *      Author: steven
 */

#include "xJson.h"
using namespace std;



xJson* xJson::serialize(xObject pObjeto){

	switch (include_char){
		case "xInt":
			Json::Value valorJson;
			Json::StyledWriter escritor;
			//serializacion para xObject de tipo xInt
			break;

		case "xChar":
			//serializacion para xObject de tipo xChar
			break;
	}


	//valorJson["Valor"]= pObjecto.valor;
	//valorJson["ID"]= pObjecto.id;

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

xJson::xJson() {

}

xJson::~xJson() {
	// TODO Auto-generated destructor stub
}
