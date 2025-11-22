#include "stubs.hpp"

const string StubISAutenticacao::TRIGGER_SUCESSO_EMAIL = "emailteste@gmail.com";
const string StubISAutenticacao::TRIGGER_SUCESSO_SENHA = "A3n5#";

bool StubISAutenticacao::autenticar(Email email, Senha senha){
    if(email.getEmail() == TRIGGER_SUCESSO_EMAIL &&
       senha.getSenha() == TRIGGER_SUCESSO_SENHA){
        return true;
       }
    return false;
}

const string StubISReservas::TRIGGER_CODIGO_HOTEL_VALIDO = "htl1234567";
const string StubISReservas::TRIGGER_ERRO = "erro";

bool StubISReservas::criarHotel(Hotel hotel){
    if(hotel.getCodigo().getCodigo() == TRIGGER_CODIGO_HOTEL_VALIDO){
        return false;
    }
    return true;
}

bool StubISReservas::lerHotel(Hotel& hotel){
    if(hotel.getCodigo().getCodigo() == TRIGGER_CODIGO_HOTEL_VALIDO){
        Nome nome;
        nome.setNome("Hotel UnB");
        Endereco endereco;
        endereco.setEndereco("Campus Darcy Ribeiro");
        Telefone telefone;
        telefone.setTelefone("+55618493027584");

        hotel.setNome(nome);
        hotel.setEndereco(endereco);
        hotel.setTelefone(telefone);
        return true;
    }
    return false;
}

bool StubISReservas::editarHotel(Hotel hotel){
    if(hotel.getCodigo().getCodigo() == TRIGGER_CODIGO_HOTEL_VALIDO){
        return true;
    }
    return false;
}

bool StubISReservas::excluirHotel(Hotel hotel){
    if(hotel.getCodigo().getCodigo() == TRIGGER_CODIGO_HOTEL_VALIDO){
        return true;
    }
    return false;
}

bool StubISReservas::listarHotel(vector<Hotel>& hoteis) {
    Hotel h1, h2;
    Nome n1, n2;
    Codigo c1, c2;
    Endereco e1, e2;

    n1.setNome("Hotel Brasilia"); c1.setCodigo("bsbs123456"); e1.setEndereco("Avenida universo bsb");
    h1.setNome(n1); h1.setCodigo(c1); h1.setEndereco(e1);

    n2.setNome("Hotel Plano Piloto"); c2.setCodigo("plan123456"); e2.setEndereco("Eixo norte 103");
    h2.setNome(n2); h2.setCodigo(c2); h2.setEndereco(e2);

    hoteis.push_back(h1);
    hoteis.push_back(h2);

    return true;
}

const string StubISReservas::TRIGGER_CODIGO_RESERVA_VALIDO = "gtls234d67";

bool StubISReservas::criarReserva(Reserva reserva) {
    if(reserva.getCodigo().getCodigo() == TRIGGER_CODIGO_RESERVA_VALIDO){
        return false;
    }
    return true;
}
bool StubISReservas::lerReserva(Reserva& reserva) {
    if(reserva.getCodigo().getCodigo() == TRIGGER_CODIGO_RESERVA_VALIDO){
        Data chegada;
        chegada.setData("15-SET-2025");
        Data partida;
        partida.setData("23-DEZ-2025");
        Dinheiro valor;
        valor.setDinheiro("599.99");

        reserva.setChegada(chegada);
        reserva.setPartida(partida);
        reserva.setValor(valor);
        return true;
    }
    return false;
}
bool StubISReservas::editarReserva(Reserva reserva) {
    if(reserva.getCodigo().getCodigo() == TRIGGER_CODIGO_RESERVA_VALIDO){
        return true;
    }
    return false;
}
bool StubISReservas::excluirReserva(Reserva reserva) {
    if(reserva.getCodigo().getCodigo() == TRIGGER_CODIGO_RESERVA_VALIDO){
        return true;
    }
    return false;
}
bool StubISReservas::listarReservasDoHotel(const Hotel& hotel, vector<Reserva>& reservas) {
    if (hotel.getCodigo().getCodigo() == TRIGGER_CODIGO_HOTEL_VALIDO) {
        Reserva r1;
        Codigo c1; c1.setCodigo("reserva001");
        Data che1; che1.setData("10-DEZ-2024");
        Data par1; par1.setData("15-DEZ-2024");
        Dinheiro val1; val1.setDinheiro("1500,00");

        r1.setCodigo(c1);
        r1.setChegada(che1);
        r1.setPartida(par1);
        r1.setValor(val1);

        Reserva r2;
        Codigo c2; c2.setCodigo("reserva002");
        Data che2; che2.setData("20-JAN-2025");
        Data par2; par2.setData("25-JAN-2025");
        Dinheiro val2; val2.setDinheiro("2500,50");

        r2.setCodigo(c2);
        r2.setChegada(che2);
        r2.setPartida(par2);
        r2.setValor(val2);

        reservas.push_back(r1);
        reservas.push_back(r2);

        return true;
    }
    return false;
}

const string StubISReservas::TRIGGER_EMAIL_HOSPEDE_VALIDO = "romulo@gmail.com";

