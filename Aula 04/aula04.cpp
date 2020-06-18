#include <iostream>
#include <string>
#include <fstream>

void show_usage(const std::string &prog_name);
void list();

int main(int argc, char const *argv[]){

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

    std::string message;

    if (argc == 2){
        std::cout << "Informe a mensagem: " << std::endl;
        std::getline(std::cin, message);
    }   else {
        message = argv[2];
    }

    std::ofstream file("messages.txt", std::ios::app);

    if(!file.is_open()){
        std::cerr << "O arquivo não pode ser criado." << std::endl;
        return 1;
    }

    file << message << "\n";
    
    std::cout << "Mensagem Adicionada!" << std::endl;

    return 0;
}

void show_usage(const std::string &prog_name) {
    std::cout << "Uso: " << prog_name << " add <mensagem>" << std::endl;
}

void list(){
    std::ifstream file("messages.txt");

    if(!file.is_open()){
        std::cerr << "Arquivo inexistente ou sem permissão de leitura" << std::endl;
    }

    std::string message;
    int line_number = 0;

    while (!file.eof()) {
        line_number++;    
        std::getline(file, message);

        if (message.size() == 0){
            continue;
        }

        std::cout << line_number << ". " << message << std::endl;
    }    

    file.close();
}