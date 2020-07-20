#include <string>
#include <iostream>
#include "ClientePJ.hpp"
using namespace std;

class Clientepf : public Cliente
{
public:
    Clientepf();
    Clientepf(string nome, string cpf);
    ~Clientepf();

    string getNome();
    void setNome(string nome);
    string getCpf();
    void setCpf(string cpf);

    void display();
};