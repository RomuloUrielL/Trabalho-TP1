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

inline void Pessoa::setNome(Nome nome){
    this->nome = nome;
}

inline Nome Pessoa::getNome(){
    return nome;
}

inline void Pessoa::setEmail(Email email){
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

inline void Hospede::setCartao(const Cartao* cartao){
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

//implementacao dos metodos get e set dos atributos da entidade hotel

#endif // ENTIDADES_HPP_INCLUDED
