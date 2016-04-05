/*
   TCPConnector.h

   TCPConnector class definition. TCPConnector provides methods to actively
   establish TCP/IP connections with a server.

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
   limitations under the License
*/


#include "tcpconnector.h"

xMemoryNode::xMemoryNode(int numeroDePuerto,int espacioDeMemoria, char ubicacionDeDisco,int preoridaDeMemoria){
	this->portNumber=numeroDePuerto;
	this->memorySpace=espacioDeMemoria;
	this->diskUbication=ubicacionDeDisco;
	this->priority=preoridaDeMemoria;
}
xMemoryNode::~xMemoryNode(){}

TCPStream* xMemoryNode::connect(const char* ipNumber)
{
	int port=portNumber;
    struct sockaddr_in address;
    /*
     * @brief Se configura la informacion del socket
     */
    memset (&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    if (resolveHostName(ipNumber, &(address.sin_addr)) != 0 ) {
        inet_pton(PF_INET, ipNumber, &(address.sin_addr));
    } 

    /*
     * @brief Crea el socket, y valida si se este se creo correctamente.
     * @Return Retorna null si el socket no se creo.
     */
    int socket = socket(AF_INET, SOCK_STREAM, 0);
    if (socket < 0) {
        perror*(ClientConstants::ERROR_SOCKET);
        return NULL;
    }
    /*
         * @brief Confirma la conexion con el servidor.
         * @Return Retorna null si el socket no se creo.
         */
    if (::connect(socket, (struct sockaddr*)&address, sizeof(address)) != 0) {
        perror*(ClientConstants::ERROR_CONECTAR);
        close(socket);
        return NULL;
    }
    return new TCPStream(socket, &address);
}

TCPStream* xMemoryNode::connect(const char* server, int port, int timeout)
{
    if (timeout == 0) return connect(server);
    
    struct sockaddr_in address;

    memset (&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = port;
    if (resolveHostName(server, &(address.sin_addr)) != 0 ) {
        inet_pton(PF_INET, server, &(address.sin_addr));        
    }     

    long arg;
    fd_set sdset;
    struct timeval tv;
    socklen_t len;
    int result = -1, valopt, sd = socket(AF_INET, SOCK_STREAM, 0);
    
    // Bail if we fail to create the socket
    if (sd < 0) {
    	perror*(ClientConstants::ERROR_SOCKET);
        return NULL;
    }    

    // Set socket to non-blocking
    arg = fcntl(sd, F_GETFL, NULL);
    arg |= O_NONBLOCK;
    fcntl(sd, F_SETFL, arg);
    
    // Connect with time limit
    string message;
    if ((result = ::connect(sd, (struct sockaddr *)&address, sizeof(address))) < 0) 
    {
        if (errno == EINPROGRESS)
        {
            tv.tv_sec = timeout;
            tv.tv_usec = 0;
            FD_ZERO(&sdset);
            FD_SET(sd, &sdset);
            int s = -1;
            do {
                s = select(sd + 1, NULL, &sdset, NULL, &tv);
            } while (s == -1 && errno == EINTR);
            if (s > 0)
            {
                len = sizeof(int);
                getsockopt(sd, SOL_SOCKET, SO_ERROR, (void*)(&valopt), &len);
                if (valopt) {
                    fprintf(stderr, "connect() error %d - %s\n", valopt, strerror(valopt));
                }
                // connection established
                else result = 0;
            }
            else fprintf(stderr, "connect() timed out\n");
        }
        else fprintf(stderr, "connect() error %d - %s\n", errno, strerror(errno));
    }

    // Return socket to blocking mode 
    arg = fcntl(sd, F_GETFL, NULL);
    arg &= (~O_NONBLOCK);
    fcntl(sd, F_SETFL, arg);

    // Create stream object if connected
    if (result == -1) return NULL;
    return new TCPStream(sd, &address);
}

int xMemoryNode::resolveHostName(const char* hostname, struct in_addr* addr)
{
    struct addrinfo *res;
  
    int result = getaddrinfo (hostname, NULL, NULL, &res);
    if (result == 0) {
        memcpy(addr, &((struct sockaddr_in *) res->ai_addr)->sin_addr, sizeof(struct in_addr));
        freeaddrinfo(res);
    }
    return result;
}
