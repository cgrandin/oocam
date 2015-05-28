#include "Logger.h"

const string Logger::m_filename = "oocam_runtime.log";
Logger* Logger::m_this = 0;
ofstream Logger::m_ofstream;

Logger::Logger(){
  // Delete old log file if it exists
  if(file_exists(m_filename)){
    remove(m_filename.c_str());
  }
}

Logger* Logger::Instance(){
  static Logger m_this;
  m_ofstream.open(m_filename.c_str(), ios::out | ios::trunc);
  return &m_this;
}

ofstream* Logger::get_logger(){
 m_ofstream.open(m_filename.c_str(), ios::app );
 return &m_ofstream;
}

bool Logger::file_exists(const string& filename){
 struct stat buf;
 if (stat(filename.c_str(), &buf) != -1){
   return true;
 }
 return false;
}

Logger::~Logger(){
  m_ofstream.close();
}
