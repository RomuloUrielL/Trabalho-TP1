#include <iostream>
#include <string>
#include<limits>
#include "dominios.hpp"
#include "entidades.hpp"
#include <stdexcept>
#include "testes.hpp"
using namespace std;

int main(){

    TUNumero testeNumero;

    switch(testeNumero.run()){
        case TUNumero::SUCESSO: cout << "SUCESSO" << endl;
        break;
        case TUNumero::FALHA: cout << "FALHA" << endl;
        break;
    }
    return 0;
}
