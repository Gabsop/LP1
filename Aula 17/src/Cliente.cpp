#include "../include/Cliente.hpp"

using namespace std;

Cliente::Cliente()
{
}

Cliente::Cliente(string nome, string cpf)
{
    this->nome = nome;
    this->cpf = cpf;
}

Cliente::~Cliente()
{
}

string Cliente::getNome() { return this->nome; }
void Cliente::setNome(string nome) { this->nome = nome; }
string Cliente::getCpf() { return this->cpf; }
void Cliente::setCpf(string cpf) { this->cpf = cpf; }

void Cliente::display()
{
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "CPF:" << cpf << std::endl;
}