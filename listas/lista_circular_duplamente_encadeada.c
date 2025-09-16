#include <iostream>
using namespace std;

struct No {
    int dado;
    No* prox;
    No* ant;
};

// Inserir no final
void inserir(No*& cabeca, int valor) {
    No* novo = new No{valor, nullptr, nullptr};
    if (!cabeca) {
        cabeca = novo;
        novo->prox = novo;
        novo->ant = novo;
        return;
    }
    No* ultimo = cabeca->ant;
    ultimo->prox = novo;
    novo->ant = ultimo;
    novo->prox = cabeca;
    cabeca->ant = novo;
}

// Exibir lista circular com setas
void exibir(No* cabeca) {
    if (!cabeca) {
        cout << "[ VAZIA ]\n";
        return;
    }
    No* temp = cabeca;
    do {
        cout << "+-----+     ";
        temp = temp->prox;
    } while (temp != cabeca);
    cout << "\n";
    
    temp = cabeca;
    do {
        cout << "| " << temp->dado << " | --> ";
        temp = temp->prox;
    } while (temp != cabeca);
    cout << "(volta para cabeça)\n";
}

// Menu interativo
void menu() {
    No* lista = nullptr;
    int opcao, valor;

    do {
        cout << "\n--- Lista Circular Duplamente Encadeada ---\n";
        cout << "1. Inserir no final\n";
        cout << "2. Exibir lista\n";
        cout << "0. Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                cout << "Valor: "; cin >> valor;
                inserir(lista, valor);
                break;
            case 2:
                exibir(lista);
                break;
            case 0:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opção inválida!\n";
        }

    } while(opcao != 0);
}

int main() {
    menu();
    return 0;
}