bool StubISReservas::criarHospede(Hospede hospede) {
    if(hospede.getEmail().getEmail() == TRIGGER_CODIGO_RESERVA_VALIDO){
        return false;
    }
    return true;
}
bool StubISReservas::lerHospede(Hospede& hospede) {
    if(hospede.getEmail().getEmail() == TRIGGER_EMAIL_HOSPEDE_VALIDO){
        Nome nome;
        nome.setNome("Romulo Uriel Liberal");
        Endereco endereco;
        endereco.setEndereco("Qnm 42 casa 30");
        Cartao cartao;
        cartao.setCartao("5244999774960569");

        hospede.setNome(nome);
        hospede.setEndereco(endereco);
        hospede.setCartao(cartao);
        return true;
    }
    return false;
}
bool StubISReservas::editarHospede(Hospede hospede) {
    if(hospede.getEmail().getEmail() == TRIGGER_CODIGO_RESERVA_VALIDO){
        return true;
    }
    return false;
}
bool StubISReservas::excluirHospede(Hospede hospede) {
    if(hospede.getEmail().getEmail() == TRIGGER_CODIGO_RESERVA_VALIDO){
        return true;
    }
    return false;
}
bool StubISReservas::listarHospedesDoHotel(const Hotel& hotel, vector<Hospede>& hospedes) {
    if (hotel.getCodigo().getCodigo() == TRIGGER_CODIGO_HOTEL_VALIDO) {
        Hospede h1;
        Nome n1;
        n1.setNome("Neymar Junior");
        Endereco e1;
        e1.setEndereco("Barra da Tijuca");
        Email email1;
        email1.setEmail("neymarjunior@gmail.com");
        Cartao c1;
        c1.setCartao("4532015112830366");

        h1.setNome(n1);
        h1.setEndereco(e1);
        h1.setEmail(email1);
        h1.setCartao(c1);

        Hospede h2;
        Nome n2;
        n1.setNome("Messi Ronaldo");
        Endereco e2;
        e2.setEndereco("Argentina Portugal");
        Email email2;
        email2.setEmail("messironaldo@gmail.com");
        Cartao c2;
        c2.setCartao("4242424242424242");

        h2.setNome(n2);
        h2.setEndereco(e2);
        h2.setEmail(email2);
        h2.setCartao(c2);

        hospedes.push_back(h1);
        hospedes.push_back(h2);

        return true;
    }
    return false;
}

const string StubISReservas::TRIGGER_NUMERO_QUARTO_VALIDO = "104";

bool StubISReservas::criarQuarto(Quarto quarto) {
    if(quarto.getNumero().getNumero() == TRIGGER_NUMERO_QUARTO_VALIDO){
        return false;
    }
    return true;
}
bool StubISReservas::lerQuarto(Quarto& quarto) {
    if(quarto.getNumero().getNumero() == TRIGGER_NUMERO_QUARTO_VALIDO){
        Ramal ramal;
        ramal.setRamal("45");
        Capacidade capacidade;
        capacidade.setCapacidade(2);
        Dinheiro diaria;
        diaria.setDinheiro("399.99");

        quarto.setRamal(ramal);
        quarto.setCapacidade(capacidade);
        quarto.setDinheiro(diaria);
        return true;
    }
    return false;
}
bool StubISReservas::editarQuarto(Quarto quarto) {
    if(quarto.getNumero().getNumero() == TRIGGER_NUMERO_QUARTO_VALIDO){
        return true;
    }
    return false;
}
bool StubISReservas::excluirQuarto(Quarto quarto) {
    if(quarto.getNumero().getNumero() == TRIGGER_NUMERO_QUARTO_VALIDO){
        return true;
    }
    return false;
}
bool StubISReservas::listarQuartosDoHotel(const Hotel& hotel, vector<Quarto>& quartos) {
    if (hotel.getCodigo().getCodigo() == TRIGGER_CODIGO_HOTEL_VALIDO) {
        Quarto q1;
        Numero n1;
        n1.setNumero("110");
        Capacidade c1;
        c1.setCapacidade(2);
        Dinheiro d1;
        d1.setDinheiro("299.99");
        Ramal r1;
        r1.setRamal("28");

        q1.setNumero(n1);
        q1.setCapacidade(c1);
        q1.setDinheiro(d1);
        q1.setRamal(r1);

        Quarto q2;
        Numero n2;
        n2.setNumero("203");
        Capacidade c2;
        c2.setCapacidade(4);
        Dinheiro d2;
        d2.setDinheiro("499.99");
        Ramal r2;
        r2.setRamal("13");

        q2.setNumero(n2);
        q2.setCapacidade(c2);
        q2.setDinheiro(d2);
        q2.setRamal(r2);

        quartos.push_back(q1);
        quartos.push_back(q2);

        return true;
    }
    return false;
}

const string StubISPessoal::TRIGGER_SUCESSO_EMAIL = "admin@teste.com";
const string StubISPessoal::TRIGGER_ERRO_EMAIL = "erro@teste.com";

bool StubISPessoal::criarGerente(Gerente gerente) {
    if (gerente.getEmail().getEmail() == TRIGGER_ERRO_EMAIL) {
        return false;
    }
    return true;
}

bool StubISPessoal::lerGerente(Gerente& gerente) {
    if (gerente.getEmail().getEmail() == TRIGGER_SUCESSO_EMAIL) {
        Nome n; n.setNome("Admin Testador");
        Ramal r; r.setRamal("10");
        Senha s; s.setSenha("A3n5#");

        gerente.setNome(n);
        gerente.setRamal(r);
        gerente.setSenha(s);

        return true;
    }
    return false;
}

bool StubISPessoal::atualizarGerente(Gerente gerente) {
    if (gerente.getEmail().getEmail() == TRIGGER_SUCESSO_EMAIL) {
        return true;
    }
    return false;
}

bool StubISPessoal::descadastrarGerente(Gerente gerente) {
    if (gerente.getEmail().getEmail() == TRIGGER_SUCESSO_EMAIL) {
        return true;
    }
    return false;
}

