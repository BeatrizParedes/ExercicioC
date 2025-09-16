# 🌳 Introdução a Árvores em C++

## 📌 Por que estudar Árvores?
As **árvores** são estruturas de dados fundamentais porque:
- Representam **hierarquias** (ex.: pastas, menus, organogramas).
- Permitem **busca, inserção e remoção rápidas** (em O(log n) quando balanceadas).
- São usadas em **bancos de dados, sistemas de arquivos e compressão de dados**.
- Facilitam o **raciocínio recursivo** em programação.

---

## 📖 Conceito Básico
Uma **árvore** é composta por:
- **Nó (node):** elemento que armazena um valor.
- **Raiz (root):** nó inicial.
- **Filhos:** nós ligados abaixo de outro nó.
- **Folhas:** nós sem filhos.
- **Altura da árvore:** maior caminho da raiz até uma folha.

---

## 🔹 Estrutura de um Nó em C++
```cpp
#include <iostream>
using namespace std;

struct No {
    int valor;    // dado armazenado no nó
    No* esquerda; // ponteiro para filho da esquerda
    No* direita;  // ponteiro para filho da direita
};
```

---

## 🔹 Criando um Nó
```cpp
No* criarNo(int valor) {
    No* novo = new No;      // aloca memória
    novo->valor = valor;    // define o valor
    novo->esquerda = NULL;  // sem filhos no início
    novo->direita = NULL;
    return novo;
}
```

---

## 🔹 Inserção em Árvore Binária de Busca (BST)
```cpp
No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor); // se a raiz é nula, cria novo nó
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor); // insere à esquerda
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);   // insere à direita
    }

    return raiz; // retorna raiz sem modificar
}
```

---

## 🔹 Busca em Árvore
```cpp
bool buscar(No* raiz, int valor) {
    if (raiz == NULL) {
        return false; // valor não encontrado
    }
    if (raiz->valor == valor) {
        return true; // valor encontrado
    }
    if (valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);
    } else {
        return buscar(raiz->direita, valor);
    }
}
```

---

## 🔹 Percursos em Árvore
### 1. **Pré-ordem (raiz → esquerda → direita)**
```cpp
void preOrdem(No* raiz) {
    if (raiz != NULL) {
        cout << raiz->valor << " ";
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}
```

### 2. **Em-ordem (esquerda → raiz → direita)**
```cpp
void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        cout << raiz->valor << " ";
        emOrdem(raiz->direita);
    }
}
```

### 3. **Pós-ordem (esquerda → direita → raiz)**
```cpp
void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        cout << raiz->valor << " ";
    }
}
```

---

## 🔹 Programa Completo
```cpp
#include <iostream>
using namespace std;

struct No {
    int valor;
    No* esquerda;
    No* direita;
};

No* criarNo(int valor) {
    No* novo = new No;
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) return criarNo(valor);

    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserir(raiz->direita, valor);

    return raiz;
}

bool buscar(No* raiz, int valor) {
    if (raiz == NULL) return false;
    if (raiz->valor == valor) return true;

    if (valor < raiz->valor)
        return buscar(raiz->esquerda, valor);
    else
        return buscar(raiz->direita, valor);
}

void preOrdem(No* raiz) {
    if (raiz != NULL) {
        cout << raiz->valor << " ";
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        cout << raiz->valor << " ";
        emOrdem(raiz->direita);
    }
}

void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        cout << raiz->valor << " ";
    }
}

int main() {
    No* raiz = NULL;

    // Inserindo elementos
    raiz = inserir(raiz, 50);
    inserir(raiz, 30);
    inserir(raiz, 70);
    inserir(raiz, 20);
    inserir(raiz, 40);
    inserir(raiz, 60);
    inserir(raiz, 80);

    // Exibindo percursos
    cout << "Pré-ordem: ";
    preOrdem(raiz);
    cout << endl;

    cout << "Em-ordem: ";
    emOrdem(raiz);
    cout << endl;

    cout << "Pós-ordem: ";
    posOrdem(raiz);
    cout << endl;

    // Busca
    cout << "\nBuscando o valor 40: " << (buscar(raiz, 40) ? "Encontrado" : "Não encontrado") << endl;
    cout << "Buscando o valor 90: " << (buscar(raiz, 90) ? "Encontrado" : "Não encontrado") << endl;

    return 0;
}
```

---

## ✅ Conclusão
As **árvores** são poderosas para organizar dados de forma hierárquica e eficiente.  
Dominar essa estrutura abre portas para compreender algoritmos mais avançados, como **árvores balanceadas, grafos e inteligência artificial**.
