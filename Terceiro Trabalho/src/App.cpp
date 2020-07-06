#include "../include/App.h"
#include <string>
#include <fstream>
#include <sstream>
#include <istream>
#include <iostream>

App::App() : diary()
{
    config();
}

int App::run(int argc, char *argv[])
{
    if (argc == 1)
    {
        return show_usage();
    }

    std::string action = argv[1];

    if (action == "add")
    {
        if (argc == 2)
        {
            add();
        }
        else
        {
            add(argv[2]);
        }
    }
    else if (action == "list")
    {
        if (argc == 2)
        {
            list_messages();
        }
        else
        {
            list_messages(argv[2]);
        }
    }
    else if (action == "search")
    {
        if (argc == 2)
        {
            search();
        }
        else
        {
            search(argv[2]);
        }
    }
    else if (action == "interactive")
    {
        interactive();
    }
    else
    {
        return show_usage();
    }

    return 0;
}

void App::config()
{
    std::string message;
    std::string path;
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

    getline(file, message);
    char discard;

    std::stringstream stream(message);

    for (size_t i = 0; i < 5; i++)
    {
        stream >> discard;
    }

    stream >> path;
}

void App::add()
{
    std::string message;
    std::cout << "Enter your message:" << std::endl;
    std::getline(std::cin, message);

    add(message);
}

void App::add(const std::string message)
{
    diary.add(message);
    diary.write();
}

void App::list_messages()
{
    std::fstream file("diary.config");
    std::string line;
    size_t search_date;
    size_t search_time;
    size_t search_message;
    std::string date = "%d";
    std::string time = "%t";
    std::string message = "%m";
    char discard;

    std::getline(file, line);
    std::getline(file, line);
    std::string format;

    std::stringstream stream(line);

    for (size_t i = 0; i < 15; i++)
    {
        stream >> discard;
    }
    std::getline(stream, format);

    for (size_t i = 0; i < diary.messages.size(); i++)
    {
        std::string current_message = format;
        search_date = current_message.find(date);
        if (search_date >= 0 && search_date < 1000)
        {
            //std::cout << "Entrou data" << std::endl;
            current_message.erase(search_date, 2);
            current_message.insert(search_date, diary.messages[i].date.to_string());
        }

        search_time = current_message.find(time);
        if (search_time >= 0 && search_time < 1000)
        {
            //std::cout << "Entrou time" << std::endl;
            current_message.erase(search_time, 2);
            current_message.insert(search_time, diary.messages[i].time.to_string());
        }

        search_message = current_message.find(message);
        if (search_message >= 0 && search_message < 1000)
        {
            //std::cout << "Entrou message" << std::endl;
            current_message.erase(search_message, 2);
            current_message.insert(search_message, diary.messages[i].content);
        }

        std::cout << current_message << std::endl;
    }
}

void App::list_messages(const std::string format)
{
    std::fstream file("diary.config");
    std::string line;
    size_t search_date;
    size_t search_time;
    size_t search_message;
    std::string date = "%d";
    std::string time = "%t";
    std::string message = "%m";
    char discard;

    std::getline(file, line);
    std::getline(file, line);

    std::stringstream stream(line);

    for (size_t i = 0; i < 15; i++)
    {
        stream >> discard;
    }

    for (size_t i = 0; i < diary.messages.size(); i++)
    {
        std::string current_message = format;
        search_date = current_message.find(date);
        if (search_date >= 0 && search_date < 1000)
        {
            current_message.erase(search_date, 2);
            current_message.insert(search_date, diary.messages[i].date.to_string());
        }

        search_time = current_message.find(time);
        if (search_time >= 0 && search_time < 1000)
        {
            current_message.erase(search_time, 2);
            current_message.insert(search_time, diary.messages[i].time.to_string());
        }

        search_message = current_message.find(message);
        if (search_message >= 0 && search_message < 1000)
        {
            current_message.erase(search_message, 2);
            current_message.insert(search_message, diary.messages[i].content);
        }

        std::cout << current_message << std::endl;
    }
}

int App::show_usage()
{
    std::cout << "Usage: " << diary.path << " add <mensagem>" << std::endl;
    return 1;
}

void App::search()
{
    std::string message;
    std::cout << "Enter the word to be searched:" << std::endl;
    getline(std::cin, message);
    std::vector<Message *> search = diary.search(message);

    if (!search.empty())
    {
        for (size_t i = 0; i < search.size(); i++)
        {
            std::cout << "Message found in date: " << search[i]->date.to_string() << " at time: " << search[i]->time.to_string() << std::endl;
            std::cout << search[i]->content << std::endl;
        }
    }
    else
    {
        if (diary.messages.empty())
        {
            std::cout << "The diary is empty!" << std::endl;
        }
        else
        {
            std::cout << "There are no messages with this word." << std::endl;
        }
    }
}

void App::search(const std::string &what)
{
    std::vector<Message *> search = diary.search(what);

    if (!search.empty())
    {
        for (size_t i = 0; i < search.size(); i++)
        {
            std::cout << "Message found in date: " << search[i]->date.to_string() << " at time: " << search[i]->time.to_string() << std::endl;
            std::cout << search[i]->content << std::endl;
        }
    }
    else
    {
        if (diary.messages.empty())
        {
            std::cout << "The diary is empty!" << std::endl;
        }
        else
        {
            std::cout << "There are no messages with this word." << std::endl;
        }
    }
}

void App::interactive()
{
    std::string option;

    while (option != "0")
    {
        std::cout << "Diary 1.0" << std::endl;
        std::cout << "\n";
        std::cout << "-------------------" << std::endl;
        std::cout << "Select an option:" << std::endl;
        std::cout << "\n";
        std::cout << "1) List messages" << std::endl;
        std::cout << "2) Add new message" << std::endl;
        std::cout << "3) Search a message" << std::endl;
        std::cout << "\n";
        std::cout << "0) Quit" << std::endl;
        std::cout << "-------------------" << std::endl;
        std::getline(std::cin, option);

        if (option == "1")
        {
            std::cout << "-------------------" << std::endl;
            list_messages();
            std::cout << "-------------------" << std::endl;
        }
        else if (option == "2")
        {
            std::cout << "-------------------" << std::endl;
            add();
            std::cout << "-------------------" << std::endl;
        }
        else if (option == "3")
        {
            std::cout << "-------------------" << std::endl;
            search();
            std::cout << "-------------------" << std::endl;
        }
    }
}