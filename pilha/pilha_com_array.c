#include <iostream>
using namespace std;

#define MAX 10  // tamanho máximo da pilha

// Estrutura da pilha
struct Pilha {
    int dados[MAX];
    int topo;
};

// Inicializar pilha
void inicializar(Pilha &p) {
    p.topo = -1;
}

// Verificar se está cheia
bool cheia(Pilha &p) {
    return p.topo == MAX - 1;
}

// Verificar se está vazia
bool vazia(Pilha &p) {
    return p.topo == -1;
}

// Empilhar (push)
void push(Pilha &p, int valor) {
    if (cheia(p)) {
        cout << "Pilha cheia!\n";
        return;
    }
    p.topo++;
    p.dados[p.topo] = valor;
    cout << "Empilhado: " << valor << endl;
}

// Desempilhar (pop)
void pop(Pilha &p) {
    if (vazia(p)) {
        cout << "Pilha vazia!\n";
        return;
    }
    cout << "Desempilhado: " << p.dados[p.topo] << endl;
    p.topo--;
}

// Consultar topo
int top(Pilha &p) {
    if (vazia(p)) {
        cout << "Pilha vazia!\n";
        return -1;
    }
    return p.dados[p.topo];
}

// Exibir pilha com ASCII art
void exibirPilha(Pilha &p) {
    if (vazia(p)) {
        cout << "[ VAZIA ]\n";
        return;
    }
    cout << "Topo ->\n";
    for (int i = p.topo; i >= 0; i--) {
        cout << "+-----+\n";
        cout << "| " << p.dados[i] << " |\n";
        cout << "+-----+\n";
    }
    cout << "Base\n";
}

// Menu interativo
void menu() {
    Pilha pilha;
    inicializar(pilha);
    int opcao, valor;

    do {
        cout << "\n--- Pilha com Array Interativa ---\n";
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
