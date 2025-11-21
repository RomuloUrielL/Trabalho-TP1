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

    StubISAutenticacao* stubServicoAuth = new StubISAutenticacao();
    StubISReservas* stubReservas = new StubISReservas();

    cntrApresentacaoAuth.setCntrSAutenticacao(stubServicoAuth);
    cntrReservas.setCntrIS_Reservas(stubReservas);

    Email emailLogado;
    cout << "=== Credenciais para o teste ===" << endl;
    cout << "Para SUCESSO, use: emailteste@gmail.com / A3n5#" << endl;
    cout << "Para FALHA, use qualquer outra coisa." << endl;
    cout << "-----------------------------------------------------" << endl;

    bool resultado = cntrApresentacaoAuth.autenticar(emailLogado);

    if (resultado) {
        cout << "\nRESULTADO: Login realizado com SUCESSO!" << endl;
        cout << "Usuario logado: " << emailLogado.getEmail() << endl;

        cntrReservas.executar(emailLogado);
    } else {
        cout << "\nFalha no login." << endl;
    }

    delete stubServicoAuth;
    delete stubReservas;

    return 0;
}
