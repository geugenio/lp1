#pragma once
#include <iostream>
#include <chrono>

#include "Plano.h"

using namespace std;

class User{
    private:
        int id;
        string nome;
        string email;
        string senha;
        Plano* planoAssinatura;
};