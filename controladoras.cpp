#include "controladoras.hpp"
#include "dominios.hpp"
#include "entidades.hpp"
#include "containers.hpp"
#include "stubs.hpp"

bool CntrIUAutenticacao::autenticar(Email &gerente) {
    Email email;
    Senha senha;
    string entradaEmail, entradaSenha;

    while(true) {
        cout << endl << "-----Autenticacao de usuario----" << endl;
        try {
            cout << "Digite o email: ";
            cin >> entradaEmail;
            email.setEmail(entradaEmail);
            cout << "Digite a senha: ";
            cin >> entradaSenha;
            senha.setSenha(entradaSenha);
            break;
        }
        catch (const invalid_argument &exp) {
            cout << endl << "Erro: " << exp.what() << endl;
            cout << "Por favor, tente novamente." << endl;
        }
    }

    bool resultado = cntrServicoAutenticacao->autenticar(email, senha);

    if(resultado){
        gerente = email;
    }

    return resultado;
}

void CntrIUReservas::executar(Email email){
    int opcao = -1;

    while(opcao != 0){
        cout << "\n---- SISTEMA DE RESERVAS ----" << endl;
        cout << "0. Voltar ao menu principal" << endl;
        cout << "1. Criar hotel" << endl;
        cout << "2. Ler hotel" << endl;
        cout << "3. Editar hotel" << endl;
        cout << "4. Excluir hotel" << endl;
        cout << "5. Criar Reserva" << endl;
        cout << "6. Ler Reserva" << endl;
        cout << "7. Editar Reserva" << endl;
        cout << "8. Excluir Reserva" << endl;
        cout << "9. Criar Hospede" << endl;
        cout << "10. Ler Hospede" << endl;
        cout << "11. Editar Hospede" << endl;
        cout << "12. Excluir Hospede" << endl;
        cout << "13. Criar Quarto" << endl;
        cout << "14. Ler Quarto" << endl;
        cout << "15. Editar Quarto" << endl;
        cout << "16. Excluir Quarto" << endl;
        cout << "17. Listar Hoteis" << endl;
        cout << "18. Listar Reservas" << endl;
        cout << "19. Listar Hospedes" << endl;
        cout << "20. Listar Quartos" << endl;

        cout << "Digite a opcao desejada: ";
        cin >> opcao;

        switch (opcao){
            case 0: {
                cout << "Voltando ao menu principal..." << endl;
                break;
            }
            case 1: {
                cout << "\n----Criacao de hoteis----" << endl;
                try {
                    Nome nome;
                    Endereco endereco;
                    Telefone telefone;
                    Codigo codigo;
                    Email emailGerente;
                    Hotel hotel;

                    string entradaNome, entradaEndereco, entradaTelefone,
                    entradaCodigo, entradaEmailGerente;


                    cout << "Digite o nome do hotel: ";
                    getline(cin >> ws, entradaNome);
                    nome.setNome(entradaNome);
                    hotel.setNome(nome);
                    cout << "Digite o endereco do hotel: ";
                    getline(cin >> ws, entradaEndereco);
                    endereco.setEndereco(entradaEndereco);
                    hotel.setEndereco(endereco);
                    cout << "Digite o Telefone do hotel: ";
                    cin >> entradaTelefone;
                    telefone.setTelefone(entradaTelefone);
                    hotel.setTelefone(telefone);
                    cout << "Digite o codigo do hotel: ";
                    cin >> entradaCodigo;
                    codigo.setCodigo(entradaCodigo);
                    hotel.setCodigo(codigo);
                    cout << "Digite o email do gerente responsavel: ";
                    cin >> entradaEmailGerente;
                    emailGerente.setEmail(entradaEmailGerente);
                    hotel.setEmailGerente(emailGerente);


                    bool resultado = cntrIS_Reservas->criarHotel(hotel);

                    if(resultado){
                        cout << "Hotel criado com sucesso!\n" << endl;
                    } else {
                        cout << "Falha ao criar o hotel.\n" << endl;
                    }
                }
                catch (const invalid_argument &exp) {
                    cout << endl << "Erro: " << exp.what() << endl;
                    cout << "Por favor, tente novamente." << endl;
                }
                break;
            }
            case 2: {
                cout << "----Leitura de Hoteis----" << endl;
                try{
                    Codigo codigo;
                    Hotel hotel;
                    string entradaCodigo;

                    cout << "Digite o codigo do hotel a ser pesquisado: ";
                    cin >> entradaCodigo;
                    codigo.setCodigo(entradaCodigo);
                    hotel.setCodigo(codigo);

                    bool encontrou = cntrIS_Reservas->lerHotel(hotel);

                    if(encontrou){
                        cout << "\n----Informacoes do hotel pesquisado----" << endl;

                        cout << "Nome: " << hotel.getNome().getNome() << endl;
                        cout << "Endereco: " << hotel.getEndereco().getEndereco() << endl;
                        cout << "Telefone: " << hotel.getTelefone().getTelefone() << endl;
                        cout << "Codigo: " << hotel.getCodigo().getCodigo() << "\n" << endl;
                        cout << "Gerente:  " << hotel.getEmailGerente().getEmail() << endl;
                    } else {
                        cout << "Hotel não foi encontrado com esse codigo." << endl;
                    }
                }
                catch (const invalid_argument &exp) {
                    cout << endl << "Erro: " << exp.what() << endl;
                    cout << "Por favor, tente novamente." << endl;
                }
                break;
            }
            case 3: {
                cout << "----Edicao de hoteis----" << endl;
                try {
                    Codigo codigo;
                    string entradaCodigo;
                    cout << "Digite o codigo do hotel a ser editado: ";
                    cin >> entradaCodigo;
                    codigo.setCodigo(entradaCodigo);

                    Hotel hotelAtualizado;
                    hotelAtualizado.setCodigo(codigo);

                    Nome novoNome;
                    string entradaNome;
                    cout << "Digite o novo nome do hotel: ";
                    getline(cin >> ws, entradaNome);
                    novoNome.setNome(entradaNome);
                    hotelAtualizado.setNome(novoNome);

                    Endereco novoEndereco;
                    string entradaEndereco;
                    cout << "Digite o endereco do hotel: ";
                    getline(cin >> ws, entradaEndereco);
                    novoEndereco.setEndereco(entradaEndereco);
                    hotelAtualizado.setEndereco(novoEndereco);

                    Telefone novoTelefone;
                    string entradaTelefone;
                    cout << "Digite o novo telefone: ";
                    cin >> entradaTelefone;
                    novoTelefone.setTelefone(entradaTelefone);
                    hotelAtualizado.setTelefone(novoTelefone);

                    bool sucesso = cntrIS_Reservas->editarHotel(hotelAtualizado);

                    if(sucesso){
                        cout << "Hotel editado com sucesso!" << endl;
                    } else {
                        cout << "Hotel não encontrado ou erro na edição." << endl;
                    }
                }
                catch (const invalid_argument &exp) {
                    cout << endl << "Erro nos dados: " << exp.what() << endl;
                }
                break;
            }
            case 4: {
                cout << "----Excluir hoteis----" << endl;
                try{
                    Hotel hotel;
                    Codigo codigo;
                    string entradaCodigo;
                    char confirmacao;

                    cout << "Digite o codigo do hotel a ser excluido: ";
                    cin >> entradaCodigo;

                    codigo.setCodigo(entradaCodigo);
                    hotel.setCodigo(codigo);

                    cout << "Tem certeza que deseja excluir este hotel? (S/N): ";
                    cin >> confirmacao;

                    if(confirmacao == 'S' || confirmacao == 's'){
                        bool resultado = cntrIS_Reservas->excluirHotel(hotel);
                        if(resultado){
                            cout << "Hotel excluido com sucesso!" << endl;
                        } else {
                            cout << "Falha ao excluir hotel." << endl;
                        }
                    } else {
                        cout << "Operacao cancelada." << endl;
                    }
                }
                catch (const invalid_argument &exp) {
                    cout << endl << "Erro: " << exp.what() << endl;
                    cout << "Por favor, tente novamente." << endl;
                }
                break;
            }
            case 5: {
                cout << "----Criacao de reservas----" << endl;
                try{
                    Data chegada;
                    Data partida;
                    Dinheiro valor;
                    Codigo codigo;
                    Reserva reserva;
                    Codigo codHotel;
                    Email emailHospede;
                    Numero numeroQuarto;
                    string entradaChegada, entradaPartida, entradaValor, entradaCodigo;
                    string entradaEmailHospede;
                    string entradaNumeroQuarto;


                    cout << "Digite a data de chegada: ";
                    cin >> entradaChegada;
                    chegada.setData(entradaChegada);
                    reserva.setChegada(chegada);
                    cout << "Digite a data de partida: ";
                    cin >> entradaPartida;
                    partida.setData(entradaPartida);
                    reserva.setPartida(partida);
                    cout << "Digite o valor da reserva: ";
                    cin >> entradaValor;
                    valor.setDinheiro(entradaValor);
                    reserva.setValor(valor);
                    cout << "Digite o codigo da reserva: ";
                    cin >> entradaCodigo;
                    codigo.setCodigo(entradaCodigo);
                    reserva.setCodigo(codigo);

                    cout << "Digite o codigo do hotel desta reserva: ";
                    cin >> entradaCodigo;
                    codHotel.setCodigo(entradaCodigo);
                    reserva.setCodigoHotel(codHotel);
                    cout << "Digite o email do hospede responsavel: ";
                    cin >> entradaEmailHospede;
                    emailHospede.setEmail(entradaEmailHospede);
                    reserva.setEmailHospede(emailHospede);
                    cout << "Digite o numero do quarto reservado: ";
                    cin >> entradaNumeroQuarto;
                    numeroQuarto.setNumero(entradaNumeroQuarto);
                    reserva.setNumeroQuarto(numeroQuarto);

                    bool resultado = cntrIS_Reservas->criarReserva(reserva);

                    if(resultado){
                        cout << "Reserva criada com sucesso!" << endl;
                    } else {
                        cout << "Falha ao criar a reserva." << endl;
                    }
                }
                catch (const invalid_argument &exp) {
                    cout << endl << "Erro: " << exp.what() << endl;
                    cout << "Por favor, tente novamente." << endl;
                }
                break;
            }
            case 6: {
                cout << "----Ler Reservas----" << endl;
                try{
                    Codigo codigo;
                    Reserva reserva;
                    string entradaCodigo;

                    cout << "Digite o codigo da reserva a ser lida: ";
                    cin >> entradaCodigo;
                    codigo.setCodigo(entradaCodigo);
                    reserva.setCodigo(codigo);

                    bool encontrou = cntrIS_Reservas->lerReserva(reserva);

                    if(encontrou){
                        cout << "----Informacoes da reserva pesquisada----" << endl;

                        cout << "Chegada: " << reserva.getChegada().getData() << endl;
                        cout << "Partida: " << reserva.getPartida().getData() << endl;
                        cout << "Valor: " << reserva.getValor().getDinheiro() << endl;
                        cout << "Codigo: " << reserva.getCodigo().getCodigo() << endl;
                    } else {
                        cout << "Reserva nao foi encontrada com esse codigo." << endl;
                    }
                }
                catch (const invalid_argument &exp) {
                    cout << endl << "Erro: " << exp.what() << endl;
                    cout << "Por favor, tente novamente." << endl;
                }
                break;
            }
            case 7: {
                cout << "----Edicao de reservas----" << endl;
                try {
                    Codigo codigo;
                    string entradaCodigo;
                    cout << "Digite o codigo da reserva a ser editada: ";
                    cin >> entradaCodigo;
                    codigo.setCodigo(entradaCodigo);

                    Reserva reservaAtualizada;
                    reservaAtualizada.setCodigo(codigo);

                    Data novaChegada;
                    string entradaChegada;
                    cout << "Digite o nova data de chegada da reserva: ";
                    cin >> entradaChegada;
                    novaChegada.setData(entradaChegada);
                    reservaAtualizada.setChegada(novaChegada);

                    Data novaPartida;
                    string entradaPartida;
                    cout << "Digite a nova data de partida da reserva: ";
                    cin >> entradaPartida;
                    novaPartida.setData(entradaPartida);
                    reservaAtualizada.setPartida(novaPartida);

                    Dinheiro novoValor;
                    string entradaValor;
                    cout << "Digite o novo valor: ";
                    cin >> entradaValor;
                    novoValor.setDinheiro(entradaValor);
                    reservaAtualizada.setValor(novoValor);

                    bool sucesso = cntrIS_Reservas->editarReserva(reservaAtualizada);

                    if(sucesso){
                        cout << "Reserva editada com sucesso!" << endl;
                    } else {
                        cout << "Reserva nao encontrada ou erro na edicao." << endl;
                    }
                }
                catch (const invalid_argument &exp) {
                    cout << endl << "Erro nos dados: " << exp.what() << endl;
                }
                break;
            }
            case 8: {
                cout << "----Excluir Reservas----" << endl;
                try{
                    Reserva reserva;
                    Codigo codigo;
                    string entradaCodigo;
                    char confirmacao;

                    cout << "Digite o codigo da reserva a ser excluida: ";
                    cin >> entradaCodigo;

                    codigo.setCodigo(entradaCodigo);
                    reserva.setCodigo(codigo);

                    cout << "Tem certeza que deseja excluir esta reserva? (S/N): ";
                    cin >> confirmacao;

                    if(confirmacao == 'S' || confirmacao == 's'){
                        bool resultado = cntrIS_Reservas->excluirReserva(reserva);
                        if(resultado){
                            cout << "reserva excluida com sucesso!" << endl;
                        } else {
                            cout << "Falha ao excluir a reserva." << endl;
                        }
                    } else {
                        cout << "Operacao cancelada." << endl;
                    }
                }
                catch (const invalid_argument &exp) {
                    cout << endl << "Erro: " << exp.what() << endl;
                    cout << "Por favor, tente novamente." << endl;
                }
                break;
            }
            case 9: {
                cout << "----Criacao de hospede----" << endl;
                try {
                    Nome nome;
                    Email email;
                    Endereco endereco;
                    Cartao cartao;
                    Hospede hospede;
                    string entradaCodigo;

                    string entradaNome, entradaEmail, entradaEndereco, entradaCartao;


                    cout << "Digite o nome do hospede: ";
                    getline(cin >> ws, entradaNome);
                    nome.setNome(entradaNome);
                    hospede.setNome(nome);
                    cout << "Digite o email do hospede: ";
                    cin >> entradaEmail;
                    email.setEmail(entradaEmail);
                    hospede.setEmail(email);
                    cout << "Digite o endereco do hospede: ";
                    getline(cin >> ws, entradaEndereco);
                    endereco.setEndereco(entradaEndereco);
                    hospede.setEndereco(endereco);
                    cout << "Digite o cartao do hospede: ";
                    cin >> entradaCartao;
                    cartao.setCartao(entradaCartao);
                    hospede.setCartao(cartao);

                    cout << "Digite o codigo do hotel deste hospede: ";
                    cin >> entradaCodigo;

                    Codigo codHotel;
                    codHotel.setCodigo(entradaCodigo);
                    hospede.setCodigoHotel(codHotel);

                    bool resultado = cntrIS_Reservas->criarHospede(hospede);

                    if(resultado){
                        cout << "Hospede criado com sucesso!" << endl;
                    } else {
                        cout << "Falha ao criar o hospede." << endl;
                    }
                }
                catch (const invalid_argument &exp) {
                    cout << endl << "Erro: " << exp.what() << endl;
                    cout << "Por favor, tente novamente." << endl;
                }
                break;
            }
            case 10: {
                cout << "----Leitura de Hospedes----" << endl;
                try{
                    Email email;
                    Hospede hospede;
                    string entradaEmail;

                    cout << "Digite o email do hospede a ser pesquisado: ";
                    cin >> entradaEmail;
                    email.setEmail(entradaEmail);
                    hospede.setEmail(email);

                    bool encontrou = cntrIS_Reservas->lerHospede(hospede);

                    if(encontrou){
                        cout << "--Informacoes do hospede pesquisado" << endl;

                        cout << "Nome: " << hospede.getNome().getNome() << endl;
                        cout << "Endereco: " << hospede.getEndereco().getEndereco() << endl;
                        cout << "Email: " << hospede.getEmail().getEmail() << endl;
                        cout << "Cartao: " << hospede.getCartao().getCartao() << endl;
                    } else {
                        cout << "Hospede não foi encontrado com esse email." << endl;
                    }
                }
                catch (const invalid_argument &exp) {
                    cout << endl << "Erro: " << exp.what() << endl;
                    cout << "Por favor, tente novamente." << endl;
                }
                break;
            }
            case 11: {
                cout << "----Edicao de reservas----" << endl;
                try {
                    Email email;
                    string entradaEmail;
                    cout << "Digite o email do hospede a ser editado: ";
                    cin >> entradaEmail;
                    email.setEmail(entradaEmail);

                    Hospede hospedeAtualizado;
                    hospedeAtualizado.setEmail(email);

                    if(cntrIS_Reservas->lerHospede(hospedeAtualizado)){
                        Nome novoNome;
                        string entradaNome;
                        cout << "Digite o novo nome do hospede: ";
                        getline(cin >> ws, entradaNome);
                        novoNome.setNome(entradaNome);
                        hospedeAtualizado.setNome(novoNome);

                        Endereco novoEndereco;
                        string entradaEndereco;
                        cout << "Digite o endereco hosppede: ";
                        getline(cin >> ws, entradaEndereco);
                        novoEndereco.setEndereco(entradaEndereco);
                        hospedeAtualizado.setEndereco(novoEndereco);

                        Cartao novoCartao;
                        string entradaCartao;
                        cout << "Digite o novo cartao: ";
                        cin >> entradaCartao;
                        novoCartao.setCartao(entradaCartao);
                        hospedeAtualizado.setCartao(novoCartao);

                        bool sucesso = cntrIS_Reservas->editarHospede(hospedeAtualizado);

                        if(sucesso){
                            cout << "Hospede editado com sucesso!" << endl;
                        } else {
                            cout << "Hospede não encontrado ou erro na edicao." << endl;
                        }
                    } else {
                        cout << "Hospede nao encontrado com esse email." << endl;
                    }
                }
                catch (const invalid_argument &exp) {
                    cout << endl << "Erro nos dados: " << exp.what() << endl;
                }
                break;
            }
            case 12: {
                cout << "----Excluir hospedes----" << endl;
                try{
                    Hospede hospede;
                    Email email;
                    string entradaEmail;
                    char confirmacao;

                    cout << "Digite o email do hospede a ser excluido: ";
                    cin >> entradaEmail;

                    email.setEmail(entradaEmail);
                    hospede.setEmail(email);

                    cout << "Tem certeza que deseja excluir este hospede? (S/N): ";
                    cin >> confirmacao;

                    if(confirmacao == 'S' || confirmacao == 's'){
                        bool resultado = cntrIS_Reservas->excluirHospede(hospede);
                        if(resultado){
                            cout << "Hospede excluido com sucesso!" << endl;
                        } else {
                            cout << "Falha ao excluir hospede." << endl;
                        }
                    } else {
                        cout << "Operacao cancelada." << endl;
                    }
                }
                catch (const invalid_argument &exp) {
                    cout << endl << "Erro: " << exp.what() << endl;
                    cout << "Por favor, tente novamente." << endl;
                }
                break;
            }
            case 13: {
                cout << "----Criacao de Quartos----" << endl;
                try {
                    Numero numero;
                    Capacidade capacidade;
                    Dinheiro diaria;
                    Ramal ramal;
                    Quarto quarto;
                    string entradaCodigo;

                    short entradaCapacidade;
                    string entradaDiaria, entradaNumero, entradaRamal;

                    cout << "Digite o numero do quarto: ";
                    cin >> entradaNumero;
                    numero.setNumero(entradaNumero);
                    quarto.setNumero(numero);
                    cout << "Digite a capacidade do quarto: ";
                    cin >> entradaCapacidade;
                    capacidade.setCapacidade(entradaCapacidade);
                    quarto.setCapacidade(capacidade);
                    cout << "Digite a diaria do quarto: ";
                    cin >> entradaDiaria;
                    diaria.setDinheiro(entradaDiaria);
                    quarto.setDinheiro(diaria);
                    cout << "Digite o ramal do quarto: ";
                    cin >> entradaRamal;
                    ramal.setRamal(entradaRamal);
                    quarto.setRamal(ramal);

                    cout << "Digite o codigo do hotel deste quarto: ";
                    cin >> entradaCodigo;

                    Codigo codHotel;
                    codHotel.setCodigo(entradaCodigo);
                    quarto.setCodigoHotel(codHotel);

                    bool resultado = cntrIS_Reservas->criarQuarto(quarto);

                    if(resultado){
                        cout << "Quarto criado com sucesso!" << endl;
                    } else {
                        cout << "Falha ao criar o quarto." << endl;
                    }
                }
                catch (const invalid_argument &exp) {
                    cout << endl << "Erro: " << exp.what() << endl;
                    cout << "Por favor, tente novamente." << endl;
                }
                break;
            }
            case 14: {
                cout << "----Leitura de Quartos----" << endl;
                try{
                    Numero numero;
                    Quarto quarto;
                    string entradaNumero;

                    cout << "Digite o numero do quarto a ser pesquisado: ";
                    cin >> entradaNumero;
                    numero.setNumero(entradaNumero);
                    quarto.setNumero(numero);

                    bool encontrou = cntrIS_Reservas->lerQuarto(quarto);

                    if(encontrou){
                        cout << "--Informacoes do quarto pesquisado" << endl;

                        cout << "Numero: " << quarto.getNumero().getNumero() << endl;
                        cout << "Capacidade: " << quarto.getCapacidade().getCapacidade() << endl;
                        cout << "Diaria: " << quarto.getDiaria().getDinheiro() << endl;
                        cout << "Ramal: " << quarto.getRamal().getRamal() << endl;
                        cout << "Hotel: " << quarto.getCodigoHotel().getCodigo() << endl;
                    } else {
                        cout << "Quarto nao foi encontrado com esse codigo." << endl;
                    }
                }
                catch (const invalid_argument &exp) {
                    cout << endl << "Erro: " << exp.what() << endl;
                    cout << "Por favor, tente novamente." << endl;
                }
                break;
            }
            case 15: {
                cout << "----Edicao de quartos----" << endl;
                try {
                    Numero numero;
                    string entradaNumero;
                    cout << "Digite o numero do quarto a ser editado: ";
                    cin >> entradaNumero;
                    numero.setNumero(entradaNumero);

                    Quarto quartoAtualizado;
                    quartoAtualizado.setNumero(numero);

                    Capacidade novaCapacidade;
                    short entradaCapacidade;
                    cout << "Digite a nova capacidade do quarto: ";
                    cin >> entradaCapacidade;
                    novaCapacidade.setCapacidade(entradaCapacidade);
                    quartoAtualizado.setCapacidade(novaCapacidade);

                    Dinheiro novaDiaria;
                    string entradaDiaria;
                    cout << "Digite a nova diaria do hotel: ";
                    cin >> entradaDiaria;
                    novaDiaria.setDinheiro(entradaDiaria);
                    quartoAtualizado.setDinheiro(novaDiaria);

                    Ramal novoRamal;
                    string entradaRamal;
                    cout << "Digite o novo ramal: ";
                    cin >> entradaRamal;
                    novoRamal.setRamal(entradaRamal);
                    quartoAtualizado.setRamal(novoRamal);

                    bool sucesso = cntrIS_Reservas->editarQuarto(quartoAtualizado);

                    if(sucesso){
                        cout << "Quarto editado com sucesso!" << endl;
                    } else {
                        cout << "Quarto nao encontrado ou erro na edicao." << endl;
                    }
                }
                catch (const invalid_argument &exp) {
                    cout << endl << "Erro nos dados: " << exp.what() << endl;
                }
                break;
            }
            case 16: {
                cout << "----Excluir quartos----" << endl;
                try{
                    Quarto quarto;
                    Numero numero;
                    string entradaNumero;
                    char confirmacao;

                    cout << "Digite o numero do quarto a ser excluido: ";
                    cin >> entradaNumero;

                    numero.setNumero(entradaNumero);
                    quarto.setNumero(numero);

                    cout << "Tem certeza que deseja excluir este quarto? (S/N): ";
                    cin >> confirmacao;

                    if(confirmacao == 'S' || confirmacao == 's'){
                        bool resultado = cntrIS_Reservas->excluirQuarto(quarto);
                        if(resultado){
                            cout << "quarto excluido com sucesso!" << endl;
                        } else {
                            cout << "Falha ao excluir quarto." << endl;
                        }
                    } else {
                        cout << "Operacao cancelada." << endl;
                    }
                }
                catch (const invalid_argument &exp) {
                    cout << endl << "Erro: " << exp.what() << endl;
                    cout << "Por favor, tente novamente." << endl;
                }
                break;
            }
            case 17: {
                cout << "----Listagem de Hoteis----" << endl;
                vector<Hotel> listaDeHoteis;

                if (cntrIS_Reservas->listarHotel(listaDeHoteis)) {

                    if (listaDeHoteis.empty()) {
                        cout << "Nenhum hotel cadastrado." << endl;
                    } else {
                        for (const auto& hotel : listaDeHoteis) {
                            cout << "------------------------" << endl;
                            cout << "Nome: " << hotel.getNome().getNome() << endl;
                            cout << "Endereco: " << hotel.getEndereco().getEndereco() << endl;
                            cout << "Telefone: " << hotel.getTelefone().getTelefone() << endl;
                            cout << "Codigo: " << hotel.getCodigo().getCodigo() << endl;
                        }
                        cout << "------------------------" << endl;
                    }
                } else {
                    cout << "Erro ao tentar listar os hoteis." << endl;
                }
                break;
            }
            case 18: {
                cout << "---- Listagem de Reservas do Hotel ----" << endl;
                try {
                    Hotel hotelFiltro;
                    Codigo codigo;
                    string entradaCodigo;

                    cout << "Digite o Codigo do Hotel para listar suas reservas: ";
                    cin >> entradaCodigo;
                    codigo.setCodigo(entradaCodigo);
                    hotelFiltro.setCodigo(codigo);

                    vector<Reserva> listaDeReservas;

                    if (cntrIS_Reservas->listarReservasDoHotel(hotelFiltro, listaDeReservas)) {

                        if (listaDeReservas.empty()) {
                            cout << "Nenhuma reserva encontrada para este hotel." << endl;
                        } else {
                            for (const auto& reserva : listaDeReservas) {
                                cout << "------------------------" << endl;
                                cout << "Codigo:  " << reserva.getCodigo().getCodigo() << endl;
                                cout << "Chegada: " << reserva.getChegada().getData() << endl;
                                cout << "Partida: " << reserva.getPartida().getData() << endl;
                                cout << "Valor:   " << reserva.getValor().getDinheiro() << endl;
                                cout << "Hospede: " << reserva.getEmailHospede().getEmail() << endl;
                                cout << "Quarto:  " << reserva.getNumeroQuarto().getNumero() << endl;
                            }
                            cout << "------------------------" << endl;
                        }
                    } else {
                        cout << "Erro: Hotel nao encontrado ou falha na listagem." << endl;
                    }
                }
                catch (const invalid_argument &exp) {
                    cout << "Erro no codigo do hotel: " << exp.what() << endl;
                }
                break;
            }
            case 19: {
                cout << "---- Listagem de hospedes do Hotel ----" << endl;
                try {
                    Hotel hotelFiltro;
                    Codigo codigo;
                    string entradaCodigo;

                    cout << "Digite o Codigo do Hotel para listar seus hospedes: ";
                    cin >> entradaCodigo;
                    codigo.setCodigo(entradaCodigo);
                    hotelFiltro.setCodigo(codigo);

                    vector<Hospede> listaDeHospedes;

                    if (cntrIS_Reservas->listarHospedesDoHotel(hotelFiltro, listaDeHospedes)) {

                        if (listaDeHospedes.empty()) {
                            cout << "Nenhum hospede encontrado para este hotel." << endl;
                        } else {
                            for (const auto& hospede : listaDeHospedes) {
                                cout << "------------------------" << endl;
                                cout << "Nome:  " << hospede.getNome().getNome() << endl;
                                cout << "Email: " << hospede.getEmail().getEmail() << endl;
                                cout << "Endereco: " << hospede.getEndereco().getEndereco() << endl;
                                cout << "Cartao:   " << hospede.getCartao().getCartao() << endl;
                            }
                            cout << "------------------------" << endl;
                        }
                    } else {
                        cout << "Erro: Hotel nao encontrado ou falha na listagem." << endl;
                    }
                }
                catch (const invalid_argument &exp) {
                    cout << "Erro no codigo do hotel: " << exp.what() << endl;
                }
                break;
            }
            case 20: {
                cout << "---- Listagem de quartos do Hotel ----" << endl;
                try {
                    Hotel hotelFiltro;
                    Codigo codigo;
                    string entradaCodigo;

                    cout << "Digite o Codigo do Hotel para listar seus quartos: ";
                    cin >> entradaCodigo;
                    codigo.setCodigo(entradaCodigo);
                    hotelFiltro.setCodigo(codigo);

                    vector<Quarto> listaDeQuartos;

                    if (cntrIS_Reservas->listarQuartosDoHotel(hotelFiltro, listaDeQuartos)) {

                        if (listaDeQuartos.empty()) {
                            cout << "Nenhum quarto encontrado para este hotel." << endl;
                        } else {
                            for (const auto& quarto : listaDeQuartos) {
                                cout << "------------------------" << endl;
                                cout << "Numero:  " << quarto.getNumero().getNumero() << endl;
                                cout << "Capacidade: " << quarto.getCapacidade().getCapacidade() << endl;
                                cout << "Diaria: " << quarto.getDiaria().getDinheiro() << endl;
                                cout << "Ramal: " << quarto.getRamal().getRamal() << endl;
                            }
                            cout << "------------------------" << endl;
                        }
                    } else {
                        cout << "Erro: Hotel nao encontrado ou falha na listagem." << endl;
                    }
                }
                catch (const invalid_argument &exp) {
                    cout << "Erro no codigo do hotel: " << exp.what() << endl;
                }
                break;
            }
        }
    }
}

