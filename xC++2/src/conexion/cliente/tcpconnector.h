/*
   TCPConnector.h

   TCPConnector class interface. TCPConnector provides methods to actively
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

#ifndef __tcpconnector_h__
#define __tcpconnector_h__

#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include "../conexion/tcpstream.h"
#include "../conexion/ClientConstants.h"



class xMemoryNode
{
  public:

	const int portNumber;
	int memorySpace;
	string diskUbication;
	int priority;


  public:
	xMemoryNode(int numeroDePuerto,int espacioDeMemoria, string ubicacionDeDisco,int preoridaDeMemoria);
	~xMemoryNode();
    TCPStream* connect(const char* ipNumber);
    TCPStream* connect(const char* server, int timeout);
    
  public:
    int getPortNumber();
    int getMemorySpace();
    string getdiskUbication();
    int getPriority();
    void setPortNumber(int numeroDePuerto);
    void setMemorySpace(int espacioDeMemoria);
    void setdiskUbication(string ubicacionDeDisco);
    void setPriority(int preoridaDeMemoria);

  private:
    int resolveHostName(const char* host, struct in_addr* addr);


};

#endif
