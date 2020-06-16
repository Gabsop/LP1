#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
  std::string const function = "add";

  if (argc == 1 || function.compare(argv[1]) != 0) {
    std::cout << "Uso: " << argv[0] << " " << function << " <mensagem>\n";
    return -1;
  }

   std::string mensagem;

   if (argc == 2) {
     std::cout << "Digite uma mensagem:\n";
     std::getline(std::cin, mensagem);
   }

   if (argc > 2) {
       for (int i = 2; i < argc; i++){
            mensagem += argv[i];
            mensagem += " ";
       }
   }

   std::cout << "Mensagem adicionada!\n" << mensagem << "\n";

   return 0;
}