//-----------------------------falta formatar para seguir o mesmo padrao do outro code(augusto)----------------------------------//


void CntrIUPessoal::criar() {
    cout << "---- Cadastro de Novo Gerente ----" << endl;
    try {
        Nome nome;
        Email email;
        Senha senha;
        Ramal ramal;
        Gerente gerente;

        string entradaNome, entradaEmail, entradaSenha, entradaRamal;

        cout << "Digite o nome: ";
        getline(cin >> ws, entradaNome);
        nome.setNome(entradaNome);
        gerente.setNome(nome);

        cout << "Digite o email: ";
        cin >> entradaEmail;
        email.setEmail(entradaEmail);
        gerente.setEmail(email);

        cout << "Digite a senha: ";
        cin >> entradaSenha;
        senha.setSenha(entradaSenha);
        gerente.setSenha(senha);

        cout << "Digite o ramal: ";
        cin >> entradaRamal;
        ramal.setRamal(entradaRamal);
        gerente.setRamal(ramal);

        bool resultado = cntrIS_Pessoal->criarGerente(gerente);

        if(resultado) {
            cout << "Gerente cadastrado com sucesso!" << endl;
        } else {
            cout << "Falha no cadastro." << endl;
        }
    }
    catch (const invalid_argument &exp) {
        cout << "Erro nos dados: " << exp.what() << endl;
    }
    catch (const out_of_range &exp) {
        cout << "Erro nos dados: " << exp.what() << endl;
    }
    catch (const length_error &exp) {
        cout << "Erro nos dados: " << exp.what() << endl;
    }
}

