#include "Store.h"
int main(int argc, char** argv) {
    
    //get port number
    if (argc != 3) {
        cout << "Store <port> <item file>" << endl;
        return -1;
    }
    char* port = argv[1];
    char* fileName = argv[2];
    return 0;

}
