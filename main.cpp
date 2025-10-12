#include <iostream>
#include <string>
#include<limits>
#include "dominios.hpp"
#include "entidades.hpp"
#include <stdexcept>
#include "testes.hpp"
using namespace std;

int main() {
// Adicione isso na sua main.cpp

cout << "\n--- Testando a classe Codigo ---" << endl;
Codigo codigo_teste;

// Cenário de Sucesso
try {
    codigo_teste.setCodigo("a1b2c3d4e5");
    cout << "SUCESSO: Codigo definido como '" << codigo_teste.getCodigo() << "'" << endl;
} catch (const exception& e) {
    cout << "FALHA (INESPERADA): " << e.what() << endl;
}

// Cenário de Falha (comprimento incorreto)
try {
    codigo_teste.setCodigo("a1b2c3");
    cout << "FALHA (INESPERADA): Codigo invalido foi aceito." << endl;
} catch (const exception& e) {
    cout << "SUCESSO (ESPERADO): Erro detectado. Mensagem: " << e.what() << endl;
}

// Cenário de Falha (caractere inválido - letra maiúscula)
try {
    codigo_teste.setCodigo("a1b2C3d4e5");
    cout << "FALHA (INESPERADA): Codigo invalido foi aceito." << endl;
} catch (const exception& e) {
    cout << "SUCESSO (ESPERADO): Erro detectado. Mensagem: " << e.what() << endl;
}

// Cenário de Falha (caractere inválido - símbolo)
try {
    codigo_teste.setCodigo("a1b2c-d4e5");
    cout << "FALHA (INESPERADA): Codigo invalido foi aceito." << endl;
} catch (const exception& e) {
    cout << "SUCESSO (ESPERADO): Erro detectado. Mensagem: " << e.what() << endl;
}
    return 0;
}
