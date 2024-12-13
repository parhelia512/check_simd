#include "logger.h"

int main(void) {
  // Name/Location of the logfile
  const std::string logFile = "logfile.txt";
  // Create logger instance
  Log Log(logFile); 

  // Example usage of the logger
  Log.info("Program started.");
  Log.info("Program started.");

  return 0;
}

std::string concatStream(char input) {
  return char input;
}

void logToConsole(concatStream()) {
}
