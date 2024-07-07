#include "server.h"
#include <unistd.h>

using std::cin;

void Server::run() {
  string cmd = "";

  thread listener();
  listener.detach();

  sleep(200);

  do {
    cout << "Enter command: ";
    cin >> cmd;

    if (cmd == "EXIT" || cmd == "") {
    } else if (cmd == "HELP") {
      cout << "Commands: EXIT, HELP" << endl;
    } else {
      cout << "Please enter a valid command!" << endl
           << "for help enter: HELP" << endl;
    }
  } while (cmd != "EXIT");
}
