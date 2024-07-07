#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

typedef int code;

namespace Responses {

struct Error {
public:
  string message;
};

struct Login {
public:
  code status;
};

struct Signup {
public:
  code status;
};

struct Logout {
public:
  code status;
};

}; // namespace Responses
