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

/**
@brief Controladora da Camada de Apresentação responsável pela Autenticação
dos usuários.
@details Esta classe implementa a Interface Apresentação Autenticação. Tem o
objetivo servir como intermediária entre o usuário e a camada de Serviço.
 */
class CntrIUAutenticacao: public IA_Autenticacao{
    private:
        IS_Autenticacao *cntrServicoAutenticacao;
    public:
        /**
        @brief Executa o fluxo de interação com o usuário para login.
        @details Este método entra em um loop solicitando Email e Senha ao usuário.
        Ele trata exceções de formato lançadades pelos métodos validar das
        classes domínios e, após serem validados os formatos, repassar para
        o método autenticar da camada de serviço.
        @param email Referência para um objeto da classe dompinio Email. Se a
        autenticação ocorrer com sucesso o objeto é preenchido com o email do
        usuário autenticado.
        @return ture caso o email seja autenticado com sucesso e false caso o email
        não consiga ser autenticado com sucesso.
        */
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
