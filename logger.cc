#include <ctime>

#include "base/dcheck.h"
#include "logger.h"

// Constructor: 
Log::Log(const std::string& filename) {
#ifdef DCHECK_IS_ON
  DCHECK(filename);
#endif
  init(filename);
}

// Destructor: Closes the log file
Log::~Log() { logFile.close(); }

// Get current timestamp
time_t now = time(0);
tm* timeinfo = localtime(&now);
char timestamp[29];

// Opens the log file in append mode
void Log::init(const std::string& filename) {
  logFile.open(filename, std::ios::app);
  if (!logFile.is_open()) {
    std::cerr << "Error opening log file." << std::endl;
  }
}

// Log messages with a given log level
void Log::info(const std::string& info_message) {
  strftime(timestamp, sizeof(timestamp),
           "%Y-%m-%d %H:%M:%S", timeinfo);

  // Output to console
  std::ostringstream infoEntry;
  infoEntry << "[" << timestamp << "] "
           << levelToString(INFO) << ": " << info_message
           << std::endl;
  logOutput = infoEntry.str();
  std::cout << logOutput;
  filelog(logOutput);
}

void Log::warn(const std::string& warn_message) {
  strftime(timestamp, sizeof(timestamp),
           "%Y-%m-%d %H:%M:%S", timeinfo);

  std::ostringstream warnEntry;
  warnEntry << "[" << timestamp << "] "
           << levelToString(WARN) << ": " << warn_message
           << std::endl;
  logOutput = warnEntry.str();
  std::cerr << logOutput;
  filelog(logOutput);
}

void Log::error(const std::string& error_message) {
  strftime(timestamp, sizeof(timestamp),
           "%Y-%m-%d %H:%M:%S", timeinfo);

  std::ostringstream errEntry;
  errEntry << "[" << timestamp << "] "
           << levelToString(ERROR) << ": " << error_message
           << std::endl;
  logOutput = errEntry.str();
  std::cerr << logOutput;
  filelog(logOutput);
  logFile.close();
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

#ifdef STANDALONE_LOGGER
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
  Log.info("this is a warnah");
  Log.error("An error occurred.");

  return 0;
}
#endif
