#pragma once

#include "iDatabase.h"
#include "loginManager.h"

class LoginRequestHandler;

class RequestHandlerFactory {
private:
  LoginManager _loginManager;
  IDatabase *_db;

public:
  explicit RequestHandlerFactory(IDatabase *db)
      : _db(db), _loginManager(LoginManager(db)) {}
  LoginRequestHandler *createLoginRequestHandler();
  LoginManager &getLoginManager();
};
