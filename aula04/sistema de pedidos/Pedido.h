#pragma once

#include <iostream>
#include "itens.h"
#include <vector>

using namespace std;

struct Pedido{
    vector<Itens> itens;
    int quantidade_de_itens = 0;

    Pedido(vector<Itens> itens);
    float totalPedido();
};