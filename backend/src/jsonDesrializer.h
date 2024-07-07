#pragma once

#include "requests.h"
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

using nlohmann::json;
using std::string;
using std::vector;

typedef unsigned char byte;

namespace JsonDesrializer {
Requests::Login deserializeLoginRequest(vector<byte> buffer);
Requests::Signup deserializeSingupRequest(vector<byte> buffer);
}; // namespace JsonDesrializer
