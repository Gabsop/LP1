#include <iostream>
#include "../include/Conta.hpp"
#include "../include/Fila.hpp"

int main(int argc, char const *argv[])
{
    Clientepf a("Gabriel", "123");
    Clientepf b("Lucas", "456");
    Clientepf c("Denied", "Não vai entrar");

    Clientepj d("Riachuelo", "789");
    Clientepj e("C&A", "101112");
    Clientepj f("Denied", "Não vai entrar");

    std::cout << "Fila dos Clientes:" << std::endl;
    Fila<Clientepf> clientes(2);
    clientes.push(a);
    clientes.push(b);
    clientes.push(c);
    clientes.list();

    std::cout << "Fila dos Clientes Juridicos:" << std::endl;
    Fila<Clientepj> clientespj(2);
    clientespj.push(d);
    clientespj.push(e);
    clientespj.push(f);
    clientespj.list();

    return 0;
}
