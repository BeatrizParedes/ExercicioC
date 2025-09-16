// Função para criar um novo nó
Node* novoNo(int valor) {
Node* node = (struct Node*) malloc(sizeof(struct Node));
node->valor = valor;
node->esquerda = node->direita = NULL;
return node;
}

// Função para inserir um valor na árvore binária de busca
struct Node* inserir(struct Node* raiz, int valor) {
// Se a árvore estiver vazia, cria um novo nó
if (raiz == NULL)
return novoNo(valor);
// Se o valor for menor, insere na sub-árvore esquerda
if (valor < raiz->valor)
raiz->esquerda = inserir(raiz->esquerda, valor);
// Se o valor for maior, insere na sub-árvore direita
else if (valor > raiz->valor)
raiz->direita = inserir(raiz->direita, valor);
return raiz; // Retorna a raiz atualizada
}
