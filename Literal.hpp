#pragma once

#include <string>

class Literal {
private:
  union {
    char s[sizeof(std::string)];
    int i;
    bool b;
  };
};