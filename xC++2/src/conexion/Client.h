#ifndef CLIENT_H_
#define CLIENT_H_

#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#include "ClientConstants.h"

using namespace std;

struct infoClient{
	int _Conection;
};

class Client : public ClientConstants{
public:
	Client();
	virtual ~Client();

	void start();
	int get() const;
	void sendinfo(const char *pMensaje);
private:
	int _Socket;
	int _Port;
	sockaddr_in _Info;

	bool create();
	bool conectar();
	static void* controlador(void *pObjeto);
};

#endif /* CLIENT_H_ */
