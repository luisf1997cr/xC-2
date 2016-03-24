/*
 * Ficheros.cpp
 *
 *  Created on: 4 de mar. de 2016
 *      Author: gabriel
 *
 *      Se encarga del manejo de logica en archivos
 */

#include "Ficheros.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

/**
 * @param char pnameArchive[] Corresponde a un char con el nombre del archivo en que se desea leer
 * @return Lee cada linea del archivo
 */
void Ficheros::leerEnFichero(char pnameArchive[]) {
	    ifstream myfile(pnameArchive, std::ifstream::in);
		if (myfile.is_open()){
			 string s;
			  while(getline(myfile,s)){
			    cout << s << "\n";
			}
			cout << "listo leido"<< endl;
			myfile.close();
		}
		else {
			cout << "No se pudo abrir el archivo: "<< pnameArchive<<endl;
		}
}

/**
 * @param char pnameArchive[] Corresponde a un char con el nombre del archivo en que se desea escribir
 * @param char pEscribir[] Lo que se desea escribir
 * @return Escribe determinado char en un archivo
 */
void Ficheros::escribirEnFicheroExistente(char pnameArchive[], char pEscribir[]) {
	    std::fstream myfile;
	    myfile.open(pnameArchive, std::fstream::in | std::fstream::out | std::fstream::app);

		if (myfile.is_open()){
			 myfile << pEscribir<<endl;
			 cout << "Se escribio"<< endl;
			 myfile.close();
		}
		else {
			cout << "No se pudo abrir el archivo";
		}
}

/**
 * @param char pnameArchive[] Corresponde a un char con el nombre del archivo en que se desea escribir
 * @param char pEscribir[] Lo que se desea escribir
 * @return Escribe determinado char en un archivo
 */
void Ficheros::escribirEnFicheroNuevo(char pnameArchive[], char pEscribir[]) {
	    ofstream myfile(pnameArchive);
		if (myfile.is_open()){
			myfile<<pEscribir;
			 cout << "Se escribio"<< endl;
			 myfile.close();
		}
		else {
			cout << "No se pudo abrir el archivo";
		}
}

/**
 * @param char plineadiv[] Linea en la cual se va a buscar determinado char
 * @param char pBuscar[] Lo que se desea buscar en la linea
 * @return True o False al encontrar o no lo que se desea
 */
bool Ficheros::cadenaDentroDeOtra (char plineadiv[], char pBuscar[])
{
	char * pch;
	pch = strstr(plineadiv, pBuscar);
	if (pch != NULL){
		std::cout<<"Si se encuentra"<<std::endl;
		return true;
	}
	std::cout<<"No se encuentra"<<std::endl;
	return false;
}

/**
 * @param char pline[] Linea en la que se desea buscar cierta inormacion
 * @param int plarge Correponde a un entero del tamano de caracteres de pline
 * @return
 */
char* Ficheros::extraerParametrosInclude (char pline[], int plarge)
{
	int i=0;
	int y = strlen(pline)-(plarge);
	static char NuevoCharLine[30];
	while(i<y){
		NuevoCharLine[i] = pline[i];
		i = i+1;
	}
	cout<< "sali" <<endl;
	NuevoCharLine[y] = 0;
	return NuevoCharLine;

}

/**
 * @param char pnameArchive[] Corresponde a un char con el nombre del archivo en que se desea leer
 * @param char pBusscar[] oken para buscar, ya sea //x include o //<xL>   versión=XXXX
 * @return Lee cada linea del archivo y realiza la logica de buscar includes
 */
void Ficheros::leerEnFicheroPrepro(char pnameArchive[], char pBusscar[]) {
	ifstream myfile(pnameArchive, std::ifstream::in);
	if (myfile.is_open()){
		string s;
		int numLine = 0;
		while(getline(myfile,s)){
			numLine = numLine+1;
			char line[s.length()];
			strcpy(line, s.c_str());
			if (cadenaDentroDeOtra(line, pBusscar)){


				char *e =extraerParametrosInclude(line, strlen(pBusscar)); // ESTE ES EL CHAR QUE DEVUELVE LO DEL INCLUDE

				cout <<e<<endl;

				escribirEnFicheroExistente("/home/gabriel/Escritorio/PRUEBASPREPRO.TXT", e);

			}
			cout<<"Numero de linea en archivo: " <<numLine<<endl;
		}
		cout << "listo leido"<< endl;
		myfile.close();
	}
	else {
		cout << "No se pudo abrir el archivo: " << pnameArchive<< endl;
	}
}

/**
 * @param char pline[] Corresponde a un char con la linea a analizar
 * @return Se encarga de procesar los tokens de xC++2
 */
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

/**
 * @param char pline[] Corresponde a un char con la linea a analizar
 * @return Se encarga de procesar los tokens de xC++2
 */
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

/**
 * @param char pSourceDir[] Corresponde a un char con el directorio donde buscar archivos .cpp y .h
 * * @param char pBusscar[] oken para buscar, ya sea //x include o //<xL>   versión=XXXX
 * @return Se encarga de procesar la direccion, buscar archivos y mandar a llamar metodos del preprocesador
 */
int Ficheros::BuscarArchivosEnFolder (char pSourceDir[], char pBusscar[])
{
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
				leerEnFicheroPrepro((strncat(NewSD, ep->d_name, (sizeof(ep->d_name)))), pBusscar);
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
