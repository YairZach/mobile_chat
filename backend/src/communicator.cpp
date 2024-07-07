#include "communicator.h"
#include "handlers.h"
#include "iRequestHandler.h"
#include "requestHandlerFactory.h"
#include <iostream>
#include <netinet/in.h>
#include <stdexcept>
#include <sys/socket.h>

Communicator::Communicator(RequestHandlerFactory &factory)
    : _handlerFactory(factory) {
  this->_serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}

Communicator::~Communicator() {
  cout << "closing the socket" << endl;
  try {
    close(this->_serverSocket);
  } catch (...) {
  }
}

void Communicator::bindAndListen() {
  this->_serverSocket = socket(AF_INET, SOCK_STREAM, 0);

  sockaddr_in sockAddr;
  sockAddr.sin_family = AF_INET;
  sockAddr.sin_port = htons(8081);
  sockAddr.sin_addr.s_addr = INADDR_ANY;

  if (bind(this->_serverSocket, (struct sockaddr *)&sockAddr,
           sizeof(sockAddr)) == -1) {
    std::cerr << "Can't bind to ip/port" << endl;
  }
  if (listen(this->_serverSocket, 8) == -1) {
    std::cerr << "Can't start listening" << endl;
  }
}

void Communicator::startHandleRequest() {
  this->bindAndListen();

  while (true) {
    int clientSocket = accept(this->_serverSocket, NULL, NULL);
    if (clientSocket == -1)
      throw std::runtime_error("cant connect to client");

    this->_clients[clientSocket] = reinterpret_cast<IRequestHandler *>(
        this->_handlerFactory.createLoginRequestHandler());

    thread tr(&Communicator::handleNewClient, this, clientSocket);
    tr.detach();
  }
}

void Communicator::handleNewClient(int clientSocket) {
  Handlers::RequestResult result;
  Handlers::RequestInfo info;
  char *response = NULL;
  int status = true;

  do {
    try {
      char msg[1024] = {0};
      char check = {0};
      status = recv(clientSocket, msg, 1023, 0);

      if (status == -1)
        throw std::runtime_error("Client disconnected");

      vector<byte> buffer(msg, msg + 1024);
      info = {msg[0], std::time(NULL), buffer};
      result = this->_clients[clientSocket]->handleRequest(info);
      response = reinterpret_cast<char *>(&result.buffer[0]);

      send(clientSocket, response, result.buffer.size(), 0);

      delete this->_clients[clientSocket];
      this->_clients[clientSocket] = result.newHandler;
    } catch (...) {
    }
  } while (true);
}
