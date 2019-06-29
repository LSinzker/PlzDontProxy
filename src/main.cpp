#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <vector>
#include "AppSocket.hpp"
#include "NetSocket.hpp"
//#include "HTTPrequest.hpp"
//firefox http://localhost:8080

int main(int argc, char *argv[]) {

  int port_number = 8228;
  char buffer[4096];

  std::cout << "Welcome to PlzDontProxy." << std::endl;

  if (argc == 1)
    std::cout << "Using default port number, 8228." << std::endl;
  else if (argc == 3) {
    port_number = atoi(argv[2]);
  } else {
    std::cout << "::Error::" << std::endl;
    std::cout << "Wrong number of arguments!" << std::endl;
    exit(0);
  }

  //TODO call server here
  AppSocket app;
  app.Start((int)port_number);
  app.AcceptCall();
  int request_size = app.ReceiveRequest(buffer, sizeof(buffer));
  // GETS HERE buffer is weird
  HTTPrequest request(buffer);
  std::cout << "Request: " << std::endl << buffer << std::endl;

  NetSocket net;
  std::cin.get();
  int answer_size = net.SendRequest(request, buffer, sizeof(buffer));
  buffer[answer_size] = '\0';
  std::cout << "Answer: " << std::endl << buffer << std::endl;
  app.AnswerRequest(buffer, answer_size);
  std::cin.get();

  return 0;
}
