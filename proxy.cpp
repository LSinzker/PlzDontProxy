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

int proxy(uint16_t port_number) {

    char buffer[1024*1024];

    std::cout << "Welcome to PlzDontProxy." << std::endl;

    if (port_number == 8228)
      std::cout << "Using default port number, 8228." << std::endl;
    else
      std::cout << "Using port " << port_number << "." << std::endl;

    //TODO call server here
    AppSocket app;
    app.Start(port_number);

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

    std::cout << "Closing socket... ";
    app.~AppSocket();
    std::cout << "Exiting." << std::endl;

    return 0;
  }
