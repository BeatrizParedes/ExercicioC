#include <iostream>
using namespace std;
#define MAX 5

struct FilaCircular {
    int dados[MAX];
    int frente;
    int tras;
    int tamanho;
};

void inicializar(FilaCircular &f) {
    f.frente = 0;
    f.tras = -1;
    f.tamanho = 0;
}

bool cheia(FilaCircular &f) { return f.tamanho == MAX; }
bool vazia(FilaCircular &f) { return f.tamanho == 0; }

void enqueue(FilaCircular &f, int valor) {
    if (cheia(f)) {
        f.tras = (f.tras + 1) % MAX;
        cout << "Fila cheia! Sobrescrevendo.\n";
    } else {
        f.tras = (f.tras + 1) % MAX;
        f.tamanho++;
    }
    f.dados[f.tras] = valor;
    cout << "Enfileirado: " << valor << endl;
}

void dequeue(FilaCircular &f) {
    if (vazia(f)) { cout << "Fila vazia!\n"; return; }
    cout << "Desenfileirado: " << f.dados[f.frente] << endl;
    f.frente = (f.frente + 1) % MAX;
    f.tamanho--;
}

void exibir(FilaCircular &f) {
    if (vazia(f)) { cout << "[ VAZIA ]\n"; return; }
    cout << "Frente -> ";
    for (int i = 0; i < f.tamanho; i++) {
        int idx = (f.frente + i) % MAX;
        cout << f.dados[idx] << " -> ";
    }
    cout << "Tras\n";
}

void menu() {
    FilaCircular fila;
    inicializar(fila);
    int opcao, valor;

    do {
        cout << "\n--- Fila Circular ---\n";
        cout << "1. Enfileirar\n2. Desenfileirar\n3. Exibir\n0. Sair\nEscolha: ";
        cin >> opcao;

        switch(opcao) {
            case 1: cout << "Valor: "; cin >> valor; enqueue(fila, valor); break;
            case 2: dequeue(fila); break;
            case 3: exibir(fila); break;
            case 0: cout << "Saindo...\n"; break;
            default: cout << "Inválido!\n";
        }

    } while(opcao != 0);
}

int main() { menu(); return 0; }
