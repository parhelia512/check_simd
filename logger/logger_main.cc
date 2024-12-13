#include "logger.h"

std::string concatStream(const std::string& input) {
  return input;
}

void logToConsole() {
  const std::string test = "test";
  concatStream(test);
}

int main(void) {
  try {
    // Alex313031: TODO: To be replaced with actual logic later
    const bool dum = true;
    if (dum) {
      // Name/Location of the logfile
      const std::string logFile = "logfile.txt";
      // Create logger instance
      Log Log(logFile); 

      // Example usage of the logger
      Log.info("Standalone Logging Program started.");
      logToConsole();

      return 0;
    } else {
      constexpr int return_code = 1;
      throw (return_code);
    }
  } catch(int return_code) {
    void exit(const int& return_code);
  }
}
