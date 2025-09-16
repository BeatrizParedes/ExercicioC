#include <iostream> // Biblioteca para entrada e saída
#include <string>   // Biblioteca para manipulação de strings
using namespace std; // Permite usar cout, cin sem std::

// Função simples que soma dois números
int somar(int a, int b) {
    return a + b; // Retorna a soma de a e b
}

// Função que imprime uma mensagem de boas-vindas
void boasVindas(string nome) {
    cout << "Olá, " << nome << "! Bem-vindo(a) ao C++.\n";
}

int main() {
    // ======================
    // 1. Variáveis e Tipos
    // ======================
    int idade;                // Número inteiro
    double altura;            // Número decimal
    char genero;              // Caracter
    string nome;              // Texto (sequência de caracteres)
    bool estudante;           // Valor verdadeiro/falso

    // ======================
    // 2. Entrada de dados
    // ======================
    cout << "Digite seu nome: ";
    cin >> nome;  // Armazena o nome digitado na variável 'nome'

    cout << "Digite sua idade: ";
    cin >> idade;

    cout << "Digite sua altura (ex: 1.75): ";
    cin >> altura;

    cout << "Digite seu genero (M/F): ";
    cin >> genero;

    cout << "Você é estudante? (1 = sim, 0 = não): ";
    cin >> estudante;

    // ======================
    // 3. Saída de dados
    // ======================
    cout << "\n--- Resumo ---\n";
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << endl;
    cout << "Altura: " << altura << " m" << endl;
    cout << "Genero: " << genero << endl;
    cout << "Estudante: " << (estudante ? "Sim" : "Não") << endl;

    // ======================
    // 4. Condicional
    // ======================
    if (idade >= 18) {
        cout << "Você é maior de idade.\n";
    } else {
        cout << "Você é menor de idade.\n";
    }

    // ======================
    // 5. Laço de repetição
    // ======================
    cout << "\nContando de 1 até 5 usando for:\n";
    for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Contando de 5 até 1 usando while:\n";
    int j = 5;
    while (j >= 1) {
        cout << j << " ";
        j--;
    }
    cout << endl;

    // ======================
    // 6. Vetores (arrays)
    // ======================
    int numeros[5]; // Array com 5 posições
    cout << "\nDigite 5 números inteiros:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Número " << i + 1 << ": ";
        cin >> numeros[i];
    }

    cout << "Os números digitados foram: ";
    for (int i = 0; i < 5; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    // ======================
    // 7. Funções
    // ======================
    int a, b;
    cout << "\nDigite dois números para somar:\n";
    cin >> a >> b;
    int resultado = somar(a, b); // Chamada da função
    cout << "Resultado da soma: " << resultado << endl;

    // Chamada da função de boas-vindas
    boasVindas(nome);

    // Final do programa
    cout << "\nFim do programa.\n";
    return 0;
}
