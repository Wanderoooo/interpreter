#pragma once

#include <string>
#include <vector>

class Literal {
private:
  std::vector<char> v;
  union {
    int i;
    bool b;
  } data = { 0 };
};