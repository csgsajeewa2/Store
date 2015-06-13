#ifndef SOCKET_H
#define	SOCKET_H

#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <sstream>
#include <cstring>

#define BUFFER_SIZE 1024
using namespace std;

struct ReceiveMessage
{
	char message[BUFFER_SIZE+1];
	int length;
};

class Socket {
public:   
    Socket(const Socket& orig);
    virtual ~Socket();
    bool sendMessage(string message);
    ReceiveMessage* receive();
    Socket(); 
    
protected:
    int socketId;
    
private:
    
};


#endif

