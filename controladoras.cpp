#include "controladoras.hpp"
#include "dominios.hpp"
#include "entidades.hpp"

bool CntrIUAutenticacao::autenticar(Email &gerente) {
    Email email;
    Senha senha;
    string entradaEmail, entradaSenha;

    while(true) {
        cout << endl << "Autenticacao de usuario." << endl;
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

            }
        }

    }



}
