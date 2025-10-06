#ifndef TESTES_HPP_INCLUDED
#define TESTES_HPP_INCLUDED

#include <stdexcept>

#include "dominios.hpp"

using namespace std;

class TUCapacidade{
    private:
        const static int VALOR_VALIDO = 2;
        const static int VALOR_INVALIDO = 5;
        Capacidade *capacidade;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
        void testarCenarioValorInvalido();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = - 1;
        int run();
};



#endif // TESTES_HPP_INCLUDED
