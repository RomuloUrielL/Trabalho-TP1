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

class CntrIUReservas : public IA_Reservas{
    private:
        IS_Reservas *cntrIS_Reservas;
    public:
        void executar(const Email);
        void setCntrIS_Reservas(IS_Reservas*);
};

inline void CntrIUReservas::setCntrIS_Reservas(IS_Reservas *cntrIS_Reservas){
    this->cntrIS_Reservas = cntrIS_Reservas;
}

#endif // CONTROLADORAS_H_INCLUDED
