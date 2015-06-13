#ifndef CLIENTSOCKET_H
#define	CLIENTSOCKET_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include "Socket.h"
#include <iostream>
#include <cstdio>
#include <netdb.h>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <sstream>

class ClientSocket: public Socket
{
public:
    ClientSocket();
    ClientSocket(const ClientSocket& orig);
    virtual ~ClientSocket();
    int connectToServer(char* ipAddress, char* portNumber);

};

#endif	/* CLIENTSOCKET_H */

