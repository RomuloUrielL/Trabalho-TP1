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
    virtual bool lerGerente(Gerente&) = 0;
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
    @param gerente Objeto da classe entidade Gerente para ser excluido.
    @return true caso o email os dados do gerente sejam excluidos com sucesso e
    false caso a conta do gerente não consiga ser excluída com sucesso.
    */
    virtual bool descadastrarGerente(Gerente) = 0;
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
        /**
        @brief Serviço relacionado a criação de um hotel no sistema.
        @param hotel Objeto da classe entidade Hotel contendo um nome, endereço,
        telefone e código fornecidos para a criação de um hotel.
        @return true caso o hotel seja criado com sucesso e false caso o hotel
        não seja criado.
        */
        bool virtual criarHotel(Hotel) = 0;
        /**
        @brief Serviço relacionando a leitura de um hotel armazenado no sistema.
        @param hotel Endereço de memória de um objeto da classe entidade Hotel
        fornecido para leitura dos dados do hotel.
        @return true caso a leitura consiga ser feita e false caso a leitura não
        consiga ser feita com sucesso.
        */
        bool virtual lerHotel(Hotel&) = 0;
        /**
        @brief Serviço relacionado a edição dos dados de um hotel armazenado no
        sistema.
        @param hotel Objeto da classe entidade Hotel contendo um nome, endereço,
        telefone e código fornecidos para a edição de um hotel.
        @return true caso a edição dos dados do hotel seja feita com sucesso e
        false caso a edição dos dados do hotel não seja feito com sucesso.
        */
        bool virtual editarHotel(Hotel) = 0;
        /**
        @brief Serviço relacionado a exclusão de hotéis armazenados no sistema.
        @param hotel Objeto da classe entidade Hotel contendo um nome, endereço,
        telefone e código fornecidos para a exclusão de um hotel.
        @return true caso o hotel seja excluido com sucesso e false caso o hotel
        não seja excluído com sucesso.
        */
        bool virtual excluirHotel(Hotel) = 0;

        /**
        @brief Serviço relacionado a criação de reservas no sistema.
        @param reserva Objeto da classe entidade Reserva contendo uma data de
        chegada, uma data de partida, valor da reserva e código da reserva a ser
        criado.
        @return true caso a reserva seja criada com sucesso e false caso a
        reserva não seja criada com sucesso.
        */
        bool virtual criarReserva(Reserva) = 0;
        /**
        @brief Serviço relacionado a leitura de uma reserva armazenada no
        sistema.
        @param reserva Endereço de memória de um Objeto da classe entidade
        Reserva fornecido para a leitura dos dados da reserva.
        @return true caso a leitura dos dados sejam feitas com sucesso e false
        caso a leitura dos dados não consiga ser realizada com sucesso.
        */
        bool virtual lerReserva(Reserva&) = 0;
        /**
        @brief Serviço relacionado a edição da dados de reservas armazenados no
        sistema.
        @param reserva Objeto da classe entidade Reserva contendo uma data de
        chegada, uma data de partida, valor da reserva e código da reserva a ser
        editado.
        @return true caso os dados da reserva sejam editados com sucesso e false
        caso os dados da reserva não consigam ser editados com sucesso.
        */
        bool virtual editarReserva(Reserva) = 0;
        /**
        @brief Serviço relacionado a exclusão de dados de reservas armazenados
        no sistema.
        @param reserva Objeto da classe entidade Reserva contendo uma data de
        chegada, uma data de partida, valor da reserva e código da reserva a ser
        excluido.
        @return true caso a reserva consiga ser excluída com sucesso false caso
        a reserva não seja excluída com sucesso.
        */
        bool virtual excluirReserva(Reserva) = 0;

        /**
        @brief Serviço relacionado a criação de um hóspede dentro do sistema do
        hotel.
        @param hospede Objeto da classe entidade Hospede contendo um nome,
        email, endereco e cartão a ser criado.
        @return true caso o hóspede seja adicionado ao sistema com sucesso e
        false caso o hóspede não seja adicionado ao sistema.
        */
        bool virtual criarHospede(Hospede) = 0;
        /**
        @brief Serviço relacionado a leitura dos dados de um hóspede armazenado
        no sistema do hotel.
        @param hospede Endereço de memória de um objeto da classe entidade
        Hospede fornecido para a leitura dos dados armazenados no sistema do
        hotel.
        @return
        */
        bool virtual lerHospede(Hospede&) = 0;
        /**
        @brief Serviço relacionado a edição dos dados de um hóspede armazenado
        no sistema do hotel.
        @param hospede Objeto da classe entidade Hospede contendo um nome,
        email, endereco e cartão a ser editado.
        @return true caso os dados do hóspede sejam editados com sucesso e false
        caso os dados do hóspede não consigam ser editados.
        */
        bool virtual editarHospede(Hospede) = 0;
        /**
        @brief Serviço relacionado a exclusão de um hóspede armazenado no
        sistema do hotel.
        @param hospede Objeto da classe entidade Hospede contendo um nome,
        email, endereco e cartão a ser excluido.
        @return true caso o hóspede seja excluído com sucesso e false caso o
        hóspede não seja excluído com sucesso.
        */
        bool virtual excluirHospede(Hospede) = 0;

        /**
        @brief Serviço relacionado a criação de um quarto dentro do sistema do
        hotel.
        @param quarto Objeto da classe entidade Quarto contendo  um número,
        capacidade, diária e ramal do quarto a ser criado.
        @return true caso o quarto seja criado com sucesso e false caso o quarto
        não seja criado.
        */
        bool virtual criarQuarto(Quarto) = 0;
        /**
        @brief Serviço relacionado a leitura dos dados de um quarto armazenado
        dentro do sistema do hotel.
        @param quarto Endereço de memória de um objeto da classe entidade Quarto
        fornecido para a leitura dos dados armazenados no sistema do hotel.
        @return true caso os dado do quarto consigam ser lidos com sucesso e
        false caso os dados do quarto não consigam ser lidos.
        */
        bool virtual lerQuarto(Quarto&) = 0;
        /**
        @brief Serviço relacionado a edição dos dados de um quarto armazenado no
        sistema do hotel.
        @param quarto Objeto da classe entidade Quarto contendo  um número,
        capacidade, diária e ramal do quarto a ser editado.
        @return true caso os dados do quarto consigam ser editados com sucesso e
        false caso os dados do quarto não consigam ser editados.
        */
        bool virtual editarQuarto(Quarto) = 0;
        /**
        @brief serviço relacionado a exclusão de um quarto do sistema do hotel.
        @param quarto Objeto da classe entidade Quarto contendo  um número,
        capacidade, diária e ramal do quarto a ser excluído.
        @return true caso o quarto seja excluido com sucesso e false caso o
        quarto não seja excluído do sistema do hotel.
        */
        bool virtual excluirQuarto(Quarto) = 0;

        /**
        @brief Serviço relacionado a listagem dos hotéis armazenados no sistema
        de hotéis.
        @param hoteis Vetor que será preenchido com os objetos da classe
        entidade Hotel encontrados no sistema.
        @return true caso os hotéis consigam ser listados com sucesso e false
        caso a listagem de hotéis não seja feita com sucesso.
        */
        virtual bool listarHotel(std::vector<Hotel>&) = 0;
        /**
        @brief Serviço relacionado a listagem das reservas de determinado hotel
        no sistema de hotéis.
        @param hotel Endereço de memória de um objeto da classe entidade Hotel
        no qual se deseja listar as reservas.
        @param reservas Vetor que será preenchido com os objetos da classe
        entidade Reserva encontrados no sistema.
        @return true caso as reservas consigam ser listadas com sucesso e false
        caso a listagem de reservas não seja feita com sucesso.
        */
        virtual bool listarReservasDoHotel(const Hotel&, vector<Reserva>&) = 0;
        /**
        @brief serviço relacionado a listagem dos hóspedes de determinado hotel
        armazenados no sistema de hotéis.
        @param hotel Endereço de memória de um objeto da classe entidade Hotel
        no qual se deseja listar os hóspedes.
        @param hospedes Vetor que será preenchido com os objetos da classe
        entidade Hospede encontrados no sistema.
        @return true caso os hospedes consigam ser listados com sucesso e false
        caso a listagem de hóspedes do botel não seja feita com sucesso.
        */
        virtual bool listarHospedesDoHotel(const Hotel&, vector<Hospede>&) = 0;
        /**
        @brief Serviço relacionado a listagem do quartos de determinado hotel
        armazenados no sistema de hotéis.
        @param hotel Endereço de memória de um objeto da classe entidade Hotel
        no qual se deseja listar os quartos.
        @param quartos Vetor que será preenchido com os objetos da classe
        entidade Quarto encontrados no sistema.
        @return true caso os quartos do hotel consigam ser listados com sucesso
        e false caso a listagem dos quartos do hotel não seja feita com sucesso.
        */
        virtual bool listarQuartosDoHotel(const Hotel&, vector<Quarto>&) = 0;

        /**
        @brief Destrutor virtual padrão.
        */
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
        @brief Método para estabelecer ligação (link) com a controladora de
        serviço.
        @param is_reservas Ponteiro para objeto da Interface da camada de
        serviço relacionada ao sistema de reservas.
        */
        virtual void setCntrIS_Reservas(IS_Reservas*) = 0;
        /**
        @brief Destrutor virtual padrão.
        */
        virtual ~IA_Reservas(){}
};

#endif // INTERFACES_H_INCLUDED
