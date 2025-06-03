#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> numeros;
    
    for(int i = 0; i < 5; i++){
        cout << "Digite o numero de indice " << i << ": ";
        int insert;
        cin >> insert;
        numeros.push_back(insert);
    }

    try{
        cout <<"Insira o indice para acessar o elemento: ";
        int indice;
        cin >> indice;        
        cout << "Numero: " << numeros.at(indice)<<endl;
        
    } catch(const out_of_range& e){
        cout << "Exception: " << e.what() << endl;
        
    }

    return 0;
}