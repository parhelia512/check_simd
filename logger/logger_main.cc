#include "logger.h"

std::string concatStream(const std::string& input) {
  return input;
}

void logToConsole() {
  const std::string test = "test";
  concatStream(test);
}

int main(void) {
  // Name/Location of the logfile
  const std::string logFile = "logfile.txt";
  // Create logger instance
  Log Log(logFile); 

  // Example usage of the logger
  Log.info("Program started.");
  logToConsole();

  return 0;
}
