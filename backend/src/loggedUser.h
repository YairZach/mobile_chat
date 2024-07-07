#pragma once

#include "iDatabase.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class LoggedUser {
private:
  string _username;

public:
  string getUsername();
  explicit LoggedUser(string name) : _username(name) {}
};
