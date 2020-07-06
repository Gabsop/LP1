#include <string>
using namespace std;

class Conta
{
public:
    string numeroConta;
    string titular;
    double saldo;

    void saca(double valor);
    void deposita(double valor);
    void transfere(double valor, Conta &c);
};