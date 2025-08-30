#include <iostream>
#include <string>
#include "dominios.hpp"

using namespace std;

int main(){

    Telefone *ptra;

    ptra = new Telefone();

    if(ptra->setTelefone("+55061992116412"))
        cout<<"Telefone: "<<ptra->getTelefone()<<endl;
    else
        cout<<"Telefone invalido!"<<endl;

    if(ptra->setTelefone("+55011998850010"))
        cout<<"Telefone: "<<ptra->getTelefone()<<endl;
    else
        cout<<"Telefone invalido!"<<endl;

    delete ptra;

    return 0;
}
