#pragma once

#include "handlers.h"

// login handler codes
#define LOGIN '\x64'
#define SIGNUP '\x65'
#define LOGOUT '\x66'

// messaging handler code
#define SYNC = '\x70'
#define SEND_MESSAGE = '\x71'

class IRequestHandler {
public:
  virtual bool isRequestRelevent(Handlers::RequestInfo r) = 0;
  virtual Handlers::RequestResult handleRequest(Handlers::RequestInfo r) = 0;
  virtual ~IRequestHandler() {}
};