void CntrIUPessoal::executar(Email emailLogado) {
    int opcao = -1;

    while(opcao != 0) {
        cout << endl << "---- MENU DE PESSOAL ----" << endl;
        cout << "Usuario logado: " << emailLogado.getEmail() << endl;
        cout << "0. Voltar ao menu de inicializacao" << endl;
        cout << "1. Criar Gerente" << endl;
        cout << "2. Ler Gerente" << endl;
        cout << "3. Editar Gerente" << endl;
        cout << "4. Excluir Gerente" << endl;
        cout << "Digite a opcao: ";
        cin >> opcao;

        switch(opcao) {
            case 0:
                cout << "Voltando ao menu principal..." << endl;
                break;
            case 1: {
                cout << "\n----Criacao de hoteis----" << endl;
                try {
                    Nome nome;
                    Email email;
                    Ramal ramal;
                    Senha senha;
                    Gerente gerente;

                    string entradaNome, entradaEmail, entradaRamal, entradaSenha;


                    cout << "Digite o nome do gerente: ";
                    getline(cin >> ws, entradaNome);
                    nome.setNome(entradaNome);
                    gerente.setNome(nome);
                    cout << "Digite o email do gerente: ";
                    getline(cin >> ws, entradaEmail);
                    email.setEmail(entradaEmail);
                    gerente.setEmail(email);
                    cout << "Digite o ramal do gerente: ";
                    cin >> entradaRamal;
                    ramal.setRamal(entradaRamal);
                    gerente.setRamal(ramal);
                    cout << "Digite a senha do gerente: ";
                    cin >> entradaSenha;
                    senha.setSenha(entradaSenha);
                    gerente.setSenha(senha);

                    bool resultado = cntrIS_Pessoal->criarGerente(gerente);

                    if(resultado){
                        cout << "gerente criado com sucesso!\n" << endl;
                    } else {
                        cout << "Falha ao criar o gerente.\n" << endl;
                    }
                }
                catch (const invalid_argument &exp) {
                    cout << endl << "Erro: " << exp.what() << endl;
                    cout << "Por favor, tente novamente." << endl;
                }
                break;
            }
            case 2: {
                cout << "----Leitura de Gerentes----" << endl;
                try{
                    Email email;
                    Gerente gerente;
                    string entradaEmail;

                    cout << "Digite o email do gerente a ser pesquisado: ";
                    cin >> entradaEmail;
                    email.setEmail(entradaEmail);
                    gerente.setEmail(email);

                    bool encontrou = cntrIS_Pessoal->lerGerente(gerente);

                    if(encontrou){
                        cout << "\n----Informacoes do gerente pesquisado----" << endl;

                        cout << "Nome: " << gerente.getNome().getNome() << endl;
                        cout << "Email: " << gerente.getEmail().getEmail() << endl;
                        cout << "Ramal: " << gerente.getRamal().getRamal() << endl;
                    } else {
                        cout << "gerente nao foi encontrado com esse email." << endl;
                    }
                }
                catch (const invalid_argument &exp) {
                    cout << endl << "Erro: " << exp.what() << endl;
                    cout << "Por favor, tente novamente." << endl;
                }
                break;
            }
            case 3: {
                cout << "----Edicao de gerentes----" << endl;
                try {
                    Email email;
                    string entradaEmail;
                    cout << "Digite o email do gerente a ser editado: ";
                    cin >> entradaEmail;
                    email.setEmail(entradaEmail);

                    Gerente gerenteAtualizado;
                    gerenteAtualizado.setEmail(email);

                    Nome novoNome;
                    string entradaNome;
                    cout << "Digite o novo nome do gerente: ";
                    getline(cin >> ws, entradaNome);
                    novoNome.setNome(entradaNome);
                    gerenteAtualizado.setNome(novoNome);

                    Ramal novoRamal;
                    string entradaRamal;
                    cout << "Digite o novo ramal do gerente: ";
                    getline(cin >> ws, entradaRamal);
                    novoRamal.setRamal(entradaRamal);
                    gerenteAtualizado.setRamal(novoRamal);

                    Senha novaSenha;
                    string entradaSenha;
                    cout << "Digite a nova senha do gerente: ";
                    cin >> entradaSenha;
                    novaSenha.setSenha(entradaSenha);
                    gerenteAtualizado.setSenha(novaSenha);

                    bool sucesso = cntrIS_Pessoal->atualizarGerente(gerenteAtualizado);

                    if(sucesso){
                        cout << "Gerente editado com sucesso!" << endl;
                    } else {
                        cout << "Gerente nao encontrado ou erro na edicao." << endl;
                    }
                }
                catch (const invalid_argument &exp) {
                    cout << endl << "Erro nos dados: " << exp.what() << endl;
                }
                break;
            }
            case 4: {
                cout << "----Excluir gerentes----" << endl;
                try{
                    Gerente gerente;
                    Email email;
                    string entradaEmail;
                    char confirmacao;

                    cout << "Digite o email do gerente a ser excluido: ";
                    cin >> entradaEmail;

                    email.setEmail(entradaEmail);
                    gerente.setEmail(email);

                    cout << "Tem certeza que deseja excluir este gerente? (S/N): ";
                    cin >> confirmacao;

                    if(confirmacao == 'S' || confirmacao == 's'){
                        bool resultado = cntrIS_Pessoal->descadastrarGerente(gerente);
                        if(resultado){
                            cout << "gerente excluido com sucesso!" << endl;
                        } else {
                            cout << "Falha ao excluir gerente." << endl;
                        }
                    } else {
                        cout << "Operacao cancelada." << endl;
                    }
                }
                catch (const invalid_argument &exp) {
                    cout << endl << "Erro: " << exp.what() << endl;
                    cout << "Por favor, tente novamente." << endl;
                }
                break;
            }
        }
    }
}

