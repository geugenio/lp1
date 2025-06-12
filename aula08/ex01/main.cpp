#include <iostream>
using namespace std;

class Pessoa{
    public:
        string nome;
        int idade;

        Pessoa(){

        }
        Pessoa(string nome, int idade = 0){
            this-> nome = nome;
            this-> idade = idade;
        }
};

int main(){
    Pessoa p();
    cout << p.idade << endl;
    return 0;
}