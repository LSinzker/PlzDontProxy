#include <iostream>
#include <string>
#include <cstring>
#include "AppSocket.hpp"
#include "HTTPrequest.hpp"

void AppSocket::Start(int port) {

  // Create a socket
  listening = socket(AF_INET, SOCK_STREAM, 0); // AF_INET is for IPv4
  if (listening == -1) {  //something wrong happened
    std::cerr << "Could not create a socket." << std::endl;
    exit(-1);
  }
  // Bind the socket to an IP/port
        // Binding informatioin
  server_hint.sin_family = AF_INET;   //IPv4
  server_hint.sin_port = htons(port); // htons (host to network short)
                                      // flips the bits to lendian or bendian
                                      // depending on the processor it's running on
  inet_pton(AF_INET, "0.0.0.0", &server_hint.sin_addr);  //"0.0.0.0 -> any address in this machine"
                                                  //pton will convert IPv4 addr to binary
        // Actual binding process
  if ( bind(listening, (sockaddr*)&server_hint, sizeof(server_hint)) == -1 ) {
      std::cerr << "Cannot bind to IP/port." << std::endl;
      exit(-2);
  }
  std::cout << "Socket has been bound." << std::endl;

  // Mark the socket for listening
  if (listen(listening, SOMAXCONN) == -1) {    //SOMAXCONN -> maximum number of connections
      std::cerr << "Cannot listen." << std::endl;
      exit(-3);
  }
  std::cout << "Listening to port " << port << std::endl;
}

void AppSocket::AcceptCall() {
  // Accept a call
  clientSocket = accept (listening, (sockaddr*)&client, &clientSize);
  if (clientSocket == -1) {
    std::cerr << "Client could not connect." << std::endl;
    exit(-4);
  }
  // Close the listening socket
  //close(listening);
  memset(host, 0, NI_MAXHOST);
  memset(svc, 0, NI_MAXSERV);

  result = getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, svc, NI_MAXSERV, 0);

  if (result) {
    std::cout << host << " connected on " << svc << std::endl;
  } else {  // If there is a problem, we fix things manually. Hopefully it works then.
    inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);     //does the opposit of inet_pton
    std::cout << host << " connect on " << ntohs(client.sin_port) << std::endl;
  }
}

  // While receiving display message, echo message
int AppSocket::ReceiveRequest(char *buffer, int max){

    // Clear buffer
  //memset(buffer, 0, max);
    // Wait for message
  std::cout << "Receiving request." << std::endl;
  size_msg = read(clientSocket, buffer, max);

  if (size_msg == -1)
    std::cerr << "A connection issue has occurred." << std::endl;
  if (size_msg == 0)
    std::cout << "Client disconnected." << std::endl;
  if (size_msg >= max) {
    std::cout << "Buffer overflow when receiving request." << std::endl;
    exit(-1);
  }
  return size_msg;
}
void AppSocket::AnswerRequest(char *buffer, int size) {

  std::cout << "Reached." << std::endl;       //TODO: remove this test
  if (write(clientSocket, buffer, size) < 0) {
    std::cerr << "Unable to answer request." << std::endl;
  }
}

// Close socket
AppSocket::~AppSocket() {
  close(clientSocket);
}
