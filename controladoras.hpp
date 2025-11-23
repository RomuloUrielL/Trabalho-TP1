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
        @details Este método entra em um loop solicitando Email e Senha ao
        usuário. Ele trata exceções de formato lançadades pelos métodos validar
        das classes domínios e, após serem validados os formatos, repassa para
        o método autenticar da camada de serviço.
        @param email Referência para um objeto da classe dompinio Email. Se a
        autenticação ocorrer com sucesso o objeto é preenchido com o email do
        usuário autenticado.
        @return true caso o email seja autenticado com sucesso e false caso o
        email não consiga ser autenticado com sucesso.
        */
        bool autenticar(Email&) override;
        /**
        @brief Responsável por criar o link com a camada de serviço. Implementa
        a relação de dependência da arquitetura do sistema.
        @param Ponteiro para um objeto que implemente a interface Serviço
        Autenticação.
        */
        void setCntrSAutenticacao(IS_Autenticacao*);
};

void inline CntrIUAutenticacao::setCntrSAutenticacao(IS_Autenticacao *cntrServicoAutenticacao){
        this->cntrServicoAutenticacao = cntrServicoAutenticacao;
}
/**
@brief Controladora da camada de Apresentação responsável pela interface com
usuário do subsistema de reservas.
@details Esta classe implementa a Interface Apresentação Reservas. Tem o
objetivo de servir como intermediária entre o usuário e a camada de serviço com
as funcionalidades relacionadas a reservas.
*/
class CntrIUReservas : public IA_Reservas{
    private:
        IS_Reservas *cntrIS_Reservas;
    public:
        /**
        @brief Executa o fluxo de interação com o usuário para o módulo de
        Reservas.
        @details Este método apresenta um menu de opções permitindo ao usuário
        selecionar entre operações de CRUD e listagem. O método entra em um loop
        que só termina quando o usuário seleciona a opção de voltar (0). Durante
        a execução, este método coleta os dados de entrada, valida o formato e
        chama os métodos na controladora de serviço.
        @param email O email do usuário atualmente logado no sistema.
        */
        void executar(const Email);
        /**
        @brief Estabelece a ligação com a controladora da camada de serviço.
        @details Implementa o padrão de Dependência da Interface da camada de
        apresentação para a camada de serviços.
        @param cntrIS_Reservas Ponteiro para um objeto que implementa a
        interface IS_Reservas.
        */
        void setCntrIS_Reservas(IS_Reservas*);
};

inline void CntrIUReservas::setCntrIS_Reservas(IS_Reservas *cntrIS_Reservas){
    this->cntrIS_Reservas = cntrIS_Reservas;
}


//-----------------------------code do augusto(falta formatar algumas coisas)---------------------------------//
/**
@brief Controladora da Camada de Apresentação responsável pelo gerenciamento de
Pessoal (Gerentes e Hóspedes).
@details Implementa a interface IA_Pessoal e se comunica com a IS_Pessoal.
*/
class CntrIUPessoal : public IA_Pessoal {
    private:
        IS_Pessoal *cntrIS_Pessoal;
    public:
        /**
        @brief Realiza o cadastro de um novo Gerente (Sign Up).
        */
        void criar() override;

        /**
        @brief Executa o menu de gerenciamento de usuários (CRUD de Gerente e Hóspede).
        @param email O email do usuário logado.
/       */
        void executar(Email) override;

        /**
        @brief Linka com a camada de serviço.
        */
        void setCntrIS_Pessoal(IS_Pessoal*);
};

inline void CntrIUPessoal::setCntrIS_Pessoal(IS_Pessoal *cntrIS_Pessoal){
    this->cntrIS_Pessoal = cntrIS_Pessoal;
}

/**
@brief Controladora da camada de serviço responsável pela lógica de negócio e
armazenamento de dados de entrada.
@details Esta classe implementa a Interface Serviço Reservas. Tem o
objetivo de implementar a lógica de negócio do sistema com base no
relacionamento entre os objetos do sistema e também armazenamento dos dados em
containeres.
*/
class CntrISReservas : public IS_Reservas{
    public:

