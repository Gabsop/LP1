#include "ClientePF.hpp"
#include "Agencia.hpp"
using namespace std;

class Conta
{
public:
    Agencia agencia;
    Clientepf titular;

    int numeroConta;
    double saldo;
    static int numContas;

    Conta(Clientepf titular);
    Conta();
    ~Conta();

    void saca(double valor);
    void deposita(double valor);
    void transfere(double valor, Conta &c);
};