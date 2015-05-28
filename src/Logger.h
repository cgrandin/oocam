#ifndef _LOGGER_H
#define _LOGGER_H
#include <fstream>
#include <iostream>
#include <string>
#include <sys/stat.h>

using namespace std;
#define LOG *Logger::Instance()->get_logger()

class Logger{
 public:
  static Logger* Instance();
  static ofstream* get_logger();
 private:
  Logger();
  Logger(Logger const&){};
  ~Logger();
  static const string m_filename;
  static ofstream m_ofstream;
  static Logger* m_this;
  Logger& operator=(const Logger&){return *this;};
  bool file_exists(const string& filename);
};
#endif