//----------------------------------FIM AUGUSTO-------------------

bool CntrISReservas::criarHotel(Hotel hotel){
    return ContainerHoteis::getInstancia()->incluir(hotel);
}

bool CntrISReservas::lerHotel(Hotel& hotel){
    return ContainerHoteis::getInstancia()->pesquisar(&hotel);
}

bool CntrISReservas::editarHotel(Hotel hotel){
    return ContainerHoteis::getInstancia()->atualizar(hotel);
}

bool CntrISReservas::excluirHotel(Hotel hotel) {
    string codigoHotel = hotel.getCodigo().getCodigo();

    vector<Quarto> quartosDoHotel;
    ContainerQuartos::getInstancia()->listar(codigoHotel, quartosDoHotel);
    for (const auto& quarto : quartosDoHotel) {
        ContainerQuartos::getInstancia()->remover(quarto.getNumero().getNumero());
    }

    vector<Reserva> reservasDoHotel;
    ContainerReservas::getInstancia()->listar(codigoHotel, reservasDoHotel);
    for(const auto& reserva : reservasDoHotel) {
        ContainerReservas::getInstancia()->remover(reserva.getCodigo().getCodigo());
    }

    return ContainerHoteis::getInstancia()->remover(hotel.getCodigo().getCodigo());
}

