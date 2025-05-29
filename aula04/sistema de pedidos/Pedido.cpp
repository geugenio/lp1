
#include "Pedido.h"
#include <iostream>
#include "Itens.h"

using namespace std;

Pedido::Pedido(vector<Itens> itens){
    this->itens = itens;
    for (Itens item : itens) {
       this->quantidade_de_itens += item.quantidade;
    }
}

