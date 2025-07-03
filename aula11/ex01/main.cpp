//Exercicio da aula 03/07/2025

#include <iostream>
using namespace std;

class Animal{
    public:
        string nome;
        Animal(){}
        Animal(string nome){
            this->nome = nome;
        }
        virtual ~Animal(){}
        string emitirSom(){
            return "Esse animal emitiu um som";
        }
};

class Gato : public Animal {
    public:
        int idade;
        Gato(){}
        Gato(string nome, int idade) : Animal(nome){
            this-> idade = idade;
        }
        void miar(){
            cout << "miau"<< endl;
        }
};

class Cachorro : public Animal {
    public:
        Cachorro(){}
        Cachorro(string nome) : Animal(nome){
        }
        void latir(){
            cout << "au au"<<endl;
        }
};

// void vacinar(Cachorro c){
//     cout << "Vacinar: " << c.nome;
// }
// void vacinar(Gato g){
//     cout << "Vacinar: " << g.nome;
// }

void vacinar(Animal a){
    cout << "Vacinar: " << a.nome << endl;
}
int main(){
    Gato g("frajola", 10);
    Cachorro c("Zeus");
    vacinar(g);
    cout << g.idade << endl;
    Animal* mingal = new Gato("Mingal", 3);
    
    //Animal* toto = new Cachorro("Toto");
    //if(dynamic_cast<Cachorro*>(toto) !=nullptr){
    //    cout << "É um cachorro";
    //}
    dynamic_cast<Gato*>(mingal)->miar();
    return 0;
}