bool CntrISReservas::listarHotel(vector<Hotel>& hoteis){
    return ContainerHoteis::getInstancia()->listar(hoteis);
}

long converterData(string data) {
    map<string, string> meses;
    meses["JAN"] = "01"; meses["FEV"] = "02"; meses["MAR"] = "03";
    meses["ABR"] = "04"; meses["MAI"] = "05"; meses["JUN"] = "06";
    meses["JUL"] = "07"; meses["AGO"] = "08"; meses["SET"] = "09";
    meses["OUT"] = "10"; meses["NOV"] = "11"; meses["DEZ"] = "12";

    string dia = data.substr(0, 2);
    string mesTexto = data.substr(3, 3);
    string ano = data.substr(7, 4);

    string dataFormatada = ano + meses[mesTexto] + dia;
    return stol(dataFormatada);
}

bool CntrISReservas::criarReserva(Reserva reserva){

    Quarto quartoBusca;
    quartoBusca.setNumero(reserva.getNumeroQuarto());

    if (ContainerQuartos::getInstancia()->pesquisar(&quartoBusca) == false) {
        return false;
    }

    Hospede hospedeBusca;
    hospedeBusca.setEmail(reserva.getEmailHospede());

    if (ContainerHospedes::getInstancia()->pesquisar(&hospedeBusca) == false) {
        return false;
    }

    vector<Reserva> todasReservas;
    ContainerReservas::getInstancia()->listar(todasReservas);
    string hotelNova = reserva.getCodigoHotel().getCodigo();
    string quartoNova = reserva.getNumeroQuarto().getNumero();
    long inicioNova = converterData(reserva.getChegada().getData());
    long fimNova = converterData(reserva.getPartida().getData());

    for (const auto& resExistente : todasReservas) {
        if (resExistente.getCodigoHotel().getCodigo() == hotelNova &&
            resExistente.getNumeroQuarto().getNumero() == quartoNova) {

            long inicioExistente = converterData(resExistente.getChegada().getData());
            long fimExistente = converterData(resExistente.getPartida().getData());

            if (inicioNova <= fimExistente && inicioExistente <= fimNova) {
                return false;
            }
        }
    }
    return ContainerReservas::getInstancia()->incluir(reserva);
}

