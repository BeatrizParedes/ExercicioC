#include <iostream>
#include <string>
using namespace std;

#define MAX 5  // tamanho máximo da fila

struct FilaCircular {
    int dados[MAX];
    string historico[MAX]; // histórico de sobrescrita
    int frente;  // índice do primeiro elemento
    int tras;    // índice do último elemento
    int tamanho; // quantidade de elementos
};

// Inicializar fila
void inicializar(FilaCircular &f) {
    f.frente = 0;
    f.tras = -1;
    f.tamanho = 0;
    for (int i = 0; i < MAX; i++)
        f.historico[i] = "";
}

// Verificar se cheia
bool cheia(FilaCircular &f) {
    return f.tamanho == MAX;
}

// Verificar se vazia
bool vazia(FilaCircular &f) {
    return f.tamanho == 0;
}

// Enfileirar (enqueue) circular
void enqueue(FilaCircular &f, int valor) {
    if (cheia(f)) {
        f.tras = (f.tras + 1) % MAX;
        cout << "Fila cheia! Sobrescrevendo: " << f.dados[f.tras] << endl;
        f.historico[f.tras] += " -> sobrescrito por " + to_string(valor);
        f.dados[f.tras] = valor;
    } else {
        f.tras = (f.tras + 1) % MAX;
        f.dados[f.tras] = valor;
        f.historico[f.tras] = "";
        f.tamanho++;
    }
    cout << "Enfileirado: " << valor << endl;
}

// Desenfileirar (dequeue)
void dequeue(FilaCircular &f) {
    if (vazia(f)) {
        cout << "Fila vazia!\n";
        return;
    }
    cout << "Desenfileirado: " << f.dados[f.frente] << endl;
    f.frente = (f.frente + 1) % MAX;
    f.tamanho--;
}

// Consultar frente
int front(FilaCircular &f) {
    if (vazia(f)) {
        cout << "Fila vazia!\n";
        return -1;
    }
    return f.dados[f.frente];
}

// Exibir fila circular com histórico
void exibirFila(FilaCircular &f) {
    if (vazia(f)) {
        cout << "[ VAZIA ]\n";
        return;
    }
    cout << "Frente ->\n";
    for (int i = 0; i < f.tamanho; i++) {
        int idx = (f.frente + i) % MAX;
        cout << "+-----+\n";
        cout << "| " << f.dados[idx] << " |\n";
        cout << "+-----+\n";
        if (!f.historico[idx].empty())
            cout << "  Histórico: " << f.historico[idx] << endl;
    }
    cout << "<- Tras\n";
}

// Menu interativo
void menu() {
    FilaCircular fila;
    inicializar(fila);
    int opcao, valor;

    do {
        cout << "\n--- Fila Circular Avançada com Histórico ---\n";
        cout << "1. Enfileirar (enqueue)\n";
        cout << "2. Desenfileirar (dequeue)\n";
        cout << "3. Consultar frente\n";
        cout << "4. Exibir fila\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                cout << "Valor a enfileirar: ";
                cin >> valor;
                enqueue(fila, valor);
                break;
            case 2:
                dequeue(fila);
                break;
            case 3:
                valor = front(fila);
                if (valor != -1)
                    cout << "Frente da fila: " << valor << endl;
                break;
            case 4:
                exibirFila(fila);
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
