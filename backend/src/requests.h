#pragma once

#include <string>

using std::string;

namespace Requests {

struct Login {
public:
  string username;
  string password;
};

struct Signup {
public:
  string username;
  string password;
  string email;
};

}; // namespace Requests
