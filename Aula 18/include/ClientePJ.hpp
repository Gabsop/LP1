#include <string>
#include <iostream>
#include "../include/Cliente.hpp"
using namespace std;

class Clientepj : Cliente
{
public:
    Clientepj();
    Clientepj(string cnpj, string razaoSocial);
    ~Clientepj();

    string getCnpj();
    void setCnpj(string cnpj);
    string getRazaoSocial();
    void setRazaoSocial(string razaoSocial);

    void display();
};