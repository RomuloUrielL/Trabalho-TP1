#include "dominios.hpp"
#include <cctype>
#include <string>

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

bool Cartao::validarCartao(string cartao){
    int quantidadeCaracteres = 16;
    int somaposPares = 0;
    int somaposImpares = 0;

    if(cartao.length() != quantidadeCaracteres){
        return false;
    }

    for(char c : cartao){
        if(!isdigit(c)){
            return false;
        }
    }

    for(int i = (quantidadeCaracteres - 2); i >= 0; i -= 2){
        int digito = cartao[i] - '0';
        int dobro = digito * 2;
        somaposPares += (dobro / 10)+ (dobro % 10);
    }
    for(int i = (quantidadeCaracteres - 1); i >= 0; i -= 2){
        int digito = cartao[i] - '0';
        somaposImpares += digito;
    }

    int somaTotal = somaposImpares + somaposPares;

        return (somaTotal % 10 == 0);
}

bool Cartao::setCartao(string cartao){
    if(!validarCartao(cartao)){
        return false;
    }
    this->cartao = cartao;
    return true;
}

bool Senha::validarSenha(string senha){
    int quantidadeCaracteres = 5;
    int contadorMinuscula = 0;
    int contadorMaiuscula = 0;
    int contadorDigito = 0;
    int contadorCarEspecial = 0;

    int ehLetra = 0;
    int ehDigito = 1;
    int ehEspecial = 2;

    int caractereAnterior = -1, caractereAtual;

    if(senha.length() != quantidadeCaracteres){
        return false;
    }

    for(int i = 0; i < quantidadeCaracteres; i++){
        //contar se a senha tem todos os tipos de caracteres requisitos de uma senha
        char c =  senha[i];
        if(c >= 'A' && c <= 'Z'){
            contadorMaiuscula++;
            caractereAtual = 0;
        } else if(c >= 'a' && c <= 'z'){
            contadorMinuscula++;
            caractereAtual = 0;
        } else if(c >='0' && c <= '9'){
            contadorDigito++;
            caractereAtual = 1;
        } else if((c >= '!' && c <= '&') || c == '?'){
            contadorCarEspecial++;
            caractereAtual = 2;
        } else {
            return false;
        }

        if(caractereAtual == caractereAnterior){
            return false;
        }

        caractereAnterior = caractereAtual;
    }

        //verifica se tem todos os tipos de caracteres
    if(contadorMinuscula > 0 && contadorMaiuscula > 0 && contadorCarEspecial > 0 && contadorDigito > 0){
        return true;
    } else {
        return false;
    }
}

bool Senha::setSenha(string senha){
    if(!validarSenha(senha)){
        return false;
    }
    this->senha = senha;
    return true;
}

bool Nome::validarNome(string nome){
    int comprimentoNome = nome.length();

    if(comprimentoNome < limiteMin || comprimentoNome > limiteMax){
        return false;
    }

    for(int i = 0; i < comprimentoNome; i++){
        char c = nome[i];

        if(i == 0 && (c < 'A' || c > 'Z')){
            return false;
        }

        if(i >= 1){
            if(nome[i-1] == ' ' && (c < 'A' || c > 'Z')){
                return false;
            } else if(!isalpha(c) && c != ' '){
                return false;
            }
        }

        if(i == (comprimentoNome - 1) && c == ' '){
            return false;
        }
    }

    return true;
}

bool Nome::setNome(string nome){
    if(!validarNome(nome)){
        return false;
    }
    this->nome = nome;
    return true;
}

bool Email::validarEmail(string email){
    string parteLocal, dominio;
    int pos = email.find('@');

    if(pos == string::npos){
        return false;
    }

    parteLocal = email.substr(0, pos);
    dominio = email.substr(pos + 1);

    if(parteLocal.length() < limiteMin || parteLocal.length() > limiteMax_Local){
        return false;
    }
    if(dominio.length() < limiteMin || dominio.length() > limiteMax_Dominio){
        return false;
    }

    //verificar validade da parte local

    for(int i = 0; i < parteLocal.length(); i++){
        char c = parteLocal[i];

        if((i == 0 || i == parteLocal.length() - 1) && (c == '.' || c == '-')){
            return false;
        }

        if(!isalpha(c) && !isdigit(c) && c != '.' && c != '-'){
            return false;
        }

        if((c == '.' || c == '-') && i + 1 < parteLocal.length()){
            if(!isdigit(parteLocal[i+1]) && !isalpha(parteLocal[i+1])){
                return false;
            }
        }
    }

    //verificar validade da parte dominio

      for(int i = 0; i < dominio.length(); i++){
       char c = dominio[i];

        if((i == 0 || i == dominio.length() - 1) && c == '-'){
            return false;
        }

        if(!islower(c) && !isdigit(c) && c != '.' && c != '-'){
            return false;
        }

        if(c == '.' && i + 1 < dominio.length() && dominio[i+1] == '.'){
            return false;
        }

        if(c == '.' && (dominio[i+1] == '-' || (i > 0 && dominio[i-1] == '-'))){
            return false;
        }
    }

    return true;
}

bool Email::setEmail(string email){
    if(!validarEmail(email)){
        return false;
    }
    this->email = email;
    return true;
}

bool Endereco::validarEndereco(string endereco){

    if(endereco.length() < limiteMin || endereco.length() > limiteMax){
        return false;
    }

    for(int i = 0; i < endereco.length(); i++){
        char c = endereco[i];

        if((i == 0 || i == endereco.length() - 1) && (c == ' ' || c == '.' || c == ',')){
            return false;
        }

        if(!isalpha(c) && !isdigit(c) && c != ',' && c != '.' && c != ' '){
            return false;
        }

        if((c == ',' || c == '.') && i + 1 < endereco.length()){
            if(endereco[i+1] == ',' || endereco[i+1] == '.'){
                return false;
            }
        }

        if(c == ' ' && i + 1 < endereco.length()){
            if(!isalpha(endereco[i+1]) && !isdigit(endereco[i+1])){
                return false;
            }
        }
    }
    return true;
}

bool Endereco::setEndereco(string endereco){
    if(!validarEndereco(endereco)){
        return false;
    }
    this->endereco = endereco;
    return true;
}
