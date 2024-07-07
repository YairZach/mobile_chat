#pragma once

#include <string>

using std::string;

class IDatabase {
public:
  virtual bool open() = 0;
  virtual bool close() = 0;
  virtual bool doesUserExist(string name) = 0;
  virtual bool doesPasswordMatch(string name, string pass) = 0;
  virtual int addNewUser(string name, string pass, string email);
};
