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

int main(int argc, char *argv[]) {

  int port_number = 8228;
  char buffer[1024*1024];

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

  while(true){

    app.AcceptCall();
    int request_size = app.ReceiveRequest(buffer, sizeof(buffer));

    if (request_size < 5) {
      std::cerr << "Invalid.." << std::endl;
      continue;
    }
    buffer[request_size] = '\0';

    HTTPrequest request(buffer);
    std::cout << "Request: " << std::endl << buffer << std::endl;

    NetSocket net;
    int answer_size = net.SendRequest(request, buffer, sizeof(buffer));

    buffer[answer_size] = '\0';
    std::cout << "Answer: " << std::endl << buffer << std::endl;

    app.AnswerRequest(buffer, answer_size);

  }
  /*QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();*/

  std::cout << "Closing socket... ";
  app.~AppSocket();
  std::cout << "Exiting." << std::endl;

  return 0;
}
