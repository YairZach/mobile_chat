#include "jsonSerializer.h"
#include "responses.h"

vector<byte> JsonSerializer::serializeResponse(Responses::Error r) {
  json msg;
  if (r.message.length() == 0)
    r.message = "";
  msg["message"] = r.message;
  int size = msg.dump().length();
  vector<byte> sizeByte(4);
  for (int i = 0; i < 4; i++)
    sizeByte[3 - i] = (size >> (i * 8));
  string str = string(1, static_cast<char>(static_cast<byte>(ERROR_CODE))) +
               string(sizeByte.begin(), sizeByte.end()) + msg.dump();
  vector<byte> res(str.begin(), str.end());
  return res;
}

vector<byte> JsonSerializer::serializeResponse(Responses::Login r) {
  json msg;
  msg["status"] = r.status;
  int size = msg.dump().length();
  vector<byte> sizeByte(4);
  for (int i = 0; i < 4; i++)
    sizeByte[3 - i] = (size >> (i * 8));
  string str = string(1, static_cast<char>(static_cast<byte>(LOGIN_CODE))) +
               string(sizeByte.begin(), sizeByte.end()) + msg.dump();
  vector<byte> res(str.begin(), str.end());
  return res;
}

vector<byte> JsonSerializer::serializeResponse(Responses::Logout r) {
  json msg;
  msg["status"] = r.status;
  int size = msg.dump().length();
  vector<byte> sizeByte(4);
  for (int i = 0; i < 4; i++)
    sizeByte[3 - i] = (size >> (i * 8));
  string str = string(1, static_cast<char>(static_cast<byte>(LOGOUT_CODE))) +
               string(sizeByte.begin(), sizeByte.end()) + msg.dump();
  vector<byte> res(str.begin(), str.end());
  return res;
}

vector<byte> JsonSerializer::serializeResponse(Responses::Signup r) {
  json msg;
  msg["status"] = r.status;
  int size = msg.dump().length();
  vector<byte> sizeByte(4);
  for (int i = 0; i < 4; i++)
    sizeByte[3 - i] = (size >> (i * 8));
  string str = string(1, static_cast<char>(static_cast<byte>(SIGNUP_CODE))) +
               string(sizeByte.begin(), sizeByte.end()) + msg.dump();
  vector<byte> res(str.begin(), str.end());
  return res;
}
