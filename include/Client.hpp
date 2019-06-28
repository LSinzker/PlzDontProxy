#pragma once

#include "HTTPrequest.hpp"

class Client {
private:
  int socket_fd = -1;   //File Descriptor

public:
  Client() = default;
  char *answer;
  int max;
  void SendRequest(HTTPrequest &request, char *answer, int max);

};
