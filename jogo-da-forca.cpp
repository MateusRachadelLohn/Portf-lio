#include <iostream>
#include <cstdlib>
#include <cctype> 

using namespace std;

int main() {

    char palavra[30], secreta[30];
    char entrada[10];
    char letra;
    int tam = 0, chances = 6, acertos = 0;
    bool valido, acertou;

    do {
        cout << "Fale para seu colega fechar o olho e digite uma palavra (somente letras, sem espacos): ";
        cin >> palavra;

        valido = true;

        for (int i = 0; palavra[i] != '\0'; i++) {
            if (!isalpha(palavra[i])) {
                valido = false;
                cout << "Palavra invalida! Use apenas letras, sem numeros ou espacos.\n";
                break;
            }
        }

    } while (!valido);

    system("cls");

    //palavra secreta
    while (palavra[tam] != '\0') {
        secreta[tam] = '-';
        tam++;
    }
    secreta[tam] = '\0';

    //main loop
    while (chances > 0 && acertos < tam) {

        cout << "\nPalavra: " << secreta << endl;
        cout << "Chances restantes: " << chances << endl;

        do {
            cout << "Digite uma letra (somente UMA letra): ";
            cin >> entrada;

            if (entrada[1] != '\0' || !isalpha(entrada[0])) {
                cout << "Entrada invalida! Digite apenas UMA letra.\n";
            }

        } while (entrada[1] != '\0' || !isalpha(entrada[0]));

        letra = entrada[0];
        acertou = false;

        //verificação da letra
        for (int i = 0; i < tam; i++) {
            if (letra == palavra[i] && secreta[i] == '-') {
                secreta[i] = letra;
                acertos++;
                acertou = true;
            }
        }

        if (!acertou) {
            chances--;
        }
    }

    system("cls");

    if (acertos == tam) {
        cout << "Parabens! Voce ganhou! A palavra era: " << palavra << endl;
    } else {
        cout << "Voce perdeu! A palavra era: " << palavra << endl;
    }

    return 0;
}
