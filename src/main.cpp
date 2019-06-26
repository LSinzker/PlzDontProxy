#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "Server.hpp"

int main(int argc, char *argv[]) {

  int port_number = 8228;

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
  Server server;
  server.Start((int)port_number);
  return 0;
}
