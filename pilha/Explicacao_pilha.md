# Estrutura de Dados: Pilhas em C++

## 📌 O que é uma Pilha?
A **pilha** é uma estrutura de dados linear que segue a regra **LIFO (Last In, First Out)**, ou seja, o último elemento a entrar é o primeiro a sair.

📍 Exemplo do mundo real: uma pilha de pratos em um restaurante. O último prato colocado em cima é o primeiro a ser retirado.

---

## 🔹 Operações principais em uma pilha
- **Push (empilhar)** → adiciona um elemento no topo.  
- **Pop (desempilhar)** → remove o elemento do topo.  
- **Top/Peek (topo)** → consulta o elemento do topo sem removê-lo.  
- **Empty (vazia)** → verifica se a pilha está vazia.  

---

## 🔹 Implementação em C++ usando arrays

```cpp
#include <iostream>
using namespace std;

#define MAX 5 // tamanho máximo da pilha

struct Pilha {
    int itens[MAX];
    int topo;
};

// Inicializa a pilha
void inicializar(Pilha &p) {
    p.topo = -1;
}

// Verifica se está cheia
bool estaCheia(Pilha &p) {
    return (p.topo == MAX - 1);
}

// Verifica se está vazia
bool estaVazia(Pilha &p) {
    return (p.topo == -1);
}

// Insere elemento na pilha
void push(Pilha &p, int valor) {
    if (estaCheia(p)) {
        cout << "Pilha cheia!\n";
    } else {
        p.itens[++p.topo] = valor;
        cout << valor << " empilhado.\n";
    }
}

// Remove elemento da pilha
void pop(Pilha &p) {
    if (estaVazia(p)) {
        cout << "Pilha vazia!\n";
    } else {
        cout << p.itens[p.topo--] << " desempilhado.\n";
    }
}

// Mostra a pilha
void mostrar(Pilha &p) {
    if (estaVazia(p)) {
        cout << "Pilha vazia!\n";
    } else {
        cout << "Pilha: ";
        for (int i = 0; i <= p.topo; i++) {
            cout << p.itens[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    Pilha p;
    inicializar(p);

    push(p, 10);
    push(p, 20);
    push(p, 30);

    mostrar(p);

    pop(p);
    mostrar(p);

    return 0;
}
```

---

## 🔹 Implementação usando a biblioteca STL

```cpp
#include <iostream>
#include <stack> // biblioteca da STL
using namespace std;

int main() {
    stack<int> pilha;

    // Inserindo elementos
    pilha.push(10);
    pilha.push(20);
    pilha.push(30);

    cout << "Topo da pilha: " << pilha.top() << "\n";

    // Removendo elemento
    pilha.pop();
    cout << "Novo topo: " << pilha.top() << "\n";

    // Verificando se está vazia
    if (pilha.empty()) {
        cout << "Pilha vazia!\n";
    } else {
        cout << "Ainda há elementos na pilha.\n";
    }

    return 0;
}
```

---

## 📌 Por que estudar Pilhas?
- Modelam **problemas do mundo real** (ex.: desfazer ações em editores, navegação no navegador).  
- Usadas em **recursão**, **avaliação de expressões matemáticas** e **conversão de notações (infixa, pós-fixa)**.  
- Fundamentais para **compiladores e algoritmos**.  

---

✅ Agora você tem uma visão clara sobre **Pilhas em C++** com exemplos de código e explicações passo a passo!
