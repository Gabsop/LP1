#include <iostream>
#include "../include/Conta.hpp"
#include "../include/ClientePJ.hpp"
#include "../include/Fila.hpp"

int main(int argc, char const *argv[])
{
    Cliente a("Gabriel", "123");
    Cliente b("Lucas", "456");
    Cliente c("Denied", "Não vai entrar");

    Clientepj d("Riachuelo", "789");
    Clientepj e("C&A", "101112");
    Clientepj f("Denied", "Não vai entrar");

    std::cout << "Fila dos Clientes:" << std::endl;
    Fila<Cliente> clientes(2);
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
