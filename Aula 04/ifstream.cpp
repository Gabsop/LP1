#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char const *argv[]) {
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

    return 0;
}
