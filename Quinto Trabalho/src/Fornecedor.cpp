#include "../include/Fornecedor.hpp"
#include <fstream>
#include <sstream>
using namespace std;

Fornecedor::Fornecedor()
{
    lerProdutos();
}
Fornecedor::~Fornecedor()
{
}

void Fornecedor::lerProdutos()
{
    Produto produtoAtual;
    ifstream file("fornecedor.csv");

    if (!file.is_open())
    {
        return;
    }

    string line;

    getline(file, line);

    size_t foundfirst;

    while (!file.eof())
    {
        getline(file, line);

        if (line.size() == 0)
        {
            continue;
        }

        foundfirst = line.find_last_of(",");
        string getQuantidade;
        produtoAtual.nome = line.substr(0, foundfirst);
        getQuantidade = line.substr(foundfirst + 1);
        produtoAtual.quantidade = stoi(getQuantidade);

        quantidadeElementos++;
        produtos.push(produtoAtual);
    }
}

void Fornecedor::listarProdutos()
{
    for (size_t i = 0; i < produtos.sizeVector(); i++)
    {
        cout << "[" << produtos.elementos[i].nome << ", " << produtos.elementos[i].quantidade << "]" << endl;
    }
}

void Fornecedor::repassarProdutos(Produto &p, int quantidade)
{
    for (size_t i = 0; i < produtos.sizeVector(); i++)
    {
        if (p.nome == produtos.elementos[i].nome)
        {
            if (produtos.elementos[i].quantidade < quantidade)
            {
                std::cout << "Quantidade indisponível." << std::endl;
                return;
            }
            else
            {
                produtos.elementos[i].quantidade -= quantidade;
                ofstream file("fornecedor.csv");
                file << "PRODUTO,QUANTIDADE" << std::endl;
                for (size_t i = 0; i < produtos.sizeVector(); i++)
                {
                    file << produtos.elementos[i].nome << "," << produtos.elementos[i].quantidade << std::endl;
                }
            }
        }
    }
}