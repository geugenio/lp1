#pragma once
#include <iostream>
#include <list>

#include "Pedido.h"

using namespace std;

class Mesa{
    public:
        int id;
        bool status;
        list<Pedido> pedidos;

        Mesa(int id);

        void descricao() const;

        float valorTotalMesa() const;

        void adicionarPedido(Pedido pedidoNovo);

        void encerrarMesa();

        void exibirPedidos() const;

};