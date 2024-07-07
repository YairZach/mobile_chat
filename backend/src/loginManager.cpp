#include "loginManager.h"

int LoginManager::login(string name, string pass) {
  if (!this->_db->doesUserExist(name))
    return USER_NOT_EXISTS;

  if (!this->_db->doesPasswordMatch(name, pass))
    return PASS_NOT_TRUE;

  for (auto it = this->_loggedUsers.begin(); it != this->_loggedUsers.end();
       ++it) {
    if (it->getUsername() == name)
      return USER_ONLINE;
  }

  this->_loggedUsers.push_back(LoggedUser(name));
  return 0;
}

int LoginManager::logout(string name) {
  if (!this->_db->doesUserExist(name))
    return USER_NOT_EXISTS;

  for (auto it = this->_loggedUsers.begin(); it != this->_loggedUsers.end();
       ++it) {
    if (it->getUsername() == name) {
      this->_loggedUsers.erase(it);
      return 0;
    }
  }

  return USER_NOT_ONLINE;
}

int LoginManager::signup(string name, string pass, string email) {
  if (this->_db->doesUserExist(name))
    return USER_EXISTS;

  this->_db->addNewUser(name, pass, email);
  this->login(name, pass);
  return 0;
}
