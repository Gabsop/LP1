#include "../include/Cliente.hpp"
#include <fstream>

using namespace std;

Vector_supermercado<Produto> Cliente::sacola;

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
        sacola.push(produto);
    }
}

void Cliente::verSacola()
{
    std::cout << "Produtos na sacola:" << std::endl;
    if (this->sacola.isEmpty())
    {
        std::cout << "Sacola vazia!" << std::endl;
    }
    else
    {
        for (size_t i = 0; i < sacola.sizeVector(); i++)
        {
            std::cout << sacola.elementos[i].nome << std::endl;
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
    for (size_t i = 0; i < sacola.sizeVector(); i++)
    {
        file << "Nome do produto: " << sacola.elementos[i].nome << "| Preço do produto: " << sacola.elementos[i].preco << std::endl;
        total += sacola.elementos[i].preco;
    }
    file << "Valor total gasto: " << total << std::endl;
    sacola.clear();
}