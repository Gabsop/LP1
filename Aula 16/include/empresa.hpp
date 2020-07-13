#include <string>
#include <vector>
#include "../include/funcionario.hpp"

using namespace std;

class Empresa
{
private:
    string nome;
    string cnpj;

public:
    static vector<Funcionario> listaFuncionarios;
    Empresa(string nome, string cnpj);
    ~Empresa();
    void setNome(string nome);
    string getNome();
    void setCnpj(string cnpj);
    string getCnpj();
};