#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

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
        static const int valorMax = 50;
        int ramal;
        bool validarRamal(int);
    public:
        bool setRamal(int);
        double getRamal();
};

inline int Ramal::getRamal(){
    return ramal;
}


#endif // DOMINIOS_HPP_INCLUDED
