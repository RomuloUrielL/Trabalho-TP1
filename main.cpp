#include <iostream>
#include <string>
#include<limits>
#include "dominios.hpp"
#include "entidades.hpp"

using namespace std;

int main(){

    Telefone *ptra;
    string telefone;

    ptra = new Telefone();

    while(true){
        cout << "Digite o telefone: ";
        if(!(cin >> telefone)){
            cerr << "Telefone invalido! Digite apenas numeros. \n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        try{
            ptra->setTelefone(telefone);
            break;
        }
        catch(const length_error&exp){
            cerr << exp.what() << endl;
        }
        catch(const invalid_argument&exp){
            cerr << exp.what() << endl;
        }
        catch(const out_of_range&exp){
            cerr << exp.what() << endl;
        }
    }

    cout << "Telefone aceito." << endl;

    delete ptra;

    return 0;
}
