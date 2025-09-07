#include <iostream>
#include <string>
#include "dominios.hpp"

using namespace std;

int main(){

    Senha *ptra;

    ptra = new Senha();

    if(ptra->setSenha("A1a$B"))
        cout<<"Senha: "<<ptra->getSenha()<<endl;
    else
        cout<<"Senha invalida!"<<endl;

    if(ptra->setSenha("A5s&e2"))
        cout<<"Senha: "<<ptra->getSenha()<<endl;
    else
        cout<<"Senha invalida!"<<endl;

    delete ptra;

    return 0;
}
