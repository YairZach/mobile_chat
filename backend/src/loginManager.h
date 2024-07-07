#pragma once

#include "iDatabase.h"
#include "loggedUser.h"
#include "loginManager.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

// signup error codes
#define USER_EXISTS -1
#define EMAIL_EXISTS -2

// login error codes
#define USER_NOT_EXISTS -3
#define PASS_NOT_TRUE -4
#define USER_ONLINE -5

// logout error codes
#define USER_NOT_ONLINE -6

class LoginManager {
private:
  IDatabase *_db;
  vector<LoggedUser> _loggedUsers;

public:
  explicit LoginManager(IDatabase *db) : _db(db) {}
  ~LoginManager() {}
  int signup(string name, string pass, string email);
  int login(string name, string pass);
  int logout(string name);
};
