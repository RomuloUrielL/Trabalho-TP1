#include "dominios.hpp"

bool Capacidade::validarCapacidade(int capacidade){
    if(capacidade > limiteMax || capacidade < limiteMin){
        return false;
    }
    return true;
};

bool Capacidade::setCapacidade(int capacidade){
    if(!validarCapacidade(capacidade)){
        return false;
    }
    this->capacidade = capacidade;
    return  true;
};

const double Dinheiro::limiteMin = 0.01;
const double Dinheiro::limiteMax = 1000000.00;

bool Dinheiro::validarDinheiro(double dinheiro){
    if(dinheiro < limiteMin || dinheiro > limiteMax){
        return false;
    }
    return true;
};

bool Dinheiro::setDinheiro(double dinheiro){
    if(!validarDinheiro(dinheiro)){
        return false;
    }
    this->dinheiro = dinheiro;
    return true;
};
