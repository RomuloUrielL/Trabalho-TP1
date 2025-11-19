#include "controladoras.hpp"
#include "dominios.hpp"
#include "entidades.hpp"

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
    return resultado;
}

void CntrIUReservas::executar(Email email){
    int opcao = -1;

    while(opcao != 0){
        cout << "---- SISTEMA DE RESERVAS ----" << endl;
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

        cout << "Digite a opção desejada: ";
        cin >> opcao;

        switch (opcao){
            case 1: {
                cout << "----Criação de hotéis----" << endl;
                try {
                    Nome nome;
                    Endereco endereco;
                    Telefone telefone;
                    Codigo codigo;
                    Hotel hotel;

                    string entradaNome, entradaEndereco, entradaTelefone, entradaCodigo;


                    cout << "Digite o nome do hotel: ";
                    cin >> entradaNome;
                    nome.setNome(entradaNome);
                    hotel.setNome(nome);
                    cout << "Digite o endereco do hotel: ";
                    cin >> entradaEndereco;
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

                    bool resultado = cntrIS_Reservas->criarHotel(hotel);

                    if(resultado){
                        cout << "Hotel criado com sucesso!" << endl;
                    } else {
                        cout << "Falha ao criar o hotel." << endl;
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
                        cout << "--Informações do hotel pesquisado" << endl;

                        cout << "Nome: " << hotel.getNome().getNome() << endl;
                        cout << "Endereco: " << hotel.getEndereco().getEndereco() << endl;
                        cout << "Telefone: " << hotel.getTelefone().getTelefone() << endl;
                        cout << "Codigo: " << hotel.getCodigo().getCodigo() << endl;
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
                    cin >> entradaNome;
                    novoNome.setNome(entradaNome);
                    hotelAtualizado.setNome(novoNome);

                    Endereco novoEndereco;
                    string entradaEndereco;
                    cout << "Digite o nome endereco: ";
                    cin >> entradaEndereco;
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
                    string entradaChegada, entradaPartida, entradaValor, entradaCodigo;


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
                        cout << "----Informações da reserva pesquisada----" << endl;

                        cout << "Chegada: " << reserva.getChegada().getData() << endl;
                        cout << "Partida: " << reserva.getPartida().getData() << endl;
                        cout << "Valor: " << reserva.getValor().getDinheiro() << endl;
                        cout << "Codigo: " << reserva.getCodigo().getCodigo() << endl;
                    } else {
                        cout << "Reserva não foi encontrada com esse codigo." << endl;
                    }
                }
                catch (const invalid_argument &exp) {
                    cout << endl << "Erro: " << exp.what() << endl;
                    cout << "Por favor, tente novamente." << endl;
                }
                break;
            }
            case 7: {
                cout << "----Edição de reservas----";
                try {
                    Reserva reserva;
                    Codigo codigo;
                    string entradaCodigo;

                    cout << "Digite o codigo da reserva a ser editado: ";
                    cin >> entradaCodigo;
                    codigo.setCodigo(entradaCodigo);
                    reserva.setCodigo(codigo);

                    bool encontrou = cntrIS_Reservas->editarReserva(reserva);

                    if(encontrou){

                    } else {
                        cout << "reserva não foi encontrado com esse codigo." << endl;
                    }
                }
                catch (const invalid_argument &exp) {
                    cout << endl << "Erro: " << exp.what() << endl;
                    cout << "Por favor, tente novamente." << endl;
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
        }
    }
}

