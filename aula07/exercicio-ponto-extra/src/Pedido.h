#pragma once
#include <iostream>
#include "Item.h"
#include <list>
using namespace std;

class Pedido{
    public:
        int id;
        list<Item> itens;

        void pedidosTotais() const;
        float valorTotal() const;
        void adicionarItem(const Item& item);
        
};