bool CntrISReservas::lerReserva(Reserva& reserva){
    return ContainerReservas::getInstancia()->pesquisar(&reserva);
}

bool CntrISReservas::editarReserva(Reserva reserva){
    return ContainerReservas::getInstancia()->atualizar(reserva);
}

bool CntrISReservas::excluirReserva(Reserva reserva){
    return ContainerReservas::getInstancia()->remover(reserva.getCodigo().getCodigo());
}

bool CntrISReservas::listarReservasDoHotel(const Hotel& hotel, vector<Reserva>& reservas){
    return ContainerReservas::getInstancia()->listar(hotel.getCodigo().getCodigo(), reservas);
}

bool ContainerReservas::listar(vector<Reserva>& reservas) {
    reservas.clear();
    for (auto const& [chave, valor] : container) {
        reservas.push_back(valor);
    }
    return true;
}

bool CntrISReservas::criarHospede(Hospede hospede){
    return ContainerHospedes::getInstancia()->incluir(hospede);
}

bool CntrISReservas::lerHospede(Hospede& hospede){
    return ContainerHospedes::getInstancia()->pesquisar(&hospede);
}

bool CntrISReservas::editarHospede(Hospede hospede){
    return ContainerHospedes::getInstancia()->atualizar(hospede);
}

bool CntrISReservas::excluirHospede(Hospede hospede){
    string emailAlvo = hospede.getEmail().getEmail();

    vector<Reserva> todasReservas;
    ContainerReservas::getInstancia()->listar(todasReservas);

    for (const auto& res : todasReservas) {
        if (res.getEmailHospede().getEmail() == emailAlvo) {
            return false;
        }
    }

    return ContainerHospedes::getInstancia()->remover(hospede.getEmail().getEmail());
}

