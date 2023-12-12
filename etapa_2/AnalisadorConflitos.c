#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 1000003 // Um número primo para minimizar colisões

// Estrutura para os nós da lista encadeada usada na tabela hash
typedef struct no {
    char chave[13];
    struct no *proximo;
} No;

No *tabelaHash[TAMANHO_TABELA];

// Função para calcular o valor hash de uma string
unsigned int hash(char *str) {
    unsigned int valor = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        valor = valor * 37 + str[i];
    }
    return valor % TAMANHO_TABELA;
}

// Inserir uma string na tabela hash
void inserir(char *str) {
    unsigned int indice = hash(str);
    No *novoNo = (No *)malloc(sizeof(No));
    strcpy(novoNo->chave, str);
    novoNo->proximo = tabelaHash[indice];
    tabelaHash[indice] = novoNo;
}

// Buscar uma string na tabela hash
int buscar(char *str) {
    unsigned int indice = hash(str);
    No *no = tabelaHash[indice];
    int contador = 0;
    while (no != NULL) {
        contador++;
        if (strcmp(no->chave, str) == 0) {
            return contador; // Encontrado
        }
        no = no->proximo;
    }
    return 0; // Não encontrado
}

void imprimirLista(char *str) {
    unsigned int indice = hash(str);
    No *no = tabelaHash[indice];
    while (no != NULL) {
        printf("%s ", no->chave);
        no = no->proximo;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    char comando[10], str[13];

    for (int i = 0; i < n; i++) {
        scanf("%s %s", comando, str);
        printf("%d %s", hash(str), str);
        if (strcmp(comando, "insert") == 0) {
            inserir(str);
        } else if (strcmp(comando, "find") == 0) {
            if (buscar(str) > 1) {
                imprimirLista(str);
            }
        }
    }

    // Liberar a memória alocada
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        No *no = tabelaHash[i];
        while (no != NULL) {
            No *temp = no;
            no = no->proximo;
            free(temp);
        }
    }

    return 0;
}