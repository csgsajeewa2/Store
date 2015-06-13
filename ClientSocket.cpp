#include "ClientSocket.h"

ClientSocket::ClientSocket() {
}

ClientSocket::ClientSocket(const ClientSocket& orig) {
}

ClientSocket::~ClientSocket() {
}

int ClientSocket::connectToServer(char* ipAddress, char* portNumber) {
    
    char* ip = ipAddress;
    char* port = portNumber;
    cout << "client using ip address=" << ip << ", port=" << port << endl;
    struct addrinfo addr, *info;
    memset(&addr, 0, sizeof (addrinfo));
    addr.ai_family = AF_UNSPEC;
    addr.ai_socktype = SOCK_STREAM;
    addr.ai_flags = AI_PASSIVE;
    if (getaddrinfo(ip, port, &addr, &info) != 0) {
        std::cout << "unable to get address info" << std::endl;
    }
    int clientSocketId = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocketId == -1) {
        std::cout << "unable to create socket " << ip << port << std::endl;
        return -1;
    }

    
    if (connect(clientSocketId, info->ai_addr, info->ai_addrlen) == -1) {
        std::cout << "unable to connect socket " << ip << port << std::endl;
        return -1;
    }
    freeaddrinfo(info);
    socketId = clientSocketId;
    std::cout << "connected to " << ip << port << std::endl;
    return 0;
}

