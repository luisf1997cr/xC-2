/*
 * Ficheros.cpp
 *
 *  Created on: 4 de mar. de 2016
 *      Author: gabriel
 *
 *      Se encarga del manejo de logica en archivos
 */

#include "Ficheros.h"


void Ficheros::leerEnFichero(char pnameArchive[]) {
	    ifstream myfile(pnameArchive, std::ifstream::in);
		if (myfile.is_open()){
			 string s;
			  while(getline(myfile,s)){
			    cout << s << "\n";
			}
			cout << FicherosConstants::MSJ_LEIDO<< endl;
			myfile.close();
		}
		else {
			cout << FicherosConstants::ERROR_AL_ABRIR<< pnameArchive<<endl;
		}
}

void Ficheros::escribirEnFicheroExistente(char pnameArchive[], char pEscribir[]) {
	    std::fstream myfile;
	    myfile.open(pnameArchive, std::fstream::in | std::fstream::out | std::fstream::app);

		if (myfile.is_open()){
			 myfile << pEscribir<<endl;
			 cout << FicherosConstants::MSJ_ESCRITO<< endl;
			 myfile.close();
		}
		else {
			cout << FicherosConstants::ERROR_AL_ABRIR;
		}
}

void Ficheros::escribirEnFicheroNuevo(char pnameArchive[], char pEscribir[]) {
	    ofstream myfile(pnameArchive);
		if (myfile.is_open()){
			myfile<<pEscribir;
			 cout << FicherosConstants::MSJ_ESCRITO<< endl;
			 myfile.close();
		}
		else {
			cout << FicherosConstants::ERROR_AL_ABRIR;
		}
}


bool Ficheros::cadenaDentroDeOtra (char plineadiv[], char pBuscar[])
{
	char * pch;
	pch = strstr(plineadiv, pBuscar);
	if (pch != NULL){
		std::cout<<FicherosConstants::MSJ_ENCONTRADO<<std::endl;
		return true;
	}
	std::cout<<FicherosConstants::MSJ_NO_ENCONTRADO<<std::endl;
	return false;
}

char* Ficheros::extraerParametrosInclude (char pline[], int plarge)
{
	int i=FicherosConstants::NUM_CERO;
	int y = strlen(pline)-(plarge);
	static char NuevoCharLine[FicherosConstants::CHARLINE_SIZE];
	NuevoCharLine[i] = FicherosConstants::COMILLAS;
	i++;
	while(i<y){
		NuevoCharLine[i] = pline[i];
		i++;
	}
	cout<< FicherosConstants::MSJ_SALIR <<endl;
	NuevoCharLine[y] = FicherosConstants::COMILLAS;
	NuevoCharLine[y++] = FicherosConstants::NUM_CERO;
	return NuevoCharLine;

}


