#include <iostream>
#include <string>
#include <fstream>

#include "../include/time.h"
#include "../include/diary.h"

int main(int argc, char const *argv[]){

    std::string message;

    if (argc == 1) {
        show_usage(argv[0]);
        return 1;
    }
    
    std::string action = argv[1];

    if (action != "add" && action != "list"){
        show_usage(argv[0]);
        return 1;
    }

    if (action == "list") {
        list();
        return 1;
    }

    if (argc == 2){
        std::cout << "Informe a mensagem: " << std::endl;
        std::getline(std::cin, message);
    }   else {
        message = argv[2];
    }

    std::ofstream file("messages.md", std::ios::app);

    if(!file.is_open()){
        std::cerr << "O arquivo não pode ser criado." << std::endl;
        return 1;
    }

    bool check = checkData();

    if (check == false){
        file << "\n"; 
        file << "# " << get_current_date() << std::endl;
        file << "\n";
        file << "- " << get_current_time() << " " << message << "\n";
    
    } else if (check == true){
        file << "- " << get_current_time() << " " << message << "\n";
    }

    std::cout << "Mensagem Adicionada!" << std::endl;

    return 0;
}