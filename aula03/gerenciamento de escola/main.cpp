#include <iostream>

using namespace std;

struct Aluno{
    string nome;
    int n1;
    int n2;
    float media = (n1+n2)/2;
    Aluno (string nome, int n1, int n2){
        this->nome = nome;
        this->n1=n1;
        this->n2=n2;
    }

    Aluno(){}
};


int main(){
    int quantidadeDeAlunos;
    cout << "Insira a quantidade de alunos: ";
    cin >> quantidadeDeAlunos;
    Aluno alunos[10];
    int mediaGeral;

    if (quantidadeDeAlunos>10){
        cout << "Erro! número indevido de alunos.";
        return -1;
    }
    for (int i = 0; i < quantidadeDeAlunos;i++){
        string nome;
        int n1;
        int n2;
        cin >> nome >> n1 >> n2;
        Aluno p1(nome, n1, n2);
        alunos[i] = p1;
        int somaNotas = somaNotas + alunos[i].media;
    }
    
    int opc = -1;


    do{
        cout << "OPCÕES" << endl;
        cout << "Escolha a opcao: " << std::endl;
        cout << "1 - Listar todos os alunos" << std::endl;
        cout << "2 - Buscar aluno por nome" << std::endl;
        cout << "3 - Média geral da turma" << std::endl;
        cout << "0 - Sair" << std::endl;
        cin >> opc;
        string nomeBusca;
        switch(opc){
            case 1: 
                cout << "Alunos cadastrados: " << endl;
                int somaNotas;
                for (int i = 0; i < quantidadeDeAlunos; i++){
                    cout << "Aluno " << i << endl;
                    cout << "Nome: " << alunos[i].nome << endl;
                    cout << "Notas: " << alunos[i].n1 << " e " << alunos[i].n2 << endl;
                    cout << "Média: " << alunos[i].media << endl;
                    
                }
                break;
            case 2:
                
                cout << "Insira o nome do aluno: ";
                cin >> nomeBusca;
                for (int i = 0; i < quantidadeDeAlunos;i++){
                    if (alunos[i].nome == nomeBusca){
                        cout << "Aluno " << i << endl;
                        cout << "Nome: " << alunos[i].nome << endl;
                        cout << "Notas: " << alunos[i].n1 << " e " << alunos[i].n2 << endl;
                        cout << "Média: " << alunos[i].media << endl;
                    }
                }
                break;
            case 3:
                mediaGeral = somaNotas/quantidadeDeAlunos;
                cout << "Média da turma: " << mediaGeral << endl;
                break;
            default:
                cout << "Erro!" << endl;
                break;
        }
    } while (opc!=0);

    
    return 0;

}