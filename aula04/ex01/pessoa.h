#pragma once

#include <iostream>

using namespace std;

struct Pessoa{
    string nome;
    int idade;
    
    void saudacao(string nome = "Usuario", string saud = "Olá");
};