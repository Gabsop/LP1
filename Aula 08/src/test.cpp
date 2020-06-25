#include "../include/Date.h"
#include "../include/Diary.h"

#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string date = "25/06/2020";
    Date d;

    std::stringstream stream(date);
    char discard;

    stream >> d.day;
    stream >> discard;
    stream >> d.month;
    stream >> discard;
    stream >> d.year;

    std::string result = stream.str();

    std::cout << d.day << std::endl;
    std::cout << d.month << std::endl;
    std::cout << d.year << std::endl;

    return 0;
}
