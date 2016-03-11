/*
 * Ficheros.cpp
 *
 *  Created on: 4 de mar. de 2016
 *      Author: gabriel
 */

#include "Ficheros.h"

using namespace std;

int leer() {
	    ifstream myfile("prueba.txt", std::ifstream::in);
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

int escribir() {
	    ofstream myfile("prueba.txt");
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

bool contiene (char *lineadiv)
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
/*
int main(){

	int helado = leer();
	int vainilla = escribir();

	cout << helado<< endl;
	cout << vainilla<< endl;

	return 0;
}
*/
