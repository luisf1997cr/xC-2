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

int Ficheros::leer(char nameArchive[]) {
	    ifstream myfile(nameArchive, std::ifstream::in);
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

int Ficheros::escribir(char nameArchive[]) {
	    ofstream myfile(nameArchive);
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

bool Ficheros::contiene (char lineadiv[])
{
	std::cout<<"aqui"<<std::endl;
	char * pch;
	pch = strstr(lineadiv, "//x include" );
	if (pch != NULL){
		std::cout<<"sipa"<<std::endl;
		return true;
	}
	std::cout<<"nopa"<<std::endl;
	return false;
}

Ficheros::Ficheros(){

}
Ficheros::~Ficheros(){

}

