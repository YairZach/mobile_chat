#include "server.h"
#include "communicator.h"
#include "requestHandlerFactory.h"
#include "sqliteDatabase.h"
#include <unistd.h>

using std::cin;

Server::Server()
    : _db(new SqliteDatabase()),
      _handlerFactory(RequestHandlerFactory(this->_db)),
      _communicator(Communicator(this->_handlerFactory)) {
  this->_db->open();
}

Server::~Server() {
  this->_db->close();
  delete this->_db;
}

void Server::run() {
  string cmd = "";

  thread listener(&Communicator::startHandleRequest, this->_communicator);
  listener.detach();

  // sleep(200);

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
