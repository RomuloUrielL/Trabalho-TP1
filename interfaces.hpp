#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.hpp"
#include "entidades.hpp"

class IS_Autenticacao {
public:
    virtual bool autenticar(Email, Senha) = 0;
    virtual ~IS_Autenticacao(){}
};

class IS_Pessoal {
public:
    virtual bool criarGerente(Gerente) = 0;
    virtual bool lerGerente(Email&, Gerente&) = 0;
    virtual bool atualizarGerente(Gerente) = 0;
    virtual bool descadastrarGerente(Email) = 0;

    virtual void ~IS_Pessoal(){}
};

class IS_Reservas {
    public:
        bool virtual criarHotel(Hotel) = 0;
        bool virtual lerHotel(Hotel&) = 0;
        bool virtual editarHotel(Hotel) = 0;
        bool virtual excluirHotel(Hotel) = 0;

        bool virtual criarReserva(Reserva) = 0;
        bool virtual lerReserva(Reserva&) = 0;
        bool virtual editarReserva(Reserva) = 0;
        bool virtual excluirReserva(Reserva) = 0;

        bool virtual criarHospede(Hospede) = 0;
        bool virtual lerHospede(Hospede&) = 0;
        bool virtual editarHospede(Hospede) = 0;
        bool virtual excluirHospede(Hospede) = 0;

        bool virtual criarQuarto(Quarto) = 0;
        bool virtual lerQuarto(Quarto&) = 0;
        bool virtual editarQuarto(Quarto) = 0;
        bool virtual excluirQuarto(Quarto) = 0;

        virtual void IS_Reservas(){}
};

/*
@brief Interface responsável por prover os serviços ao módulo inicialização para
autenticação de usuários do sistema.
@details É implementada pelo Módulo Apresentação-Autenticação e solicitada pelo
Módulo Apresentação-Inicialização para validar um usuário no sistema.
*/
class IA_Autenticacao{
    public:
    virtual bool autenticar(Email&) = 0;
    virtual void ~IA_Autenticacao(){}
};

class IA_Pessoal{
    public:
    virtual void criar() = 0;
    //modificar o retorno da função executar porque pode dar problema caso o
    //usuário apague a própia conta.
    virtual void executar(Email) = 0;
    virtual void ~IA_Pessoal(){}
};

#endif // INTERFACES_H_INCLUDED
