#ifndef DIARY_H
#define DIARY_H

#include "Message.h"
#include <vector>

#include <string>

struct Diary
{
    Diary();

    std::string filename;
    std::vector<Message> messages;
    std::string path;

    void define_path();
    void add(const std::string &message);                   // Adicionar mais de uma mensagem por vez utilizando o write()
    void write();                                           // Escreve as mensagens no arquivo
    void load_messages();                                   // Carrega as mensagens já existentes e coloca no array
    std::vector<Message *> search(const std::string &what); // Procura mensagens no diário.
};
#endif
