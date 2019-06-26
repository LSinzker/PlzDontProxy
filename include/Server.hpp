#include <cstdint>
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

class Server {

private:
    sockaddr_in server_hint;
    int listening;          //socket

    sockaddr_in client;
    socklen_t clientSize = sizeof(client);
    char host[NI_MAXHOST];  //buffer for host
    char svc[NI_MAXSERV];   //buffer for service
    int clientSocket;       //socket
    int result;
    char buffer[4096];
    int in_msg;


public:
    Server() = default;
    void Start(int port);
};
