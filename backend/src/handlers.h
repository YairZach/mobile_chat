#pragma once

class IRequestHandler;

#include <ctime>
#include <string>
#include <vector>

using std::string;
using std::vector;

typedef unsigned char byte;

namespace Handlers {

struct RequestResult {
public:
  vector<byte> buffer;
  IRequestHandler *newHandler;
};

struct RequestInfo {
public:
  int id;
  time_t recivalTime;
  vector<byte> buffer;
};
}; // namespace Handlers
