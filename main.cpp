#include "aracnewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    /*int port_number = 8228;

    if (argc == 1)
      std::cout << "Using default port number, 8228." << std::endl;
    else if (argc == 3) {
      port_number = atoi(argv[2]);
    } else {
      std::cout << "::Error::" << std::endl;
      std::cout << "Wrong number of arguments!" << std::endl;
      exit(0);
    }*/

    QApplication a(argc, argv);
    AracneWindow w;
    w.show();

    return a.exec();
}
