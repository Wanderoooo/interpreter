#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

#include "orck.hpp"
#include "constants.hpp"

namespace fs = std::filesystem;

Orck::Orck()
{

}

Orck& Orck::getInstance()
{
  static Orck instance;
  return instance;
}

int Orck::executePrompt()
{
  std::string userInput;
  while (true)
  {
    std::getline(std::cin, userInput); // when Enter hit, reads line
    if (userInput == "Ctrl+E")
    {
      std::cout << "Ctrl+E pressed, exiting program...";
      break;
    }

    std::vector<char> strVec(userInput.begin(), userInput.end());
    int runLineResult = run(strVec);

    if (runLineResult)
    {
      hasError = PROGRAM_EXECUTION_FAILURE;
    }
  }
}

int Orck::execute(std::string scriptPath)
{
  return searchAndReadScript(scriptPath);
}

int Orck::run(std::vector<char>& strVec)
{
  // Scanner input here
  // TODO: guard for empty string
  std::string s(strVec.begin(), strVec.end()); // TODO: vector can be too long for a string! Fixed after run is implemented
  std::cout << s << std::endl; // TODO: actually run lines
  return PROGRAM_EXECUTION_SUCCESS;
}

std::vector<char> Orck::readFileBytes(const std::string& filePath)
{
  std::ifstream file(filePath, std::ios::binary);
  if (!file) {
      throw std::runtime_error("Failed to open file: " + filePath);
  }

  // Read file contents into a vector
  std::vector<char> fileBytes((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
  return fileBytes;
}

int Orck::searchAndReadScript(const std::string& scriptPath)
{
  fs::path path(scriptPath);
  std::string directory = path.parent_path().string();
  std::string scriptName = path.filename().string();
  int readSuccess = PROGRAM_EXECUTION_FAILURE;

  for (const auto& entry : fs::directory_iterator(directory)) {
    if (entry.is_regular_file() && entry.path().filename() == scriptName) {
      std::cout << "Found script: " << entry.path() << std::endl;

      try {
        std::vector<char> scriptBytes = readFileBytes(entry.path().string());
        std::cout << "Script size: " << scriptBytes.size() << " bytes" << std::endl; // TODO: print for debug
        readSuccess = run(scriptBytes);
        // Process script bytes as needed
      } catch (const std::exception& e) {
        std::cerr << "Error reading script: " << e.what() << std::endl;
      }
    }
  }

  std::cout << "Script not found in directory: " << directory << std::endl;
  return readSuccess;
}
