#include "../include/Time.h"
#include "../include/Aux.h"
#include <string>
#include <sstream>

void Time::set_from_string(const std::string& time)
{
    std::stringstream stream(time);

    char discard;
    stream >> hours;
    stream >> discard;
    stream >> minutes;
    stream >> discard;
    stream >> seconds; 
}