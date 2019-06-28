#include <string>
#include <map>

class HTTPrequest {
public:
  std::string method;
  std::string url;
  std::string version;
  std::map<std::string, std::string> header;
  HTTPrequest();
  HTTPrequest(char * request);
  void Parse(char * request);
  std::string Converter();

};
