#ifndef DATE_H
#define DATE_H

#include <string>

struct Date
{
    unsigned day;
    unsigned month;
    unsigned year;

    void set_from_string(const std::string& date);

};
#endif