#include <iostream>
#include "dominios.hpp"
#include "entidades.hpp"
#include "testes.hpp"

using namespace std;

int main() {

    Dinheiro c;

    try {
        c.setDinheiro("1.000.000,00");
        cout << c.getDinheiro() << endl;
    } catch (const exception& e) {
        cerr << "Erro: " << e.what() << endl;
    }

    return 0;
}
