#include <string>

using namespace std;

class Funcionario
{
private:
    string nome;
    string empresa;
    string departamento;
    float salario;
    string dataAdmissao;

public:
    Funcionario(string nome, float salario, string departamento);
    ~Funcionario();
    void setNome(string nome);
    string getNome();
    void setEmpresa(string empresa);
    string getEmpresa();
    void setDepartamento(string departamento);
    string getDepartamento();
    void setSalario(float salario);
    float getSalario();
    void setData(string dataAdmissao);
    string getData();
};