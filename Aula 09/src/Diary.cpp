#include <fstream>
#include <iostream>
#include <sstream>
#include "../include/Diary.h"
#include "../include/Date.h"
#include "../include/Time.h"
#include "../include/Aux.h"


Diary::Diary(const std::string& filename): filename(filename),
messages(nullptr), messages_size(0), messages_capacity(10)
{
    messages = new Message[messages_capacity];
    load_messages();
}

Diary::~Diary()
{
    delete[] messages;
}

void Diary::add(const std::string& message)
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

    messages[messages_size] = current_message;
    std::cout << "Mensagem Adicionada!" << std::endl;
}

void Diary::write()
{
    // Gravar as mensagens no disco
    std::ofstream file("messages.md", std::ios::app);

    if(!file.is_open()){
        std::cerr << "O arquivo não pode ser criado." << std::endl;
        return;
    }

    bool check = checkData();
    
    if (check == false){
        file << "\n"; 
        file << "# " << messages[messages_size].date.to_string() << std::endl;
        file << "\n";
        file << "- " << messages[messages_size].time.to_string() << " " << messages[messages_size].content << "\n";
    
    } else if (check == true){
        file << "- " << get_current_time() << " " << messages[messages_size].content << "\n";
    }
    messages_size++;
}

void Diary::load_messages() {

    std::string message;
    std::ifstream file("messages.md");
    
    if(!file.is_open()){
        return;
    }
    
    while (!file.eof()) {   
        std::getline(file, message);

        if (message.size() == 0){
            continue;
        }
        char compare = message.at(0);

        if (compare == '-'){
            
            std::stringstream stream(message);
            std::string content;
            std::string time;

            char discard;
            stream >> discard;
            stream >> time;
            messages[messages_size].time.set_from_string(time);
            std::getline(stream, content);
            messages[messages_size].content = content;
            messages_size++; // aqui

            if(messages_size >= messages_capacity) {
                messages_capacity *= 2;

                Message* messages_aux = new Message[messages_capacity];

                for (size_t i = 0; i < messages_capacity/2; i++)
                {
                    messages_aux[i] = messages[i];
                }

                delete[] messages;        
                messages = messages_aux;

            }
        }
    }
}