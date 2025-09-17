#include <iostream>
using namespace std;

class No {
public:
    int valor;
    No* esquerda;
    No* direita;

    No(int v) {
        valor = v;
        esquerda = direita = nullptr;
    }
};

No* inserir(No* raiz, int valor) {
    if (raiz == nullptr)
        return new No(valor);

    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserir(raiz->direita, valor);

    return raiz;
}

int buscar(No* raiz, int valor) {
    if (raiz == nullptr)
        return 0;
    if (raiz->valor == valor)
        return 1;
    else if (valor < raiz->valor)
        return buscar(raiz->esquerda, valor);
    else
        return buscar(raiz->direita, valor);
}

int main() {
    No* raiz = nullptr;

    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    int valores[] = {60, 25, 40};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++) {
        if (buscar(raiz, valores[i]) == 1)
            cout << "Valor " << valores[i] << " encontrado na arvore." << endl;
        else
            cout << "Valor " << valores[i] << " NAO encontrado na arvore." << endl;
    }

    return 0;
}
