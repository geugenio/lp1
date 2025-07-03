#include <iostream>
#include <vector>

using namespace std;


class Veiculo {
    public:
        string marca;
        string modelo;
        Veiculo(){}
        Veiculo(string marca, string modelo){
            this->marca=marca;
            this->modelo=modelo;
        }
        void exibirInformacoes(){
            cout << "marca: " << marca << endl;
            cout << "modelo: " << modelo << endl;
        }
};

class Carro : Veiculo{
    public:
        int numeroPortas;
        Carro(){}
        Carro(string marca, string modelo, int numeroPortas) : Veiculo(marca, modelo) {;
            this->numeroPortas = numeroPortas;
        }
        void exibirInformacoesCarro(){
            exibirInformacoes();
            cout << "numero de portas" << numeroPortas << endl;
        }
};

class Moto : Veiculo{
    public:
        int cilindrada;
        Moto(){}
        Moto(string marca, string modelo, int cilindrada) : Veiculo(marca, modelo) {;
            this->cilindrada = cilindrada;
        }
        void exibirInformacoesMoto(){
            exibirInformacoes();
            cout << "numero de cilindradas: " << cilindrada << endl;
        }
};

class SistemaVeiculos{
    public:
        vector<Veiculo> veiculos;

        void adicionarVeiculo(Veiculo veiculo){
            veiculos.push_back(veiculo);
        }
        void removerVeiculo(Veiculo veiculo){
            veiculos.pop_back();
        }
        void exibirTodosOsVeiculos(){
            for (size_t i = 0; i < veiculos.size(); ++i) {
                cout << "Veiculo " << i + 1 << ":" << endl;
                veiculos[i].exibirInformacoes();
                cout << endl;
            }
        }
};

int main(){


    return 0;
}