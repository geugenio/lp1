#include "Mesa.h"

Mesa::Mesa(int id){
    this->id = id;
    this->status = true;
}

float Mesa::valorTotalMesa() const {
    float total = 0.0;
    for (const auto& pedido : pedidos) {
        total += pedido.valorTotal();
    }
    return total;
}

void Mesa::adicionarPedido(Pedido pedidoNovo){
    if(status){
        pedidos.push_front(pedidoNovo);
    }
}
void Mesa::encerrarMesa(){
    status = false;
}

void Mesa::descricao() const {
    cout << "Mesa ID: " << id << endl;
    cout << "Status: " << (status ? "Aberta" : "Fechada") << endl;

    cout << "Pedidos:" << endl;

    for(const Pedido& pedido : pedidos){
        cout << "Pedido ID: " << pedido.id << endl;
        pedido.pedidosTotais();
        cout << "Valor total do pedido: R$" << pedido.valorTotal() << endl;
    }
    float valorTotal = valorTotalMesa();
    cout << "Valor total da mesa: R$" << valorTotal << endl;
}

void Mesa::exibirPedidos() const {
    if (pedidos.empty()) {
        cout << "Nenhum pedido na mesa." << endl;
        return;

    } else {
        cout << "Pedidos na mesa " << id << ":" << endl;
        for (const Pedido& pedido : pedidos) {
            cout << "Pedido ID: " << pedido.id << endl;
            pedido.pedidosTotais();
            cout << "Valor total do pedido: R$" << pedido.valorTotal() << endl;
        }
    }
}