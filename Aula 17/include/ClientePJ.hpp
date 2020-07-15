#include <string>
#include <iostream>
using namespace std;

class Clientepj
{
private:
    string cnpj;
    string razaoSocial;

public:
    Clientepj();
    Clientepj(string cnpj, string razaoSocial);
    ~Clientepj();

    string getCnpj();
    void setCnpj(string cnpj);
    string getRazaoSocial();
    void setRazaoSocial(string razaoSocial);

    void display();
};