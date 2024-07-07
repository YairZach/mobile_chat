#include "sqliteDatabase.h"
#include <filesystem>
#include <fmt/core.h>
#include <iostream>

bool SqliteDatabase::open() {
  string dbFileName = "chat_db.sqlite";

  bool fileExists = std::filesystem::exists(dbFileName);
  int res = sqlite3_open(dbFileName.c_str(), &_db);
  if (res != SQLITE_OK) {
    this->_db = nullptr;
    std::cerr << "Failed to open db" << endl;
    return false;
  }

  char *errMsg = nullptr;
  string sqlStatement;

  if (fileExists) {
    sqlStatement = "CREATE TABLE USERS (NAME TEXT PRIMARY KEY NOT NULL, "
                   "PASSWORD TEXT NOT NULL, EMAIL TEXT NOT NULL)";
    errMsg = nullptr;
    res = sqlite3_exec(_db, sqlStatement.c_str(), NULL, NULL, &errMsg);
    if (res != SQLITE_OK) {
      std::cerr << errMsg << endl;
      return false;
    }
  }

  return true;
}

bool SqliteDatabase::close() {
  int res = sqlite3_close(_db);
  if (res != SQLITE_OK) {
    std::cerr << "couldnt close db" << endl;
    return false;
  }
  _db = nullptr;

  return true;
}

bool SqliteDatabase::doesUserExist(string name) {
  string sqlStatement = "SELECT NAME FROM USERS WHERE NAME = '" + name + "';";
  char *errMsg = nullptr;
  bool exists = false;
  int res = sqlite3_exec(
      _db, sqlStatement.c_str(),
      [](void *data, int argc, char **argv, char **azColName) -> int {
        *reinterpret_cast<bool *>(data) = true;
        return 0;
      },
      reinterpret_cast<void *>(&exists), &errMsg);
  return res == SQLITE_OK && exists;
}

bool SqliteDatabase::doesPasswordMatch(string name, string pass) {
  string sqlStatement = "SELECT NAME FROM USERS WHERE NAME = '" + name +
                        "' AND PASSWORD = '" + pass + "';";
  char *errMsg = nullptr;
  bool exists = false;
  int res = sqlite3_exec(
      _db, sqlStatement.c_str(),
      [](void *data, int argc, char **argv, char **azColName) -> int {
        *reinterpret_cast<bool *>(data) = true;
        return 0;
      },
      reinterpret_cast<void *>(&exists), &errMsg);
  return res == SQLITE_OK && exists;
}

int SqliteDatabase::addNewUser(string name, string pass, string email) {
  string sqlStatement = fmt::format(
      "INSERT INTO USERS (NAME, PASSWORD, EMAIL) VALUES ('{}', '{}', '{}')",
      name, pass, email);
  char *errMsg = nullptr;

  int res = sqlite3_exec(_db, sqlStatement.c_str(), NULL, NULL, &errMsg);
  return res == SQLITE_OK;
}
