#ifndef STUBS_HPP_INCLUDED
#define STUBS_HPP_INCLUDED
#include "interfaces.hpp"
#include "dominios.hpp"
#include "entidades.hpp"

using namespace std;

class StubISAutenticacao : public IS_Autenticacao{
    public:
        const static string TRIGGER_SUCESSO_EMAIL;
        const static string TRIGGER_SUCESSO_SENHA;

        bool autenticar(const Email email, const Senha senha) override;
};

class StubISReservas : public IS_Reservas{
    static const string TRIGGER_CODIGO_HOTEL_VALIDO;
    static const string TRIGGER_CODIGO_RESERVA_VALIDO;
    static const string TRIGGER_EMAIL_HOSPEDE_VALIDO;
    static const string TRIGGER_NUMERO_QUARTO_VALIDO;
    static const string TRIGGER_ERRO;

    bool criarHotel(Hotel hotel) override;
    bool lerHotel(Hotel& hotel) override;
    bool editarHotel(Hotel hotel) override;
    bool excluirHotel(Hotel hotel) override;
    bool listarHotel(vector<Hotel>& hoteis) override;

    bool criarReserva(Reserva reserva) override;
    bool lerReserva(Reserva& reserva) override;
    bool editarReserva(Reserva reserva) override;
    bool excluirReserva(Reserva reserva) override;
    bool listarReservasDoHotel(const Hotel& hotel, vector<Reserva>& reservas) override;

    bool criarHospede(Hospede hospede) override;
    bool lerHospede(Hospede& hospede) override;
    bool editarHospede(Hospede hospede) override;
    bool excluirHospede(Hospede hospede) override;
    bool listarHospedesDoHotel(const Hotel& hotel, vector<Hospede>& hospedes) override;

    bool criarQuarto(Quarto quarto) override;
    bool lerQuarto(Quarto& quarto) override;
    bool editarQuarto(Quarto quarto) override;
    bool excluirQuarto(Quarto quarto) override;
    bool listarQuartosDoHotel(const Hotel& hotel, vector<Quarto>& quartos) override;
};

class StubISPessoal : public IS_Pessoal{
    public:
        static const string TRIGGER_SUCESSO_EMAIL;
        static const string TRIGGER_ERRO_EMAIL;;

        bool criarGerente(Gerente gerente) override;
        bool lerGerente(Gerente& gerente) override;
        bool atualizarGerente(Gerente gerente) override;
        bool descadastrarGerente(Gerente gerente);
};

#endif // STUBS_HPP_INCLUDED
