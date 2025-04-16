#pragma once

class Orck {
public:
  static Orck& getInstance();
  int run(const std::string userInput);
  int executePrompt();
  std::vector<char> readFileBytes(const std::string& filePath);
  int searchAndReadScript(const std::string& scriptPath);
  int execute(std::string scriptPath);

private:
  Orck();
  Orck(const Orck&) = delete;
  Orck& operator=(const Orck&) = delete;
};