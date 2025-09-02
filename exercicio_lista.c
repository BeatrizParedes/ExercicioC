/******************************************************************************
Implemente uma lista encadeada simples em c/c++ com as seguintes funcinoalidades:
Inserir elementos no inicio da lista
Inserir elementos no final da lista
Imprimir todos os elementos da lista

Ex:
Inserir no inicio: 10,20,30
Inserir no fina: 40,50

Saída esperada: 30->20->10->40->50->NULL

*******************************************************************************/

#include <iostream> //para cout
using namespace std;

struct No{
    int dado;
    No* prox;
};

No* inserir_inicio(No* head, int valor){
    No* novo = new No; //não pode ser minúsculo
    novo->dado= valor;
    novo->prox = head;
    return novo;
}

void imprimir_lista (No* head){
    No* atual = head;
    while (atual != nullptr){
        cout << atual->dado << " -> ";
        atual=atual->prox;
    }
    cout << "NULL" <<endl;
}