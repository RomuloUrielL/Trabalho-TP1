#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.hpp"
#include "entidades.hpp"

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
