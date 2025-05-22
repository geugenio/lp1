#include <iostream>
#include <vector>

using namespace std;


int main(){
    int j = 0;
    do {
        cout << "j == " << j << endl;
        j++;

    } while(j<5);

    cout << "------------------------" << endl;
    vector<int> numeros = {1,2,3,4,5};
    for (int n: numeros){
        cout << n << endl;
    }
    return 0;
}