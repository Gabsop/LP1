#ifndef DIARY_H
#define DIARY_H

#include "Message.h"

#include <string>

struct Diary
{
    Diary(const std::string& filename);
    ~Diary();

    std::string filename;
    Message* messages;
    size_t messages_size; // Quantas messages realmente tem
    size_t messages_capacity; // Máximo que o array suporta

    void add(const std::string& message); // Adicionar mais de uma mensagem por vez utilizando o write()
    void write(); // Escreve as mensagens no arquivo
};
#endif
