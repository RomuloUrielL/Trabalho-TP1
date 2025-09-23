#ifndef ENTIDADES_HPP_INCLUDED
#define ENTIDADES_HPP_INCLUDED

#include "dominios.hpp"

using namespace std;

class Pessoa{
    private:
        Nome nome;
        Email email;
    public:
        void setNome(const Nome& nome);
        Nome getNome();
        void setEmail(const Email& email);
        Email getEmail();
};

inline void Pessoa::setNome(const Nome& nome){
    this->nome = nome;
}

inline Nome Pessoa::getNome(){
    return nome;
}

inline void Pessoa::setEmail(const Email& email){
    this->email =  email;
}

inline Email Pessoa::getEmail(){
    return email;
}

class Gerente:public Pessoa{
    private:
        Ramal ramal;
        Senha senha;
    public:
        void setRamal(const Ramal& ramal);
        Ramal getRamal() const;
        void setSenha(const Senha& senha);
        Senha getSenha() const;
};

inline void Gerente::setRamal(const Ramal& ramal){
    this->ramal = ramal;
}

inline Ramal Gerente::getRamal() const{
    return ramal;
}

inline void Gerente::setSenha(const Senha& senha){
    this->senha = senha;
}

inline Senha Gerente::getSenha() const{
    return senha;
}

class Hospede:public Pessoa{
    private:
        Endereco endereco;
        Cartao cartao;
    public:
        void setEndereco(const Endereco& endereco);
        Endereco getEndereco() const;
        void setCartao(const Cartao& cartao);
        Cartao getCartao() const;
};

inline void Hospede::setEndereco(const Endereco& endereco){
    this->endereco = endereco;
}

inline Endereco Hospede::getEndereco() const {
    return endereco;
}

inline void Hospede::setCartao(const Cartao& cartao){
    this->cartao = cartao;
}

inline Cartao Hospede::getCartao() const{
    return cartao;
}

class Hotel{
    private:
        Nome nome;
        Endereco endereco;
        Telefone telefone;
        Codigo codigo;
    public:
        void setNome(const Nome& nome);
        Nome getNome() const;
        void setEndereco(const Endereco& endereco);
        Endereco getEndereco()const;
        void setTelefone(const Telefone& telefone);
        Telefone getTelefone() const;
        void setCodigo(const Codigo& codigo);
        Codigo getCodigo() const;
};

inline void Hotel::setNome(const Nome& nome){
    this->nome = nome;
}

inline Nome Hotel::getNome() const{
    return nome;
}

inline void Hotel::setEndereco(const Endereco& endereco){
    this->endereco = endereco;
}

inline Endereco Hotel::getEndereco() const{
    return endereco;
}

inline void Hotel::setTelefone(const Telefone& telefone){
    this->telefone = telefone;
}

inline Telefone Hotel::getTelefone() const{
    return telefone;
}

inline void Hotel::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}

inline Codigo Hotel::getCodigo() const{
    return codigo;
}

class Quarto{
    private:
        Numero numero;
        Capacidade capacidade;
        Dinheiro diaria;
        Ramal ramal;
    public:
        void setNumero(const Numero& numero);
        Numero getNumero()const;
        void setCapacidade(const Capacidade& capacidade);
        Capacidade getCapacidade()const;
        void setDinheiro(const Dinheiro& diaria);
        Dinheiro getDiaria()const;
        void setRamal(const Ramal& ramal);
        Ramal getRamal()const;
};

inline void Quarto::setNumero(const Numero& numero){
    this->numero = numero;
}

inline Numero Quarto::getNumero() const{
    return numero;
}

inline void Quarto::setCapacidade(const Capacidade& capacidade){
    this->capacidade = capacidade;
}

inline Capacidade Quarto::getCapacidade()const{
    return capacidade;
}

inline void Quarto::setDinheiro(const Dinheiro& dinheiro){
    this->diaria = dinheiro;
}

inline Dinheiro Quarto::getDiaria()const{
    return diaria;
}

inline void Quarto::setRamal(const Ramal& ramal){
    this->ramal = ramal;
}

inline Ramal Quarto::getRamal()const{
    return ramal;
}

class Reserva{
    private:
        Data chegada;
        Data partida;
        Dinheiro valor;
        Codigo codigo;
    public:
        void setChegada(const Data& data);
        Data getChegada()const;
        void setPartida(const Data& data);
        Data getPartida()const;
        void setValor(const Dinheiro& valor);
        Dinheiro getValor()const;
        void setCodigo(const Codigo& codigo);
        Codigo getCodigo()const;
};

inline void Reserva::setChegada(const Data& data){
    this->chegada = data;
}

inline Data Reserva::getChegada()const{
    return chegada;
}

inline void Reserva::setPartida(const Data& data){
    this->partida = data;
}

inline Data Reserva::getPartida()const{
    return partida;
}

inline void Reserva::setValor(const Dinheiro& valor){
    this->valor = valor;
}

inline Dinheiro Reserva::getValor()const{
    return valor;
}

inline void Reserva::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}

inline Codigo Reserva::getCodigo()const{
    return codigo;
}

#endif // ENTIDADES_HPP_INCLUDED
