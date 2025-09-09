#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <string>

using namespace std;

class Capacidade{
    private:
        static const int limiteMin = 1, limiteMax = 4;
        int capacidade;
        bool validarCapacidade(int);
    public:
        bool setCapacidade(int);
        int getCapacidade();
};

inline int Capacidade::getCapacidade(){
    return capacidade;
}

class Dinheiro{
    private:
        static const double limiteMin, limiteMax;
        double dinheiro;
        bool validarDinheiro(double);
    public:
        bool setDinheiro(double);
        double getDinheiro();
};

inline double Dinheiro::getDinheiro(){
    return dinheiro;
}

class Ramal{
    private:
        static const int valorMax = 50, valorMin = 0;
        string ramal;
        bool validarRamal(string);
    public:
        bool setRamal(string);
        string getRamal();
};

inline string Ramal::getRamal(){
    return ramal;
}

class Numero{
    private:
        static const int valorMin = 1, valorMax = 999;
        string numero;
        bool validarNumero(string);
    public:
        bool setNumero(string);
        string getNumero();
};

inline string Numero::getNumero(){
    return numero;
}

class Telefone{
    private:
        string telefone;
        bool validarTelefone(string);
    public:
        bool setTelefone(string);
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
