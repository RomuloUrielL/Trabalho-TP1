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
    catch(out_of_range &excecao){
        estado = FALHA;
    }
}

void TUCapacidade::testarCenarioValorInvalido(){
    try{
        capacidade->setCapacidade(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(out_of_range &excecao){
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

const string TUCartao::VALOR_VALIDO = "5244999774960569";
const string TUCartao::VALOR_INVALIDO = "100";

void TUCartao::setUp(){
    cartao = new Cartao();
    estado = SUCESSO;
}


void TUCartao::tearDown(){
    delete cartao;
}

void TUCartao::testarCenarioValorValido(){
    try{
        cartao->setCartao(VALOR_VALIDO);
        if(cartao->getCartao() != VALOR_VALIDO){
            estado = FALHA;
        }
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUCartao::testarCenarioValorInvalido(){
    try{
        cartao->setCartao(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if(cartao->getCartao() == VALOR_INVALIDO){
            estado = FALHA;
        }
    }
}

int TUCartao::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}

const string TURamal::VALOR_VALIDO = "10";
const string TURamal::VALOR_INVALIDO = "60";

void TURamal::setUp(){
    ramal = new Ramal();
    estado = SUCESSO;
}

void TURamal::tearDown(){
    delete ramal;
}

void TURamal::testarCenarioValorValido(){
    try{
        ramal->setRamal(VALOR_VALIDO);
        if(ramal->getRamal() != VALOR_VALIDO){
            estado = FALHA;
        }
    }
    catch(length_error &excecao){
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
    catch(out_of_range &excecao){
        estado = FALHA;
    }
}

void TURamal::testarCenarioValorInvalido(){
    try{
        ramal->setRamal(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(length_error &excecao){
        if(ramal->getRamal() == VALOR_INVALIDO){
            estado = FALHA;
        }
    }
    catch(invalid_argument &excecao){
        if(ramal->getRamal() == VALOR_INVALIDO){
            estado = FALHA;
        }
    }
    catch(out_of_range &excecao){
        if(ramal->getRamal() == VALOR_INVALIDO){
            estado = FALHA;
        }
    }
}

int TURamal::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}

const string TUTelefone::VALOR_VALIDO = "+12345678912345";
const string TUTelefone::VALOR_INVALIDO = "+123";

void TUTelefone::setUp(){
    telefone = new Telefone();
    estado = SUCESSO;
}

void TUTelefone::tearDown(){
    delete telefone;
}

void TUTelefone::testarCenarioValorValido(){
    try{
        telefone->setTelefone(VALOR_VALIDO);
        if(telefone->getTelefone() != VALOR_VALIDO){
            estado = FALHA;
        }
    }catch(length_error &excecao){
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUTelefone::testarCenarioValorInvalido(){
    try{
        telefone->setTelefone(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(length_error &excecao){
        if(telefone->getTelefone() == VALOR_INVALIDO){
            estado = FALHA;
        }
    }
    catch(invalid_argument &excecao){
        if(telefone->getTelefone() == VALOR_INVALIDO){
            estado = FALHA;
        }
    }
}

int TUTelefone::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}

const string TUNumero::VALOR_VALIDO = "100";
const string TUNumero::VALOR_INVALIDO = "10000";

void TUNumero::setUp(){
    numero = new Numero();
    estado = SUCESSO;
}

void TUNumero::tearDown(){
    delete numero;
}

void TUNumero::testarCenarioValorValido(){
    try{
        numero->setNumero(VALOR_VALIDO);
        if(numero->getNumero()!= VALOR_VALIDO){
            estado = FALHA;
        }
    }
    catch(length_error &excecao){
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
    catch(out_of_range &excecao){
        estado = FALHA;
    }
}

void TUNumero::testarCenarioValorInvalido(){
    try{
        numero->setNumero(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(length_error &excecao){
        if(numero->getNumero() == VALOR_INVALIDO){
            estado = FALHA;
        }
    }
    catch(invalid_argument &excecao){
        if(numero->getNumero() == VALOR_INVALIDO){
            estado = FALHA;
        }
    }
    catch(out_of_range &excecao){
        if(numero->getNumero() == VALOR_INVALIDO){
            estado = FALHA;
        }
    }
}

int TUNumero::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}

