#include <iostream>
#include <string>
#include<limits>
#include "dominios.hpp"
#include "entidades.hpp"
#include <stdexcept>
#include "testes.hpp"
using namespace std;

int main(){

    TUTelefone testeTelefone;

    switch(testeTelefone.run()){
        case TUTelefone::SUCESSO: cout << "SUCESSO" << endl;
        break;
        case TUTelefone::FALHA: cout << "FALHA" << endl;
        break;
    }
    return 0;
}
