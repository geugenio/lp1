#include <iostream>

using namespace std;

struct Pessoa{
    string nome;
    int idade;

    Pessoa(string nome, int idade){
        this->nome = nome;
        this->idade = idade;
    }
};


int main(){
    Pessoa p1("Flavinho", 23);
    cout << "Nome: " << p1.nome << endl << "Idade: " << p1.idade <<endl;
    
    Pessoa* p = new Pessoa("Lucas", 30);
    delete p;
    

    return 0;
}