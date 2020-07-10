#include <string>
#include <vector>
#include <iostream>
#include "../include/Produto.hpp"

using namespace std;

class Cliente
{
public:
    Cliente();
    Cliente(float saldo, string nome);
    ~Cliente();

    double saldo;
    string nome;
    static vector<Produto> sacola;

    void compra(Produto produto);
    void verSacola();
    void registro();
};