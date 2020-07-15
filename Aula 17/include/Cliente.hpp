#include <string>
#include <iostream>
using namespace std;

class Cliente
{
private:
    string nome;
    string cpf;

public:
    Cliente();
    Cliente(string nome, string cpf);
    ~Cliente();

    string getNome();
    void setNome(string nome);
    string getCpf();
    void setCpf(string cpf);

    void display();
};