void Ficheros::leerEnFicheroPrepro(char pnameArchive[], char pBusscar[]) {
	ifstream myfile(pnameArchive, std::ifstream::in);
	if (myfile.is_open()){
		string s;
		int numLine = FicherosConstants::NUM_CERO;
		LinkedList<char>* listaresult = new LinkedList<char>;
		while(getline(myfile,s)){
			numLine++;
			char line[s.length()];
			strcpy(line, s.c_str());
			if (cadenaDentroDeOtra(line, pBusscar)){


				char *e =extraerParametrosInclude(line, strlen(pBusscar)); // ESTE ES EL CHAR QUE DEVUELVE LO DEL INCLUDE

				cout <<e<<endl;

				listaresult->insertData(e);
				//escribirEnFicheroExistente(pnameArchive, e);
				int i=FicherosConstants::NUM_CERO;
				int y = strlen(pnameArchive)-FicherosConstants::NUM_UNO;
				static char NuevoCharLine[FicherosConstants::CHARLINE_SIZE];
				while(i<y){
					NuevoCharLine[i] = pnameArchive[i];
					i++;
				}
				NuevoCharLine[y] = FicherosConstants::LETRA_C;
				NuevoCharLine[y+1] = 'p';
				NuevoCharLine[y+2] = 'p';
				NuevoCharLine[y+3] = 0;
				pnameArchive = NuevoCharLine;
				escribirEnFicheroExistente(pnameArchive, "xJson* xObject::serialize(){");
				escribirEnFicheroExistente(pnameArchive, "Json::Value valorJson;");
				escribirEnFicheroExistente(pnameArchive, "Json::StyledWriter escritor;");
				int indice = 0;//lleva el indice de la lista de lo que leyo cada include
				stringstream convert;//conversor del indice de int a char*
				convert<<indice;
				const char* parametro = convert.str().c_str();//parametro en forma de char*
				while(indice < listaresult->getLength()){
					const char* inicio = "valorJson [""\"""param";
					const char* medio = "\"""] = ";
					const char* final = ";";
					char* buff = new char[250];
					strcpy(buff, inicio);
					strcat(buff, parametro);
					strcat(buff, medio);
					strcat(buff, listaresult->getItemByPosition(indice+1)->getVal());
					strcat(buff, final);
					escribirEnFicheroExistente(pnameArchive, buff);
					indice++;
					convert<<indice;
					parametro = convert.str().c_str();

				}
			cout<<"Numero de linea en archivo: " <<numLine<<endl;
			escribirEnFicheroExistente(pnameArchive, "string sObjeto=escritor.write(valorJson);");
			escribirEnFicheroExistente(pnameArchive, "xJson* pJson = new xJson(sObjeto);");
			escribirEnFicheroExistente(pnameArchive, "return pJson;");
			escribirEnFicheroExistente(pnameArchive, "}");
			escribirEnFicheroExistente(pnameArchive, "bool xObject::deserialize(xJson* pJson){");
			escribirEnFicheroExistente(pnameArchive, "Json::Value valorJson;");
			escribirEnFicheroExistente(pnameArchive, "Json::Reader lector;");
			escribirEnFicheroExistente(pnameArchive, "bool parsedSuccess = lector.parse(pJson->getString(),valorJson,false);");
			escribirEnFicheroExistente(pnameArchive, "if(not parsedSuccess){");
			escribirEnFicheroExistente(pnameArchive, "cout<<FicherosConstants::ERROR_AL_PARSEAR<<endl;");
			escribirEnFicheroExistente(pnameArchive, "return 1;");
			escribirEnFicheroExistente(pnameArchive, "}");
			escribirEnFicheroExistente(pnameArchive, "return parsedSuccess;");
			escribirEnFicheroExistente(pnameArchive, "}");
		}

		}

		cout << "listo leido"<< endl;
		myfile.close();
	}
	else {
		cout << "No se pudo abrir el archivo: " << pnameArchive<< endl;
	}
}

void Ficheros::LogicaDeIncludeSerializar(char pline[]){
	if (cadenaDentroDeOtra(pline, "xInt")){

	}

	if (cadenaDentroDeOtra(pline, "xChar")){

	}

	if (cadenaDentroDeOtra(pline, "xDouble")){

	}

	if (cadenaDentroDeOtra(pline, "xLong")){

	}

	if (cadenaDentroDeOtra(pline, "xFloat")){

	}

	if (cadenaDentroDeOtra(pline, "xBool")){

	}

	if (cadenaDentroDeOtra(pline, "xShort")){

	}

	if (cadenaDentroDeOtra(pline, "xObject")){

	}

}

void Ficheros::LogicaDeIncludeDesserializar(char pline[]){
	if (cadenaDentroDeOtra(pline, "xInt")){

	}

	if (cadenaDentroDeOtra(pline, "xChar")){

	}

	if (cadenaDentroDeOtra(pline, "xDouble")){

	}

	if (cadenaDentroDeOtra(pline, "xLong")){

	}

	if (cadenaDentroDeOtra(pline, "xFloat")){

	}

	if (cadenaDentroDeOtra(pline, "xBool")){

	}

	if (cadenaDentroDeOtra(pline, "xShort")){

	}

	if (cadenaDentroDeOtra(pline, "xObject")){

	}

}


int Ficheros::BuscarArchivosEnFolder (char pSourceDir[],char pBuscar[])
{
	int SiZe = sizeof(pSourceDir);
	unsigned char isFile =0x8;
	DIR *dp;
	struct dirent *ep;
	dp = opendir (pSourceDir);
	if (dp != NULL)
	{
		while (ep = readdir (dp)){
			char NewSD[100] ={};
			strcat(NewSD, pSourceDir);
			 if ( ep->d_type == isFile)
			   {
				cout <<"Found a File : " << ep->d_name << endl;
				leerEnFicheroPrepro((strncat(NewSD, ep->d_name, (sizeof(ep->d_name)))), pBuscar);
			   }
		}
		(void) closedir (dp);
	}
	else
		perror ("Couldn't open the directory");

	return 0;
}



Ficheros::Ficheros(){

}
Ficheros::~Ficheros(){

}
