#include "HTTPrequest.hpp"
#include <cstring>
#include <vector>
#include <sstream>
#include <iostream>


HTTPrequest::HTTPrequest(char *request) {
  Parse(request);
}

void HTTPrequest::Parse(char *request) {
  method = strtok(request, " ");
  url = strtok(NULL, " ");
  version = strtok(NULL, "\r\n");

  if (method == "CONNECT") {
    std::cout << "Atempting to CONNECT" << std::endl;
  }

  char *field_name, *field_value;
  while ((field_name = strtok(NULL, " ")) && (field_value = strtok(NULL, "\r\n"))) {
    header[field_name + 1] = field_value;
  }
}
std::string HTTPrequest::Converter() {

  std::stringstream head;
  head << method << " " << url << " " << version << "\r\n";
  for (auto& field : header) {
    head << field.first << " " << field.second << "\r\n";
  }
  head << "\r\n";

  return head.str();

}
