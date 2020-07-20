#include "../include/Aux.hpp"

using namespace std;

void menu(Cliente a, Estabelecimento e, Fornecedor f)
{
    int opcao = 9;
    while (opcao != 0)
    {
        std::cout << "Escolha uma opção:" << std::endl;
        std::cout << "1. Listar produtos" << std::endl;
        std::cout << "2. Comprar" << std::endl;
        std::cout << "3. Depositar" << std::endl;
        std::cout << "4. Checar Saldo" << std::endl;
        std::cout << "5. Checar Sacola" << std::endl;
        std::cout << "6. Checar Caixa" << std::endl;
        std::cout << "7. Listar Fornecedor" << std::endl;
        std::cout << "8. Reabastecer" << std::endl;
        std::cout << "0. Voltar" << std::endl;
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            e.listar();
            break;

        case 2:
            int escolhaCodigo;
            std::cout << "O que deseja comprar, " << a.nome << "?" << std::endl;
            std::cout << "Seu saldo é: " << a.saldo << std::endl;
            std::cout << "Digite o código do produto: " << std::endl;
            cin >> escolhaCodigo;

            for (size_t i = 0; i < e.produtos.sizeVector(); i++)
            {
                if (e.produtos.elementos[i].codigo == escolhaCodigo)
                {
                    a.compra(e.produtos.elementos[i]);
                    e.venda(e.produtos.elementos[i]);
                }
            }
            break;

        case 3:
            float deposito;
            std::cout << "Quanto deseja depositar?" << std::endl;
            cin >> deposito;
            a.saldo += deposito;
            break;

        case 4:
            std::cout << "Seu saldo é:" << std::endl;
            std::cout << a.saldo << std::endl;
            break;

        case 5:
            a.verSacola();
            break;

        case 6:
            e.caixa();
            break;

        case 7:
            f.listarProdutos();
            break;

        case 8:
            int reabastecer;
            int reabastecerQuantidade;
            std::cout << "Qual produto você deseja reabastecer?" << std::endl;
            std::cout << "Digite o código do produto:" << std::endl;
            cin >> reabastecer;
            std::cout << "Digite a quantidade:" << std::endl;
            cin >> reabastecerQuantidade;

            for (size_t i = 0; i < e.produtos.sizeVector(); i++)
            {
                if (e.produtos.elementos[i].codigo == reabastecer)
                {
                    f.repassarProdutos(e.produtos.elementos[i], reabastecerQuantidade);
                    e.reabastecer(e.produtos.elementos[i], reabastecerQuantidade);
                }
            }
            break;

        default:
            cout << "Opção inválida" << std::endl;
            break;
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