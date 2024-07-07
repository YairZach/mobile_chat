#include "loginRequestHandler.h"
#include "jsonDesrializer.h"
#include "jsonSerializer.h"
#include "requests.h"
#include "responses.h"

Handlers::RequestResult
LoginRequestHandler::handleRequest(Handlers::RequestInfo r) {
  Handlers::RequestResult res;

  switch (static_cast<char>(r.buffer.at(0))) {
  case LOGIN:
    res = login(r);
    break;
  case SIGNUP:
    res = signup(r);
    break;
  default:
    Responses::Error err = {"The message code is incorrect"};
    res.buffer = JsonSerializer::serializeResponse(err);
    res.newHandler = this->_handlerFactory.createLoginRequestHandler();
  }

  return res;
}

bool LoginRequestHandler::isRequestRelevent(Handlers::RequestInfo r) {
  return (r.buffer.at(0) == LOGIN || r.buffer.at(0) == SIGNUP);
}

Handlers::RequestResult LoginRequestHandler::login(Handlers::RequestInfo r) {
  Handlers::RequestResult res;
  Requests::Login req = JsonDesrializer::deserializeLoginRequest(r.buffer);
  Responses::Login resp;
  resp.status =
      this->_handlerFactory.getLoginManager().login(req.username, req.password);
  res.buffer = JsonSerializer::serializeResponse(resp);
  if (resp.status == 0) {
    // TODO(Yair Zach) add handler for logged in users
  } else
    res.newHandler = this->_handlerFactory.createLoginRequestHandler();
  return res;
}
