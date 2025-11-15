#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED
#include <vector>
#include "dominios.hpp"
#include "entidades.hpp"

using namespace std;
using std::vector;

/**
@brief Interface resposável por prover os serviços ao Modulo Apresentação
Autenticação para o susbsistema de acesso de usuários ao sistema.
@details É implementada pelo Módulo Serviços Autenticação e solicitada pelo
Módulo Apresentação Autenticação para validação de um usuário do sistema.
*/
class IS_Autenticacao {
public:
    /**
    @brief Serviço resposável por realizar a autenticação de um usuário por meio
    de email e senha.
    @param email Objeto da classe domínio Email contendo a cadeira de caracteres
    que representam um email fornecido para a autenticação.
    @param senha Objeto da classe domínio Senha contendo uma sequência de
    caracteres que representam uma senha de acesso ao sistema fornecida para a
    autenticação do usuário.
    @return True caso o usuário seja autenticado com sucesso e False caso o
    usuário não seja autenticado.
    */
    virtual bool autenticar(Email, Senha) = 0;
    /**
    @brief Destrutor virtual padrão.
    */
    virtual ~IS_Autenticacao(){}
};

/**
@brief Interface responsável por prover os serviços ao Módulo Apresententação
Pessoal para o subsistema de gerenciamento dos gerentes.
@details É implementada pelo Módulo Serviços Pessoal e solicitada pelo Módulo
Apresentação Pessoal para realizar o CRUD dos gerentes do sistema.
*/
class IS_Pessoal {
public:
    /**
    @brief Serviço relacionado a criação de um novo gerente no sistema.
    @param gerente Objeto da classe entidade Gerente contendo um nome, email,
    ramal e senha.
    @return True caso o gerente seja criando com sucesso e False caso o gerente
    não seja criado.
    */
    virtual bool criarGerente(Gerente) = 0;
    /**
    @brief Serviço relacionado a leitura de um gerente no sistema.
    @param email Endereço de memória do email do gerente a ser lido e
    disponibilizado para o usuário do sistema.
    @param gerente Endereço de memória do gerente a ser lido e disponibilizado
    para o usuário do sistema.
    @return true caso o gerente consiga ser lido com sucesso e false caso o
    gerente não consiga ser lido.
    */
    virtual bool lerGerente(Email&, Gerente&) = 0;
    /**
    @brief Serviço relacionado a atualização dos dados cadastrais do gerente
    como nome, email, ramal ou senha.
    @param gerente Objeto da classe entidade Gerente contendo um nome, email,
    ramal e senha.
    @return true caso os dados do gerente sejam atualizados com sucesso e false
    caso os dados do gerente não consigam ser atualizados com sucesso.
    */
    virtual bool atualizarGerente(Gerente) = 0;
    /**
    @brief Serviço relacionado a exclusão dos dados cadastrais de um gerente do
    sistema.
    @param email Objeto da classe domínio Email contendo a cadeira de caracteres
    que representam um email fornecido para a autenticação.
    @return true caso o email os dados do gerente sejam excluidos com sucesso e
    false caso a conta do gerete não consiga ser excluída com sucesso.
    */
    virtual bool descadastrarGerente(Email) = 0;
    /**
    @brief Destrutor virtual padrão.
    */
    virtual ~IS_Pessoal(){}
};

/**
@brief Interface responsável por prover os serviços ao Módulo Apresentação
Reservas para o  subsistema de gerenciamento das reservas do hotel.
@details É implementada pelo Módulo serviços Reservas e solicitada pelo Módulo
Apresentação Reservas. É responsável por realizar o CRUD de hoteis, reservas,
hóspedes e quartos e também listar hotes, reservas, hóspedes e quartos.
*/
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

        virtual bool listarHotel(std::vector<Hotel>& hoteis) = 0;
        virtual bool listarReservasDoHotel(const Hotel&, vector<Reserva>& reservas) = 0;
        virtual bool listarHospedesDoHotel(const Hotel&, vector<Hospede>& hospedes) = 0;
        virtual bool listarQuartosDoHotel(const Hotel&, vector<Quarto>& quartos) = 0;

        virtual ~IS_Reservas(){}
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
    virtual ~IA_Autenticacao(){}
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
    virtual ~IA_Pessoal(){}
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
        virtual ~IA_Reservas(){}
};

#endif // INTERFACES_H_INCLUDED
