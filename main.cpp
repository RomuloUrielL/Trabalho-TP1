#include <iostream>
#include <string>
#include "dominios.hpp"

using namespace std;

int main(){

    Nome *ptra;

    ptra = new Nome();

    if(ptra->setNome("Romulo Uriel"))
        cout<<"Nome: "<<ptra->getNome()<<endl;
    else
        cout<<"Nome invalido!"<<endl;

    if(ptra->setNome("Romulo"))
        cout<<"Nome: "<<ptra->getNome()<<endl;
    else
        cout<<"Nome invalido!"<<endl;

    delete ptra;

    return 0;
}
