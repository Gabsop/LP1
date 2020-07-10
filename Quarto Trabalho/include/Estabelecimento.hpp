#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "../include/Cliente.hpp"

using namespace std;

class Estabelecimento
{
public:
    Estabelecimento();
    ~Estabelecimento();

    static vector<Produto> produtos;
    static list<Produto> produtosVendidos;

    void listar();
    void venda(Produto produto);
    void caixa();
    void carregarProdutos();
    void registro();
};