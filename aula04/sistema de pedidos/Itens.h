#pragma once

#include <iostream>

using namespace std;

struct Itens{
    string nome;
    int quantidade;
    float valor_unitario;
    Itens(string nome, int quantidade, float valor_unitario);
    Itens();
};