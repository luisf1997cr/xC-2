/*
   TCPAcceptor.cpp

   TCPAcceptor class definition. TCPAcceptor provides methods to passively
   establish TCP/IP connections with clients.

   ------------------------------------------

   Copyright � 2013 [Vic Hargrave - http://vichargrave.com]

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include "tcpacceptor.h"

LinkedList<string>* Server::_Mensajes = new LinkedList<string>();

TCPAcceptor::TCPAcceptor(const char* address)
: Socket(0), m_port(ServerConstants::PORT), m_address(address), m_listening(false) {
	this->_Clientes = new LinkedList<int>();
}

TCPAcceptor::~TCPAcceptor()
{
    if (Socket > 0) {
        close(Socket);
    }
}

int TCPAcceptor::start()
{
    if (m_listening == true) {
        return 0;
    }

    Socket = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in address;

    memset(&address, 0, sizeof(address));
    address.sin_family = PF_INET;
    address.sin_port = m_port;
    if (m_address.size() > 0) {
        inet_pton(PF_INET, m_address.c_str(), &(address.sin_addr));
    }
    else {
        address.sin_addr.s_addr = INADDR_ANY;
    }
    
    int optval = 1;
    setsockopt(Socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);
    
    int result = bind(Socket, (struct sockaddr*)&address, sizeof(address));
    if (result != 0) {
        perror("bind() failed");
        return result;
    }
    
    result = listen(Socket, 5);
    if (result != 0) {
        perror("listen() failed");
        return result;
    }

    m_listening = true;
    return result;
}


TCPStream* TCPAcceptor::acceptSocket()
{
    if (m_listening == false) {
        return NULL;
    }

    infoSocket  data;
    socklen_t len = sizeof(data);
    data._Conection = ::accept(Socket, (struct sockaddr*)&data, &len);
    if (data._Conection < 0) {
        perror("accept() failed");
        return NULL;
    }else{
		if(ServerConstants::DEBUG)
			cout << ServerConstants::CONNECT << endl;
		this->_Clientes->insertAtFinal(data._Conection);
    }
    pthread_t hilo;
    pthread_create(&hilo,0,Server::controlador,(void*)data);
    pthread_detach(hilo);
    return new TCPStream(Socket, &data);
    close(Socket);
}


void* TCPAcceptor::controlador(void* pObjeto){
	 TCPStream* stream = NULL;
	 string mensaje;
	 if (start() == 0) {
	        while (1) {
	            stream = acceptSocket();
	            if (stream != NULL) {
	            	infoSocket *data = (infoSocket*)pObjeto;
	                ssize_t len;
	                char line[256];
	                while ((len = stream->receive(line, sizeof(line))) > 0) {
	                    line[len] = 0;
	                    printf("received - %s\n", line);
	                    mensaje.append(line, len);
	                    stream->send(line, len);
	                }
	                delete stream;
	            }
	        }
	    }
	pthread_exit(NULL);
}

void TCPAcceptor::sendinfo(const char* pMensaje){
	for (int index = 0; index < this->_Clientes->len(); index++){
		cout << ServerConstants::SENDINFO_MSJ << send(this->_Clientes->searchPosition(index),pMensaje,strlen(pMensaje),0);
	}
}

string TCPAcceptor::getMensaje(){
	string mensaje = ServerConstants::NO_HAY_MSJ;
	if(this->_Mensajes->isEmpty()){
		mensaje = this->_Mensajes->searchBegin();
		this->_Mensajes->deleteAtBegin();
	}
}
