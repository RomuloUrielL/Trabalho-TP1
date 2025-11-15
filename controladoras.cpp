#include "controladoras.hpp"

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
