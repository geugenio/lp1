#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Conteudo{
    protected:
        int id;
        string titulo;
        string sinopse;
        string diretor;
        vector<string> elenco;
        string genero;
        string subgenero;
        int anoLançamento;
        string classificacao;
        float duracao;

    public:
        // Construtores
        Conteudo(int id, string titulo, string sinopse, string diretor, vector<string> elenco, 
            string genero, string subgenero, int anoLançamento, string classificacao, float duracao);
        Conteudo();

        // Métodos
        virtual Conteudo* buscarConteudoId(int id) const;
        virtual void exibir() const;
        // Getters e Setters
        int getId() const;
        string getTitulo() const;
        string getSinopse() const;
        string getDiretor() const;
        vector<string> getElenco() const;
        string getGenero() const;
        string getSubgenero() const;
        int getAnoLancamento() const;
        string getClassificacao() const;
        float getDuracao() const;
        void setId(int id);
        void setTitulo(string titulo);
        void setSinopse(string sinopse);
        void setDiretor(string diretor);
        void setElenco(vector<string> elenco);
        void setGenero(string genero);
        void setSubgenero(string subgenero);
        void setAnoLancamento(int anoLançamento);
        void setClassificacao(string classificacao);
        void setDuracao(float duracao);
};