#include <iostream>
#include "../include/conta.hpp"

int main(int argc, char const *argv[])
{
    Conta a;
    Conta b;

    a.saldo = 300;
    b.saldo = 400;

    std::cout << a.saldo << std::endl;

    a.saca(50);

    std::cout << a.saldo << std::endl;

    a.deposita(60);

    std::cout << a.saldo << std::endl;

    a.transfere(60, b);

    std::cout << a.saldo << std::endl;
    std::cout << b.saldo << std::endl;
    std::cout << a.numContas << std::endl;

    return 0;
}
