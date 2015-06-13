#include "Store.h"

#define BUFFER_SIZE 1024


//create items from xml and 
string Store::addNews(string name)
{
	cout << "namee" << endl;
}

void Store::createItemList(char* fileName) {

    std::ifstream infile(fileName);
    std::string line;
    while (std::getline(infile, line)) {
        Item* i = new Item();
        printf("%s \n", line.c_str());


        std::istringstream ss(line);
        std::string token;
		
       
        i->unitPrice =atoi(token.c_str());
        
        printf("%s :: %d :: %d \n",i->name.c_str(),i->unitPrice,i->quantity);
	items.push_back(i);
    }
};


string Store::getMessage(string itemName, int quantity) {

    vector<Item*>::iterator itBegin = items.begin();
    vector<Item*>::iterator itEnd = items.end();
    bool matched = false;
    string message;
    for (vector<Item*>::iterator it = itBegin; it != itEnd; ++it) {
        Item* i = *it;
        if (i->name.compare(itemName) == 0) {
            message = "  Item exist";
            matched = true;
            if (i->quantity < quantity) {
                message = "   Item exist but not enough";
            } else {
                int value = (i->unitPrice) * quantity;
                string vResult;
                ostringstream convert1;
                convert1 << value;
                vResult = convert1.str();

                string qResult;
                ostringstream convert2;
                convert2 << quantity;
                qResult = convert2.str();
                //35 Apples cost 350/=
                message = "   " + qResult + " " + itemName + " cost " + vResult;
            }
        }
    }

    if (!matched) {
        message = "   Item not exist";
    }

    return message;
}

void Store::start(char* portNumber, char* itemFileName) {
    createItemList(itemFileName);
    serverSocket.connect(portNumber);
    serverSocket.run();
   	
    while (true) {

        //first receive
        ReceiveMessage* receiveMessage = serverSocket.receive();
        if (receiveMessage->length == -1) {
            cout << "recv error" << endl;
            break;
        } 
        else if (receiveMessage->length > 0) {
            receiveMessage->message[receiveMessage->length] = '\0';
            string buffe(receiveMessage->message);
            if (buffe.compare("exit") == 0) {
                break;
            }
            cout << "server recv:" << receiveMessage->message << endl;
            char *pch;
            pch = strtok(receiveMessage->message, "=");
            string itemName(pch);
            pch = strtok(NULL, "=");
            int quantity = atoi(pch);
            cout << "Item Name:" << itemName << endl;
            cout << "Quantity: " << quantity << endl;

            string message = getMessage(itemName, quantity);
            if(!serverSocket.sendMessage(message));
            {
                cout << "send error" << endl;
            }
        }
    }
}

