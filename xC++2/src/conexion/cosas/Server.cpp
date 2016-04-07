/**
 * @file Server.cpp
 * @date 15/2/16
 * @author Jose Eduardo Jimenez A 2014072577
 * @title Server
 * @brief Server del juego
 */

#include "Server.h"

LinkedList<string>* Server::_Mensajes = new LinkedList<string>();

Server::Server() {
	this->_Clientes = new LinkedList<int>();
	this->_Socket = 0;
	this->_Port = ServerConstants::PORT;
}

Server::~Server() {
	// TODO Auto-generated destructor stub
}

bool Server::create(){
	this->_Socket = socket(AF_INET, SOCK_STREAM, 0);
	if (this->_Socket < 0)
		return false;
	memset(&this->_Info, 0, sizeof(struct sockaddr_in));
	this->_Info.sin_family = AF_INET;
	this->_Info.sin_port = htons(ServerConstants::PORT);
	this->_Info.sin_addr.s_addr = htonl(INADDR_ANY);
	return true;
}

bool Server::connect(){
	int b = bind(this->_Socket, (struct sockaddr*) &this->_Info, sizeof(this->_Info));
	if(b != 0)
		return false;
	b = listen(this->_Socket, 1);
	return true;
}

void Server::start(){
	if (!this->create()){
		if(ServerConstants::DEBUG)
			cout << ServerConstants::EROOR_SOCKET << endl;
		exit(1);
	}
	if (!this->connect()){
		if(ServerConstants::DEBUG)
			cout << ServerConstants::ERROR_CONECTAR << endl;
		exit(1);
	}
	while(true){
		infoSocket  data;
		socklen_t data_len;
		data._Conection = accept(this->_Socket, (sockaddr*) &data, &data_len);
		if (data._Conection < 0) {
			if(ServerConstants::DEBUG)
				cout << ServerConstants::WAITING << endl;
		}else{
			if(ServerConstants::DEBUG)
				cout << ServerConstants::CONNECT << endl;
			this->_Clientes->insertAtFinal(data._Conection);
			pthread_t hilo;
			pthread_create(&hilo,0,Server::controlador,(void*)&data);
			pthread_detach(hilo);
		}

	    //this->sendinfo("lol");
	}
	close(this->_Socket);
}
void* Server::controlador(void* pObjeto){
	infoSocket *data = (infoSocket*)pObjeto;
	string mensaje;
	while(true){
		char buffer[10] = {0};
		int bytes = recv(data->_Conection, buffer,10,0);
		mensaje.append(buffer, bytes);
		if (bytes < 10)
			break;
	}
	cout << mensaje << endl;
	//_Mensajes->insertAtFinal(mensaje);
	pthread_exit(NULL);
}

void Server::sendinfo(const char* pMensaje){
	for (int index = 0; index < this->_Clientes->len(); index++){
		cout << ServerConstants::SENDINFO_MSJ << send(this->_Clientes->searchPosition(index),pMensaje,strlen(pMensaje),0);
	}
}

string Server::getMensaje(){
	string mensaje = ServerConstants::NO_HAY_MSJ;
	if(this->_Mensajes->isEmpty()){
		mensaje = this->_Mensajes->searchBegin();
		this->_Mensajes->deleteAtBegin();
	}
}
