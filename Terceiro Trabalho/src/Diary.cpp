#include <fstream>
#include <iostream>
#include <sstream>
#include "../include/Diary.h"
#include "../include/Date.h"
#include "../include/Time.h"
#include "../include/Aux.h"

Diary::Diary()
{
    define_path();
    load_messages();
}

void Diary::add(const std::string &message)
{
    Message current_message;

    Date current_date;
    std::string get_date = get_current_date();

    Time current_time;
    std::string get_time = get_current_time();

    current_date.set_from_string(get_date);
    current_time.set_from_string(get_time);
    current_message.content = message;

    current_message.date = current_date;
    current_message.time = current_time;

    messages.push_back(current_message);
    std::cout << "Mensagem Adicionada!" << std::endl;
}

void Diary::write()
{
    // Gravar as mensagens no disco
    std::ofstream file(path, std::ios::app);

    if (!file.is_open())
    {
        std::cerr << "The file cannot be created." << std::endl;
        return;
    }

    bool check = checkData();

    if (check == false)
    {
        file << "\n";
        file << "# " << messages.back().date.to_string() << std::endl;
        file << "\n";
        file << "- " << messages.back().time.to_string() << " " << messages.back().content << "\n";
    }
    else if (check == true)
    {
        file << "- " << get_current_time() << " " << messages.back().content << "\n";
    }
}

void Diary::define_path()
{
    std::ifstream file("diary.config");
    std::string default_path = "path=diary.md";
    std::string default_format = "default_format=%d %t: %m";

    if (!file.is_open())
    {
        std::ofstream create_file("diary.config");
        create_file << default_path << std::endl;
        create_file << default_format;
        return;
    }

    std::string message;

    getline(file, message);
    char discard;

    std::stringstream stream(message);

    for (size_t i = 0; i < 5; i++)
    {
        stream >> discard;
    }

    stream >> path;
}

void Diary::load_messages()
{
    Message m;
    std::string message;
    std::string date;
    std::ifstream file(path);

    if (!file.is_open())
    {
        return;
    }

    while (!file.eof())
    {
        std::getline(file, message);

        if (message.size() == 0)
        {
            continue;
        }
        char compare = message.at(0);

        if (compare == '#')
        {
            std::stringstream stream(message);

            char discard;
            stream >> discard;
            stream >> date;
            m.date.set_from_string(date);
        }

        if (compare == '-')
        {
            std::stringstream stream(message);
            std::string content;
            std::string time;

            char discard;
            stream >> discard;
            stream >> time;
            m.time.set_from_string(time);
            m.date.set_from_string(date);
            std::getline(stream, content);
            m.content = content;
            messages.push_back(m);
        }
    }
}

std::vector<Message *> Diary::search(const std::string &what)
{
    std::vector<Message *> message;
    size_t search;

    for (size_t i = 0; i < messages.size(); i++)
    {
        search = messages[i].content.find(what);
        if (search != std::string::npos)
        {
            message.push_back(&messages[i]);
        }
    }
    return message;
}