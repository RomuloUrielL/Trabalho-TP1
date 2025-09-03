#include "dominios.hpp"
#include<cctype>

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

bool Ramal::validarRamal(string ramal){
    if(ramal.length() != 2){
        return false;
    }
    for(char c : ramal){
        if(!isdigit(c)){
            return false;
        }
    }
    int valor = stoi(ramal);
    if(valor >= valorMin && valor <= valorMax){
            return true;
    }
    return false;
};

bool Ramal::setRamal(string ramal){
    if(!validarRamal(ramal)){
        return false;
    }
    this->ramal = ramal;
    return true;
};

bool Numero::validarNumero(string numero){
    if(numero.length() != 3){
        return false;
    }
    for(char c : numero){
        if(!isdigit(c)){
            return false;
        }
    }
    int valor = stoi(numero);
    if(valor >= valorMin && valor <= valorMax){
            return true;
    }
    return false;
}

bool Numero::setNumero(string numero){
    if(!validarNumero(numero)){
        return false;
    }
    this->numero = numero;
    return true;
}

bool Telefone::validarTelefone(string telefone){
    if(telefone.length() != 15 || telefone[0] != '+'){
        return false;
    }
    for(int i = 1; i < (int)telefone.length(); i++){
        if(!isdigit(telefone[i])){
            return false;
        }
    }
    return true;
}

bool Telefone::setTelefone(string telefone){
    if(!validarTelefone(telefone)){
        return false;
    }
    this->telefone = telefone;
    return true;
}

bool Data::validarData(string data){
    if(data.length() != 11 || data[2] != '-' || data[6] != '-'){
        return false;
    }

    string dia = data.substr(0, 2);
    string mes = data.substr(3, 3);
    string ano = data.substr(7, 4);

    for(char c : dia){
        if(!isdigit(c)){
            return false;
        }
    }
    for(char c : ano){
        if(!isdigit(c)){
            return false;
        }
    }

    int diaInt = stoi(dia);
    int anoInt = stoi(ano);

    string calendario[12][2] = {
        {"JAN", "31"},
        {"FEV", "28"},
        {"MAR", "31"},
        {"ABR", "30"},
        {"MAI", "31"},
        {"JUN", "30"},
        {"JUL", "31"},
        {"AGO", "31"},
        {"SET", "30"},
        {"OUT", "31"},
        {"NOV", "30"},
        {"DEZ", "31"}
    };

    if(anoInt % 4 == 0){
        calendario[1][1] = "29";
    }


    for(int i = 0; i < 12; i++){
        if(mes == calendario[i][0] && diaInt > stoi(calendario[i][1])){
            return false;
            break;
        }
    }
    return true;
}

bool Data::setData(string data){
    if(!validarData(data)){
        return false;
    }
    this->data = data;
    return true;
}

bool Codigo::validarCodigo(string codigo){
    if(codigo.length() != 10){
        return false;
    }
    for(char c : codigo){
        if(!(isdigit(c) || (c >= 'a' && c <= 'z'))){
            return false;
        }
    }
    return true;
}

bool Codigo::setCodigo(string codigo){
    if(!validarCodigo(codigo)){
        return false;
    }
    this->codigo = codigo;
    return true;
}
