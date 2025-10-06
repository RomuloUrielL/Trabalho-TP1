#include "testes.hpp"

void TUCapacidade::setUp(){
    capacidade = new Capacidade();
    estado = SUCESSO;
}

void TUCapacidade::tearDown(){
    delete capacidade;
}

void TUCapacidade::testarCenarioValorValido(){
    try{
        capacidade->setCapacidade(VALOR_VALIDO);
        if(capacidade->getCapacidade() != VALOR_VALIDO){
            estado = FALHA;
        }

    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUCapacidade::testarCenarioValorInvalido(){
    try{
        capacidade->setCapacidade(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if(capacidade->getCapacidade() == VALOR_INVALIDO){
            estado = FALHA;
        }
    }
}

int TUCapacidade::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}
