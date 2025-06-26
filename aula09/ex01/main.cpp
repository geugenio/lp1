#include <iostream>
#include <string>
using namespace std;

class Pessoa {
    public:
        int idade;
        
        Pessoa(){}
        Pessoa(int idade){
            this -> idade = idade;
        }
        friend ostream& operator << (ostream& os, Pessoa& p);     
};

istream& operator>>(istream& is, Pessoa& p){
    string idade_str;
    cout << "Digite a idade: ";
    getline(is, idade_str);
    p.idade = stoi(idade_str);
    cout << "Digite"
}

Pessoa operator+(int ano, Pessoa& p){
    return operadorSomaPessoa(p, ano);
}

Pessoa operator+(Pessoa& p, int ano){
    return operadorSomaPessoa(p, ano);
}

Pessoa operadorSomaPessoa(Pessoa p, int ano){
    //logica
    return Pessoa(p.idade + ano);
}

int main(){
    Pessoa p(30);
    Pessoa p2 = p+1;
    cout << p2.idade << endl;
    return 0;
}