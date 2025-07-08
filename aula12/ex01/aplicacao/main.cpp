#include <iostream>
#include <string>


using namespace std;

class Autenticacao{
public:
    bool virtual autenticar(){
        coletarDados();
        validarDados(); //se tiver autenticado, passa, se não joga exceção e não inicia.
        iniciarSessao();
    };
    bool virtual validarDados();
    void virtual coletarDados();
    void iniciarSessao(){
        cout << "Sessão iniciada!" << endl;
    }
};



class LoginSenha : Autenticacao{
public:
    string login;
    string senha;
    bool validarDados() override {
        try {
            if (login.size() > 4 && senha.size() > 8) {
                return true;
            } else {
                cout << "Login ou senha inválidos!" << endl;
                return false;
            }
        } catch (exception& e) {
            cout << "Erro ao validar dados: " << e.what() << endl;
            return false;
        }
    }

    void coletarDados() override{
        cin >> login;
        cin >> senha;
    }

};


class GoogleAuth : Autenticacao{
public:
     string email;

     void coletarDados() override{
        cin >> email;
     }
     bool validarDados() override{
        try{
            if (email )
        }
     }
}


int main(){

    return 0;
}