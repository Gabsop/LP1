#ifndef TIME_H
#define TIME_H

#include <string>

struct Time
{
    unsigned hours;
    unsigned minutes;
    unsigned seconds;

    void set_from_string(const std::string& time);

};
#endif