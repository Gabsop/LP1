#include "../include/ClientePF.hpp"

using namespace std;

Clientepf::Clientepf()
{
}

Clientepf::Clientepf(string nome, string cpf)
{
    this->nome = nome;
    this->cpf = cpf;
}

Clientepf::~Clientepf()
{
}

string Clientepf::getNome() { return this->nome; }
void Clientepf::setNome(string nome) { this->nome = nome; }
string Clientepf::getCpf() { return this->cpf; }
void Clientepf::setCpf(string cpf) { this->cpf = cpf; }

void Clientepf::display()
{
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "CPF:" << cpf << std::endl;
}