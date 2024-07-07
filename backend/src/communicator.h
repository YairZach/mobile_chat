#pragma once

#include "iRequestHandler.h"
#include "requestHandlerFactory.h"
#include <ctime>
#include <exception>
#include <iostream>
#include <map>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <string>
#include <sys/socket.h>
#include <thread>
#include <unistd.h>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::exception;
using std::map;
using std::string;
using std::thread;
using std::vector;

typedef unsigned char byte;

class Communicator {
public:
  explicit Communicator(RequestHandlerFactory &factory);
  ~Communicator();
  void startHandleRequest();

private:
  void bindAndListen();
  void handleNewClient(int clientSocket);
  int _serverSocket;
  map<int, IRequestHandler *> _clients;
  RequestHandlerFactory &_handleFactory;
};
