//Pode ser definida como um conjunto de variáveis de tipos diferentes organizadas sob um único nome.
//Em programação, criar uma "estrutura" equivale à criação de um novo tipo de dado.
//Normalmente, typedef struct é declarado fora da função main, para que o tipo fique disponível globalmente.

#include <stdio.h>

typedef struct {
    int i;
    char c;
    float f;
} Simple;

int main() {
    Simple s1 = {1, 'a', 3.14};
    printf("%d %c %.2f\n", s1.i, s1.c, s1.f);
    return 0;
}
