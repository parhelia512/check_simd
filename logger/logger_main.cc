#include "logger.h"

std::wstring concatStream(const std::wstring& input) {
  return input;
}

std::wstring logToConsole() {
  const std::wstring test = "test";
  const std::wstring concattedStream =
      concatStream(test);
  return concattedStream;
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
      Log.warn(logToConsole());

      return 0;
    } else {
      constexpr int return_code = 1;
      throw (return_code);
    }
  } catch(int return_code) {
    void exit(const int& return_code);
  }
}
