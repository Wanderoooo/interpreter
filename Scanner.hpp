#pragma once

#include <string>
#include <vector>

#include "TokenInfo.hpp"

class Scanner {
public:
  Scanner(std::vector<char>& codeBuffer);
  int scanCodeBuffer();
  int scanCurrIndex();


private:
  std::vector<char> codeBuffer;
  std::vector<Token> tokens;
  int startIndex = { 0 };
  int currIndex = { 0 };
};