#include "../include/App.h"
#include <string>
#include <iostream>

App::App(const std::string &filename) : diary(filename)
{
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
        list_messages();
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
    else
    {
        return show_usage();
    }

    return 0;
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
    for (size_t i = 0; i < diary.messages.size(); i++)
    {
        std::cout << i + 1 << ". - " << diary.messages[i].content << std::endl;
    }
}

int App::show_usage()
{
    std::cout << "Usage: " << diary.filename << " add <mensagem>" << std::endl;
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