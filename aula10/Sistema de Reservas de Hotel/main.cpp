#include <iostream>
#include <vector>
using namespace std;

class Hotel{
    public:
        vector<Quarto> quartos;
        static int numTotalReservas;

        void adicionarQuarto(Quarto quarto){
            quartos.push_back(quarto);
            numTotalReservas++;
        }
};
static int numTotalReservas = 0;

class Quarto{
    public:
        int id;
        double precoBase;
        string tipo;
        static const string Luxo;
        static const string Comum;

        Quarto(){}
        Quarto(int id, double precoBase, string tipo){
            this-> id = id;
            this-> precoBase = precoBase;
            this-> tipo = tipo;
        }
};


const string Quarto::Luxo = "Luxo";
const string Quarto::Comum = "comum";

class Cliente{
    public:
    string tipo;
    static const string VIP;
    static const string Comum;
    string nome;
        Cliente(){}
        Cliente(string nome, string tipo){
            this->nome=nome;
            this-> tipo = tipo;
        }
};

const string Cliente::VIP = "VIP";
const string Cliente::Comum = "comum";


class Reserva{
    public:
        Cliente clienteDono;
        Quarto quartoReservado;
        double valorDiaria;
        Reserva(){}
        Reserva(Cliente cliente, Quarto quarto, double valorDiaria) {
            this->clienteDono = cliente;
            this->quartoReservado = quarto;
            this->valorDiaria = valorDiaria;
        }
        void exibir(){
            cout << "Nome do cliente: " << clienteDono.nome << endl;
            cout << "Numero do quarto: " << quartoReservado.id << endl;
            double valorFinal;
            double desconto;

            if(clienteDono.tipo == "VIP"){
                desconto += 0.1*(valorDiaria+quartoReservado.precoBase);
            }

            if(quartoReservado.tipo == "Luxo"){
                desconto += 0.2*(valorDiaria+quartoReservado.precoBase);
            }

            valorFinal = valorDiaria + quartoReservado.precoBase - desconto;
            cout << "Valor final: " << (valorDiaria + quartoReservado.precoBase) << endl;
        }
};

int main(){
    Hotel hotel;
    Quarto q1(1, 100, Quarto::Luxo);
    hotel.adicionarQuarto(q1);
    Cliente c1("Gabriel", Cliente::VIP);
    Reserva r1(c1, q1, 20);
    
    return 0;
}