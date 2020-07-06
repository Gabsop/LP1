#include "../include/Aux.h"
#include <fstream>
#include <iostream>

std::string get_current_date() { return format_current_date("%d/%m/%Y"); }
std::string get_current_time() { return format_current_date("%H:%M:%S"); }

std::string format_current_date(const std::string &format)
{
    std::time_t time = std::time(nullptr);
    char result[1024];
    std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));
    return std::string(result);
}

bool checkData()
{
    std::ifstream file("messages.md");
    std::string date = "# " + get_current_date();
    std::string message;

    if (!file.is_open())
    {
        std::cerr << "Arquivo inexistente ou sem permissão de leitura" << std::endl;
    }

    while (!file.eof())
    {
        std::getline(file, message);
        if (date == message)
        {
            return true;
        }
    }
    return false;
}