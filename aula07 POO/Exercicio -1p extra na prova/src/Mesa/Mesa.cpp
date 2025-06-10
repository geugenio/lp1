#include "Mesa.h"

float Mesa::valorTotalMesa(){
    float valor = 0.0f;
    for(const Pedido& pedido : pedidos){
        valor += pedido.valorTotal();
    }
    return valor;
}

void Mesa::adicionarPedido(Pedido pedidoNovo){
    if(status){
        pedidos.push_front(pedidoNovo);
    }
}
void Mesa::encerrarMesa(){
    status = false;
}