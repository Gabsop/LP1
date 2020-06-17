#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char const *argv[]) {
    std::string function = "add";
    std::string mensagem;
    std::ofstream output("diary.txt", std::ios::app);

    if (argc == 1) {
        std::cout << "Uso: " << argv[0] << " " << function << " <mensagem>\n";
        return -1;
    }
  
    if (argc == 2 && std::string(argv[1]) == function) {
        std::cout << "Digite uma mensagem:\n";
        std::getline(std::cin, mensagem);
        std::cout << "Mensagem adicionada!" << std::endl;
    }

    if (argc > 2 && std::string(argv[1]) == function) {
        mensagem = argv[2];
        std::cout << "Mensagem adicionada!" << std::endl;
    }

    output << mensagem << std::endl;
    output.close();
    
    return 0;
}




   