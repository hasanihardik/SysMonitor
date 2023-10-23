#include "processor.h"
#include "linux_parser.h"

// Done: Return the aggregate CPU utilization
float Processor::Utilization() { 
  long activeJiffies = LinuxParser::ActiveJiffies();
  long totJiffies = LinuxParser::Jiffies();
  return float(activeJiffies) / float(totJiffies); 
}