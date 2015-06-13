#ifndef SERVERSOCKET_H
#define	SERVERSOCKET_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include "Socket.h"
#include <netdb.h>
#include <iostream>
#include <cstdio>
#include <netdb.h>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <sstream>

class ServerSocket: public Socket
{
public:
    ServerSocket();
    ServerSocket(const ServerSocket& orig);
    virtual ~ServerSocket();
    int connect(char* port);
    int run();
private:
    int serverSocketId;
};

#endif	/* SERVERSOCKET_H */