    /**
    @brief Solicita a criação de um novo hotel no sistema.
    @details Este método armazena o objeto em container.
    Antes de criar, o container verifica se já existe um hotel com o mesmo
    código para evitar duplicidade.
    @param hotel Objeto contendo os dados do hotel a ser criado.
    @return true se o hotel foi cadastrado com sucesso. false se já existir um
    hotel com o mesmo código.
    */
    bool criarHotel(Hotel hotel) override;
    /**
    @brief Recupera os dados de um hotel a partir do seu código.
    @details Busca no container de hoteis usando o código fornecido no objeto.
    Se encontrado, preenche o objeto passado por referência com os dados
    completos.
    @param[in,out] hotel Referência para um objeto Hotel.
    @return true se o hotel foi encontrado.false se o código não corresponde a
    nenhum hotel cadastrado.
    */
    bool lerHotel(Hotel& hotel) override;
    /**
    @brief Atualiza os dados de um hotel existente.
    @details Substitui os dados do hotel no container de hoteis. A busca é feita
    pelo código do hotel.
    @param hotel Objeto contendo o código do hotel a ser editado e os novos
    dados.
    @return true se a atualização foi realizada com sucesso. false se o hotel
    não foi encontrado.
    */
    bool editarHotel(Hotel hotel) override;
    /**
    @brief Remove um hotel e todos os seus dados associados do sistema.
    @details Implementa a regra de negócio de Exclusão em Cascata:
    1. Remove todas as Reservas associadas a este hotel.
    2. Remove todos os Hóspedes associados a este hotel.
    3. Remove todos os Quartos associados a este hotel.
    4. Por fim, remove o Hotel do container.
    @param hotel Objeto contendo o código do hotel a ser excluído.
    @return true se o processo de exclusão foi concluído com sucesso. false se o
    hotel não foi encontrado.
    */
    bool excluirHotel(Hotel hotel) override;
    /**
    @brief Lista todos os hotéis cadastrados no sistema.
    @details Recupera todos os registros armazenados no container de hotéis.
    @param[out] hoteis Vetor que será limpo e preenchido com a lista de hotéis.
    @return true se a operação de listagem foi bem-sucedida falso caso
    contrário.
    */
    bool listarHotel(vector<Hotel>& hoteis) override;

    /**
    @brief Solicita a criação de uma nova reserva no sistema.
    @details Este método armazena o objeto em container.
    Antes de criar, o container verifica se já existe um hotel com o mesmo
    código para evitar duplicidade.
    @param hotel Objeto contendo os dados do hotel a ser criado.
    @return true se o hotel foi cadastrado com sucesso. false se já existir um
    hotel com o mesmo código.
    */
    bool criarReserva(Reserva reserva) override;
    /**
    @brief Recupera os dados de uma reserva.
    @details Busca no container de reservas utilizando o código da reserva.
    @param reserva Referência para o objeto. Deve conter o código para busca.
    Ao final, será preenchido com os dados completos da reserva.
    @return true se a reserva foi encontrada false caso contrário.
    */
    bool lerReserva(Reserva& reserva) override;
    /**
    @brief Atualiza os dados de uma reserva existente.
    @details Permite alterar datas ou valor. A validação de conflito de datas
    deve ser considerada.
    @param reserva Objeto com os dados atualizados.
    @return true se atualizado com sucesso, false se não encontrado.
    */
    bool editarReserva(Reserva reserva) override;
    /**
    @brief Remove uma reserva do sistema.
    @details Apenas remove o registro do conteiner de reservas, liberando o
    quarto e o hóspede para outras operações.
    @param reserva Objeto contendo o código da reserva a ser excluída.
    @return true se removido com sucesso, false se não encontrado.
    */
    bool excluirReserva(Reserva reserva) override;
    /**
    @brief Lista todas as reservas associadas a um hotel específico.
    @details Utiliza o vínculo com código de hotel presente em cada reserva para
    filtrar os resultados do container de reservas.
    @param hotel Objeto Hotel que serve como filtro.
    @param reservas Vetor que será preenchido com as reservas encontradas.
    @return true se a busca foi realizada com sucesso, false caso contrário.
    */
    bool listarReservasDoHotel(const Hotel& hotel, vector<Reserva>& reservas) override;

