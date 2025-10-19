#ifndef ENTIDADES_HPP_INCLUDED
#define ENTIDADES_HPP_INCLUDED

#include "dominios.hpp"

using namespace std;

/**
@brief Classe entidade que representa um indivíduo no sistema.
@details A classe Pessoa define um indivíduo no sistema que possuem informações
cadastrais no sistema, podendo ser especializada em outras classes entidades
como Gerente ou Hospede.
@see Nome, Email, Hospede, Gerente.
*/
class Pessoa{
    private:
        Nome nome;
        Email email;
    public:
        /**
        @brief Define o nome da pessoa.
        @param nome Objeto da classe 'Nome' contendo o nome a ser atribuído.
        */
        void setNome(const Nome& nome);
        /**
        @brief Retorna o nome da pessoa.
        @return Objeto da classe 'Nome' associado à pessoa.
        */
        Nome getNome();
        /**
        @brief Define o email da pessoa.
        @param email Objeto da classe 'Email' contendo o email a ser atribuído.
        */
        void setEmail(const Email& email);
        /**
        @brief Retorna o e-mail da pessoa.
        @return Objeto da classe 'Email' associado à pessoa.
        */
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
        /**
        @brief Define o ramal do gerente.
        @param ramal Objeto da classe 'Ramal' contendo o ramal a ser atribuído.
        */
        void setRamal(const Ramal& ramal);
        /**
        @brief Retorna o ramal do gerente.
        @return Objeto da classe 'Ramal' associado ao gerente.
        */
        Ramal getRamal() const;
        /**
        @brief Define a senha do gerente.
        @param senha Objeto da classe 'Senha' contendo a senha a ser atribuída.
        */
        void setSenha(const Senha& senha);
        /**
        @brief Retorna a senha do gerente.
        @brief Objeto da classe 'Senha' associado ao gerente.
        */
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
        /**
        @brief Define o endereço do hóspede.
        @param endereco Objeto da classe 'Endereco' contendo o endereço do
        hóspede a ser atribuído.
        */
        void setEndereco(const Endereco& endereco);
        /**
        @brief Retorna o endereço do hóspede.
        @return Objeto da classe 'Endereco' associado ao hospede.
        */
        Endereco getEndereco() const;
        /**
        @brief Define o cartão do hóspede.
        @param cartao Objeto da classe 'Cartao' contendo o número do cartão do
        hóspede a ser atribuído.
        */
        void setCartao(const Cartao& cartao);
        /**
        @brief Retorna o número do cartão do hóspede.
        @return Objeto da classe 'Cartao' associado ao hóspede.
        */
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
        /**
        @brief Define o nome do hotel.
        @param nome Objeto da classe 'Nome' contendo o nome do hotel a ser
        atribuído.
        */
        void setNome(const Nome& nome);
        /**
        @brief Retorna o nome do hotel.
        @return Objeto da classe 'Nome' associado ao hotel;
        */
        Nome getNome() const;
        /**
        @brief Define o endereço do hotel.
        @param endereco Objeto da classe 'Endereco' contendo o endereço do hotel
        a ser atribuído.
        */
        void setEndereco(const Endereco& endereco);
        /**
        @brief Retorna o endereço do hotel.
        @return Objeto da classe 'Endereco' associado ao hotel.
        */
        Endereco getEndereco()const;
        /**
        @brief Define o telefone do hotel.
        @param telefone Objeto da classe 'Telefone' contendo o telefone do hotel
        a ser atribuído.
        */
        void setTelefone(const Telefone& telefone);
        /**
        @brief Retorna o telefone do hotel.
        @return Objeto da classe 'Telefone' associado ao hotel.
        */
        Telefone getTelefone() const;
        /**
        @brief Define o código do hotel.
        @param codigo Objeto da classe 'Codigo' contendo o codigo do hotel a ser
        atribuído.
        */
        void setCodigo(const Codigo& codigo);
        /**
        @brief Retorna o código do hotel.
        @return Objeto da classe 'Codigo' associado ao hotel.
        */
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
        /**
        @brief Define o numero do quarto.
        @param numero Objeto da classe 'Numero' contendo o número do quarto a
        ser atribuído.
        */
        void setNumero(const Numero& numero);
        /**
        @brief Retorna o número do quarto.
        @return Objeto da classe 'Numero' associado ao quarto.
        */
        Numero getNumero()const;
        /**
        @brief Define a capacidade do quarto.
        @param capacidade Objeto da classe 'Capacidade' contendo a capacidade do
        quarto a ser atribuída.
        */
        void setCapacidade(const Capacidade& capacidade);
        /**
        @brief Retorna a capacidade do quarto.
        @return Objeto da classe 'Capacidade' associado ao quarto.
        */
        Capacidade getCapacidade()const;
        /**
        @brief Define a diária do quarto.
        @param diaria Objeto da classe 'Dinheiro' contendo a diária do quarto a
        ser atribuída.
        */
        void setDinheiro(const Dinheiro& diaria);
        /**
        @brief Retorna a diária do hotel.
        @return Objeto da classe 'Dinheiro' associada ao quarto.
        */
        Dinheiro getDiaria()const;
        /**
        @brief Define o ramal do quarto.
        @param ramal Objeto da classe 'Ramal' contendo o ramal do quarto a ser
        atribuído.
        */
        void setRamal(const Ramal& ramal);
        /**
        @brief Retorna o ramal do quarto.
        @return Objeto da classe 'Ramal' associado ao quarto.
        */
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
