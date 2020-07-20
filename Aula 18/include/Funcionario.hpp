#include <string>
using namespace std;

class Funcionario
{
protected:
    string nome;
    float salario;

public:
    void setNome(string nome) { this->nome = nome; }
    string getNome() { return this->nome; }

    void setSalario(float salario) { this->salario = salario; }
    float getSalario() { return this->salario; }
};