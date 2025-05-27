#include <iostream>
#include "matematica.h"

int main(){
    int opc = -1;
    do{
        int a, b;
        std::cout << "Escolha a opcao: " << std::endl;
        std::cout << "1 - Soma" << std::endl;
        std::cout << "2 - Subtracao" << std::endl;
        std::cout << "3 - Multiplicacao" << std::endl;
        std::cout << "4 - Divisao" << std::endl;
        std::cout << "0 - Sair" << std::endl;
        std::cin >> opc;
        switch (opc)
        {
        case 1:
            std:: cin >> a;
            std:: cin >> b;
            std::cout << "Resultado da soma: " << soma(a, b) << std::endl;
            break;
        case 2:
            std:: cin >> a;
            std:: cin >> b;
            std::cout << "Resultado da subtracao: " << subtracao(a, b) << std::endl;
            break;
        case 3:
            std:: cin >> a;
            std:: cin >>b;
            std::cout << "Resultado da multiplicacao: " << multiplicacao(a,b) <<std::endl;
            break;
        case 4:
            std:: cin>>a;
            std:: cin>>b;
            if (b == 0){
                std::cout << "Divisao por zero!" << std::endl;
            } else {
                std::cout << "Resultado da divisao: " << divisao(a, b) << std::endl;
            }
        default:
            break;
        }
    } while (opc !=0);
}
