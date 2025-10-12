#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <string>

using namespace std;

/**
@class Capacidade
*@brief Classe domínio que representa o limite da quantidade de pessoas em um
quarto.
*@details Armazena um short e garante que a capacidade do quarto esteja no
formato válido: (1, 2, 3 ou 4).
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
            @return Valor da capacidade armazenada.
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
o dinheiro esteja no formato válido: (0,01 a 1.000.000,00).
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
            @return Valor do dinheiro armazenado.
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
e esteja no formato válido: (00 a 50).
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
        @return Valor do ramal armazenado.
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
esteja no formato válido: (000 a 999).
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
        @return Numero de quarto armazenado.
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
seguido por 14 números. Formato válido: +DDDDDDDDDDDDDD D é dígito (0-9).
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
        @return Telefone do hotel armazenado.
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
ano é bissexto permitindo que fevereiro tenha 29 dias. Formato válido:
dia-mês-ano. Dia é número de 1 a 31. Mês é JAN, FEV, MAR, ABR, MAI, JUN, JUL,
AGO, SET, OUT, NOV ou DEZ. Ano é número de 2000 a 2999.
*/
class Data{
    private:
        static const int length = 11;
        string data;
        void validarData(string);
    public:
        /**
        @brief Define a Data.
        @details Armazena uma string. Valida a data ou lança exceção caso o
        usuário digite uma data inválida.
        @throw invalid_argument com a mensagem
        //continuar documentaçao!!!!!

        */
        void setData(string);
        /**
        @brief Retorna a data armazenada.
        @return Data armazenada.
        */
        string getData();
};

inline string Data::getData(){
    return data;
}

class Codigo{
    private:
        string codigo;
        void validarCodigo(string);
    public:
        void setCodigo(string);
        string getCodigo();
};

inline string Codigo::getCodigo(){
    return codigo;
}

/**
@brief Classe domínio usada para armazenar o número de identificação de um
cartão bancário.
@details Armazena uma cadeia de 16 caracteres com o número do cartão e valida o
número utilizando o algoritmo de Luhn para verificar a validade do número do
cartão através do dígito verificador. Formato válido: 16 dígitos e presença de
dígito verificador calculado segundo o algorítmo de Luhn.
*/
class Cartao{
    private:
        string cartao;
        void validarCartao(string);
    public:
        /**
        @brief Armazena o valor do número do cartão.
        @details Armazena o número do cartão em um cadeia de caracteres. Valida
        ou lança exceção caso o número digitado seja inválido.
        @throw lenght_error caso a quantidade de dígitos do cartão seja
        diferente de 16 dígitos numéricos.
        @throw invalid_argument caso o número do cartão digitado não seja
        válido, ou seja, o número não passou no teste do dígito verificador ou,
        não foram digitados apenas dígitos numéricos.
        @param cartao Valor que representa o número do cartão.
        */
        void setCartao(string);
        /**
        @brief Retorna o número de cartão armazenado.
        @return Cadeia de caracteres que representam o número do cartão.
        */
        string getCartao();
};

inline string Cartao::getCartao(){
    return cartao;
}

/**
@class Senha.
@brief Classe domínio usada para armazenar uma chave de acesso ao sistema.
@details Armazena uma cadeia de caracteres que representam uma senha que pode
ser usada para verificar a identidade de uma pessoa no sistema. Formato válido:
5 caracteres. Caracter pode ser letra (a-z ou A-Z), dígito (0-9) ou caracter
especial ( ! " # $ % & ? ); letra não pode ser seguida por letra, dígito não
pode ser seguido por dígito; existe pelo menos uma letra minúscula (a-z), uma
letra maiúscula (A-Z), um dígito (0-9) e um caracter especial.
*/
class Senha{
    private:
        string senha;
        void validarSenha(string);
    public:
        /**
        @brief Armazena a cadeia de caracteres que representam a senha.
        @details Armazena a senha. Valida o formato da senha ou lança exceção
        caso a senha digitada seja inválida.
        @throw lenght_error caso a senha não possua 5 caracteres.
        @throw invalid_argument caso a senha digitada não siga as regras de
        formatação da senha.
        @param senha Cadeia de caracteres que representam a senha a ser
        validada.
        */
        void setSenha(string);
        /**
        @brief Retorna a senha armazenada.
        @return Cadeia de caracteres que representam uma senha.
        */
        string getSenha();
};

inline string Senha::getSenha(){
    return senha;
}

/**
@class Nome.
@brief Classe domínio usada para armazenar e validar o nome de uma pessoa.
@details Armazena uma cadeia de caracteres que representam o nome de uma
pesosoas e valida o formato do nome. Formato válido: Texto com 5 a 20
caracteres. Cada caracter pode ser letra (a-z ou A-Z) ou espaço em branco;
primeiro caracter de cada termo é letra maiúscula (A-Z); espaço em branco é
seguido por letra; último caracter não pode ser espaço em branco.
*/
class Nome{
    private:
        static const int limiteMin = 5, limiteMax = 20;
        string nome;
        void validarNome(string);
    public:
        void setNome(string);
        string getNome();
};

inline string Nome::getNome(){
    return nome;
}

class Email{
    private:
        static const int limiteMin = 1, limiteMax_Local = 64, limiteMax_Dominio = 255;
        string email;
        void validarEmail(string);
    public:
        void setEmail(string);
        string getEmail();
};

inline string Email::getEmail(){
    return email;
}

class Endereco{
    private:
        static const int limiteMin = 5, limiteMax = 30;
        string endereco;
        void validarEndereco(string);
    public:
        void setEndereco(string);
        string getEndereco();
};

inline string Endereco::getEndereco(){
    return endereco;
}

#endif
