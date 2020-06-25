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