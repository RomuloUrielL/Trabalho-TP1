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

#endif
