#ifndef CONTAINERS_HPP_INCLUDED
#define CONTAINERS_HPP_INCLUDED

#include "entidades.hpp"
#include <map>
#include <string>
#include <vector>

using namespace std;

class ContainerHoteis{
    private:
        static ContainerHoteis* instancia;
        map<string, Hotel> container;
        ContainerHoteis(){}
    public:
        static ContainerHoteis* getInstancia();

        bool incluir(Hotel hotel);
        bool pesquisar(Hotel* hotel);
        bool atualizar(Hotel hotel);
        bool remover(string codigo);
        bool listar(vector<Hotel>& hoteis);
};

class ContainerReservas{
    private:
        static ContainerReservas* instancia;
        map<string, Reserva> container;
        ContainerReservas(){}
    public:
        static ContainerReservas* getInstancia();

        bool incluir(Reserva reserva);
        bool pesquisar(Reserva* reserva);
        bool atualizar(Reserva reserva);
        bool remover(string codigo);
        bool listar(string codigoHotelFiltro, vector<Reserva>& reservas);
        bool listar(vector<Reserva>& reservas);
};

class ContainerHospedes{
    private:
        static ContainerHospedes* instancia;
        map<string, Hospede> container;
        ContainerHospedes(){}
    public:
        static ContainerHospedes* getInstancia();

        bool incluir(Hospede hospede);
        bool pesquisar(Hospede* hospede);
        bool atualizar(Hospede hospede);
        bool remover(string email);
        bool listar(string codigoHotelFiltro, vector<Hospede>& hospedes);
        bool listar(vector<Hospede>& hospedes);
};

class ContainerQuartos{
    private:
        static ContainerQuartos* instancia;
        map<string, Quarto> container;
        ContainerQuartos(){}
    public:
        static ContainerQuartos* getInstancia();

        bool incluir(Quarto quarto);
        bool pesquisar(Quarto* quarto);
        bool atualizar(Quarto quarto);
        bool remover(string numero);
        bool listar(string codigoHotelFiltro, vector<Quarto>& quartos);
        bool listar(vector<Quarto>& quarto);
};

#endif // CONTAINERS_HPP_INCLUDED
