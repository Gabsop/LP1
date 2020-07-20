#include <string>
using namespace std;

class Agencia
{
private:
    string nome;
    int numero;
    string cnpj;

public:
    Agencia();
    Agencia(string nome, int numero, string cnpj);
    ~Agencia();

    string getNome();
    void setNome(string nome);
    int getNumero();
    void setNumero(int numero);
    string getCnpj();
    void setCnpj(string cnpj);
};