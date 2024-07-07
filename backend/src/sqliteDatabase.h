#pragma once

#include "iDatabase.h"
#include "sqlite3.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <string>

using std::cout;
using std::endl;
using std::map;
using std::string;

class SqliteDatabase : public IDatabase {
public:
  bool open() override;
  bool close() override;
  bool doesUserExist(string name) override;
  bool doesPasswordMatch(string name, string pass) override;
  int addNewUser(string name, string pass, string email) override;
  ~SqliteDatabase() {}

private:
  sqlite3 *_db;
};
