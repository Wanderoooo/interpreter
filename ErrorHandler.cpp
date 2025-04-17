#include <iostream>
#include <stdexcept>

#include "ErrorHandler.hpp"

void ErrorHandler::errorOccurred(int line, std::string message) // TODO: not called anywhere yet
{
  errorReport(line, "TODO", message);
}

void ErrorHandler::errorReport(int line, std::string loc, std::string message)
{
  std::cerr << "Error: " << message << " at line: " << line << std::endl;
}