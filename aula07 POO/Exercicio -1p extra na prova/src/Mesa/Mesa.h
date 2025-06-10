#pragma once
#include <iostream>
#include <list>

#include "Pedido.h"

using namespace std;

class Mesa{
    public:
        int id;
        bool status = true;
        list<Pedido> pedidos;
        float valorTotalMesa();

        void adicionarPedido(Pedido pedidoNovo);

        void encerrarMesa();

};