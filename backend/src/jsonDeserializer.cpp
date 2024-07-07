#include "jsonDeserializer.h"
#include "requests.h"

Requests::Login JsonDesrializer::deserializeLoginRequest(vector<byte> buffer) {
  string msg(buffer.begin() + 5, buffer.end());
  json msgParse = json::parse(msg);

  Requests::Login res;
  res.username = msgParse["username"];
  res.password = msgParse["password"];

  return res;
}

Requests::Signup
JsonDesrializer::deserializeSingupRequest(vector<byte> buffer) {
  string msg(buffer.begin() + 5, buffer.end());
  json msgParse = json::parse(msg);

  Requests::Signup res;
  res.username = msgParse["username"];
  res.password = msgParse["password"];
  res.email = msgParse["email"];

  return res;
}
