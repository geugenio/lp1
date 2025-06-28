#include <iostream>
using namespace std;

class Conta{
    public:
        int numero;
        float saldo;
        string titulo;
        Conta() : numero(0), saldo(0.0f), titulo("") {}
        Conta(string titulo, int numero, float saldo){
            this->titulo = titulo;
            this->numero = numero;
            this->saldo = saldo;
        }

        Conta& operator+=(float valor){
            this->saldo = saldo + valor;
            return *this;
        }
};


Conta operator-(Conta& c, float valor) {
    Conta temp = c;
    temp.saldo = c.saldo - valor;
    c.saldo -= valor;
    return temp;
}


int main(){
    Conta c1("Gabriel", 1, 20.00f);
    Conta c2("Flavio", 2, 40.00f);

    cout << c1.saldo << endl;
    cout << c2.saldo << endl;

    cout << "-------------" << endl;
    c2 = c1-2;
    cout << c1.titulo << "  " << c1.saldo << endl;
    cout << c2.titulo << "  " << c2.saldo;
    return 0;
}