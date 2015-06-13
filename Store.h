#ifndef STORE_H
#define	STORE_H

#include <string>
#include <vector>
#include "ServerSocket.h"
#include <iostream>
#include <cstdio>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;

struct Item
{
	string name;
	int quantity;
	int unitPrice;
};

class Store {
public:
    string getMessage(string itemName, int quantity);
    void start(char* portNumber, char* itemFileName);

private:
    void createItemList(char* fileName);
    ServerSocket serverSocket;
    vector<Item*> items;
    
};

#endif	/* STORE_H */

