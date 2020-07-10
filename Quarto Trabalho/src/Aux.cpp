#include "../include/Aux.hpp"

using namespace std;

void menu(Cliente a, Estabelecimento e)
{
    int opcao;

    while (opcao != 0)
    {
        std::cout << "Escolha uma opção:" << std::endl;
        std::cout << "1. Listar produtos" << std::endl;
        std::cout << "2. Comprar" << std::endl;
        std::cout << "3. Depositar" << std::endl;
        std::cout << "4. Checar Saldo" << std::endl;
        std::cout << "5. Checar Sacola" << std::endl;
        std::cout << "6. Checar Caixa" << std::endl;
        std::cout << "0. Voltar" << std::endl;
        cin >> opcao;

        if (opcao == 1)
        {
            e.listar();
        }
        else if (opcao == 2)
        {
            int escolhaCodigo;
            std::cout << "O que deseja comprar, " << a.nome << "?" << std::endl;
            std::cout << "Seu saldo é: " << a.saldo << std::endl;
            std::cout << "Digite o código do produto: " << std::endl;
            cin >> escolhaCodigo;

            for (auto i : e.produtos)
            {
                if (i.codigo == escolhaCodigo)
                {
                    a.compra(i);
                    e.venda(i);
                }
            }
        }
        else if (opcao == 3)
        {
            float deposito;
            std::cout << "Quanto deseja depositar?" << std::endl;
            cin >> deposito;
            a.saldo += deposito;
        }
        else if (opcao == 4)
        {
            std::cout << "Seu saldo é:" << std::endl;
            std::cout << a.saldo << std::endl;
        }
        else if (opcao == 5)
        {
            a.verSacola();
        }
        else if (opcao == 6)
        {
            e.caixa();
        }
    }
}

Cliente criarConta()
{
    string nomeConta;
    float Saldo;

    std::cout << "Digite o nome do(a) titular da conta:" << std::endl;
    cin >> nomeConta;
    std::cout << "Digite o saldo da conta:" << std::endl;
    cin >> Saldo;
    Cliente a(Saldo, nomeConta);
    return a;
}