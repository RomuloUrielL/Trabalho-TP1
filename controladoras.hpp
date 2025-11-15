#ifndef CONTROLADORAS_H_INCLUDED
#define CONTROLADORAS_H_INCLUDED

#include "dominios.hpp"
#include "entidades.hpp"
#include "interfaces.hpp"

#include <stdexcept>
#include <iostream>

class IS_Autenticacao;
class IS_Pessoal;
class IS_Reservas;

class CntrIUAutenticacao: public IA_Autenticacao{
    private:
        IS_Autenticacao *cntrServicoAutenticacao;
    public:
        bool autenticar(Email&) override;
        void setCntrSAutenticacao(IS_Autenticacao*);
};

void inline CntrIUAutenticacao::setCntrSAutenticacao(IS_Autenticacao *cntrServicoAutenticacao){
        this->cntrServicoAutenticacao = cntrServicoAutenticacao;
}

#endif // CONTROLADORAS_H_INCLUDED
