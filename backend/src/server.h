#include "communicator.h"
#include "iDatabase.h"
#include "requestHandlerFactory.h"
#include <iostream>
#include <string>
#include <thread>

using std::cout;
using std::endl;
using std::string;
using std::thread;

class Server {
public:
  Server();
  ~Server();
  void run();

private:
  Communicator _communicator;
  IDatabase *_db;
  RequestHandlerFactory _handlerFactory;
};
