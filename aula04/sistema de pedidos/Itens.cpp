#include "Itens.h"
#include <iostream>

using namespace std;

Itens::Itens(string nome, int quantidade, float valor_unitario){
    this->nome = nome;
    this-> quantidade = quantidade;
    this-> valor_unitario = valor_unitario;
}
Itens::Itens(){
}
