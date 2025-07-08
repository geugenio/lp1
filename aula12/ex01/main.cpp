#include <iostream>
using namespace std;

class Animal{
    public:
    string nome;
    Animal(string nome){
        this-> nome = nome;
    }
    virtual void emitirSom(){
        cout << "Animal emitindo som" << endl;
    }
    //Método virtual puro, deve ser sobrescrito OBRIGATORIAMENTE
    virtual void existir() = 0;
};


class Gato : public Animal{
    public:
        Gato(string nome) : Animal(nome){
            cout << "Construtor da classe gato" << endl;
        }

        void emitirSom() override{
            cout << "Gato emitindo som" <<endl;
        }

        void miar(){
            cout << "Miau!" << endl;
        }

        void ronronar(){
            cout << "ronron" << endl;
        }

        virtual void existir(){
            cout << "Olá" << endl;
        }
};


int main(){

    Animal* a = new Gato("Flávio");

    return 0;
}
