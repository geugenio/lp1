#include <iostream>
#include <vector>

using namespace std;
int main(){
    vector<int> numeros;
        
    int menor_numero;
    int maior_numero;
    int soma;
    float media;
    
    int num = 0;
    while(true){
        try{
            cout << "Insira o numero: ";
            cin >> num;
            if (num < -1){
                throw invalid_argument("Numero invalido! Digite numeros maiores que -1");

            } else if(num > 10000){
                throw overflow_error("Numero invalido! Digite um valor menor que 10000");
                
            } else if(num == -1){
                
                for (int i = 0; i < numeros.size(); i++){
                    soma = soma + numeros.at(i);

                    if(menor_numero > numeros.at(i)){
                        menor_numero = numeros.at(i);
                    } else if(numeros.at(i) > maior_numero){
                        maior_numero = numeros.at(i);
                    }
                }
                media = soma/numeros.size();

                break;
            }
            numeros.push_back(num);

        } catch(const exception& e){
            cout << "Mensagem do erro: " << e.what() << endl; 
        }
        
    };

    cout << "Quantidade de valores inseridos: " << numeros.size() << endl;
    cout <<"Media dos numeros inseridos: " << media << endl;

    cout <<"Menor numero: " << menor_numero<< endl;
    cout <<"Maior numero: " << maior_numero<< endl;
    return 0;
    
}