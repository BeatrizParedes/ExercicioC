#include <iostream>
#include <string>
using namespace std;

#define MAX 5  // tamanho máximo da pilha

struct PilhaCircular {
    int dados[MAX];
    string historico[MAX]; // para marcar sobrescritos
    int topo;
    int tamanho;
};

// Inicializar pilha
void inicializar(PilhaCircular &p) {
    p.topo = -1;
    p.tamanho = 0;
    for (int i = 0; i < MAX; i++) {
        p.historico[i] = "";
    }
}

// Verificar se cheia
bool cheia(PilhaCircular &p) {
    return p.tamanho == MAX;
}

// Verificar se vazia
bool vazia(PilhaCircular &p) {
    return p.tamanho == 0;
}

// Empilhar com histórico
void push(PilhaCircular &p, int valor) {
    if (cheia(p)) {
        p.topo = (p.topo + 1) % MAX;
        cout << "Pilha cheia! Sobrescrevendo: " << p.dados[p.topo] << endl;
        p.historico[p.topo] += " -> sobrescrito por " + to_string(valor);
        p.dados[p.topo] = valor;
    } else {
        p.topo = (p.topo + 1) % MAX;
        p.dados[p.topo] = valor;
        p.historico[p.topo] = "";
        p.tamanho++;
    }
    cout << "Empilhado: " << valor << endl;
}

// Desempilhar
void pop(PilhaCircular &p) {
    if (vazia(p)) {
        cout << "Pilha vazia!\n";
        return;
    }
    cout << "Desempilhado: " << p.dados[p.topo] << endl;
    p.topo = (p.topo - 1 + MAX) % MAX;
    p.tamanho--;
}

// Consultar topo
int top(PilhaCircular &p) {
    if (vazia(p)) {
        cout << "Pilha vazia!\n";
        return -1;
    }
    return p.dados[p.topo];
}

// Exibir pilha com histórico
void exibirPilha(PilhaCircular &p) {
    if (vazia(p)) {
        cout << "[ VAZIA ]\n";
        return;
    }
    cout << "Topo ->\n";
    for (int i = 0; i < p.tamanho; i++) {
        int idx = (p.topo - i + MAX) % MAX;
        cout << "+-----+\n";
        cout << "| " << p.dados[idx] << " |\n";
        cout << "+-----+\n";
        if (!p.historico[idx].empty())
            cout << "  Histórico: " << p.historico[idx] << endl;
    }
    cout << "Base\n";
}

// Menu interativo
void menu() {
    PilhaCircular pilha;
    inicializar(pilha);
    int opcao, valor;

    do {
        cout << "\n--- Pilha Circular Avançada com Histórico ---\n";
        cout << "1. Empilhar (push)\n";
        cout << "2. Desempilhar (pop)\n";
        cout << "3. Consultar topo\n";
        cout << "4. Exibir pilha\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                cout << "Valor a empilhar: ";
                cin >> valor;
                push(pilha, valor);
                break;
            case 2:
                pop(pilha);
                break;
            case 3:
                valor = top(pilha);
                if (valor != -1)
                    cout << "Topo da pilha: " << valor << endl;
                break;
            case 4:
                exibirPilha(pilha);
                break;
            case 0:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opção inválida!\n";
        }
    } while (opcao != 0);
}

int main() {
    menu();
    return 0;
}
