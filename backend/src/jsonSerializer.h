#include "handlers.h"
#include "responses.h"
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

using nlohmann::json;
using std::string;
using std::vector;

typedef unsigned char byte;

#define ERROR_CODE 0
#define LOGIN_CODE 100
#define LOGOUT_CODE 101
#define SIGNUP_CODE 200

namespace JsonSerializer {
vector<byte> serializeResponse(Responses::Error);
vector<byte> serializeResponse(Responses::Login);
vector<byte> serializeResponse(Responses::Logout);
vector<byte> serializeResponse(Responses::Signup);
} // namespace JsonSerializer
