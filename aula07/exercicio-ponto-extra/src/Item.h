#pragma once
#include <iostream>

using namespace std;

class Item{
    public:
        int id;
        string nome;
        float valor;
        
        void descricao() const;
};