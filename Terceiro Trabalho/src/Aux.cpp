#include "../include/Aux.h"
#include <fstream>
#include <iostream>
#include <sstream>

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
    std::string line;
    std::string path;
    std::ifstream config_file("diary.config");
    std::string default_path = "path=diary.md";
    std::string default_format = "default_format=%d %t: %m";

    if (!config_file.is_open())
    {
        std::ofstream create_file("diary.config");
        create_file << default_path << std::endl;
        create_file << default_format;
    }

    getline(config_file, line);
    char discard;

    std::stringstream stream(line);

    for (size_t i = 0; i < 5; i++)
    {
        stream >> discard;
    }

    stream >> path;

    std::ifstream file(path);
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