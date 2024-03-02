#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

class serverHandler{
    public:
     struct socketList{
        int socket;
        socketList* nextMember = NULL;
    };
    public:
    //returns a pointer to an addrinfo struct for ipv4 address addr
    addrinfo* setUpConnection(){
        struct addrinfo newConnect;
        struct addrinfo *connectPtr;
        memset(&newConnect, 0, sizeof(newConnect));
        newConnect.ai_family = AF_INET;
        newConnect.ai_socktype = SOCK_STREAM;
        newConnect.ai_flags = AI_PASSIVE;

        if(getaddrinfo(NULL,"32666",&newConnect,&connectPtr)!=0){
            std::cout<<"Error connection failed.\n";
            exit(1);
        }
        return connectPtr;
    };
    public:
    //returns the socket descriptor of the connection pointer passed to it.
    int getSocket(addrinfo *connectptr){
        int sd = socket(connectptr->ai_family, connectptr->ai_socktype, connectptr->ai_protocol);
        free(connectptr);
        return sd;
    };
    //adds a new node to the socketList
    void addNode(int socket, socketList* head){
        socketList* newNode;
        newNode = new socketList;
        newNode->socket = socket;
        newNode->nextMember = head->nextMember;
        head->nextMember = newNode;
    }
    void deleteLast(socketList* head){
        socketList* traverse;
        traverse = head->nextMember;
        while(traverse != NULL){
            traverse = traverse->nextMember;
        }
        shutdown(traverse->socket,0);
        delete(traverse);
    }
    public:
    //sets up the server for the number of connections specified
    //returns a linked list of all connections made
    socketList* setUpServer(int numConnects){
        struct sockaddr_storage their_address;
        socketList* head = new socketList;
        addrinfo* addressptr = setUpConnection();
        int socket = getSocket(addressptr);
        bind(socket,addressptr->ai_addr,addressptr->ai_addrlen);
        listen(socket,10);
        int i=0;
        while(i<numConnects){
            socklen_t size_addr = sizeof(their_address);
            int nConnect=accept(socket,(struct sockaddr *)&their_address, &size_addr);
            addNode(nConnect,head);
            std::cout<<"you made a connection!";
            i++;
        }
        free(addressptr);
        return head;
    };
    public:
    void endServer(socketList* head){
        while(head != NULL){
            deleteLast(head);
        }
    };
};

int main(){
    serverHandler server;
    addrinfo* ptr = server.setUpConnection();
    int serverSoc = server.getSocket(ptr);
    serverHandler::socketList* head = server.setUpServer(1);
    server.endServer(head);
    return 0;
}