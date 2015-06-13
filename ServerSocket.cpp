#include "ServerSocket.h"
#include "Socket.h"
#define BUFFER_SIZE 1024
ServerSocket::ServerSocket() {
}

ServerSocket::ServerSocket(const ServerSocket& orig) {
}

ServerSocket::~ServerSocket() {
}

/**
 * socket is created and bind to specified port
 * @param portNumber
 */
int ServerSocket::connect(char* portNumber) {

    char* port = portNumber;
    std::cout << "server is created on " << port << std::endl;

    struct addrinfo addr, *info;
    memset(&addr, 0, sizeof (addrinfo));
    addr.ai_family = AF_UNSPEC;
    addr.ai_socktype = SOCK_STREAM;
    addr.ai_flags = AI_PASSIVE;

    if (getaddrinfo(NULL, port, &addr, &info) != 0) {
        std::cout << "unable to get address info" << std::endl;
        return -1;
    }

    serverSocketId = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocketId == -1) {
        std::cout << "unable to create socket at " << port << std::endl;
        return -1;
    }

    if (bind(serverSocketId, info->ai_addr, info->ai_addrlen) == -1) {
        std::cout << "unable to bind socket at " << port << std::endl;
        return -1;
    }
    std::cout << " Socket is successfully created"<< std::endl;
    freeaddrinfo(info);
    return 0;
}

int ServerSocket::run() {
   		
    if (listen(serverSocketId, 5) == -1) {
        std::cout << "unable to listen at that port"<< std::endl;
        return -1;
    }

    struct sockaddr_storage peeraddr; 
    socklen_t addr_size;
   
    int peer = accept(serverSocketId, (struct sockaddr*) &peeraddr, &addr_size);
    if (peer == -1) {
        std::cout << "unable to accept at that port" << std::endl;
        return -1;
    }
    std::cout << "connection received" << std::endl;
    socketId = peer;
    return 0;
}
