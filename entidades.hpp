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
@code
Pessoa p;
Nome n("Pedro Silva");
Email e("joao.silva@email.com");

p.setNome(n);
p.setEmail(e);

std::cout << p.getNome().getValor() << std::endl;
std::cout << p.getEmail().getValor() << std::endl;
@endcode
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

/**
@brief Classe entidade que representa um gerente, ou seja, uma pessoa
responsável pelo gerenciamento do hotel e é especialização de pessoa.
@details A classe define um gerente no sistema que herda de pessoa nome e email
e possui especilização contendo também um ramal e uma senha para acesso ao
sistema.
@see Ramal, Senha, Nome, Email.
@code
Gerente g;
Nome n("Pedro Silva");
Email e("joao.silva@email.com");
Ramal r("05");
Senha s("a9B2C");

g.setNome(n);
g.setEmail(e);
g.setRamal(r);
g.setSenha(s);

std::cout << g.getNome().getNome() << std::endl;
std::cout << g.getEmail().getEmail() << std::endl;
std::cout << g.getRamal().getRamal() << std::endl;
std::cout << g.getSenha().getSenha() << std::endl;
@endcode
*/
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
/**
@brief Classe entidade que representa um hóspede, ou seja, um cliente do hotel e
é uma especialização da classe 'Pessoa'.
@details A classe define um hóspede no sistema que herda de pessoa nome e email
e possui especialização contendo também endereço e cartão.
@see Endereco, Cartao, Nome, Email.
@code
Hospede h;
Nome n("Pedro Silva");
Email e("joao.silva@email.com");
Endereco ec("Qnm 42 conjunto K casa 20");
cartao c("5244999774960569");

h.setNome(n);
h.setEmail(e);
h.setEndereco(ec);
h.setCartao(c);

std::cout << p.getNome().getNome() << std::endl;
std::cout << p.getEmail().getEmail() << std::endl;
std::cout << p.getEndereco().getEndereco() << std::endl;
std::cout << p.getCartao().getCartao() << std::endl;
@endcode
*/
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
/**
@brief Classe entidade que representa um espaço onde pessoas utilizam
determinado período.
@details A classe Hotel define um estabelecimento que possui um gerente e é
usado para hospedagem de pessoas, além disso, pode possuir vários quartos e
vários hóspedes que possuem uma reserva no hotel.
@see Nome, Endereco, Telefone, Codigo.
@code
Hotel h;
Nome n("Pedro Silva");
Endereco ec("Qnm 42 conjunto K casa 20");
Telefone t("+619023418463");
Codigo c("a9sjdk283h");

h.setNome(n);
h.setEndereco(ec);
h.setTelefone(t);
h.setCodigo(c);

std::cout << h.getNome().getNome() << std::endl;
std::cout << h.getEndereco().getEndereco() << std::endl;
std::cout << h.getTelefone().getTelefone() << std::endl;
std::cout << h.getCodigo().getCodigo() << std::endl;
@endcode
*/
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
/**
@brief Classe entidade que representa um espaço dentro do hotel em que um
hóspede pode ficar alojado.
@details A classe Quarto define esse espaço e pode abrigar um hóspede por um
determinado período de chegada até um determinado período de partida, além disso
possui um valor que representa a diária do quarto e quantas pessoas cabem no
quarto e um ramal para comunicação interna dentro do hotel.
@see Numero, Capacidade, Dinheiro, Ramal.
@code
Quarto q;
Numero n("301");
Capacidade c("3");
Dinheiro d("102");
Ramal r("23");

q.setNumero(n);
q.setCapacidade(c);
q.setDinheiro(d);
q.setRamal(r);

std::cout << q.getNumero().getNumero() << std::endl;
std::cout << q.getCapacidade().getCapacidade() << std::endl;
std::cout << q.getDinheiro().getDinheiro() << std::endl;
std::cout << q.getRamal().getRamal() << std::endl;
@endcode
*/
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

/**
@brief Classe entidade que representa um período que um hóspede pode selecionar
para passar no hotel, além disso, o hospede pode escolher o quarto do hotel;
@details A classe Reserva define quanto tempo o hóspede irá passar no hotel
possuindo então duas datas: uma data de chegada e uma data de partida, além
disso, também possui o valor da reserva e o código da reserva.
@see Data, Dinheiro, Codigo.
@code
Reserva r;
Data d1("09/12/2025");
Data d2("07/01/2026");
Dinheiro d("2342");
Codigo c("a9sjdk283h");

r.setChegada(d1);
r.setPartida(d2);
r.setDinheiro(d);
r.setCodigo(c);

std::cout << r.getChegada().getData() << std::endl;
std::cout << r.getPartida().getData() << std::endl;
std::cout << r.getDinheiro().getDinheiro() << std::endl;
std::cout << r.getCodigo().getCodigo() << std::endl;
@endcode
*/
class Reserva{
    private:
        Data chegada;
        Data partida;
        Dinheiro valor;
        Codigo codigo;
    public:
        /**
        @brief Define a data de chegada da reserva,
        @param data Objeto da classe 'Data' contendo a data de chegada da
        reserva a ser atribuída.
        */
        void setChegada(const Data& data);
        /**
        @brief Retorna a data de chegada da reserva.
        @return Objeto da classe 'Data' associada à data de chegada da reserva.
        */
        Data getChegada()const;
        /**
        @brief Define a data de partida da reserva.
        @return data Objeto da classe 'Data' contendo a data de partida da
        reserva a ser atribuída.
        */
        void setPartida(const Data& data);
        /**
        @brief Retorna a data de partida da reserva.
        @return Objeto da classe 'Data' associada à data de partida da reserva.
        */
        Data getPartida()const;
        /**
        @brief Define o valor da reserva.
        @param valor Objeto da classe 'Dinheiro' contendo o valor da reserva a
        ser atribuído.
        */
        void setValor(const Dinheiro& valor);
        /**
        @brief Retorna o valor da reserva.
        @return Objeto da classe 'Dinheiro' associado ao valor da reserva.
        */
        Dinheiro getValor()const;
        /**
        @brief Define o código da reserva.
        @param codigo Objeto da classe 'Codigo' contendo o código da reserva a
        ser atribuído.
        */
        void setCodigo(const Codigo& codigo);
        /**
        @brief Retorna o código da reserva.
        @return Objeto da classe 'Codigo' associado ao código da reserval.
        */
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
