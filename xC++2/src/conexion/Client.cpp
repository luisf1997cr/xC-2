#include "Client.h"

Client::Client() {
}

Client::~Client() {
}

bool Client::create(){
	this->_Socket = socket(AF_INET, SOCK_STREAM, 0);
	if (this->_Socket < 0)
		return false;
	this->_Port = ClientConstants::PORT;
	struct hostent *host = gethostbyname(ClientConstants::IP);
	if (host == NULL){
		cout << "error" << endl;
	}
	this->_Info.sin_family = AF_INET;
	memmove(&(this->_Info.sin_addr.s_addr),host->h_addr_list[0],4);
	this->_Info.sin_port = htons(this->_Port);
	memset(&this->_Info.sin_zero,0,sizeof(this->_Info.sin_zero));
	return true;
}

bool Client::conectar(){
	if((connect(this->_Socket,(sockaddr*)&this->_Info,(socklen_t)sizeof(this->_Info))) < 0)
		return false;
	return true;
}

void Client::start(){
	if (!create())
		if (ClientConstants::DEBUG)
			cout << ClientConstants::ERROR_SOCKET<< endl;
	if (!conectar())
		if (ClientConstants::DEBUG)
			cout << ClientConstants::ERROR_CONECTAR << endl;
	infoClient data;
	data._Conection = this->_Socket;
	while(true){
		pthread_t hilo;
		pthread_create(&hilo,0,Client::controlador,(void*)&data);
		pthread_detach(hilo);
	}
	close(this->_Socket);
}

void Client::sendinfo(const char* pMensaje){
	send(this->_Socket,pMensaje,strlen(pMensaje),0);
}

void* Client::controlador(void *pObjeto){
	infoClient *data = (infoClient*) pObjeto;
	string mensaje;
	while(true){
		char buffer[10] = {0};
		int bytes = recv(data->_Conection,buffer,10,0);
		mensaje.append(buffer,bytes);
		if(bytes < 10)
			break;
	}
	cout << mensaje << endl;
	pthread_exit(NULL);
}
