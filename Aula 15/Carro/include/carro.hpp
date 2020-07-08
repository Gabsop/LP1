#include <string>

using namespace std;

class Carro
{
public:
    Carro(string cor, int numPortas);
    ~Carro();

    static int numCarros;

    string cor;
    int numPortas;
    double velocidade;

    void acelera(double velocidade);
    void freia(double velocidade);
};