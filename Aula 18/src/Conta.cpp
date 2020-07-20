#include "../include/Conta.hpp"

int Conta::numContas;

Conta::Conta(Clientepf titular)
{
    this->titular = titular;
    this->numContas += 1;
}

Conta::Conta()
{
    this->numContas += 1;
}

Conta::~Conta()
{
}

void Conta::saca(double valor)
{
    saldo -= valor;
}

void Conta::deposita(double valor)
{
    saldo += valor;
}

void Conta::transfere(double valor, Conta &c)
{
    saldo -= valor;
    c.saldo += valor;
}