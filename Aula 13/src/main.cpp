#include <iostream>
#include "../include/conta.cpp"

int main(int argc, char const *argv[])
{
    Conta a;
    Conta b;

    a.numeroConta = "123";
    a.titular = "Gabriel";
    a.saldo = 300;

    b.numeroConta = "456";
    b.titular = "João";
    b.saldo = 200;

    std::cout << a.saldo << std::endl;

    a.saca(50);

    std::cout << a.saldo << std::endl;

    a.deposita(60);

    std::cout << a.saldo << std::endl;

    a.transfere(60, b);

    std::cout << a.saldo << std::endl;
    std::cout << b.saldo << std::endl;

    return 0;
}
