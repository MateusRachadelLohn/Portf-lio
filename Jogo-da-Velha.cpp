#include <iostream>
#include <cstdlib>

using namespace std;

char tabuleiro[9] = {'1','2','3','4','5','6','7','8','9'};

void exibirTabuleiro() {
    system("cls"); 

    cout << "\n=== JOGO DA VELHA ===\n\n";
    cout << " " << tabuleiro[0] << " | " << tabuleiro[1] << " | " << tabuleiro[2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << tabuleiro[3] << " | " << tabuleiro[4] << " | " << tabuleiro[5] << endl;
    cout << "---|---|---" << endl;
    cout << " " << tabuleiro[6] << " | " << tabuleiro[7] << " | " << tabuleiro[8] << endl;
    cout << endl;
}

bool jogadorVenceu(char simbolo) {
    if (
        (tabuleiro[0] == simbolo && tabuleiro[1] == simbolo && tabuleiro[2] == simbolo) ||
        (tabuleiro[3] == simbolo && tabuleiro[4] == simbolo && tabuleiro[5] == simbolo) ||
        (tabuleiro[6] == simbolo && tabuleiro[7] == simbolo && tabuleiro[8] == simbolo) ||

        (tabuleiro[0] == simbolo && tabuleiro[3] == simbolo && tabuleiro[6] == simbolo) ||
        (tabuleiro[1] == simbolo && tabuleiro[4] == simbolo && tabuleiro[7] == simbolo) ||
        (tabuleiro[2] == simbolo && tabuleiro[5] == simbolo && tabuleiro[8] == simbolo) ||

        (tabuleiro[0] == simbolo && tabuleiro[4] == simbolo && tabuleiro[8] == simbolo) ||
        (tabuleiro[2] == simbolo && tabuleiro[4] == simbolo && tabuleiro[6] == simbolo)
    ) {
        return true;
    }

    return false;
}

bool deuEmpate() {
    for (int i = 0; i < 9; i++) {
        if (tabuleiro[i] != 'X' && tabuleiro[i] != 'O') {
            return false;
        }
    }
    return true;
}

void fazerJogada(char jogador) {
    int posicao;

    while (true) {
        cout << "Jogador " << jogador << ", escolha uma posicao (1 a 9): ";
        cin >> posicao;
        posicao--;

        if (posicao >= 0 && posicao <= 8 &&
            tabuleiro[posicao] != 'X' && tabuleiro[posicao] != 'O') {
            tabuleiro[posicao] = jogador;
            break;
        }

        cout << "Posicao invalida! Tente novamente.\n";
    }
}

int main() {

    char jogadorAtual = 'X';

    while (true) {
        exibirTabuleiro();
        fazerJogada(jogadorAtual);

        if (jogadorVenceu(jogadorAtual)) {
            exibirTabuleiro();
            cout << " Jogador " << jogadorAtual << " venceu o jogo!\n";
            break;
        }

        if (deuEmpate()) {
            exibirTabuleiro();
            cout << " O jogo terminou em empate!\n";
            break;
        }

        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
    }

    return 0;
}
