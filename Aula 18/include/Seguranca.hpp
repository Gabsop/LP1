#include "Funcionario.hpp"
using namespace std;

class Seguranca : public Funcionario
{
private:
    string arma = "pistola";

public:
    void setArma(string arma) { this->arma = arma; }
    string getArma() { return this->arma; }
};