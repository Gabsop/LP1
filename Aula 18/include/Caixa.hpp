#include "Funcionario.hpp"
using namespace std;

class Caixa : public Funcionario
{
private:
    string senhaCaixa = "123456789";

public:
    void setSenha(string senha) { senhaCaixa = senha; }
    string getSenha() { return senhaCaixa; }
};