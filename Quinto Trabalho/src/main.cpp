#include "../include/Aux.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    vector<Cliente> clientes;
    Estabelecimento e;
    Fornecedor f;
    std::cout << "Bem vindo(a) ao Supermercado!" << std::endl;
    std::cout << "Para começar, crie uma conta: " << std::endl;
    Cliente c = criarConta();
    clientes.push_back(c);
    menu(c, e, f);
    c.registro();
    int opcao;

    while (opcao != 0)
    {
        std::cout << "Deseja realmente sair ou criar outra conta?" << std::endl;
        std::cout << "1. Criar nova conta" << std::endl;
        std::cout << "2. Listar contas" << std::endl;
        std::cout << "0. Sair" << std::endl;
        cin >> opcao;

        if (opcao == 1)
        {
            Cliente d = criarConta();
            clientes.push_back(d);
            menu(d, e, f);
            d.registro();
        }
        else if (opcao == 2)
        {
            for (auto i : clientes)
            {
                std::cout << "Nome do titular: " << i.nome << std::endl;
                std::cout << "Saldo da conta: " << i.saldo << std::endl;
                std::cout << "\n";
            }
        }
    }

    e.registro();

    return 0;
}
