#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

// Done: Return this process's ID
int Process::Pid() const { return pid_; }

// Done: Return this process's CPU utilization
float Process::CpuUtilization() { 
  int pid = Process::Pid();
  float active_time = float(LinuxParser::ActiveJiffies(pid) / sysconf(_SC_CLK_TCK));
  float up_time = float(LinuxParser::UpTime(pid));
  return active_time / up_time; 
}

// Done: Return the command that generated this process
string Process::Command() { 
  int pid = Process::Pid();
  return LinuxParser::Command(pid); 
}

// Done: Return this process's memory utilization
string Process::Ram() const {
  int pid = Process::Pid();
  return LinuxParser::Ram(pid); 
}

// Done: Return the user (name) that generated this process
string Process::User() { 
  int pid = Process::Pid();
  return LinuxParser::User(pid); 
}

// Done: Return the age of this process (in seconds)
long int Process::UpTime() { 
  int pid = Process::Pid();
  return LinuxParser::UpTime(pid); 
}

// Done: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const { return stol(this->Ram()) < stol(a.Ram()); }