#include "Pedido.h"

Pedido::Pedido(){
    static int proxId = 1;
    id = proxId++;
}

void Pedido::pedidosTotais() const{
    for(const Item& item : itens){
        cout << "ID: " << item.id << ", Nome: " << item.nome << ", Valor: R$" << item.valor << endl;
    }
}
float Pedido::valorTotal() const{
    float total = 0.0;
    for(Item item : itens){
        total = total + item.valor;
    }
    return total;
}

void Pedido::adicionarItem(const Item& item){
    itens.push_back(item);
}