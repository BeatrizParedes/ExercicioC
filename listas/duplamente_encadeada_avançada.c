#include <iostream>
using namespace std;

// Estrutura do nó
struct No {
    int dado;
    No* prox;
    No* ant;
};

// Criar novo nó
No* criarNo(int valor) {
    No* novoNo = new No;
    novoNo->dado = valor;
    novoNo->prox = nullptr;
    novoNo->ant = nullptr;
    return novoNo;
}

// Inserir no início
void inserirInicio(No*& cabeca, int valor) {
    No* novoNo = criarNo(valor);
    if (cabeca == nullptr) {
        cabeca = novoNo;
        cabeca->prox = cabeca;
        cabeca->ant = cabeca;
        return;
    }
    No* ultimo = cabeca->ant;
    novoNo->prox = cabeca;
    novoNo->ant = ultimo;
    ultimo->prox = novoNo;
    cabeca->ant = novoNo;
    cabeca = novoNo;
}

// Inserir no fim
void inserirFim(No*& cabeca, int valor) {
    No* novoNo = criarNo(valor);
    if (cabeca == nullptr) {
        cabeca = novoNo;
        cabeca->prox = cabeca;
        cabeca->ant = cabeca;
        return;
    }
    No* ultimo = cabeca->ant;
    ultimo->prox = novoNo;
    novoNo->ant = ultimo;
    novoNo->prox = cabeca;
    cabeca->ant = novoNo;
}

// Inserir em posição específica (1 = início)
void inserirPosicao(No*& cabeca, int valor, int pos) {
    if (pos <= 1 || cabeca == nullptr) {
        inserirInicio(cabeca, valor);
        return;
    }
    No* novoNo = criarNo(valor);
    No* atual = cabeca;
    int i = 1;
    while (i < pos - 1 && atual->prox != cabeca) {
        atual = atual->prox;
        i++;
    }
    novoNo->prox = atual->prox;
    novoNo->ant = atual;
    atual->prox->ant = novoNo;
    atual->prox = novoNo;
}

// Remover nó por valor
void removerValor(No*& cabeca, int valor) {
    if (cabeca == nullptr) return;

    No* atual = cabeca;
    do {
        if (atual->dado == valor) {
            if (atual->prox == atual) { // único nó
                delete atual;
                cabeca = nullptr;
                return;
            }
            atual->ant->prox = atual->prox;
            atual->prox->ant = atual->ant;
            if (atual == cabeca)
                cabeca = atual->prox;
            delete atual;
            return;
        }
        atual = atual->prox;
    } while (atual != cabeca);
}

// Buscar nó
No* buscar(No* cabeca, int valor) {
    if (cabeca == nullptr) return nullptr;
    No* atual = cabeca;
    do {
        if (atual->dado == valor) return atual;
        atual = atual->prox;
    } while (atual != cabeca);
    return nullptr;
}

// Exibir lista para frente
void exibirParaFrente(No* cabeca) {
    if (cabeca == nullptr) {
        cout << "Lista vazia.\n";
        return;
    }
    cout << "Percorrendo para frente: ";
    No* atual = cabeca;
    do {
        cout << atual->dado << " <-> ";
        atual = atual->prox;
    } while (atual != cabeca);
    cout << "(cabeça)\n";
}

// Exibir lista para trás
void exibirParaTras(No* cabeca) {
    if (cabeca == nullptr) {
        cout << "Lista vazia.\n";
        return;
    }
    cout << "Percorrendo para trás: ";
    No* atual = cabeca->ant; // último nó
    No* inicio = atual;
    do {
        cout << atual->dado << " <-> ";
        atual = atual->ant;
    } while (atual != inicio);
    cout << "(cabeça)\n";
}

// Liberar memória
void liberarCircular(No*& cabeca) {
    if (cabeca == nullptr) return;
    No* atual = cabeca->prox;
    while (atual != cabeca) {
        No* temp = atual;
        atual = atual->prox;
        delete temp;
    }
    delete cabeca;
    cabeca = nullptr;
}

// Menu interativo
void menu() {
    No* lista = nullptr;
    int opcao, valor, pos;

    do {
        cout << "\n--- Lista Circular Duplamente Encadeada Avançada ---\n";
        cout << "1. Inserir no início\n";
        cout << "2. Inserir no fim\n";
        cout << "3. Inserir em posição específica\n";
        cout << "4. Remover por valor\n";
        cout << "5. Buscar valor\n";
        cout << "6. Exibir lista para frente\n";
        cout << "7. Exibir lista para trás\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                cout << "Valor: ";
                cin >> valor;
                inserirInicio(lista, valor);
                break;
            case 2:
                cout << "Valor: ";
                cin >> valor;
                inserirFim(lista, valor);
                break;
            case 3:
                cout << "Valor: ";
                cin >> valor;
                cout << "Posição: ";
                cin >> pos;
                inserirPosicao(lista, valor, pos);
                break;
            case 4:
                cout << "Valor a remover: ";
                cin >> valor;
                removerValor(lista, valor);
                break;
            case 5:
                cout << "Valor a buscar: ";
                cin >> valor;
                if (buscar(lista, valor))
                    cout << "Valor encontrado!\n";
                else
                    cout << "Valor não encontrado.\n";
                break;
            case 6:
                exibirParaFrente(lista);
                break;
            case 7:
                exibirParaTras(lista);
                break;
            case 0:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opção inválida!\n";
        }

    } while (opcao != 0);

    liberarCircular(lista);
}

int main() {
    menu();
    return 0;
}
