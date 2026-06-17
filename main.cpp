
// Autor: Paulo Sergio Theodoro
// Descrição: Autômato de pilha para reconhecer L = {0^n1^n | n >= 1}
#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

bool automato_pilha(string palavra) {
    stack<char> pilha;
    string estado = "q0";

    for (char simbolo : palavra) {

        if (estado == "q0") {

            if (simbolo == '0') {
                pilha.push('x'); // Empilha x para cada 0 lido
            }

            else if (simbolo == '1') {
                if (pilha.empty()) {
                    return false;
                }

                pilha.pop();     // Desempilha x
                estado = "q1";   // Muda para o estado q1
            }

            else {
                return false; // Rejeita símbolos diferentes de 0 e 1
            }
        }

        else if (estado == "q1") {

            if (simbolo == '1') {
                if (pilha.empty()) {
                    return false;
                }

                pilha.pop(); // Desempilha x para cada 1 lido
            }

            else {
                return false; // Rejeita se aparecer 0 depois de 1
            }
        }
    }

    if (pilha.empty() && estado == "q1") {
        return true;
    } else {
        return false;
    }
}

int main() {

    // Testes
    vector<string> palavras = {
        "01",
        "0011",
        "011",
        "001",
        "000111",
        "0111",
        "00011",
        "a1",
        "(1",
        "0)",
        "00001111"
    };

    for (string palavra : palavras) {
        if (automato_pilha(palavra)) {
            cout << palavra << " => aceita" << endl;
        } else {
            cout << palavra << " => rejeitada" << endl;
        }
    }

    return 0;
}