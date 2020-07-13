#include "../include/empresa.hpp"

using namespace std;

vector<Funcionario> Empresa::listaFuncionarios;

Empresa::Empresa(string nome, string cnpj)
{
    setNome(nome);
    setCnpj(cnpj);
}
Empresa::~Empresa()
{
}
void Empresa::setNome(string nome)
{
    this->nome = nome;
}
string Empresa::getNome()
{
    return this->nome;
}
void Empresa::setCnpj(string cnpj)
{
    this->cnpj = cnpj;
}
string Empresa::getCnpj()
{
    return this->cnpj;
}