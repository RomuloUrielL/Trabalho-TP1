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
@brief Controladora da Camada de Apresentação responsável pelo gerenciamento de Pessoal (Gerentes e Hóspedes).
@details Implementa a interface IA_Pessoal e se comunica com a IS_Pessoal.
*/
//class CntrIUPessoal : public IA_Pessoal {
//    private:
//        IS_Pessoal *cntrIS_Pessoal;
//    public:
//        /**
//        @brief Realiza o cadastro de um novo Gerente (Sign Up).
//        */
//        void criar() override;
//
//        /**
//        @brief Executa o menu de gerenciamento de usuários (CRUD de Gerente e Hóspede).
//        @param email O email do usuário logado.
//        */
//        void executar(Email) override;
//
//        /**
//       @brief Linka com a camada de serviço.
//        */
//        void setCntrIS_Pessoal(IS_Pessoal*);
//};
//
//inline void CntrIUPessoal::setCntrIS_Pessoal(IS_Pessoal *cntrIS_Pessoal){
//    this->cntrIS_Pessoal = cntrIS_Pessoal;
//}


#endif // CONTROLADORAS_H_INCLUDED
