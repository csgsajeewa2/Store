#include "Socket.h"
#define BUFFER_SIZE 1024

Socket::Socket() {
}

Socket::Socket(const Socket& orig) {
}

Socket::~Socket() {
}

bool Socket::sendMessage(std::string message) {
    bool sucess=true; 
    if (send(socketId, message.c_str(), message.size(), 0) != (int) message.size()) {
        sucess=false;
    }
    return sucess;
}

ReceiveMessage* Socket::receive() {
    char buffer[BUFFER_SIZE + 1];
    int length = recv(socketId, buffer, BUFFER_SIZE, 0);
    ReceiveMessage* receiveMessage = new ReceiveMessage();
    receiveMessage->length=length;
    memcpy(receiveMessage->message, buffer, sizeof(receiveMessage->message));
    return receiveMessage;
}