bool CntrISReservas::listarHospedesDoHotel(const Hotel& hotel, vector<Hospede>& hospedes){
    return ContainerHospedes::getInstancia()->listar(hotel.getCodigo().getCodigo(), hospedes);
}

bool ContainerHospedes::listar(vector<Hospede>& hospedes) {
    hospedes.clear();
    for (auto const& [chave, hospede] : container) {
        hospedes.push_back(hospede);
    }
    return true;
}

bool CntrISReservas::criarQuarto(Quarto quarto){
    return ContainerQuartos::getInstancia()->incluir(quarto);
}

bool CntrISReservas::lerQuarto(Quarto& quarto){
    return ContainerQuartos::getInstancia()->pesquisar(&quarto);
}

bool CntrISReservas::editarQuarto(Quarto quarto){
    return ContainerQuartos::getInstancia()->atualizar(quarto);
}

bool CntrISReservas::excluirQuarto(Quarto quarto){
    string numeroAlvo = quarto.getNumero().getNumero();

    vector<Reserva> todasReservas;
    ContainerReservas::getInstancia()->listar(todasReservas);

    for (const auto& res : todasReservas) {
        if (res.getNumeroQuarto().getNumero() == numeroAlvo) {
            return false;
        }
    }

    return ContainerQuartos::getInstancia()->remover(quarto.getNumero().getNumero());
}

