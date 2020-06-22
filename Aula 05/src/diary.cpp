#include <string>
#include <fstream>
#include <iostream>

#include "../include/diary.h"
#include "../include/time.h"

void show_usage(const std::string &prog_name) {
    std::cout << "Uso: " << prog_name << " add <mensagem>" << std::endl;
}

void list(){
    std::ifstream file("../messages.md");

    if(!file.is_open()){
        std::cerr << "Arquivo inexistente ou sem permissão de leitura" << std::endl;
    }

    std::string message;
    int message_number = 1;

    while (!file.eof()) {   
        std::getline(file, message);

        if (message.size() == 0){
            continue;
        }
        char compare = message.at(0);
        if (compare == '-'){
            std::cout << message_number << ". " << message << std::endl;;
            message_number++;
        }
    }    

    file.close();
}

bool checkData(){
    std::ifstream file("../messages.md");
    std::string date = "# " + get_current_date();
    std::string message;
    if(!file.is_open()){
        std::cerr << "Arquivo inexistente ou sem permissão de leitura" << std::endl;
    }
    while (!file.eof()){
        std::getline(file, message);
        if(date == message){
            return true;
        }
    }
    return false;
}