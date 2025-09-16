#include <iostream>
using namespace std;

// Estrutura do nó
struct No {
    int dado;
    No* prox;
};

// Criar um novo nó
No* criarNo(int valor) {
    No* novoNo = new No;
    novoNo->dado = valor;
    novoNo->prox = nullptr;
    return novoNo;
}

// Inserir no início da lista
void inserirInicio(No*& cabeca, int valor) {
    No* novoNo = criarNo(valor);
    novoNo->prox = cabeca;
    cabeca = novoNo;
}

// Inserir no final da lista
void inserirFinal(No*& cabeca, int valor) {
    No* novoNo = criarNo(valor);
    if (cabeca == nullptr) {
        cabeca = novoNo;
        return;
    }
    No* atual = cabeca;
    while (atual->prox != nullptr) {
        atual = atual->prox;
    }
    atual->prox = novoNo;
}

// Remover do início
void removerInicio(No*& cabeca) {
    if (cabeca == nullptr) return;
    No* temp = cabeca;
    cabeca = cabeca->prox;
    delete temp;
}

// Remover por valor
void removerValor(No*& cabeca, int valor) {
    if (cabeca == nullptr) return;

    if (cabeca->dado == valor) {
        removerInicio(cabeca);
        return;
    }

    No* atual = cabeca;
    while (atual->prox != nullptr && atual->prox->dado != valor) {
        atual = atual->prox;
    }

    if (atual->prox == nullptr) return; // valor não encontrado

    No* temp = atual->prox;
    atual->prox = temp->prox;
    delete temp;
}

// Buscar valor na lista
No* buscar(No* cabeca, int valor) {
    No* atual = cabeca;
    while (atual != nullptr) {
        if (atual->dado == valor) return atual;
        atual = atual->prox;
    }
    return nullptr; // não encontrado
}

// Exibir a lista
void exibirLista(No* cabeca) {
    No* atual = cabeca;
    while (atual != nullptr) {
        cout << atual->dado << " -> ";
        atual = atual->prox;
    }
    cout << "NULL\n";
}

// Função principal
int main() {
    No* lista = nullptr;

    // Inserindo elementos
    inserirInicio(lista, 10);
    inserirInicio(lista, 20);
    inserirFinal(lista, 30);
    inserirFinal(lista, 40);

    cout << "Lista atual: ";
    exibirLista(lista);

    // Removendo elemento
    cout << "Removendo o valor 20...\n";
    removerValor(lista, 20);
    exibirLista(lista);

    // Buscando elemento
    cout << "Buscando o valor 30...\n";
    No* encontrado = buscar(lista, 30);
    if (encontrado)
        cout << "Valor encontrado: " << encontrado->dado << endl;
    else
        cout << "Valor não encontrado\n";

    // Liberando memória
    while (lista != nullptr) {
        removerInicio(lista);
    }

    return 0;
}
