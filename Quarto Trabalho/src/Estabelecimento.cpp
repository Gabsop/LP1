#include "../include/Estabelecimento.hpp"
using namespace std;

list<Produto> Estabelecimento::produtosVendidos;
vector<Produto> Estabelecimento::produtos;

Estabelecimento::Estabelecimento()
{
    carregarProdutos();
}
Estabelecimento::~Estabelecimento()
{
}

void Estabelecimento::listar()
{
    std::cout << "Código / Nome / Medida / Preço / Quantidade" << std::endl;
    for (auto i : produtos)
    {
        std::cout << "[" << i.codigo << ", " << i.nome << ", " << i.unidadeMedida << ", " << i.preco << ", " << i.quantidade << "]" << std::endl;
    }
}

void Estabelecimento::venda(Produto produto)
{

    for (size_t i = 0; i < produtos.size(); i++)
    {
        if (produto.codigo == produtos.at(i).codigo)
        {
            if (produtos.at(i).quantidade > 0)
            {
                produtosVendidos.push_back(produtos.at(i));
                produtos.at(i).quantidade--;
                std::cout << "Venda efetuada!" << std::endl;
                return;
            }
            else
            {
                std::cout << "Produto fora de estoque." << std::endl;
            }
        }
    }

    for (size_t i = 0; i < produtos.size(); i++)
    {
        produtos.at(i);
    }

    std::cout << "Produto não encontrado." << std::endl;
}

void Estabelecimento::caixa()
{
    float total;

    if (produtosVendidos.empty())
    {
        std::cout << "Não foi vendido nenhum produto ainda!" << std::endl;
    }
    else
    {

        std::cout << "Produtos vendidos: " << std::endl;
        for (auto i : produtosVendidos)
        {
            std::cout << i.nome << std::endl;
            total += i.preco;
        }
        std::cout << "Valor arrecadado: " << std::endl;
        std::cout << total << std::endl;
    }
}

void Estabelecimento::registro()
{
    ofstream file("caixa.csv");
    float total;

    file << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO" << std::endl;
    for (auto i : produtosVendidos)
    {
        file << i.codigo << "," << i.nome << "," << i.unidadeMedida << ",\"R$ " << i.preco << "\"" << std::endl;
        total += i.preco;
    }
    file << "Valor total arrecadado: " << total << std::endl;
}

void Estabelecimento::carregarProdutos()
{
    Produto produtoAtual;
    ifstream file("estoque.csv");

    if (!file.is_open())
    {
        return;
    }

    string line;

    getline(file, line);

    size_t foundfirst;
    size_t foundlast;
    size_t foundAspas;

    while (!file.eof())
    {
        getline(file, line);
        string discard;
        char cdiscard;

        if (line.size() == 0)
        {
            continue;
        }

        foundlast = line.find_last_of(",");
        line.replace(foundlast, 1, " ");

        for (size_t i = 0; i < 2; i++)
        {
            foundAspas = line.find_first_of("\"");
            line.replace(foundAspas, 1, " ");
        }

        stringstream stream(line);
        stream >> produtoAtual.codigo;
        stream >> cdiscard;

        string getNome;
        getline(stream, getNome);
        foundfirst = getNome.find_first_of(",");
        getNome.erase(foundfirst, 50);
        produtoAtual.nome = getNome;

        foundfirst = line.find_first_of(",");
        line.erase(foundfirst, 1);

        foundfirst = line.find_first_of(",");
        line.erase(0, foundfirst + 1);

        foundfirst = line.find_first_of(",");
        line.replace(foundfirst, 1, " ");

        stringstream stream2(line);

        stream2 >> produtoAtual.unidadeMedida;
        stream2 >> cdiscard;
        stream2 >> discard;
        string getPreco;
        stream2 >> getPreco;
        foundfirst = getPreco.find_first_of(",");
        getPreco.replace(foundfirst, 1, ".");
        produtoAtual.preco = stod(getPreco);
        stream2 >> produtoAtual.quantidade;
        produtos.push_back(produtoAtual);
    }
}