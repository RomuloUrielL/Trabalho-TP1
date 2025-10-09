#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <string>

using namespace std;

/**
@class Capacidade
*@brief Classe domínio que representa o limite da quantidade de pessoas em um
quarto.
*@details Armazena um short e garante que a capacidade do quarto esteja entre
1 e 4.
*/
class Capacidade{
    private:
        static const short limiteMin = 1, limiteMax = 4;
        unsigned short capacidade;
        void validarCapacidade(unsigned short);
    public:
        /**
            @brief Define a capacidade do quarto.
            @details Armazena um short e, ou valida a capacidade ou lança
            exceção.
            @throw out_of_range com a mensagem "Capacidade invalida, digite um
            valor entre 1 e 4" caso o usuário digite uma entrada com valores
            menores que 1 ou valores maiores que 4.
            @param capacidade Valor inteiro a ser atribuido (entre 1 e 4).
        */
        void setCapacidade(unsigned short);
        /**
            @brief Retorna a capacidade armazenada.
            @return **short** Valor da capacidade armazenada.
        */
        int getCapacidade();
};

inline int Capacidade::getCapacidade(){
    return capacidade;
}

/**
@class Dinheiro
@brief Classe domínio que representa uma quantidade de valor monetário em
determinada moeda.
@details Armazena um inteiro para evitar erros de arredondamentos e garante que
o dinheiro esteja dentro da faixa esperada (0.01 e 1000000.00).
*/
//Dar manutençao na classe para terminar a documentação da classe!!!
class Dinheiro{
    private:
        static const double limiteMin, limiteMax;
        double dinheiro;
        void validarDinheiro(double);
    public:
        /**
            @brief Define o dinheiro.
            @details Armazena um inteiro. Valida o dinheiro ou lança uma exceção
             caso o usuário digite um valor inválido.
            @throw out_of_range com a mensagem "Dinheiro invalido, digite um
            valor entre 0.01 e 1000000.00" caso o usuário digite um valor fora
            da faixa 0.01 e 1000000.00.
            @param dinheiro Valor inteiro a ser atribuído (entre 0.01 e
            1000000.00).
        */
        void setDinheiro(double);
        /**
            @brief Retorna o dinheiro armazenado.
            @return **int** Valor do dinheiro armazenado.
        */
        double getDinheiro();
};

inline double Dinheiro::getDinheiro(){
    return dinheiro;
}

/**
@class Ramal
@brief Classe domínio que representa uma linha telefonica usada para comunicação
interna de um hotel.
@details Armazena uma string e garante que a string recebida possua dois dígitos
e esteja entre 00 e 50.
*/
class Ramal{
    private:
        static const int valorMax = 50, valorMin = 0, lenght = 2;
        string ramal;
        void validarRamal(string);
    public:
        /**
        @brief Define o ramal.
        @details Armazena uma string. Valida o ramal ou lança uma exceção caso o
        usuário digite um valor inválido.
        @throw lenght_error com a mensagem "Comprimento invalido! digite um
        número com 2 algarismos." caso o usuário digite um valor que seja
        diferente de dois dígitos.
        @throw invalid_argument com a mensagem "Caracteres invalidos! digite
        apenas numeros." caso o usuário não digite apenas números.
        @throw out_of_range com a mensagem "Ramal invalido! digite um ramal
        entre 00 e 50." caso o ramal digitado seja menor que 00 ou maior que 50.
        @param ramal String a ser atribuida (entre 00 e 50).
        */
        void setRamal(string);
        /**
        @brief Retorna o ramal armazenado.
        @return **string** Valor do ramal armazenado.
        */
        string getRamal();
};

inline string Ramal::getRamal(){
    return ramal;
}

/**
@class Numero
@brief Classe dominio que representa a localização de um quarto no hotel com seu
andar e número do quarto no andar.
@details Armazena uma string e garante que a string recebida possua 3 dígitos e
esteja entre 001 e 999;
*/
class Numero{
    private:
        static const int valorMin = 1, valorMax = 999, length = 3;
        string numero;
        void validarNumero(string);
    public:
        /**
        @brief Define o numero.
        @details Armazena uma string. Valida um número ou lança um exceção caso
        o usuário digite um valor inválido.
        @throw lenght_error com a mensagem "Comprimento invalido! digite um
        número com 3 dígitos." caso o usuário digite um valor que não possua 3
        dígitos.
        @throw invalid_argument "Caracteres invalidos! digite apenas numeros."
        caso o usuário não digite apenas números.
        @throw out_of_range com a mensagem "Numero fora da faixa! digite um
        valor entre 001 e 999." caso o valor esteja fora da faixa esperada.
        @param numero em string a ser atribuido (entre 001 e 999).
        */
        void setNumero(string);
        /**
        @brief Retorna o numero armazenado.
        @return **string** numero de quarto armazenado.
        */
        string getNumero();
};

inline string Numero::getNumero(){
    return numero;
}

/**
@class Telefone
@brief Classe dominio que armazena uma sequência de dígitos que identificam o
país e o estado do número, seguidos por uma sequência única de 9 dígitos.
@details Armazena uma string e garante que a string recebida inicie com + e seja
seguido por 14 números.
*/
class Telefone{
    private:
        static const int length = 15;
        string telefone;
        void validarTelefone(string);
    public:
        /**
        @brief Define o telefone.
        @details Armazena uma string. Valida o telefone ou lança exceção caso o
        usuário digite um telefone inválido.
        @throw lenght_error com a mensagem "Comprimento inválido ou sem prefixo
        '+', digite um telefone no formato +DDDDDDDDDDDDDD." caso o comprimento
        seja diferente de 15 ou não possua o '+'.
        @throw invalid_argument com a mensagem "Caracteres invalidos! Digite +
        seguido de 14 numeros." caso o usuário não digite apenas números.
        @param telefone String com o numero de telefone a ser armazenado.
        */
        void setTelefone(string);
        /**
        @brief Retorna o telefone armazenado.
        @return **string** telefone do hotel armazenado.
        */
        string getTelefone();
};

inline string Telefone::getTelefone(){
    return telefone;
}

/**
@class Data.
@brief Classe dominio que armazena uma sequência de caracteres que representam
um dia, um mês e um ano.
@details Armazena uma string e valida a data verificando a quantidade de dias do
mês e se o dia é valido, verifica se o mês está correto e também verifica se o
ano é bissexto permitindo que fevereiro tenha 29 dias.
*/
class Data{
    private:
        static const int length = 11;
        string data;
        bool validarData(string);
    public:
        /**
        @brief Define a Data.
        @details Armazena uma string. Valida a data ou lança exceção caso o
        usuário digite uma data inválida.
        @throw invalid_argument com a mensagem
        //continuar documentaçao!!!!!
         caso o usuário digite uma data com comprimento inválido ou não digite apenas números, lança exceção out_of_range caso o dia seja maior do que os números de dias que o mês possui.
        */
        bool setData(string);
        /**
        @brief Retorna a data armazenada.
        @return data Data armazenada.
        */
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
        void validarCartao(string);
    public:
        void setCartao(string);
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
