/*
   TCPAcceptor.h

   TCPAcceptor class interface. TCPAcceptor provides methods to passively
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

#ifndef __tcpacceptor_h__
#define __tcpacceptor_h__
#include <sys/socket.h>
#include <string>
#include <netinet/in.h>

#include "../conexion/tcpstream.h"
#include "../Structures/LinkedList.h"
#include "conexion/ServerConstants.h"

using namespace std;

class TCPAcceptor
{
    int    Socket;
    const int    m_port;
    const string m_address;
    bool   m_listening;
    LinkedList<int> *_Clientes;
    static LinkedList<string> *_Mensajes;

  public:
    TCPAcceptor( const char* address=ClientConstants::IP);
    ~TCPAcceptor();

    int        start();
    TCPStream* acceptSocket();
    void sendinfo(const char *pMensaje);
    string getMensaje();


  private:
    	TCPAcceptor();
    	static void * controlador(void *pObjeto);
};

#endif
