#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

void show_usage(const std::string &prog_name);
void list();
bool checkData();
std::string get_current_date();
std::string get_current_time();
std::string format_current_date(const std::string& format);

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

void show_usage(const std::string &prog_name) {
    std::cout << "Uso: " << prog_name << " add <mensagem>" << std::endl;
}

void list(){
    std::ifstream file("messages.md");

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
        char compare = message.at(0);
        if (compare == '-'){
            std::cout << line_number << ". " << message << std::endl;;
        }
    }    

    file.close();
}

bool checkData(){
    std::ifstream file("messages.md");
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

std::string get_current_date(){return format_current_date("%d/%m/%Y");}
std::string get_current_time(){return format_current_date("%H:%M:%S");}

std::string format_current_date(const std::string& format){
std::time_t time = std::time(nullptr);
char result[1024];
std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));
return std::string(result);
}
