#include <iostream>
using namespace std;

// Estrutura do nó da pilha
struct No {
    int dado;
    No* prox;
};

// Empilhar (push)
void push(No*& topo, int valor) {
    No* novoNo = new No;
    novoNo->dado = valor;
    novoNo->prox = topo;
    topo = novoNo;
}

// Desempilhar (pop)
void pop(No*& topo) {
    if (topo == nullptr) {
        cout << "Pilha vazia!\n";
        return;
    }
    No* temp = topo;
    topo = topo->prox;
    cout << "Desempilhado: " << temp->dado << endl;
    delete temp;
}

// Consultar topo
int top(No* topo) {
    if (topo == nullptr) {
        cout << "Pilha vazia!\n";
        return -1;
    }
    return topo->dado;
}

// Exibir pilha com ASCII art
void exibirPilha(No* topo) {
    if (topo == nullptr) {
        cout << "[ VAZIA ]\n";
        return;
    }
    cout << "Topo ->\n";
    No* atual = topo;
    while (atual != nullptr) {
        cout << "+-----+\n";
        cout << "| " << atual->dado << " |\n";
        cout << "+-----+\n";
        atual = atual->prox;
    }
    cout << "NULL\n";
}

// Liberar memória
void liberarPilha(No*& topo) {
    while (topo != nullptr) {
        pop(topo);
    }
}

// Menu interativo
void menu() {
    No* pilha = nullptr;
    int opcao, valor;

    do {
        cout << "\n--- Pilha Interativa ---\n";
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

    liberarPilha(pilha);
}

int main() {
    menu();
    return 0;
}
