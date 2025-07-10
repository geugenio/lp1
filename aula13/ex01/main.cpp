#include <iostream>
#include <vector>
using namespace std;

class Pessoa{
    public:
    string nome;
};

template <typename T>
class EndPoint{
    public:
        virtual void criar(T p) = 0;
        virtual void editar(T p) = 0;
};


class EndPointPessoa : EndPoint <Pessoa>{
    void criar(Pessoa p ){
        cout << "Criando pessoa " << p.nome << endl;
    }

    void editar(Pessoa p){
        cout << "Editando pessoa " << p.nome << endl;
    }
};

int main(){
    return 0;
}