#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iterator>

class Spider {
private:
    char* href_point = NULL;
    std::vector<std::string> link_tree;

public:
    std::vector<std::string> HypertextTree(char* html_buf);
    void PrintVector(std::vector<std::string> const &input);
};
