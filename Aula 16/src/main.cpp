#include "../include/empresa.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string nome, cnpj, nomeFuncionario, departamento;
    float salario;
    int quantidade;
    std::cout << "Digite o nome da empresa: " << std::endl;
    cin >> nome;
    std::cout << "Digite o CNPJ da empresa: " << std::endl;
    cin >> cnpj;
    Empresa e(nome, cnpj);

    std::cout << "Quantos funcionários você deseja na empresa " << e.getNome() << "?" << std::endl;
    cin >> quantidade;

    for (size_t i = 0; i < quantidade; i++)
    {
        std::cout << "Digite o nome do funcionario:" << std::endl;
        cin >> nomeFuncionario;
        std::cout << "Digite o salario do funcionario:" << std::endl;
        cin >> salario;
        std::cout << "Digite o departamento do funcionario:" << std::endl;
        cin >> departamento;
        Funcionario f(nomeFuncionario, salario, departamento);
        e.listaFuncionarios.push_back(f);
    }
    std::cout << "Funcionários da empresa " << e.getNome() << ":" << std::endl;
    for (auto i : e.listaFuncionarios)
    {
        std::cout << "[ Nome: " << i.getNome() << std::endl;
        std::cout << "Salario: " << i.getSalario() << std::endl;
        std::cout << "Departamento: " << i.getDepartamento() << " ]" << std::endl;
    }

    std::cout << "Você deseja dar o aumento de 10% em qual departamento?" << std::endl;
    cin >> departamento;

    for (size_t i = 0; i != e.listaFuncionarios.size(); i++)
    {
        if (departamento == e.listaFuncionarios.at(i).getDepartamento())
        {
            salario = e.listaFuncionarios.at(i).getSalario();
            salario += salario * 0.10;
            e.listaFuncionarios.at(i).setSalario(salario);
        }
    }

    std::cout << "Salarios depois do aumento: " << std::endl;

    std::cout << "Funcionários da empresa " << e.getNome() << ":" << std::endl;
    for (auto i : e.listaFuncionarios)
    {
        std::cout << "[ Nome: " << i.getNome() << std::endl;
        std::cout << "Salario: " << i.getSalario() << std::endl;
        std::cout << "Departamento: " << i.getDepartamento() << " ]" << std::endl;
    }

    return 0;
}
