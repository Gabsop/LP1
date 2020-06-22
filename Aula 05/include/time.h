#if !defined (TIME_H)
#define TIME_H

#include <string>

// Returns the current time and date
std::string get_current_date();
std::string get_current_time();
std::string format_current_date(const std::string& format);

#endif