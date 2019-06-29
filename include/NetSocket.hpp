#pragma once

#include "HTTPrequest.hpp"

class NetSocket {
private:
  int socket_fd = -1;   //File Descriptor
  void UpdateRequest(HTTPrequest &request);

public:
  NetSocket() = default;
  char *answer;
  int max;
  int SendRequest(HTTPrequest &request, char *answer, int max);

};
