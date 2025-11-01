#ifndef INTERFACES_HPP_INCLUDED
#define INTERFACES_HPP_INCLUDED

#include "dominios.hpp"
#include "entidades.hpp"

/*
@brief Interface respons�vel por prover os servi�os ao m�dulo inicializa��o para
autentica��o de usu�rios do sistema.
@details � implementada pelo M�dulo Apresenta��o-Autentica��o e solicitada pelo
M�dulo Apresenta��o-Inicializa��o para validar um usu�rio no sistema.
*/
class IA_Autenticacao{
    public:
    virtual bool autenticar(Email&) = 0;
};

class IA_Pessoal{
    public:
    virtual void criar() = 0;
    //modificar o retorno da fun��o executar porque pode dar problema caso o
    //usu�rio apague a pr�pia conta.
    virtual void executar(Email) = 0;
};

#endif // INTERFACES_HPP_INCLUDED
