#include <iostream>

using namespace std;

struct Pessoa{
    
    ~

    void minhaIdadeMains10(int idade){
        if(idade > 00){
            cout<<idade+10;
        } else{

            cout << "A idade tem que ser maior que 0";

            //throw invalide_argument("A idade tem que ser maior que 0");
        }
    }
};


int main(){
    try{
        Pessoa.p;
        p.minhaIdadeMains10(-30);
    }
    return 0;
}