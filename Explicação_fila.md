# Estrutura de Dados: Filas em C++

## 📌 O que é uma Fila?
A **fila** é uma estrutura de dados linear que segue a regra **FIFO (First In, First Out)**, ou seja, o primeiro elemento a entrar é o primeiro a sair.

📍 Exemplo do mundo real: uma fila de pessoas em um banco ou mercado.

---

## 🔹 Operações principais em uma fila
- **Enqueue (inserção)** → adiciona um elemento no final da fila.  
- **Dequeue (remoção)** → remove o elemento do início da fila.  
- **Front (frente)** → consulta o primeiro elemento sem removê-lo.  
- **Empty (vazia)** → verifica se a fila está vazia.  

---

## 🔹 Implementação em C++ usando arrays

```cpp
#include <iostream>
using namespace std;

#define MAX 5 // tamanho máximo da fila

struct Fila {
    int itens[MAX];
    int frente, tras;
};

// Inicializa a fila
void inicializar(Fila &f) {
    f.frente = -1;
    f.tras = -1;
}

// Verifica se está cheia
bool estaCheia(Fila &f) {
    return (f.tras == MAX - 1);
}

// Verifica se está vazia
bool estaVazia(Fila &f) {
    return (f.frente == -1 || f.frente > f.tras);
}

// Insere elemento na fila
void enqueue(Fila &f, int valor) {
    if (estaCheia(f)) {
        cout << "Fila cheia!\n";
    } else {
        if (f.frente == -1) f.frente = 0;
        f.itens[++f.tras] = valor;
        cout << valor << " inserido na fila.\n";
    }
}

// Remove elemento da fila
void dequeue(Fila &f) {
    if (estaVazia(f)) {
        cout << "Fila vazia!\n";
    } else {
        cout << f.itens[f.frente] << " removido da fila.\n";
        f.frente++;
    }
}

// Mostra a fila
void mostrar(Fila &f) {
    if (estaVazia(f)) {
        cout << "Fila vazia!\n";
    } else {
        cout << "Fila: ";
        for (int i = f.frente; i <= f.tras; i++) {
            cout << f.itens[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    Fila f;
    inicializar(f);

    enqueue(f, 10);
    enqueue(f, 20);
    enqueue(f, 30);

    mostrar(f);

    dequeue(f);
    mostrar(f);

    return 0;
}
```

---

## 🔹 Implementação usando a biblioteca STL

```cpp
#include <iostream>
#include <queue> // biblioteca da STL
using namespace std;

int main() {
    queue<int> fila;

    // Inserindo elementos
    fila.push(10);
    fila.push(20);
    fila.push(30);

    cout << "Frente da fila: " << fila.front() << "\n";

    // Removendo elemento
    fila.pop();

    cout << "Nova frente da fila: " << fila.front() << "\n";

    // Verificando se está vazia
    if (fila.empty()) {
        cout << "Fila vazia!\n";
    } else {
        cout << "Fila ainda possui elementos.\n";
    }

    return 0;
}
```

---

## 📌 Por que estudar Filas?
- Modelam **problemas do mundo real** (ex.: filas de processos em sistemas operacionais, filas em redes de comunicação).  
- Usadas em **algoritmos de grafos** (BFS – busca em largura).  
- Fundamentais em **sistemas de atendimento, simulações e controle de recursos**.

---

✅ Agora você tem uma visão clara sobre **Filas em C++** com exemplos de código e explicações passo a passo!
