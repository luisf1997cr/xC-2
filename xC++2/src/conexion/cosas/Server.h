/**
 * @file Server.h
 * @date 15/2/16
 * @author Jose Eduardo Jimenez A 2014072577
 * @title Server
 * @brief Server del juego
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include "../ManejoDatos/LinkedList.h"
#include "ServerConstants.h"

using namespace std;

/**
 * @brief estructura que con tiene la informacion del socket
 */
struct infoSocket{
	int _Conection;
	sockaddr_in _Info;
};

class Server : public ServerConstants{
public:
	/**
	 * @brief Metodo constructor del Server
	 */
	Server();
	/**
	 * @brief Metodo destructor de Server
	 */
	virtual ~Server();

	/**
	 * @brief Metodo inicia el server
	 */
	void start();

	/**
	 * @brief Metodo envia un mensaje por el server
	 * @param pMansaje Mensaje a enviar
	 */
	void sendinfo(const char *pMensaje);

	/**
	 * @brief Metodo retorna el mensaje
	 * "param string Mensaje
	 */
	string getMensaje();

private:
	int _Socket;
	int _Port;
	sockaddr_in _Info;
	bool create();
	bool connect();
	static void * controlador(void *pObjeto);
	LinkedList<int> *_Clientes;
	static LinkedList<string> *_Mensajes;
};

#endif /* SERVER_H_ */
