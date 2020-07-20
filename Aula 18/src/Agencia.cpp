#include "../include/Agencia.hpp"

using namespace std;

Agencia::Agencia()
{
}
Agencia::Agencia(string nome, int numero, string cnpj)
{
    this->nome = nome;
    this->numero = numero;
    this->cnpj = cnpj;
}
Agencia::~Agencia()
{
}
string Agencia::getNome() { return this->nome; }
void Agencia::setNome(string nome) { this->nome = nome; }
int Agencia::getNumero() { return this->numero; }
void Agencia::setNumero(int numero) { this->numero = numero; }
string Agencia::getCnpj() { return this->cnpj; }
void Agencia::setCnpj(string cnpj) { this->cnpj = cnpj; }