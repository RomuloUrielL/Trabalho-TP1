#include <iostream>
#include <string>
#include "dominios.hpp"

using namespace std;

int main(){

    Endereco *ptra;

    ptra = new Endereco();

    if(ptra->setEndereco("Qnm 38 conjunto P casa 13"))
        cout<<"Endereco: "<<ptra->getEndereco()<<endl;
    else
        cout<<"Endereco invalido!"<<endl;

    if(ptra->setEndereco("Qnm 38.  conjunto P"))
        cout<<"Endereco: "<<ptra->getEndereco()<<endl;
    else
        cout<<"Endereco invalido!"<<endl;

    delete ptra;

    return 0;
}
