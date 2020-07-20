#include "../include/Vector_supermercado.hpp"
#include "../include/Produto.hpp"

using namespace std;

class Fornecedor
{
private:
    Vector_supermercado<Produto> produtos;
    int quantidadeElementos;

public:
    Fornecedor();
    ~Fornecedor();

    void lerProdutos();
    void listarProdutos();
    void repassarProdutos(Produto &p, int quantidade);
};