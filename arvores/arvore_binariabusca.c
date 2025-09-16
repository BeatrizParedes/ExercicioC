#include <iostream>
using namespace std;

// Estrutura de um nó da árvore
struct No {
    int dado;       // valor armazenado no nó
    No* esquerda;   // ponteiro para filho à esquerda
    No* direita;    // ponteiro para filho à direita
};

// Função para criar um novo nó
No* criarNo(int valor) {
    No* novo = new No;       // aloca memória para o nó
    novo->dado = valor;      // define o valor
    novo->esquerda = nullptr; // inicializa ponteiros como nulos
    novo->direita = nullptr;
    return novo;
}

// Função para inserir valor na árvore binária de busca (BST)
No* inserir(No* raiz, int valor) {
    if (raiz == nullptr) return criarNo(valor); // se árvore vazia, cria a raiz

    // Se valor menor que o nó atual, vai para a subárvore esquerda
    if (valor < raiz->dado)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else // se maior ou igual, vai para a subárvore direita
        raiz->direita = inserir(raiz->direita, valor);

    return raiz; // retorna a raiz atualizada
}

// Função para buscar valor na árvore
bool buscar(No* raiz, int valor) {
    if (!raiz) return false;       // nó nulo: valor não encontrado
    if (raiz->dado == valor) return true; // valor encontrado
    if (valor < raiz->dado) return buscar(raiz->esquerda, valor); // esquerda
    return buscar(raiz->direita, valor); // direita
}

// Travessia em pré-ordem: nó, esquerda, direita
void preOrdem(No* raiz) {
    if (!raiz) return;
    cout << raiz->dado << " ";      // visita nó
    preOrdem(raiz->esquerda);       // percorre esquerda
    preOrdem(raiz->direita);        // percorre direita
}

// Travessia em ordem: esquerda, nó, direita
void emOrdem(No* raiz) {
    if (!raiz) return;
    emOrdem(raiz->esquerda);
    cout << raiz->dado << " ";
    emOrdem(raiz->direita);
}

// Travessia pós-ordem: esquerda, direita, nó
void posOrdem(No* raiz) {
    if (!raiz) return;
    posOrdem(raiz->esquerda);
    posOrdem(raiz->direita);
    cout << raiz->dado << " ";
}

// Exibição visual em ASCII da árvore
void exibirArvore(No* raiz, int espaco = 0, int incremento = 5) {
    if (!raiz) return;

    espaco += incremento;             // aumenta espaço para nível
    exibirArvore(raiz->direita, espaco); // imprime subárvore direita

    cout << endl;
    for (int i = incremento; i < espaco; i++) cout << " "; // indentação
    cout << raiz->dado << "\n";       // imprime nó atual

    exibirArvore(raiz->esquerda, espaco); // imprime subárvore esquerda
}

// Menu interativo da árvore
void menu() {
    No* raiz = nullptr; // raiz inicialmente nula
    int opcao, valor;

    do {
        cout << "\n--- Árvore Binária de Busca ---\n";
        cout << "1. Inserir\n2. Buscar\n3. Pré-ordem\n4. Em-ordem\n5. Pós-ordem\n6. Exibir árvore\n0. Sair\nEscolha: ";
        cin >> opcao;

        switch(opcao) {
            case 1: // Inserir valor
                cout << "Valor a inserir: "; 
                cin >> valor;
                raiz = inserir(raiz, valor);
                break;
            case 2: // Buscar valor
                cout << "Valor a buscar: "; 
                cin >> valor;
                cout << (buscar(raiz, valor) ? "Encontrado!\n" : "Não encontrado!\n");
                break;
            case 3: // Travessia pré-ordem
                cout << "Pré-ordem: "; preOrdem(raiz); cout << endl;
                break;
            case 4: // Travessia em-ordem
                cout << "Em-ordem: "; emOrdem(raiz); cout << endl;
                break;
            case 5: // Travessia pós-ordem
                cout << "Pós-ordem: "; posOrdem(raiz); cout << endl;
                break;
            case 6: // Exibir árvore
                cout << "Árvore:\n"; 
                exibirArvore(raiz);
                break;
            case 0: // Sair
                cout << "Saindo...\n";
                break;
            default: 
                cout << "Opção inválida!\n";
        }
    } while(opcao != 0);
}

int main() {
    menu(); // inicia menu interativo
    return 0;
}
