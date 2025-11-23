#include <iostream>
#include "dominios.hpp"
#include "entidades.hpp"
#include "testes.hpp"
#include "controladoras.hpp"
#include "stubs.hpp"

using namespace std;

int main() {

    CntrIUAutenticacao cntrApresentacaoAuth;
    CntrIUReservas cntrReservas;
    CntrIUPessoal cntrPessoal;

    CntrISAutenticacao* ServicoAuth = new CntrISAutenticacao();
    CntrISPessoal* servicoPessoal = new CntrISPessoal();
    CntrISReservas* servicoReservas = new CntrISReservas();

    cntrApresentacaoAuth.setCntrSAutenticacao(ServicoAuth);
    cntrPessoal.setCntrIS_Pessoal(servicoPessoal);
    cntrReservas.setCntrIS_Reservas(servicoReservas);

int opcaoInicial = -1;
    Email emailLogado;

    cout << "----Sistema de hoteis----" << endl;

    while (opcaoInicial != 0) {
        cout << endl << "========= MENU INICIAL =========" << endl;
        cout << "1. Fazer Login" << endl;
        cout << "2. Cadastrar Novo Gerente" << endl;
        cout << "0. Sair do Sistema" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcaoInicial;

        switch (opcaoInicial) {
            case 1: {
                if (cntrApresentacaoAuth.autenticar(emailLogado)) {

                    cout << "\nLogin realizado com sucesso! Bem-vindo, " << emailLogado.getEmail() << endl;

                    int opcaoLogado = -1;
                    while (opcaoLogado != 0) {
                        cout << endl << "------- MENU PRINCIPAL -------" << endl;
                        cout << "1. Modulo de Pessoal (Sistema Real)" << endl;
                        cout << "2. Modulo de Reservas (Sistema Real)" << endl;
                        cout << "0. Deslogar (Voltar ao inicio)" << endl;
                        cout << "Escolha: ";
                        cin >> opcaoLogado;

                        switch (opcaoLogado) {
                            case 1:
                                cntrPessoal.executar(emailLogado);
                                break;

                            case 2:
                                cntrReservas.executar(emailLogado);
                                break;

                            case 0:
                                cout << "Deslogando..." << endl;
                                break;

                            default:
                                cout << "Opcao invalida." << endl;
                        }
                    }
                } else {
                    cout << "Falha na autenticacao. Verifique suas credenciais." << endl;
                }
                break;
            }

            case 2: {
                cntrPessoal.criar();
                break;
            }
            case 0: {
                cout << "Encerrando o programa. Ate logo!" << endl;
                break;
            }
            default:
                cout << "Opcao invalida." << endl;
        }
    }

    delete ServicoAuth;
    delete servicoPessoal;
    delete servicoReservas;

    return 0;
}
