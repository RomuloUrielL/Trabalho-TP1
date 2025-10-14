#include "dominios.hpp"
#include <cctype>
#include <string>
#include<stdexcept>

void Capacidade::validarCapacidade(unsigned short capacidade){
    if(capacidade > limiteMax || capacidade < limiteMin){
        throw std::out_of_range("Capacidade invalida, digite um valor entre 1 e 4");
    }
};

void Capacidade::setCapacidade(unsigned short capacidade){
    validarCapacidade(capacidade);
    this->capacidade = capacidade;
};

const double Dinheiro::limiteMin = 0.01;
const double Dinheiro::limiteMax = 1000000.00;

void Dinheiro::validarDinheiro(double dinheiro){
    if(dinheiro < limiteMin || dinheiro > limiteMax){
        throw std::out_of_range("Dinheiro invalido, digite um valor entre 0.01 e 1000000.00");
    }
};

void Dinheiro::setDinheiro(double dinheiro){
    validarDinheiro(dinheiro);
    this->dinheiro = dinheiro;
};

void Ramal::validarRamal(string ramal){
    if((int)ramal.length() != lenght){
        throw std::length_error("Comprimento invalido! digite um número com 2 algarismos.");
    }
    for(char c : ramal){
        if(!isdigit(c)){
            throw std::invalid_argument("Caracteres invalidos! digite apenas numeros.");
        }
    }
    int valor = stoi(ramal);
    if(valor < valorMin || valor > valorMax){
        throw std::out_of_range("Ramal invalido! digite um ramal entre 00 e 50.");
    }
};

void Ramal::setRamal(string ramal){
    validarRamal(ramal);
    this->ramal = ramal;
};

void Numero::validarNumero(string numero){
    if((int)numero.length() != length){
        throw std::length_error("Comprimento invalido! digite um número com 3 dígitos.");
    }
    for(char c : numero){
        if(!isdigit(c)){
            throw std::invalid_argument("Caracteres invalidos! digite apenas digitos.");
        }
    }
    int valor = stoi(numero);
    if(valor < valorMin || valor > valorMax){
            throw std::out_of_range("Numero fora da faixa! digite um valor entre 001 e 999.");
    }
}

void Numero::setNumero(string numero){
    validarNumero(numero);
    this->numero = numero;
}

void Telefone::validarTelefone(string telefone){
    if((int)telefone.length() != length || telefone[0] != '+'){
        throw std::length_error("Comprimento inválido ou sem prefixo '+', digite um telefone no formato +DDDDDDDDDDDDDD.");
    }
    for(int i = 1; i < (int)telefone.length(); i++){
        if(!isdigit(telefone[i])){
            throw std::invalid_argument("Caracteres invalidos! Digite + seguido de 14 numeros.");
        }
    }
}

void Telefone::setTelefone(string telefone){
    validarTelefone(telefone);
    this->telefone = telefone;
}

void Data::validarData(string data){
    if(data.length() != length || data[2] != '-' || data[6] != '-'){
        throw std::invalid_argument("Formato de data invalido. Use DD-MES-AAAA (ex: 15-OUT-2025).");
    }

    string dia = data.substr(0, 2);
    string mes = data.substr(3, 3);
    string ano = data.substr(7, 4);

    for(char c : dia){
        if(!isdigit(c)){
            throw std::invalid_argument("O dia deve conter apenas digitos.");
        }
    }
    for(char c : ano){
        if(!isdigit(c)){
            throw std::invalid_argument("O ano deve conter apenas digitos.");
        }
    }

    int diaInt = stoi(dia);
    int anoInt = stoi(ano);

    if (anoInt < 2000 || anoInt > 2999) {
        throw std::out_of_range("Ano invalido. O ano deve estar entre 2000 e 2999.");
    }

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


     bool mesEncontrado = false;
    for (int i = 0; i < 12; i++) {
        if (mes == calendario[i][0]) {
            mesEncontrado = true;

            if (diaInt < 1 || diaInt > stoi(calendario[i][1])) {
                throw std::out_of_range("Dia invalido para o mes especificado.");
            }
            break;
        }
    }
    if (!mesEncontrado) {
        throw std::invalid_argument("Mes invalido. Use a abreviacao de 3 letras em maiusculo (JAN, FEV, etc.).");
    }
}

