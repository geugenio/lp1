#pragma once
#include <iostream>
#include "Conteudo.h"

using namespace std;

class Filme : public Conteudo{
    private:
        string diretor;
        string elenco;
        int episodiosTotais;
        int temporadas;
};