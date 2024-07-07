#include "server.h"
#include <exception>
#include <iostream>

using std::cout;
using std::endl;
using std::exception;

int main(void) {
  try {
    Server serv;
    serv.run();
  } catch (exception e) {
    cout << "Error: " << e.what() << endl;
  }
  return 0;
}
