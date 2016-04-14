/*
 * FicherosConstants.h
 *
 *  Created on: 12 de abr. de 2016
 *      Author: steven
 */

#ifndef FICHEROSCONSTANTS_H_
#define FICHEROSCONSTANTS_H_

class FicherosConstants {
public:
	const char* ERROR_AL_PARSEAR = "Error al parsear xJson";
	const char* ERROR_AL_ABRIR = "No se pudo abrir el archivo: ";
	const char* MSJ_LEIDO = "Listo leido";
	const char* MSJ_ESCRITO = "Se escribio";
	const char* MSJ_ENCONTRADO = "Si se encuentra";
	const char* MSJ_NO_ENCONTRADO = "No se encuentra";
	const char* MSJ_SALIR = "Sali";
	char COMILLAS = '"';
	char* MSJ_ARCHIVO_ENCONTRADO = "Found a File : ";
	char* ERROR_AL_ENCONTRAR = "Couldn't open the directory";
	char LETRA_C = 'c';
	char LETRA_P = 'p';
	int NUM_CERO = 0;
	int NUM_UNO = 1;
	int NUM_DOS = 2;
	int NUM_TRES = 3;
	int CHARLINE_SIZE = 30;
	char SERIALIZAR_LN1[] = "xJson* xObject::serialize(){";
	char SERIALIZAR_LN2[] = "Json::Value valorJson;";
	char SERIALIZAR_LN3[] = "Json::StyledWriter escritor;";
	const char* SERIALIZAR_LN4 = "valorJson [""\"""param";
	const char* SERIALIZAR_LN5 = "\"""] = ";
	const char* C_PUNTO_Y_COMA = ";";
	char PUNTO_Y_COMA[] = ";";
	int BUFF_SIZE = 250;
	char* MSJ_NUM_LINE = "Numero de linea en archivo: ";
	char SERIALIZAR_LN6[] = "string sObjeto=escritor.write(valorJson);";
	char SERIALIZAR_LN7[] = "xJson* pJson = new xJson(sObjeto);";
	char SERIALIZAR_LN8[] = "return pJson;";
	char CORCHETE[] = "}";
	char DESERIALIZAR_LN1[] = "bool xObject::deserialize(xJson* pJson){";
	char SERIALIZAR_LN2[] = "Json::Value valorJson;";
	char DESERIALIZAR_LN3[] = "Json::Reader lector;";
	char DESERIALIZAR_LN4[] = "bool parsedSuccess = lector.parse(pJson->getString(),valorJson,false);";
	char DESERIALIZAR_LN5[] = "if(not parsedSuccess){";
	char DESERIALIZAR_LN6[] = "cout<<FicherosConstants::ERROR_AL_PARSEAR<<endl;";
	char DESERIALIZAR_LN7[] = "return 1;";
	char CORCHETE[] = "}";
	char DESERIALIZAR_LN8[] = "return parsedSuccess;";
	char CORCHETE[] = "}";
	unsigned char IS_FILE_VALOR= 0x8;
	int NEWSD_SIZE = 100;
		
};

#endif /* FICHEROSCONSTANTS_H_ */
