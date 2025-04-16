#include <string>

class ErrorHandler
{
public:
  void errorOccurred(int line, std::string message); // TODO: somehow figure out location of error for better error handling
  void errorReport(int line, std::string loc, std::string message);
};