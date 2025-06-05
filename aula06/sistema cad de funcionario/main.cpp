#include <iostream>
#include <vector>

using namespace std;


namespace empresa{
    struct Funcionario{
        string nome;
        int idade;
        float salario;
        
        Funcionario(string nome, int idade, float salario){
            this->nome = nome;
            this->idade = idade;
            this->salario = salario;
        }
    };
}

namespace cadastrarFuncionario{
    void idadeValida(int idade){
        try{
            if(idade<18){
                throw invalid_argument("Idade invalida!");
            }
        } catch(const exception& e){
            throw;
        }

    }
}

int main()
{
    string strOpc;
    vector<empresa::Funcionario> funcionarios;
    while(true){
        cout << "Deseja inserir um funcionario? (s/n): ";
        cin >> strOpc;
        if (strOpc == "n"){
            break;
        } else{
            cout << "------------------------------" <<endl;
            string nome;
            int idade;
            float salario;
            cout<<"Insira o nome do funcionario: ";
            
            cin >> nome;
            cout <<"Insira a idade do funcionario: ";
            cin >> idade;

            
            try{
                cadastrarFuncionario::idadeValida(idade);
                cout << "Insira o salario: ";
                cin >> salario;         
                empresa::Funcionario f(nome, idade, salario);
                funcionarios.push_back(f);
                
            } catch(const invalid_argument& e){
                cout << "Erro: " <<e.what() <<endl;
            }
        }

    }

    for (empresa::Funcionario func : funcionarios){
        cout << "----------------------------" <<endl;
        cout <<"Nome: " << func.nome << endl;
        cout <<"Idade: " << func.idade << endl;
        cout << "Salario: " << func.salario << endl;
    }

    return 0;
}