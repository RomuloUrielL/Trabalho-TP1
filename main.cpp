#include <iostream>
#include <string>
#include "dominios.hpp"

using namespace std;

int main(){

    Codigo *ptra;

    ptra = new Codigo();

    if(ptra->setCodigo("av04ds23g5"))
        cout<<"Codigo: "<<ptra->getCodigo()<<endl;
    else
        cout<<"Codigo invalido!"<<endl;

    if(ptra->setCodigo("dfgassd123"))
        cout<<"Codigo: "<<ptra->getCodigo()<<endl;
    else
        cout<<"Codigo invalido!"<<endl;

    delete ptra;

    return 0;
}
