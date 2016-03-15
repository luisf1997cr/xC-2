/*
 * Ficheros.cpp
 *
 *  Created on: 4 de mar. de 2016
 *      Author: gabriel
 */

#include "Ficheros.h"

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

int Ficheros::leerEnFichero(char pnameArchive[]) {
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
			cout << "No se pudo abrir el archivo";
		}
	return 0;
}

int Ficheros::escribirEnFichero(char pnameArchive[]) {
	    ofstream myfile(pnameArchive);
		if (myfile.is_open()){
			 string s;

			 myfile << s;
			 cout << "Se escribio"<< endl;
			 myfile.close();
		}
		else {
			cout << "No se pudo abrir el archivo";
		}
	return 0;
}

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

char* Ficheros::extraerParametrosInclude (char pline[], int plarge)
{
	int i=0;
	cout << pline<<endl;

	int y = strlen(pline)-plarge;

	static char NuevoCharLine[15];

	cout<< y <<endl;

	while(i<y){
		NuevoCharLine[i] = pline[i];
		i = i+1;
	}
	cout<< "sali" <<endl;
	NuevoCharLine[y] = 0;

	cout<< NuevoCharLine<<endl;

	return NuevoCharLine;

}

Ficheros::Ficheros(){

}
Ficheros::~Ficheros(){

}

