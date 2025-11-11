#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.hpp"
#include "entidades.hpp"

class IS_Autenticacao {
public:
    virtual bool autenticar(const Email&, const Senha&) = 0;
    virtual ~IS_Autenticacao(){}
};

class IS_Pessoal {
public:
    virtual bool criarGerente(const Gerente&) = 0;
    virtual bool lerGerente(const Email&, Gerente&) = 0;
    virtual bool atualizarGerente(const Gerente&) = 0;
    virtual bool descadastrarGerente(const Email&) = 0;

    virtual bool criarHospede(const Hospede&) = 0;
    virtual bool lerHospede(const Email&, Hospede&) = 0;
    virtual bool atualizarHospede(const Hospede&) = 0;
    virtual bool descadastrarHospede(const Email&) = 0;

    virtual ~IS_Pessoal(){}
};


//------------------------------//

class IServicoReservas;

class IServicoReservas {
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
};


#endif // INTERFACES_H_INCLUDED
