#include <iostream>
#include "Mesa.h"
#include "Pedido.h"
#include "Item.h"
#include <vector>
using namespace std;


void menu(){
    cout << "+----------------------------+" << endl;
    cout << "|        MENU PRINCIPAL      |" << endl;
    cout << "+----------------------------+" << endl;
    cout << "| 1 | Ver cardapio           |" << endl;
    cout << "| 2 | Selecionar mesa        |" << endl;
    cout << "| 3 | Listar mesas           |" << endl;
    cout << "| 4 | Encerrar               |" << endl;
    cout << "+----------------------------+" << endl;
}

void menu2(){
    cout << "+------------------------------+" << endl;
    cout << "|         MENU DA MESA         |" << endl;
    cout << "+------------------------------+" << endl;
    cout << "| 1 | Adicionar pedido         |" << endl;
    cout << "| 2 | Ver pedidos              |" << endl;
    cout << "| 3 | Fechar conta             |" << endl;
    cout << "+------------------------------+" << endl;
}

void mostrarCardapio(const vector<Item> &itens){
    cout << "\n=== CARDÁPIO ===" << endl;
    for (const auto &item : itens){
        item.descricao();
    }
}

void relatorioFinal(const vector<Mesa> &mesas, const vector<Item> &itens){
    vector<int> contagem(itens.size() + 1, 0);
    float totalGeral = 0.0;
    for (const auto &mesa : mesas){
        for (const auto &pedido : mesa.pedidos){
            for (const auto &item : pedido.itens){
                if (item.id >= 1 && item.id <= (int)itens.size()){
                    contagem[item.id]++;
                    totalGeral += item.valor;
                }
            }
        }
    }

    cout << "Relatorio FINAL DE VENDAS" << endl;

    for (const auto &item : itens){
        int quantidade = contagem[item.id];
        float total = quantidade * item.valor;
        if (quantidade > 0){
            cout << item.nome << "\tR$ " << item.valor << "\t" << quantidade << "\tR$ " << total << endl;
        }
    }
    cout << "TOTAL GERAL VENDIDO: R$ " << totalGeral << endl;
}

int main(){
    vector<Mesa> mesas = {Mesa(1), Mesa(2), Mesa(3)};
    // Inserindo itens no cardápio
    vector<Item> itens = {
        {1, "Cachorro Quente", 7.50},
        {2, "Hamburguer", 15.00},
        {3, "Fatia de Pizza", 6.00},
        {4, "Porcao de batata frita", 7.00},
        {5, "Coxinha", 4.50},
        {6, "Fatia de bolo", 5.00},
        {7, "Agua mineral", 3.00},
        {8, "Lata de refrigerante", 5.00},
        {9, "Suco de laranja", 6.00}
    };

    int opc = 0;
    cout << "++====================================++" << endl;
    cout << "||     BEM VINDO AO SISTEMA DE        ||"  << endl;
    cout << "||   GERENCIAMENTO DO RESTAURANTE!    ||" << endl;
    cout << "++====================================++" << endl << endl;
    do{
        
        menu();
        cout << "Escolha a opcao: ";
        cin >> opc;
        cout << endl;
        switch (opc){
            case 1:{ //1 - Mostrar cardapio
                mostrarCardapio(itens);
                break;
            }

            case 2:{ //2 - Selecionar mesa
                cout << "Selecione uma mesa (1 a 3): ";
                int idMesa;
                cin >> idMesa;
                cout << endl;
                idMesa -= 1; // indice 0
                if (idMesa < 0 || idMesa >= 3){
                    cout << "Mesa invalida!" << endl;
                    break;
                }

                cout << "Mesa " << idMesa << " selecionada!" << endl;

                menu2(); // Abre o segundo menú
                int opc2;
                cout << "Escolha a opcao: ";
                cin >> opc2;
                cout << endl;
                Pedido pedidoNovo;
                // MENU 2
                switch (opc2){

                    case 1:{  //1 - Adicionar pedido à mesa
                        if (!mesas[idMesa].status){
                            cout << "Mesa fechada! Nao e possivel adicionar mais pedidos." << endl;
                        } else{
                            cout << "Adicionando pedido a mesa " << idMesa + 1 << endl;

                            mostrarCardapio(itens);
                            cout << "Digite o ID do item que deseja adicionar ao pedido (0 para finalizar):" << endl;
                            int idItem;
                            while (true){
                                cin >> idItem;
                                if (idItem == 0){
                                    if (!pedidoNovo.itens.empty()){
                                        mesas[idMesa].adicionarPedido(pedidoNovo);
                                        cout << "Pedido adicionado com sucesso!" << endl;
                                    }
                                    break; // Pedido finalizado
                                }
                                bool encontrouItem = false;

                                for (const Item &item : itens){ // varredura por todos os itens
                                    if (item.id == idItem){
                                        pedidoNovo.adicionarItem(item);
                                        encontrouItem = true;
                                        cout << "Item adicionado: " << item.nome << endl;
                                    }
                                }
                                if (!encontrouItem){
                                    cout << "ID do item invalido! Tente novamente." << endl;
                                }
                            }
                        }
                        break;
                    }

                    
                    case 2:{ // 2 - puxar os pedidos da mesa
                        if (!mesas[idMesa].pedidos.empty()){
                            mesas[idMesa].descricao();
                        }
                        else{
                            cout << "Nao ha pedidos na mesa." << endl;
                        }
                        break;
                    }
                    case 3:{ // 3 - encerrar os pedidos da mesa
                        if (mesas[idMesa].status){
                            mesas[idMesa].encerrarMesa();
                            cout << "Mesa " << idMesa << " encerrada!" << endl;
                        }
                        else{
                            cout << "Mesa " << idMesa << " ja esta encerrada." << endl;
                        }
                        break;
                    }
                    default:{
                        cout << "Valor invalido! Selecione novamente." << endl;
                        break;
                    }
                }

                break;
            }

            case 3:{ //3 - Listar mesas
                cout << "Mesas:" << endl << endl;
                for (int i = 0; i < 3; i++){
                    cout << "Mesa " << i + 1 << ":" << endl;
                    if (!mesas[i].pedidos.empty()){
                        mesas[i].descricao();
                    }
                    else{
                        cout << "Nao ha pedidos na mesa." << endl;
                    }
                }
                break;
            }

            case 4: { //4 - Encerrar o programa e apresentar o relatório
                bool mesasFechadas = true;
                for (const Mesa &mesa : mesas){
                    if (mesa.status){
                        mesasFechadas = false;
                        break;
                    }
                }
                if (mesasFechadas){
                    cout << "Vendas encerradas!" << endl;
                    relatorioFinal(mesas, itens);
                    return 0;
                }
                else{
                    cout << "Ainda possuimos mesas abertas! Precisamos que todas estejam fechadas para fechar o programa." << endl;
                }
                break;
            }

            default: {
                cout << "Valor invalido! Selecione novamente." << endl;
                break;
            }
        }
    } while (true);
}