bool CntrISReservas::listarQuartosDoHotel(const Hotel& hotel, vector<Quarto>& quartos){
    return ContainerQuartos::getInstancia()->listar(hotel.getCodigo().getCodigo(), quartos);
}

bool ContainerQuartos::listar(vector<Quarto>& quartos) {
    quartos.clear();
    for (auto const& [chave, quarto] : container) {
        quartos.push_back(quarto);
    }
    return true;
}

void CntrApresentacaoInicial::executar(){

        int opcaoInicial = -1;
        Email emailLogado;

        cout<<"----Sistema de hoteis----"<< endl;
        cout<<"Dica de Login(Stub):" << StubISAutenticacao::TRIGGER_SUCESSO_EMAIL << "/" << StubISAutenticacao::TRIGGER_SUCESSO_SENHA << endl;

        while(opcaoInicial != 0){
            cout<<endl<<"========= MENU INICIAL ========="<<endl;
            cout<<"1. Fazer login"<<endl;
            cout<<"2. Cadastrar Novo Gerente(Sign Up)"<< endl;
            cout<<"0. Sair do Sistema" << endl;
            cout<<"Escolha uma opcao: ";
            cin>>opcaoInicial;

            switch(opcaoInicial){
                case 1:{
                    if(cntrApresentacaoAutenticacao->autenticar(emailLogado)){
                        cout<<"\nLogin realizado com sucesso! Bem vindo(a), "<<emailLogado.getEmail() << endl;

                        int opcaoLogado = -1;
                        while(opcaoLogado != 0){
                            cout<<endl<<"------- MENU PRINCIPAL -------" <<endl;
                            cout<<"1. Modulo de Pessoal(Teste com Stub)" << endl;
                            cout<<"2. Modulo de Reservas(Sistema Real)" << endl;
                            cout<<"0. Deslogar (Voltar ao inicio)"<<endl;
                            cout<<"Escolha uma opcao: ";
                            cin>>opcaoLogado;

                            switch(opcaoLogado){
                                case 1:{
                                    cntrApresentacaoPessoal->executar(emailLogado);
                                    break;
                                }
                                case 2:{
                                    cntrApresentacaoReservas->executar(emailLogado);
                                    break;

                                }
                                case 0:{
                                    cout<<"Deslogando..."<<endl;
                                    break;
                                }
                                default:{
                                    cout<<"Opcao invalida."<<endl;
                                }
                            }
                        }
                    }
                    else{
                        cout<<"Falha na autenticacao. Verifique suas credenciais" << endl;
                    }
                    break;
                }
                case 2:{
                    cntrApresentacaoPessoal->criar();
                    break;
                }
                case 0:{
                    cout<<"Encerrando o programa. Até logo!"<<endl;
                    break;
                }
                default:{
                    cout<<"Opcao invalida"<<endl;
                }

            }
        }
}

bool CntrISPessoal::criarGerente(Gerente gerente){
    return ContainerGerentes::getInstancia()->incluir(gerente);
}

bool CntrISPessoal::lerGerente(Gerente& gerente){
    return ContainerGerentes::getInstancia()->pesquisar(&gerente);
}

bool CntrISPessoal::atualizarGerente(Gerente gerente){
    return ContainerGerentes::getInstancia()->atualizar(gerente);
}

bool CntrISPessoal::descadastrarGerente(Gerente gerente){
    string emailAlvo = gerente.getEmail().getEmail();
    if (ContainerHoteis::getInstancia()->existeHotelDoGerente(emailAlvo)) {
        return false;
    }
    return ContainerGerentes::getInstancia()->remover(gerente.getEmail().getEmail());
}

bool CntrISAutenticacao::autenticar(Email email, Senha senha){
    ContainerGerentes *container = ContainerGerentes::getInstancia();

    Gerente gerenteBusca;
    gerenteBusca.setEmail(email);

    if(container->pesquisar(&gerenteBusca)){
        if(gerenteBusca.getSenha().getSenha() == senha.getSenha()){
            return true;
        }
    }
    return false;
}
