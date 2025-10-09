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

class TUCartao{
    private:
        static const string VALOR_VALIDO;
        static const string VALOR_INVALIDO;
        Cartao *cartao;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
        void testarCenarioValorInvalido();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();

};

class TURamal{
    private:
        static const string VALOR_VALIDO;
        static const string VALOR_INVALIDO;
        Ramal *ramal;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
        void testarCenarioValorInvalido();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

class TUTelefone{
    private:
        static const string VALOR_VALIDO;
        static const string VALOR_INVALIDO;
        Telefone *telefone;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
        void testarCenarioValorInvalido();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

class TUNumero{
    private:
        const static string VALOR_VALIDO;
        const static string VALOR_INVALIDO;
        Numero *numero;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
        void testarCenarioValorInvalido();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();

};




#endif // TESTES_HPP_INCLUDED
