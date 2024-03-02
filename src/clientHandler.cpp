#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
class clientHandler{
    int sockDes;
    public:
    void getConnection(char* addr){
        struct addrinfo newConnect;
        struct addrinfo *connectPtr;
        memset(&newConnect, 0, sizeof(newConnect));
        newConnect.ai_family = AF_INET;
        newConnect.ai_socktype = SOCK_STREAM;
        newConnect.ai_flags = AI_PASSIVE;

        if(getaddrinfo(addr,"32666",&newConnect,&connectPtr)!=0){
            std::cout<<"Error connection to " << addr<<" failed.\n";
            exit(1);
        }

        this->sockDes = socket(connectPtr->ai_family, connectPtr->ai_socktype, connectPtr->ai_protocol);

        if(connect(this->sockDes,connectPtr->ai_addr, connectPtr->ai_addrlen)==0){
            std::cout<<"WE DID IT!!!!";
        }


    };
};

int main(){
    std::cout<<"Enter an ip to connect to";
    std::string addr;
    std::cin>>addr;
    clientHandler client;
    client.getConnection(&addr[0]);

    return 0;

}