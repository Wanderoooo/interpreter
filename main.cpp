#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>

#define PROGRAM_EXECUTION_FAILURE 1;
#define PROGRAM_EXECUTION_SUCCESS 0;

namespace fs = std::filesystem;


int run(const std::string userInput)
{
  std::cout << userInput << std::endl; // TODO: actually run lines
  return PROGRAM_EXECUTION_SUCCESS;
}

int executePrompt()
{
  std::string userInput;
  std::getline(std::cin, userInput); // when Enter hit, reads line
  return run(userInput);
}

std::vector<char> readFileBytes(const std::string& filePath) {
  std::ifstream file(filePath, std::ios::binary);
  if (!file) {
      throw std::runtime_error("Failed to open file: " + filePath);
  }

  // Read file contents into a vector
  std::vector<char> fileBytes((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
  return fileBytes;
}

int searchAndReadScript(const std::string& scriptPath) {
  fs::path path(scriptPath);
  std::string directory = path.parent_path().string();
  std::string scriptName = path.filename().string();
  int readSuccess = PROGRAM_EXECUTION_FAILURE;

  for (const auto& entry : fs::directory_iterator(directory)) {
    if (entry.is_regular_file() && entry.path().filename() == scriptName) {
      std::cout << "Found script: " << entry.path() << std::endl;

      try {
        std::vector<char> scriptBytes = readFileBytes(entry.path().string());
        std::cout << "Script size: " << scriptBytes.size() << " bytes" << std::endl; // TODO: make script actually call run()
        readSuccess = PROGRAM_EXECUTION_SUCCESS;
        // Process script bytes as needed
      } catch (const std::exception& e) {
        std::cerr << "Error reading script: " << e.what() << std::endl;
      }
    }
  }

  std::cout << "Script not found in directory: " << directory << std::endl;
  return readSuccess;
}


int execute(std::string scriptPath)
{
  return searchAndReadScript(scriptPath);
}


int main(int argc, char* argv[]) {
  int executionStatus = PROGRAM_EXECUTION_SUCCESS;

  if (argc > 2)
  {
    std::cout << "did not call script, try again. (Example: orck ./script)" << std::endl;
    executionStatus = PROGRAM_EXECUTION_FAILURE;
  }
  else if (argc == 2) // assume user pass in orck ./script
  {
    executionStatus = execute(argv[1]);
  }
  else
  {
    executionStatus = executePrompt();
  }

  return executionStatus;
}

