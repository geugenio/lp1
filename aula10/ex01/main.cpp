#include <iostream>

using namespace std;
class Pessoa{
    public:
        string nome;
        static int contador;
        
        Pessoa(){}
        Pessoa(string nome){
            contador++;
            this-> nome = nome;
        }
        static void numeroPessoas(Pessoa x){
            cout << x.nome <<endl;
        }
};

int Pessoa::contador = 0;


int main(){
    Pessoa p1("Jerff");
    cout << p1.nome << endl;
    cout << Pessoa::contador << endl;

    Pessoa p2("Ale");
    cout << p2.nome << endl;
    cout << Pessoa::contador << endl;
    //p1.numeroPessoas();
    Pessoa::numeroPessoas(p1);

    return 0;
}