void Data::setData(string data){
    validarData(data);
    this->data = data;
}

void Codigo::validarCodigo(string codigo){
    if(codigo.length() != 10){
        throw std::length_error("Codigo deve ter exatamente 10 caracteres.");
    }
    for(char c : codigo){
        if(!(isdigit(c) || (c >= 'a' && c <= 'z'))){
            throw std::invalid_argument("Codigo deve conter apenas letras minusculas (a-z) e digitos (0-9).");
        }
    }
}

void Codigo::setCodigo(string codigo){
    validarCodigo(codigo);
    this->codigo = codigo;
}

void Cartao::validarCartao(string cartao){
    const int quantidadeCaracteres = 16;
    int somaposPares = 0;
    int somaposImpares = 0;

    if((int)cartao.length() != quantidadeCaracteres){
        throw std::length_error("Tamanho invalido");
    }

    for(char c : cartao){
        if(!isdigit(c)){
            throw std::invalid_argument("O cartao aceita somente numeros");
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

        if((somaTotal % 10) != 0){
            throw std::invalid_argument("Cartao invalido");
        };
}

void Cartao::setCartao(string cartao){
    validarCartao(cartao);
    this->cartao = cartao;
}

void Senha::validarSenha(string senha){
    int quantidadeCaracteres = 5;
    int contadorMinuscula = 0;
    int contadorMaiuscula = 0;
    int contadorDigito = 0;
    int contadorCarEspecial = 0;

    int caractereAnterior = -1, caractereAtual;

    if((int)senha.length() != quantidadeCaracteres){
        throw std::invalid_argument("Senha deve conter exatamente 5 caracteres.");
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
            throw std::invalid_argument("Senha contem um caractere invalido.");
        }

        if(caractereAtual == caractereAnterior){
            throw std::invalid_argument("Senha nao pode ter caracteres do mesmo tipo em sequencia.");
        }

        caractereAnterior = caractereAtual;
    }

        //verifica se tem todos os tipos de caracteres
   if(contadorMinuscula == 0 || contadorMaiuscula == 0 || contadorCarEspecial == 0 || contadorDigito == 0){
        throw std::invalid_argument("Senha deve conter ao menos uma letra maiuscula, uma minuscula, um digito e um caractere especial (!, \", #, $, %, &, ?).");
    }
}

void Senha::setSenha(string senha){
    validarSenha(senha);
    this->senha = senha;
}

void Nome::validarNome(string nome){
    int comprimentoNome = nome.length();

    if(comprimentoNome < limiteMin || comprimentoNome > limiteMax){
        throw std::invalid_argument("O nome deve ter entre 5 e 20 caracteres.");
    }

    for(int i = 0; i < comprimentoNome; i++){
        char c = nome[i];

    if(!isalpha(c) && c != ' '){
            throw std::invalid_argument("Nome contem caractere invalido. Apenas letras e espacos sao permitidos.");
        }

    if(i == 0 && (c < 'A' || c > 'Z')){
            throw std::invalid_argument("A primeira letra do nome deve ser maiuscula.");
        }

    if(i > 0 && nome[i-1] == ' ' && (c < 'A' || c > 'Z')){
            throw std::invalid_argument("A primeira letra de cada termo do nome deve ser maiuscula.");
        }


        if(i == (comprimentoNome - 1) && c == ' '){
            throw std::invalid_argument("O nome nao pode terminar com espaco em branco.");
        }
    }
}

void Nome::setNome(string nome){
    validarNome(nome);
    this->nome = nome;
}

void Email::validarEmail(string email){
    string parteLocal, dominio;
    int pos = (int)email.find('@');

        if(pos == (int)string::npos || (int)email.find('@', pos + 1) != (int)string::npos){
        throw std::invalid_argument("Formato de email invalido. Deve conter um unico '@'.");
    }

    parteLocal = email.substr(0, pos);
    dominio = email.substr(pos + 1);

    if(parteLocal.length() < limiteMin || parteLocal.length() > limiteMax_Local){
        throw std::invalid_argument("A parte local do email (antes do '@') deve ter entre 1 e 64 caracteres.");
    }
    if(dominio.length() < limiteMin || dominio.length() > limiteMax_Dominio){
        throw std::invalid_argument("A parte do dominio (depois do '@') nao pode ser vazia e deve ter no maximo 255 caracteres.");
    }

    //verificar validade da parte local

    for(int i = 0; i < (int)parteLocal.length(); i++){
        char c = parteLocal[i];

        if((i == 0 || i == (int)parteLocal.length() - 1) && (c == '.' || c == '-')){
            throw std::invalid_argument("A parte local do email nao pode comecar ou terminar com ponto ou hifen.");
        }

        if(!isalpha(c) && !isdigit(c) && c != '.' && c != '-'){
            throw std::invalid_argument("A parte local do email contem um caractere invalido.");
        }

       if((c == '.' || c == '-') && (parteLocal[i+1] == '.' || parteLocal[i+1] == '-')){
            throw std::invalid_argument("A parte local do email nao pode ter dois pontos ou hifens seguidos.");
         }
    }

    //verificar validade da parte dominio

      for(int i = 0; i < (int)dominio.length(); i++){
       char c = dominio[i];

        if((i == 0 || i == (int)dominio.length() - 1) && c == '-'){
            throw std::invalid_argument("O dominio do email nao pode comecar ou terminar com hifen.");
        }

        if(!islower(c) && !isdigit(c) && c != '.' && c != '-'){
            throw std::invalid_argument("O dominio do email contem um caractere invalido (apenas letras minusculas, digitos, ponto e hifen).");
        }

        if(c == '.' && i + 1 < (int)dominio.length() && dominio[i+1] == '.'){
            throw std::invalid_argument("O dominio do email nao pode ter pontos sequenciais.");
        }

        if(c == '.' && (dominio[i+1] == '-' || (i > 0 && dominio[i-1] == '-'))){
            throw std::invalid_argument("Hifen no dominio nao pode ser precedido ou sucedido por um ponto.");
        }
    }
}
void Email::setEmail(string email){
    validarEmail(email);
    this->email = email;
}

void Endereco::validarEndereco(string endereco){

    if(endereco.length() < limiteMin || endereco.length() > limiteMax){
        throw std::length_error("Endereco deve ter entre 5 e 30 caracteres.");
    }

    for(int i = 0; i < (int)endereco.length(); i++){
        char c = endereco[i];

        if((i == 0 || i == (int)endereco.length() - 1) && (c == ' ' || c == '.' || c == ',')){
            throw std::invalid_argument("Endereco nao pode comecar ou terminar com espaco, ponto ou virgula.");
        }

        if(!isalpha(c) && !isdigit(c) && c != ',' && c != '.' && c != ' '){
            throw std::invalid_argument("Endereco contem caractere invalido.");
        }

        if((c == ',' || c == '.') && i + 1 < (int)endereco.length()){
            if(endereco[i+1] == ',' || endereco[i+1] == '.'){
                throw std::invalid_argument("Endereco nao pode ter pontuacao em sequencia (ex: '..', ',,', '.,').");
            }
        }

        if(c == ' ' && i + 1 < (int)endereco.length()){
            if(!isalpha(endereco[i+1]) && !isdigit(endereco[i+1])){
                throw std::invalid_argument("Endereco com espaco em branco deve ser seguido por letra ou digito.");
            }
        }
    }
}

void Endereco::setEndereco(string endereco){
    validarEndereco(endereco);
    this->endereco = endereco;
}
