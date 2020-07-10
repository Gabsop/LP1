#include "../include/Cliente.hpp"
#include <fstream>

using namespace std;

vector<Produto> Cliente::sacola;

Cliente::Cliente()
{
}

Cliente::Cliente(float saldo, string nome)
{
    this->saldo = saldo;
    this->nome = nome;
}

Cliente::~Cliente()
{
}

void Cliente::compra(Produto produto)
{
    if (produto.preco > saldo)
    {
        std::cout << "Saldo insuficiente." << std::endl;
    }
    else
    {
        saldo -= produto.preco;
        sacola.push_back(produto);
    }
}

void Cliente::verSacola()
{
    std::cout << "Produtos na sacola:" << std::endl;
    if (this->sacola.empty())
    {
        std::cout << "Sacola vazia!" << std::endl;
    }
    else
    {
        for (auto i : this->sacola)
        {
            std::cout << i.nome << std::endl;
        }
    }
}

void Cliente::registro()
{
    string clienteFile = "cliente_x";
    size_t firstfound;
    firstfound = clienteFile.find_first_of("x");
    clienteFile.replace(firstfound, 4, nome);
    clienteFile.append(".txt");
    ofstream file(clienteFile);

    float total;
    file << "Nome do Titular: " << nome << std::endl;
    for (auto i : sacola)
    {
        file << "Nome do produto: " << i.nome << "| Preço do produto: " << i.preco << std::endl;
        total += i.preco;
    }
    file << "Valor total gasto: " << total << std::endl;
    sacola.clear();
}