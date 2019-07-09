#include "spider.hpp"

#define href_str "link href="

std::vector<std::string> Spider::HypertextTree(char* html_buf) {
    href_point = strstr(html_buf, "<html>");
    char ch = NULL;
    int i=0;

    while ((href_point = strstr(href_point, href_str)) != NULL) {
        href_point = href_point+12;
        i=0;
        while (ch != '\"') {
            ch = href_point[i];
            i++;
        }
        i--;
        ch = NULL;

        std::string link_str(href_point, i);
        link_tree.push_back(link_str);
    }

    //PrintVector(link_tree);

    return link_tree;
}

void Spider::PrintVector(std::vector<std::string> const &input) {
  for (int i=0;i<input.size(); i++) {
    std::cout << input.at(i) << std::endl;
  }
}
