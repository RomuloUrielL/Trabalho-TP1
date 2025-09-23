#include <iostream>
#include <string>
#include<limits>
#include "dominios.hpp"
#include "entidades.hpp"

using namespace std;

int main(){

    Ramal *ptra;
    string ramal;

    ptra = new Ramal();

    while(true){
        cout << "Digite o ramal: ";
        if(!(cin >> ramal)){
            cerr << "Ramal invalido! Digite um numero. \n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        try{
            ptra->setRamal(ramal);
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

    cout << "Ramal aceito." << endl;

    delete ptra;

    return 0;
}
