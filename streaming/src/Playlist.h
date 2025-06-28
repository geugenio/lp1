#pragma once
#include <iostream>
#include <vector>
#include "Conteudo.h"
#include "User.h"


class Playlist{
    private:
        int id;
        string nome;
        User* criador;
        vector<Conteudo*> conteudos;
    public:
        void adicionarConteudo(Conteudo* conteudo);
        void removerConteudo(int id);
        Playlist();
        Playlist(string nome);
};