    /**
    @brief Cadastra um novo hóspede no sistema.
    @details Armazena no container de hóspedes. O email é usado como
    chave única.
    @param hospede Objeto contendo nome, email, endereço e cartão.
    @return true se cadastrado false se o email já estiver em uso.
    */
    bool criarHospede(Hospede hospede) override;
    /**
    @brief Busca os dados de um hóspede pelo email.
    @param hospede Objeto contendo o email para busca. Será preenchido
    com os demais dados se encontrado.
    @return true se encontrado, false caso contrário.
    */
    bool lerHospede(Hospede& hospede) override;
    /**
    @brief Atualiza os dados cadastrais de um hóspede.
    @details O email (chave primária) não pode ser alterado.
    @param hospede Objeto com os dados novos.
    @return true se sucesso false se não encontrado.
    */
    bool editarHospede(Hospede hospede) override;
    /**
    @brief Tenta excluir um hóspede do sistema.
    @details Verifica se o hóspede possui alguma reserva ativa no container de
    reservas. Se tiver, a exclusão é bloqueada para manter a integridade do
    sistema.
    @param hospede Objeto contendo o email do hóspede a ser excluído.
    @return true se excluído com sucesso. false se o hóspede possuir reservas
    pendentes ou não for encontrado.
     */
    bool excluirHospede(Hospede hospede) override;
    /**
    @brief Lista os hóspedes que possuem vínculo com um hotel.
    @param hotel Hotel usado para filtro.
    @param hospedes Vetor de saída.
    @return true se sucesso false casso não seja possível listar os hóspedes.
    */
    bool listarHospedesDoHotel(const Hotel& hotel, vector<Hospede>& hospedes) override;

    /**
    @brief Cria um novo quarto vinculado a um hotel.
    @details É pedido o código do hotel ao qual este quarto pertence para
    garantir a consistência da composição.
    @param quarto Objeto da classe entidade quarto.
    @return true se criado, false se o número já existir.
    */
    bool criarQuarto(Quarto quarto) override;
    /**
    @brief Busca os dados de um quarto pelo seu número.
    @param quarto Referência contendo o número para busca.
    @return true se encontrado, false caso contrário.
    */
    bool lerQuarto(Quarto& quarto) override;
    /**
    @brief Atualiza as informações de um quarto.
    @param quarto Objeto com os dados atualizados.
    @return true se sucesso, false se não encontrado.
    */
    bool editarQuarto(Quarto quarto) override;
    /**
    @brief Remove um quarto do sistema.
    @details Verifica se o quarto possui reservas. Se estiver reservado, a
    exclusão é bloqueada.
    @param quarto Objeto contendo o número do quarto.
    @return true se excluído, false se estiver reservado ou não existir.
    */
    bool excluirQuarto(Quarto quarto) override;
    /**
    @brief Lista todos os quartos pertencentes a um hotel específico.
    @details Filtra o container de quartos comparando o código do hotel
    armazenado em cada quarto com o código do hotel fornecido.
    @param hotel Hotel filtro.
    @param quartos Vetor preenchido com os quartos daquele hotel.
    @return true se sucesso false caso erro.
    */
    bool listarQuartosDoHotel(const Hotel& hotel, vector<Quarto>& quartos) override;

};

class CntrApresentacaoInicial {
    private:
        IA_Autenticacao *cntrApresentacaoAutenticacao;
        IA_Pessoal *cntrApresentacaoPessoal;
        IA_Reservas *cntrApresentacaoReservas;
    public:

        void executar();

        void setCntrApresentacaoAutenticacao(IA_Autenticacao*);

        void setCntrApresentacaoPessoal(IA_Pessoal*);

        void setCntrApresentacaoReservas(IA_Reservas*);
};

inline void CntrApresentacaoInicial::setCntrApresentacaoAutenticacao(IA_Autenticacao* cntr){
    cntrApresentacaoAutenticacao = cntr;
}

inline void CntrApresentacaoInicial::setCntrApresentacaoPessoal(IA_Pessoal* cntr){
    cntrApresentacaoPessoal = cntr;
}

inline void CntrApresentacaoInicial::setCntrApresentacaoReservas(IA_Reservas* cntr){
    cntrApresentacaoReservas = cntr;
}

class CntrISPessoal : public IS_Pessoal{
    public:

        bool criarGerente(Gerente gerente) override;
        bool lerGerente(Gerente& gerente) override;
        bool atualizarGerente(Gerente gerente) override;
        bool descadastrarGerente(Gerente gerente) override;
};
#endif // CONTROLADORAS_H_INCLUDED
