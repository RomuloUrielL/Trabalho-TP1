#ifndef INTERFACES_HPP_INCLUDED
#define INTERFACES_HPP_INCLUDED

#include "dominios.hpp"
#include "entidades.hpp"

/*
@brief Interface responsável por prover os serviços ao módulo inicialização para
autenticação de usuários do sistema.
@details É implementada pelo Módulo Apresentação-Autenticação e solicitada pelo
Módulo Apresentação-Inicialização para validar um usuário no sistema.
*/
class IA_Autenticacao{
    public:
    virtual bool autenticar(Email&) = 0;
};

class IA_Pessoal{
    public:
    virtual void criar() = 0;
    //modificar o retorno da função executar porque pode dar problema caso o
    //usuário apague a própia conta.
    virtual void executar(Email) = 0;
};

#endif // INTERFACES_HPP_INCLUDED
