#include <ctime>

#include "base/dcheck.h"
#include "base/logging.h"
#include "logger.h"

// Constructor: 
Log::Log(const std::string& filename) {
#ifdef DCHECK_IS_ON
  DCHECK(filename == "logfile.txt" ||
         filename == "log.txt" ||
         filename == "check_simd.txt" ||
         filename == "check_simd_logfile.txt" ||
         filename == "logger.txt"         
        );
#endif
  init(filename);
}

// Destructor: Closes the log file
Log::~Log() { logFile.close(); }

// Opens the log file in append mode
void Log::init(const std::string& filename) {
  logFile.open(filename, std::ios::app);
  if (!logFile.is_open()) {
    std::cerr << "Error opening log file." << std::endl;
  }
}

void Log::getTime() {
  // Get current timestamp
  time_t now = time(0);
  tm* timeinfo = localtime(&now);
  strftime(timestamp, sizeof(timestamp),
          "%Y-%m-%d %H:%M:%S", timeinfo);
}

// Log messages with a given log level
void Log::info(const std::string& info_message) {
  // Output to console
  //getTime();
  //std::wostringstream infoEntry;
  //infoEntry << "[" << timestamp << "] "
           //<< levelToString(INFO) << ": " << info_message
           //<< std::endl;
  //logOutput = infoEntry.str();
  //std::wcout.precision(32); // Set precision for output
  //std::wcout << logOutput;
  //filelog(logOutput);
  LOG(0) << info_message
}

void Log::warn(const std::string& warn_message) {
  //getTime();
  //std::wostringstream warnEntry;
  //warnEntry << "[" << timestamp << "] "
           //<< levelToString(WARN) << ": " << warn_message
           //<< std::endl;
  //logOutput = warnEntry.str();
  //std::wcerr.precision(32);
  //std::wcerr << logOutput;
  //filelog(logOutput);
  LOG(1) << warn_message
}

void Log::error(const std::string& error_message) {
  //getTime();
  //std::wostringstream errEntry;
  //errEntry << "[" << timestamp << "] "
           //<< levelToString(ERROR) << ": " << error_message
           //<< std::endl;
  //logOutput = errEntry.str();
  //std::wcerr.precision(32);
  //std::wcerr << logOutput;
  //filelog(logOutput);
  //logFile.close();
  LOG(2) << error_message
  std::cerr << "FATAL: Terminating with error code: \n";
  NOTREACHABLE();
}

void Log::nl(LogLevel level) {
  std::ostringstream nlEntry;
  nlEntry << levelToString(level);
  logOutput = nlEntry.str();
  std::cout << std::endl;
  filelog(logOutput);
}

void Log::filelog(std::string logOutput) {
  // Output to log file
  if (logFile.is_open()) {
    logFile << logOutput;
    logFile
      .flush(); // Ensure immediate write to file
  }
}

// Converts log level to a string for output
const std::string Log::levelToString(LogLevel level) {
  switch (level) {
    case INFO:
      return "INFO";
    case WARN:
      return "WARNING";
    case ERROR:
      return "ERROR";
    case NL:
      return "\n";
    default:
      return "NOTREACHED()";
  }
}

#ifdef STATIC_LOGGER
int main(void) {
  // Name/Location of the logfile
  const std::string logFile = "logfile.txt";
  // Create logger instance
  Log Log(logFile); 

  // Example usage of the logger
  Log.info("Program started.");
  Log.warn("This is a sample debug warning created with Log.warn();");

  Log.nl(NL);
  Log.info("The above is a newline created with Log.nl();");
  Log.error("An error occurred.");

  return 0;
}
#endif
