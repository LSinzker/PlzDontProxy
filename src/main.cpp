#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include "Server.hpp"

#define port_number 8228

int main(int argc, char const *argv[]) {

  std::cout << "Welcome to PlzDontProxy." << std::endl;

  if (argc == 1)
    std::cout << "Using default port number, 8228." << std::endl;
  else if (argc == 3) {
    port_number = stoi(argv[2]);
  } else {
    std::cout << "::Error::" << endl;
    std::cout << "Wrong number of arguments!" << endl;
    exit(0);
  }
  
  //TODO call server here
  /*Server server(port_number);
  server.Start();*/
  return 0;
}
