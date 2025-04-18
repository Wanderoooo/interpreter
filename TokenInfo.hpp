#pragma once

#include <string>
#include "Literal.hpp"

namespace TokenInfo {

  // code credit - book: Crafting an Interpreter
  enum class TokenType { 
    // Single-character tokens
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

    // One or two character tokens
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,

    // Literals
    IDENTIFIER, STRING, NUMBER,

    // Keywords
    AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

    // End of file
    END_OF_FILE
  };

  class Token {
  public:
    Token(std::string lexeme, int line) : lexeme(lexeme), line(line) {} // TODO: write a Token cpp file to def all functions
  private: 
    std::string lexeme;
    Literal literal; // TODO: define Literal -> convert to actual type
    int line; // no file should have a huge number of lines
  };
};
