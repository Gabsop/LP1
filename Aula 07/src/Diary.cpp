#include "../include/Diary.h"

#include <iostream>

Diary::Diary(const std::string& filename): filename(filename),
messages_capacity(10), messages_size(0), messages(nullptr)
{
    messages = new Message[messages_capacity];
}

void Diary::add(const std::string& message)
{
    Message current_message;
    current_message.content = message;
    messages[messages_size] = current_message;
    
    std::cout << "Mensagem Adicionada!" << std::endl;
    messages_size++;
    
}

void Diary::write()
{
    // Gravar as mensagens no disco
}