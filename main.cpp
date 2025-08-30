#include <iostream>
#include "dominios.hpp"

using namespace std;

int main(){

    Dinheiro *ptra;

    ptra = new Dinheiro();

    if(ptra->setDinheiro(1000))
        cout<<"Dinheiro = "<<ptra->getDinheiro()<<endl;
    else
        cout<<"Dinheiro invalido"<<endl;

    if(ptra->setDinheiro(18495.94))
        cout<<"Dinheiro = "<<ptra->getDinheiro()<<endl;
    else
        cout<<"Dinheiro invalido"<<endl;

    delete ptra;

    return 0;
}
