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
				NuevoCharLine[y+FicherosConstants::NUM_UNO] = FicherosConstants::LETRA_P;
				NuevoCharLine[y+FicherosConstants::NUM_DOS] = FicherosConstants::LETRA_P;
				NuevoCharLine[y+FicherosConstants::NUM_TRES] = FicherosConstants::NUM_CERO;
				pnameArchive = NuevoCharLine;
				escribirEnFicheroExistente(pnameArchive, FicherosConstants::SERIALIZAR_LN1);
				escribirEnFicheroExistente(pnameArchive, FicherosConstants::SERIALIZAR_LN2);
				escribirEnFicheroExistente(pnameArchive, FicherosConstants::SERIALIZAR_LN3);
				int indice = FicherosConstants::NUM_CERO;//lleva el indice de la lista de lo que leyo cada include
				stringstream convert;//conversor del indice de int a char*
				convert<<indice;
				const char* parametro = convert.str().c_str();//parametro en forma de char*
				while(indice < listaresult->getLength()){
					const char* inicio = FicherosConstants::SERIALIZAR_LN4;
					const char* medio = FicherosConstants::SERIALIZAR_LN5";
					const char* final = FicherosConstants::C_PUNTO_Y_COMA;
					char* buff = new char[FicherosConstants::BUFF_SIZE];
					strcpy(buff, inicio);
					strcat(buff, parametro);
					strcat(buff, medio);
					strcat(buff, listaresult->getItemByPosition(indice+FicherosConstants::NUM_UNO)->getVal());
					strcat(buff, final);
					escribirEnFicheroExistente(pnameArchive, buff);
					indice++;
					convert<<indice;
					parametro = convert.str().c_str();

				}
			cout<< FicherosConstants::MSJ_NUM_LINE <<numLine<<endl;
			escribirEnFicheroExistente(pnameArchive, FicherosConstants::SERIALIZAR_LN6);
			escribirEnFicheroExistente(pnameArchive, FicherosConstants::SERIALIZAR_LN7);
			escribirEnFicheroExistente(pnameArchive, FicherosConstants::SERIALIZAR_LN8);
			escribirEnFicheroExistente(pnameArchive, FicherosConstants::CORCHETE);
			escribirEnFicheroExistente(pnameArchive, FicherosConstants::DESERIALIZAR_LN1);
			escribirEnFicheroExistente(pnameArchive, FicherosConstants::SERIALIZAR_LN2);
			escribirEnFicheroExistente(pnameArchive, FicherosConstants::DESERIALIZAR_LN3);
			escribirEnFicheroExistente(pnameArchive, FicherosConstants::DESERIALIZAR_LN4);
			escribirEnFicheroExistente(pnameArchive, FicherosConstants::DESERIALIZAR_LN5);
			escribirEnFicheroExistente(pnameArchive, FicherosConstants::DESERIALIZAR_LN6);
			escribirEnFicheroExistente(pnameArchive, FicherosConstants::DESERIALIZAR_LN7);
			escribirEnFicheroExistente(pnameArchive, FicherosConstants::CORCHETE);
			escribirEnFicheroExistente(pnameArchive, FicherosConstants::DESERIALIZAR_LN8);
			escribirEnFicheroExistente(pnameArchive, FicherosConstants::CORCHETE);
		}

		}

		cout << FicherosConstants::MSJ_LEIDO<< endl;
		myfile.close();
	}
	else {
		cout << FicherosConstants::ERROR_AL_ABRIR << pnameArchive<< endl;
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
	unsigned char isFile =FicherosConstants::IS_FILE_VALOR;
	DIR *dp;
	struct dirent *ep;
	dp = opendir (pSourceDir);
	if (dp != NULL)
	{
		while (ep = readdir (dp)){
			char NewSD[FicherosConstants::NEWSD_SIZE] ={};
			strcat(NewSD, pSourceDir);
			 if ( ep->d_type == isFile)
			   {
				cout <<FicherosConstants::MSJ_ARCHIVO_ENCONTRADO << ep->d_name << endl;
				leerEnFicheroPrepro((strncat(NewSD, ep->d_name, (sizeof(ep->d_name)))), pBuscar);
			   }
		}
		(void) closedir (dp);
	}
	else
		perror (FicherosConstants::ERROR_AL_ENCONTRAR);

	return FicherosConstants::NUM_CERO;
}



Ficheros::Ficheros(){

}
Ficheros::~Ficheros(){

}
