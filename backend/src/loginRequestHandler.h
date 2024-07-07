#pragma once

class RequestHandlerFactory;

#include "handlers.h"
#include "iRequestHandler.h"
#include "requestHandlerFactory.h"

class LoginRequestHandler : public IRequestHandler {
public:
  LoginRequestHandler(RequestHandlerFactory &factory, LoginManager &login)
      : _handlerFactory(factory), _loginManager(login) {}
  bool isRequestRelevent(Handlers::RequestInfo r) override;
  Handlers::RequestResult handleRequest(Handlers::RequestInfo r) override;
  ~LoginRequestHandler() {}

private:
  RequestHandlerFactory &_handlerFactory;
  LoginManager &_loginManager;
  Handlers::RequestResult login(Handlers::RequestInfo r);
  Handlers::RequestResult signup(Handlers::RequestInfo r);
};
