#include <iostream>
#include <string>
#include<limits>
#include "dominios.hpp"
#include "entidades.hpp"
#include <stdexcept>
#include "testes.hpp"
using namespace std;

int main(){

    TUCapacidade testeCapacidade;

    switch(testeCapacidade.run()){
        case TUCapacidade::SUCESSO: cout << "SUCESSO" << endl;
        break;
        case TUCapacidade::FALHA: cout << "FALHA" << endl;
        break;
    }
    return 0;
}
