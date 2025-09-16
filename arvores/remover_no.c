// Função para encontrar o menor valor em uma sub-árvore
Node* encontrarMinimo(struct Node* node) {
// O menor valor está na extrema esquerda
while (node->esquerda != NULL)
node = node->esquerda;
return node;
}
// Função para remover um valor da árvore
Node* remover(struct Node* raiz, int valor) {
if (raiz == NULL)
return raiz; // Caso base: árvore vazia
// Se o valor for menor, busca na sub-árvore esquerda
if (valor < raiz->valor)
raiz->esquerda = remover(raiz->esquerda, valor);
// Se o valor for maior, busca na sub-árvore direita
else if (valor > raiz->valor)
raiz->direita = remover(raiz->direita, valor);
else {
// Caso 1: Nó sem filhos
if (raiz->esquerda == NULL && raiz->direita == NULL) {
free(raiz);
return NULL;
}

// Caso 2: Nó com um filho
else if (raiz->esquerda == NULL) {
struct Node* temp = raiz->direita;
free(raiz);
return temp;
} else if (raiz->direita == NULL) {
struct Node* temp = raiz->esquerda;
free(raiz);
return temp;
}
// Caso 3: Nó com dois filhos
// Encontra o sucessor
Node* temp = encontrarMinimo(raiz->direita);
// Substitui o valor
raiz->valor = temp->valor;
// Remove o sucessor
raiz->direita = remover(raiz->direita, temp->valor);
}
// Retorna a raiz atualizada
return raiz;
}
