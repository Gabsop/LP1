#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
  std::string function = "add";
  std::string mensagem;

  if (argc == 1) {
        std::cout << "Uso: " << argv[0] << " " << function << " <mensagem>\n";
        return -1;
  }
  
   if (argc == 2 && string(argv[1]) == function) {
     std::cout << "Digite uma mensagem:\n";
     std::getline(std::cin, mensagem);
   }

   if (argc > 2 && string(argv[1]) == function) {
       for (int i = 2; i < argc; i++){
            mensagem += argv[i];
            mensagem += " ";
       }
   }

   std::cout << "Mensagem adicionada!\n" << mensagem << "\n";

   return 0;
}
