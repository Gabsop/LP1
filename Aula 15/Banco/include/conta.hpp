#include "cliente.hpp"
#include "agencia.hpp"
using namespace std;

class Conta
{
public:
    Agencia agencia;
    Cliente titular;

    int numeroConta;
    double saldo;
    static int numContas;

    Conta(Cliente titular);
    Conta();
    ~Conta();

    void saca(double valor);
    void deposita(double valor);
    void transfere(double valor, Conta &c);
};