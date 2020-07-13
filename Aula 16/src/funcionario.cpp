#include "../include/funcionario.hpp"

using namespace std;

Funcionario::Funcionario(string nome, float salario, string departamento)
{
    this->nome = nome;
    this->salario = salario;
    this->departamento = departamento;
}
Funcionario::~Funcionario()
{
}
void Funcionario::setNome(string nome)
{
    this->nome = nome;
}
string Funcionario::getNome()
{
    return this->nome;
}
void Funcionario::setEmpresa(string empresa)
{
    this->empresa = empresa;
}
string Funcionario::getEmpresa()
{
    return this->empresa;
}
void Funcionario::setDepartamento(string departamento)
{
    this->departamento = departamento;
}
string Funcionario::getDepartamento()
{
    return this->departamento;
}
void Funcionario::setSalario(float salario)
{
    this->salario = salario;
}
float Funcionario::getSalario()
{
    return this->salario;
}
void Funcionario::setData(string dataAdmissao)
{
    this->dataAdmissao = dataAdmissao;
}
string Funcionario::getData()
{
    return this->dataAdmissao;
}
