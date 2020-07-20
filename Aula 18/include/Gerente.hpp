#include <string>
#include "Funcionario.hpp"
using namespace std;

class Gerente : public Funcionario
{
private:
    bool ChavedaLoja = true;

public:
    bool temChave() { return ChavedaLoja; }
};