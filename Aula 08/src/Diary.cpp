#include "../include/Diary.h"
#include "../include/Date.h"
#include "../include/Time.h"
#include "../include/Aux.h"

#include <iostream>

Diary::Diary(const std::string& filename): filename(filename),
messages(nullptr), messages_size(0),messages_capacity(10)
{
    messages = new Message[messages_capacity];
}

Diary::~Diary()
{
    delete[] messages;
}

void Diary::add(const std::string& message)
{
    if(messages_size >= messages_capacity) {
        return;
    }

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

    messages[messages_size] = current_message;
    std::cout << "Mensagem Adicionada!" << std::endl;

    // Cout para testes
    std::cout << current_message.date.day << "/" << current_message.date.month << "/" << current_message.date.year << std::endl;
    std::cout << current_message.time.hours << " : " << current_message.time.minutes << " : " << current_message.time.seconds << std::endl;
    
    messages_size++;
}

void Diary::write()
{
    // Gravar as mensagens no disco
}