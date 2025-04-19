#include "Scanner.hpp"
#include "TokenInfo.hpp"
#include "constants.hpp"

#include <string>
#include <vector>

Scanner::Scanner(std::vector<char>& codeBuffer)
{
  codeBuffer.clear();
  this->codeBuffer = codeBuffer;
}

int Scanner::scanCodeBuffer()
{
  while (currIndex < codeBuffer.size())
  {
    startIndex = currIndex;
    scanCurrIndex();
  }
}

int Scanner::scanCurrIndex()
{
  char currChar = codeBuffer[currIndex];
  switch(currChar)
  {
    // case '(': addToken(LEFT_PAREN); break;
    // case ')': addToken(RIGHT_PAREN); break;
    // case '{': addToken(LEFT_BRACE); break;
    // case '}': addToken(RIGHT_BRACE); break;
    // case ',': addToken(COMMA); break;
    // case '.': addToken(DOT); break;
    // case '-': addToken(MINUS); break;
    // case '+': addToken(PLUS); break;
    // case ';': addToken(SEMICOLON); break;
    // case '*': addToken(STAR); break; 
  }
  currIndex++;
}