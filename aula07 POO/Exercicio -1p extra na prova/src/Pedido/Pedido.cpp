 #include "Pedido.h"
 
 void Pedido::pedidosTotais(){
    for(Item item : itens){
            item.descricao();
        }
    }
float Pedido::valorTotal(){
    float total = 0;
    for(Item item : itens){
        total = total + item.valor;
    }
    return total;
}