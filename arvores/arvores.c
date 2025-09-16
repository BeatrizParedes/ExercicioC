#include <iostream>
using namespace std;

struct No {
    int dado;
    No* esquerda;
    No* direita;
};

No* criarNo(int valor) {
    No* novo = new No;
    novo->dado = valor;
    novo->esquerda = nullptr;
    novo->direita = nullptr;
    return novo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == nullptr) return criarNo(valor);
    if (valor < raiz->dado)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else
        raiz->direita = inserir(raiz->direita, valor);
    return raiz;
}

bool buscar(No* raiz, int valor) {
    if (!raiz) return false;
    if (raiz->dado == valor) return true;
    if (valor < raiz->dado) return buscar(raiz->esquerda, valor);
    return buscar(raiz->direita, valor);
}

void preOrdem(No* raiz) {
    if (!raiz) return;
    cout << raiz->dado << " ";
    preOrdem(raiz->esquerda);
    preOrdem(raiz->direita);
}

void emOrdem(No* raiz) {
    if (!raiz) return;
    emOrdem(raiz->esquerda);
    cout << raiz->dado << " ";
    emOrdem(raiz->direita);
}

void posOrdem(No* raiz) {
    if (!raiz) return;
    posOrdem(raiz->esquerda);
    posOrdem(raiz->direita);
    cout << raiz->dado << " ";
}

void exibirArvore(No* raiz, int espaco = 0, int incremento = 5) {
    if (!raiz) return;
    espaco += incremento;
    exibirArvore(raiz->direita, espaco);
    cout << endl;
    for (int i = incremento; i < espaco; i++) cout << " ";
    cout << raiz->dado << "\n";
    exibirArvore(raiz->esquerda, espaco);
}

void menu() {
    No* raiz = nullptr;
    int opcao, valor;

    do {
        cout << "\n--- Árvore Binária de Busca ---\n";
        cout << "1. Inserir\n2. Buscar\n3. Pré-ordem\n4. Em-ordem\n5. Pós-ordem\n6. Exibir árvore\n0. Sair\nEscolha: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                cout << "Valor a inserir: "; cin >> valor;
                raiz = inserir(raiz, valor);
                break;
            case 2:
                cout << "Valor a buscar: "; cin >> valor;
                cout << (buscar(raiz, valor) ? "Encontrado!\n" : "Não encontrado!\n");
                break;
            case 3:
                cout << "Pré-ordem: "; preOrdem(raiz); cout << endl;
                break;
            case 4:
                cout << "Em-ordem: "; emOrdem(raiz); cout << endl;
                break;
            case 5:
                cout << "Pós-ordem: "; posOrdem(raiz); cout << endl;
                break;
            case 6:
                cout << "Árvore:\n"; exibirArvore(raiz); break;
            case 0: cout << "Saindo...\n"; break;
            default: cout << "Inválido!\n";
        }
    } while(opcao != 0);
}

int main() {
    menu();
    return 0;
}
