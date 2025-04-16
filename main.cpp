#include <iostream>
#include <vector>

#include "constants.hpp"
#include "orck.hpp"

int main(int argc, char* argv[]) {
  int executionStatus = PROGRAM_EXECUTION_SUCCESS;
  Orck& interpreter = Orck::getInstance();


  if (argc > 2)
  {
    std::cout << "did not call script, try again. (Example: orck ./script)" << std::endl;
    executionStatus = PROGRAM_EXECUTION_FAILURE;
  }
  else if (argc == 2) // assume user pass in orck ./script
  {
    executionStatus = interpreter.execute(argv[1]);
  }
  else
  {
    executionStatus = interpreter.executePrompt();
  }

  return executionStatus;
}

