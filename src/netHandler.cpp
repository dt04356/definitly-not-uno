#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

class NetHandler {
    
};

void setConnection(char * addr){
    struct addrinfo *sinfo;
    struct addrinfo hints;
    //sets the bytes of hints to 0
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    //checks if the connection is viable
    int status = getaddrinfo(addr,"1025", &hints, &sinfo);
    if(status !=0){
        std::cout<<gai_strerror(status);
        exit(1);
    }
    else{
        std::cout<<"made the connection";
    }
    //frees the memory reserved in the sinfo struct
    freeaddrinfo(sinfo);
}
int main() {
    std::string addr = "192.168.0.211";
    char * charAddr = &addr[0];

    setConnection(charAddr);
    return 0;
}