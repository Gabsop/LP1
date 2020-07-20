#include <string>
#include <vector>
#include <iostream>
#include "../include/Fornecedor.hpp"

using namespace std;

class Cliente
{
public:
    Cliente();
    Cliente(float saldo, string nome);
    ~Cliente();

    double saldo;
    string nome;
    static Vector_supermercado<Produto> sacola;

    void compra(Produto produto);
    void verSacola();
    void registro();
};