#include "../include/ClientePJ.hpp"

using namespace std;

Clientepj::Clientepj()
{
}
Clientepj::Clientepj(string cnpj, string razaoSocial)
{
    this->cnpj = cnpj;
    this->razaoSocial = razaoSocial;
}
Clientepj::~Clientepj()
{
}
string Clientepj::getCnpj() { return this->cnpj; }
void Clientepj::setCnpj(string cnpj) { this->cnpj = cnpj; }
string Clientepj::getRazaoSocial() { return this->razaoSocial; }
void Clientepj::setRazaoSocial(string razaoSocial) { this->razaoSocial = razaoSocial; }

void Clientepj::display()
{
    std::cout << "Razão Social: " << razaoSocial << std::endl;
    std::cout << "CNPJ:" << cnpj << std::endl;
}