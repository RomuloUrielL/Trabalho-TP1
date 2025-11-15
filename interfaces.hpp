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

        virtual void ~IS_Reservas(){}
};

/**
@brief Interface responsável por prover os serviços ao módulo inicialização para
autenticação de usuários do sistema.
@details É implementada pelo Módulo Apresentação-Autenticação e solicitada pelo
Módulo Apresentação-Inicialização para validar um usuário no sistema.
*/
class IA_Autenticacao{
    public:
    /**
    @brief Inicia o fluxo da interface para autenticação do usuário.
    @details Esta função é chamada pelo Módulo Apresentação-Inicialização para
    realizar a autenticação do usuário.
    @param email Ponteiro com endereço email para ser autenticado.
    @return true em caso de sucesso na autenticação e false caso não seja
    realizada a autenticação.
    */
    virtual bool autenticar(Email&) = 0;
    /**
    @brief Destrutor virtual padrão.
    */
    virtual void ~IA_Autenticacao(){}
};

/**
@brief Interface responsável por prover os serviços ao módulo Apresentação
inicialização para prover os serviços relacionados ao pessoal.
@details É implementada pelo Módulo Apresentação pessoal e solicitada pelo
Módulo Apresentação Inicialização para realizar os serviços relacionado ao
gerenciamento de pessoal do hotel.
*/
class IA_Pessoal{
    public:
    /**
    @brief Contrato da interface para criação de gerentes.
    @details Tem a função de solicitar a criação de um novo gerente no sistema.
    */
    virtual void criar() = 0;
    /**
    @brief Inicia o fluxo na interface com o usuário para a visualização e
    edição de dados de um usuário existente.
    @details A implementação deve carregar e apresentar os dados do
    usuário. A função só retorna quando o fluxo é encerrado.
    @param email A chave de identificação do usuário logado.
    */
    virtual void executar(Email) = 0;
    /**
    @brief Destrutor virtual padrão.
    */
    virtual void ~IA_Pessoal(){}
};

/**
@brief Interface resposável por prover os serviços ao módulo inicialização
apresentação para acessar os serviços de reservas do hotel.
@details É implementado pelo modulo Apresentação Reservas e solicitado pelo
módulo Apresentação Inicialização para poder acessar os serviços relacionados a
reservas do sistema.
*/
class IA_Reservas{
    public:
        /**
        @brief Inicia o fluxo de interface com o usuário para visualização e
        gerenciamento das reservas do hotel.
        @details Esta função é chamada quando um usuário logado acessa a seção
        de "Reservas". A implementação deve permitir a solicitação de CRUD de
        hotéis, quartos, hóspedes ou reservas.
        @param email A chave de identificação do usuário logado.
        */
        virtual void executar(Email) = 0;
        /**
        @brief Destrutor virtual padrão.
        */
        virtual void ~IA_Reservas(){}
};

#endif // INTERFACES_H_INCLUDED
