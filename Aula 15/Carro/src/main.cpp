#include <iostream>
#include "../include/carro.hpp"

int main(int argc, char const *argv[])
{
    Carro c("Vermelho", 4);
    c.velocidade = 100;

    std::cout << c.velocidade << std::endl;

    c.acelera(200);

    std::cout << c.velocidade << std::endl;

    c.freia(100);

    std::cout << c.velocidade << std::endl;

    Carro a("Azul", 2);

    std::cout << c.numCarros << std::endl;

    return 0;
}
