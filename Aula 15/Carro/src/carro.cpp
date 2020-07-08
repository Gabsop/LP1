#include "../include/carro.hpp"

int Carro::numCarros;

Carro::Carro(string cor, int numPortas)
{
    this->cor = cor;
    this->numPortas = numPortas;
    this->numCarros += 1;
}

Carro::~Carro()
{
}

void Carro::acelera(double velocidade)
{
    this->velocidade += velocidade;
}

void Carro::freia(double velocidade)
{
    this->velocidade -= velocidade;
}
