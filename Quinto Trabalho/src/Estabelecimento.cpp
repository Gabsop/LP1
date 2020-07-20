#include "../include/Estabelecimento.hpp"
using namespace std;

Vector_supermercado<Produto> Estabelecimento::produtosVendidos;
Vector_supermercado<Produto> Estabelecimento::produtos;

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
    for (size_t i = 0; i < produtos.sizeVector(); i++)
    {
        std::cout << "[" << produtos.elementos[i].codigo << ", " << produtos.elementos[i].nome << ", " << produtos.elementos[i].unidadeMedida << ", " << produtos.elementos[i].preco << ", " << produtos.elementos[i].quantidade << "]" << std::endl;
    }
}

void Estabelecimento::venda(Produto produto)
{

    for (size_t i = 0; i < produtos.sizeVector(); i++)
    {
        if (produto.codigo == produtos.elementos[i].codigo)
        {
            if (produtos.elementos[i].quantidade > 0)
            {
                produtosVendidos.push(produtos.elementos[i]);
                produtos.elementos[i].quantidade--;
                std::cout << "Venda efetuada!" << std::endl;
                return;
            }
            else
            {
                std::cout << "Produto fora de estoque." << std::endl;
            }
        }
    }

    for (size_t i = 0; i < produtos.sizeVector(); i++)
    {
        produtos.elementos[i];
    }

    std::cout << "Produto não encontrado." << std::endl;
}

void Estabelecimento::caixa()
{
    float total;

    if (produtosVendidos.isEmpty())
    {
        std::cout << "Não foi vendido nenhum produto ainda!" << std::endl;
    }
    else
    {

        std::cout << "Produtos vendidos: " << std::endl;
        for (size_t i = 0; i < produtosVendidos.sizeVector(); i++)
        {
            std::cout << produtosVendidos.elementos[i].nome << std::endl;
            total += produtosVendidos.elementos[i].preco;
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
    for (size_t i = 0; i < produtosVendidos.sizeVector(); i++)
    {
        file << produtosVendidos.elementos[i].codigo << "," << produtosVendidos.elementos[i].nome << "," << produtosVendidos.elementos[i].unidadeMedida << ",\"R$ " << produtosVendidos.elementos[i].preco << "\"" << std::endl;
        total += produtosVendidos.elementos[i].preco;
    }
    file << "Valor total arrecadado: " << total << std::endl;
}

void Estabelecimento::reabastecer(Produto &p, int quantidade)
{
    for (size_t i = 0; i < produtos.sizeVector(); i++)
    {
        if (p.nome == produtos.elementos[i].nome)
        {
            produtos.elementos[i].quantidade += quantidade;
        }
    }
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
        produtos.push(produtoAtual);
    }
}