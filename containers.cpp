#include "containers.hpp"
#include "dominios.hpp"
#include "entidades.hpp"

ContainerHoteis* ContainerHoteis::instancia = nullptr;

ContainerHoteis* ContainerHoteis::getInstancia(){
    if(instancia == nullptr){
        instancia = new ContainerHoteis();
    }
    return instancia;
}

bool ContainerHoteis::incluir(Hotel hotel){
    return container.insert(make_pair(hotel.getCodigo().getCodigo(), hotel)).second;
}
bool ContainerHoteis::pesquisar(Hotel* hotel){
    map<string, Hotel>::iterator it = container.find(hotel->getCodigo().getCodigo());

    if(it != container.end()){
        *hotel = it->second;
        return true;
    }
    return false;
}
bool ContainerHoteis::atualizar(Hotel hotel){
    map<string, Hotel>::iterator it = container.find(hotel.getCodigo().getCodigo());

    if(it != container.end()){
        it->second = hotel;
        return true;
    }
    return false;
}
bool ContainerHoteis::remover(string codigo){
    map<string, Hotel>::iterator it = container.find(codigo);

    if(it != container.end()){
        container.erase(it);
        return true;
    }
    return false;
}
bool ContainerHoteis::listar(vector<Hotel>& hoteis){
    for(auto const&[chave, hotel] : container){
        hoteis.push_back(hotel);
    }
    return true;
}
bool ContainerHoteis::existeHotelDoGerente(string emailGerente) {
    for (auto const& [chave, hotel] : container) {
        if (hotel.getEmailGerente().getEmail() == emailGerente) {
            return true;
        }
    }
    return false;
}


ContainerReservas* ContainerReservas::instancia = nullptr;

ContainerReservas* ContainerReservas::getInstancia(){
    if(instancia == nullptr){
        instancia = new ContainerReservas();
    }
    return instancia;
}

bool ContainerReservas::incluir(Reserva reserva){
    return container.insert(make_pair(reserva.getCodigo().getCodigo(), reserva)).second;
}
bool ContainerReservas::pesquisar(Reserva* reserva){
    map<string, Reserva>::iterator it = container.find(reserva->getCodigo().getCodigo());

    if(it != container.end()){
        *reserva = it->second;
        return true;
    }
    return false;
}
bool ContainerReservas::atualizar(Reserva reserva){
    map<string, Reserva>::iterator it = container.find(reserva.getCodigo().getCodigo());

    if(it != container.end()){
        it->second = reserva;
        return true;
    }
    return false;
}
bool ContainerReservas::remover(string codigo){
    map<string, Reserva>::iterator it = container.find(codigo);

    if(it != container.end()){
        container.erase(it);
        return true;
    }
    return false;
}
bool ContainerReservas::listar(string codigoHotelFiltro, vector<Reserva>& reservas){
    for(auto const&[chave, reserva] : container){
        if(reserva.getCodigoHotel().getCodigo() == codigoHotelFiltro)
        reservas.push_back(reserva);
    }
    return true;
}

ContainerHospedes* ContainerHospedes::instancia = nullptr;

ContainerHospedes* ContainerHospedes::getInstancia(){
    if(instancia == nullptr){
        instancia = new ContainerHospedes();
    }
    return instancia;
}

bool ContainerHospedes::incluir(Hospede hospede){
    return container.insert(make_pair(hospede.getEmail().getEmail(), hospede)).second;
}
bool ContainerHospedes::pesquisar(Hospede* hospede){
    map<string, Hospede>::iterator it = container.find(hospede->getEmail().getEmail());

    if(it != container.end()){
        *hospede = it->second;
        return true;
    }
    return false;
}
bool ContainerHospedes::atualizar(Hospede hospede){
    map<string, Hospede>::iterator it = container.find(hospede.getEmail().getEmail());

    if(it != container.end()){
        it->second = hospede;
        return true;
    }
    return false;
}
bool ContainerHospedes::remover(string email){
    map<string, Hospede>::iterator it = container.find(email);

    if(it != container.end()){
        container.erase(it);
        return true;
    }
    return false;
}
bool ContainerHospedes::listar(string codigoHotelFiltro, vector<Hospede>& hospedes){
    for(auto const&[chave, hospede] : container){
        if(hospede.getCodigoHotel().getCodigo() == codigoHotelFiltro)
        hospedes.push_back(hospede);
    }
    return true;
}

ContainerQuartos* ContainerQuartos::instancia = nullptr;

ContainerQuartos* ContainerQuartos::getInstancia(){
    if(instancia == nullptr){
        instancia = new ContainerQuartos();
    }
    return instancia;
}

bool ContainerQuartos::incluir(Quarto quarto){
    return container.insert(make_pair(quarto.getNumero().getNumero(), quarto)).second;
}
bool ContainerQuartos::pesquisar(Quarto* quarto){
    map<string, Quarto>::iterator it = container.find(quarto->getNumero().getNumero());

    if(it != container.end()){
        *quarto = it->second;
        return true;
    }
    return false;
}
bool ContainerQuartos::atualizar(Quarto quarto){
    map<string, Quarto>::iterator it = container.find(quarto.getNumero().getNumero());

    if(it != container.end()){
        it->second = quarto;
        return true;
    }
    return false;
}
bool ContainerQuartos::remover(string numero){
    map<string, Quarto>::iterator it = container.find(numero);

    if(it != container.end()){
        container.erase(it);
        return true;
    }
    return false;
}
bool ContainerQuartos::listar(string codigoHotelFiltro, vector<Quarto>& quartos){
    for(auto const&[chave, quarto] : container){
        if(quarto.getCodigoHotel().getCodigo() == codigoHotelFiltro)
        quartos.push_back(quarto);
    }
    return true;
}

ContainerGerentes* ContainerGerentes::instancia = nullptr;

ContainerGerentes* ContainerGerentes::getInstancia(){
    if(instancia == nullptr){
        instancia = new ContainerGerentes();
    }
    return instancia;
}

bool ContainerGerentes::incluir(Gerente gerente){
    return container.insert(make_pair(gerente.getEmail().getEmail(), gerente)).second;
}
bool ContainerGerentes::pesquisar(Gerente* gerente){
    map<string, Gerente>::iterator it = container.find(gerente->getEmail().getEmail());

    if(it != container.end()){
        *gerente = it->second;
        return true;
    }
    return false;
}
bool ContainerGerentes::atualizar(Gerente gerente){
    map<string, Gerente>::iterator it = container.find(gerente.getEmail().getEmail());

    if(it != container.end()){
        it->second = gerente;
        return true;
    }
    return false;
}
bool ContainerGerentes::remover(string email){
     map<string, Gerente>::iterator it = container.find(email);

    if(it != container.end()){
        container.erase(it);
        return true;
    }
    return false;
}

