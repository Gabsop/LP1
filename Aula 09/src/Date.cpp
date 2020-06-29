#include "../include/Date.h"
#include "../include/Aux.h"
#include <string>
#include <sstream>

void Date::set_from_string(const std::string& date)
{
    std::stringstream stream(date);

    char discard;
    stream >> day;
    stream >> discard;
    stream >> month;
    stream >> discard;
    stream >> year; 
}

std::string Date::to_string()
{
    std::stringstream stream;
    if (day < 10)
    {
        stream << '0';
    }
    stream << day << '/';

    if(month < 10)
    {
        stream << '0';
    }
    stream << month << '/';
    stream << year;

    return stream.str();

}