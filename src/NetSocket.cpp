#include "NetSocket.hpp"
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <cstring>

int NetSocket::SendRequest(HTTPrequest &request, char *answer, int max) {

  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd < 0) {
    std::cerr << "Could not create client socket." << std::endl;
  }

  std::string& hostname = request.header.at("Host:");
  hostent* host = gethostbyname(hostname.c_str());
  if (host == NULL || host->h_addr_list == NULL) {
    std::cerr << "Unable to retrieve host address by name." << std::endl;
    exit(-2);
  }

  sockaddr_in addr = {0};
  addr.sin_family = AF_INET;
  addr.sin_port = htons(80);  //port 80 = HTTP
  memcpy(&addr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);
  if (connect(socket_fd, (sockaddr *) &addr, sizeof(addr)) < 0) {
    std::cerr << "Unable not connect to server." << std::endl;
    exit(-3);
  }
  // send request
  UpdateRequest(request);
  std::string request_msg = request.Converter();

  if (write(socket_fd, request_msg.c_str(), request_msg.length()) < 0) {
    std::cerr << "Unable to write to socket." << std::endl;
    exit(-4);
  }

  int n = 0, total = 0;
        //fazer assim para arquivos grandes
                  //socket  | memory buf    | num bytes
  while ((n = read(socket_fd, answer + total, max - total)) > 0) {
    total += n;     //n = number of bytes received
  }

  if (n == -1) {
    std::cerr << "Unable to read answer." << std::endl;
    exit(-5);
  }
  if (n >= max){
    std::cerr << "Buffer overflow when receiving answer." << std::endl;
    exit(-1);
  }
  return total;
}

void NetSocket::UpdateRequest(HTTPrequest &request) {
  request.header["Accept-Encoding:"] = "identity";
  request.header["Connection:"] = "close";
}
