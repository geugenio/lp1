#pragma once

#include <iostream>
#include "Pedido.h"
#include "Itens.h"
using namespace std;

struct Impressora{
    void imprimirItem(Itens item);
    void imprimirPedido(Pedido pedido);
};