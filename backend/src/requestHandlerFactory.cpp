#include "requestHandlerFactory.h"
#include "loginManager.h"

LoginRequestHandler *RequestHandlerFactory::createLoginRequestHandler() {
  return new LoginRequestHandler(*this, this->_loginManager);
}

LoginManager &RequestHandlerFactory::getLoginManager() {
  return this->_loginManager;
}
