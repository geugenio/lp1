#include <iostream>
#include "Mesa.h"
#include "Pedido.h"
#include "Item.h"


#include <vector>

using namespace std;

void menu(){
    cout << "1 - Ver cardapio" << endl;
    cout << "2 - Selecionar mesa" << endl;
    cout << "3 - Listar mesas" << endl;
    cout << "4 - Encerrar codigo" << endl;
}

void menu2(){
    cout << "1 - Adicionar pedido a mesa" << endl;
    cout << "2 - Puxar itens pedidos de uma mesa" << endl;
    cout << "3 - Encerrar conta da mesa" << endl;
}

void mostrarCardapio(const vector<Item>& itens) {
    cout << "Cardápio:" << endl;
    for (const auto& item : itens) {
        item.descricao();
    }
}

int main(){
    vector<Mesa> mesas = {
        Mesa(1), 
        Mesa(2), 
        Mesa(3)
    };


    int opc = 0;
    //Inserindo itens no cardápio
    do{
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

        menu();
        cin >> opc;
        switch (opc){
        case 1: //Ver cardápio
            mostrarCardapio(itens);
            break;
        
        case 2: { //Selecionar mesa
            cout << "Selecione uma mesa (1 a 3):" << endl;
            int idMesa;
            cin >> idMesa;
            idMesa -= 1; // indice 0
            if(idMesa < 0 || idMesa >= 2){
                cout << "Mesa invalida!" << endl;
                break;
            }

            //Abre o segundo menú
            menu2();
            int opc2;
            cin >> opc2;
            
            Pedido pedidoNovo;

            switch (opc2){
            case 1: //Adicionar pedido à mesa
                cout << "Adicionando pedido a mesa " << idMesa + 1 << endl;
                mostrarCardapio(itens);
                cout << "Digite o ID do item que deseja adicionar ao pedido (0 para finalizar):" << endl;
                int idItem;
                while (true) {
                    cin >> idItem;
                    if (idItem == 0) {
                        if (!pedidoNovo.itens.empty()){
                            mesas[idMesa].adicionarPedido(pedidoNovo);
                            cout << "Pedido adicionado com sucesso!" << endl;
                        }
                        break; //Pedido finalizado
                        
                    }
                    bool encontrouItem = false;

                    for (const Item& item : itens) { //varredura por todos os itens
                        if (item.id == idItem) {
                            pedidoNovo.adicionarItem(item);
                            encontrouItem = true;
                            cout << "Item adicionado: " << item.nome << endl;
                            break;
                        }
                    }
                    if (!encontrouItem) {
                        cout << "ID do item invalido! Tente novamente." << endl;
                    }
                }
            case 2: //Puxar pedidos da mesa
                if (!mesas[idMesa].pedidos.empty()) {
                    mesas[idMesa].descricao();
                    break;
                } else {
                    cout << "Nao ha pedidos na mesa." << endl;
                    break;
                }
            case 3:
                if(mesas[idMesa].status) {
                    mesas[idMesa].encerrarMesa();
                    cout << "Mesa " << idMesa << " encerrada!"  << endl;
                } else{
                    cout << "Mesa " << idMesa << " ja esta encerrada." << endl;
                }
                break;
            default:
                cout << "Valor invalido! Selecione novamente." << endl;
                break;
            }
            break;
        }
        case 3: //Listar mesas 
            cout << "Mesas:" << endl << endl;
            for (int i = 0; i < 2; i++){
                if (!mesas[i].pedidos.empty()){
                    mesas[i].descricao();
                } else{
                    cout << "Nao ha pedidos na mesa." << endl;
                }
            }
            break;
        case 4: //Encerrar código
            cout << "Encerrando o programa..." << endl;
            return 0;
        default:
            break;
        }
    } while (true);
    

    return 0;
}