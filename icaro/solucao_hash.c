#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int converter(char codon[4]){
    int conversao = 0;
    for (int i = 0; i < 3; i++)
    {
        conversao += (codon[i] - 65) * pow(4, i);
    }
    return conversao;
}

typedef struct lista{
    char codon[4];
    struct lista *proximo;
}Lista;

Lista *criar_no(char codon[4]){
    Lista *novo = malloc(sizeof(Lista));
    strcpy(novo->codon, codon);
    return novo;
}

void inserir_Lista(Lista *lista, char codon[4]){
    if (lista->proximo == NULL)
    {
        lista->proximo = criar_no(codon);
    }
    else{
        Lista *aux = lista;
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = criar_no(codon);
    }
}

Lista *criar_hash(int qtd_hash){
    Lista *hash = malloc(sizeof(Lista) * qtd_hash);
    for (int i = 0; i < qtd_hash; i++)
    {
        hash[i].proximo = NULL;
    }
    return hash;
}

void inserir_hash(char codon[4], Lista *hash, int tam_hash){
    int posicao = converter(codon) % tam_hash;
    inserir_Lista(&hash[posicao], codon);
}

int busca_hash(Lista *hash, char codon[12], int tam_hash){
    int posicao = converter(codon) % tam_hash;
    Lista *aux = hash[posicao].proximo;
    while (aux != NULL)
    {
        if (strcmp(aux->codon, codon) == 0)
        {
            return 1;
        }
        aux = aux->proximo;
    }
    return 0;
}


int main()
{
    int qtd_entradas;
    char codon[12];
    char opcao[8];

    scanf("%d", &qtd_entradas);
    getchar();

    Lista *hash = criar_hash(qtd_entradas);

    for (int i = 0; i < qtd_entradas; i++)
    {
        scanf("%s", opcao);
        scanf("%s", codon);
        printf("%s %s\n", opcao, codon);
        if(strcmp(opcao, "insert") == 0)
        {
            inserir_hash(codon, hash, qtd_entradas + 1);
        }
        else if(strcmp(opcao, "find") == 0)
        {
            printf("%s\n", busca_hash(hash, codon, qtd_entradas) == 1 ? "yes" : "no");
        }
    }

    return 0;
}