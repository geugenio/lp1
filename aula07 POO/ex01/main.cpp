#include <iostream>
using namespace std;
class Pessoa{
    public:
        string nome;
        int idade;
};



main(){
    Pessoa p;
    p.nome = "Jerff";
    cout << p.nome << endl;
    return 0;
}