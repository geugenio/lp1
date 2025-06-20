#pragma once
#include <iostream>
#include "Item.h"
#include <list>
using namespace std;

class Pedido{
    public:
        int id;
        list<Item> itens;

        Pedido();
        void pedidosTotais() const;
        float valorTotal() const;
        void adicionarItem(const Item& item);
        
};