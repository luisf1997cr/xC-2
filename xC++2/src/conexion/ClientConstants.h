/*
 * ServerConstants.h
 *
 *  Created on: 15 de feb. de 2016
 *      Author: jose
 */

#ifndef CLIENTCONSTANTS_H_
#define CLIENTCONSTANTS_H_

using namespace std;

class ClientConstants{
public:
	const bool DEBUG = true;
	const char* IP = "192.168.3.101";
	int PORT = 8080;
	const string ERROR_SOCKET =  "No se creo el socket";
	const string ERROR_CONECTAR = "No se logro conectar";

};



#endif /* CLIENTCONSTANTS_H_ */
