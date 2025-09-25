#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <string>

using namespace std;

/**
*@brief Classe domínio que representa a capacidade de um quarto.
*@details Armazena um inteiro e garante que a capacidade do quarto esteja entre 1 e 4.
*/

class Capacidade{
    private:
        static const int limiteMin = 1, limiteMax = 4;
        int capacidade;
        void validarCapacidade(int);
    public:
        /**
            @brief Define a capacide do quarto.
            @details Armazena um inteiro. Lança exceção caso o usuário digite uma entrada inválida com letras ou números menores que 1 ou maiores que 4.
            @param capacidade Valor inteiro a ser atribuido (entre 1 e 4).
        */
        void setCapacidade(int);
        /**
            @brief Retorna a capacidade armazenada.
            @return Valor da capacidade (inteiro).
        */
        int getCapacidade();
};

inline int Capacidade::getCapacidade(){
    return capacidade;
}

/**
    @brief Classe domínio que representa o dinheiro.
    @details Armazena um double e garante que o dinheito esteja dentro da faixa esperada (0.01 e 1000000.00).
*/

class Dinheiro{
    private:
        static const double limiteMin, limiteMax;
        double dinheiro;
        void validarDinheiro(double);
    public:
        /**
            @brief Define o dinheiro.
            @details Armazena um Double. lança um exceção caso o usuário digite um valor fora da faixa esperada.
            @param dinheiro Valor double a ser atribuído (entre 0.01 e 1000000.00).
        */
        void setDinheiro(double);
        /**
            @brief Retorna o dinheiro armazenado.
            @return Valor do dinheito (double).
        */
        double getDinheiro();
};

inline double Dinheiro::getDinheiro(){
    return dinheiro;
}

class Ramal{
    private:
        static const int valorMax = 50, valorMin = 0;
        string ramal;
        void validarRamal(string);
    public:
        void setRamal(string);
        string getRamal();
};

inline string Ramal::getRamal(){
    return ramal;
}

class Numero{
    private:
        static const int valorMin = 1, valorMax = 999;
        string numero;
        void validarNumero(string);
    public:
        void setNumero(string);
        string getNumero();
};

inline string Numero::getNumero(){
    return numero;
}

class Telefone{
    private:
        string telefone;
        void validarTelefone(string);
    public:
        void setTelefone(string);
        string getTelefone();
};

inline string Telefone::getTelefone(){
    return telefone;
}

class Data{
    private:
        string data;
        bool validarData(string);
    public:
        bool setData(string);
        string getData();
};

inline string Data::getData(){
    return data;
}

class Codigo{
    private:
        string codigo;
        bool validarCodigo(string);
    public:
        bool setCodigo(string);
        string getCodigo();
};

inline string Codigo::getCodigo(){
    return codigo;
}

class Cartao{
    private:
        string cartao;
        bool validarCartao(string);
    public:
        bool setCartao(string);
        string getCartao();
};

inline string Cartao::getCartao(){
    return cartao;
}

class Senha{
    private:
        string senha;
        bool validarSenha(string);
    public:
        bool setSenha(string);
        string getSenha();
};

inline string Senha::getSenha(){
    return senha;
}

class Nome{
    private:
        static const int limiteMin = 5, limiteMax = 30;
        string nome;
        bool validarNome(string);
    public:
        bool setNome(string);
        string getNome();
};

inline string Nome::getNome(){
    return nome;
}

class Email{
    private:
        static const int limiteMin = 1, limiteMax_Local = 64, limiteMax_Dominio = 255;
        string email;
        bool validarEmail(string);
    public:
        bool setEmail(string);
        string getEmail();
};

inline string Email::getEmail(){
    return email;
}

class Endereco{
    private:
        static const int limiteMin = 5, limiteMax = 30;
        string endereco;
        bool validarEndereco(string);
    public:
        bool setEndereco(string);
        string getEndereco();
};

inline string Endereco::getEndereco(){
    return endereco;
}

#endif
