#include <exception>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::exception;

int main(void) {
  try {

  } catch (exception e) {
    cout << "Error: " << e.what() << endl;
  }
  return 0;
}
