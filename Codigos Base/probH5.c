#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 67

typedef struct hashItem{
    int key;
    char value[2];
    struct hashItem *next;
}hashItem;

typedef struct hashTable{
    hashItem* table[SIZE];
}hashTable;

int convertChatToInt(char str[]){
    int num = 0;
    for(int i = 0; i < 3; i++){
        num = num * 100 + str[i];
    }
    return num;
}

hashTable* createHashTable() {
    hashTable* table = malloc(sizeof(hashTable));
    for(int i = 0; i < SIZE; i++) {
        table->table[i] = NULL;
    }
    return table;
}

void insert(hashTable* table, int key, char protein[2]){
    int index = key % SIZE;
    hashItem *newItem;
    newItem = (hashItem*) malloc(sizeof(hashItem));
    newItem->key = key;
    strcpy(newItem->value, protein);
    newItem->next = NULL;
    if(table->table[index] == NULL){
        table->table[index] = newItem;
    }else{
        hashItem *aux = table->table[index];
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = newItem;
    }
}

void consult(hashTable* table, int key){
    int index = key % SIZE;
    hashItem *aux = table->table[index];
    while(aux != NULL){
        if(aux->key == key){
            printf("%s", aux->value);
            return;
        }
        aux = aux->next;
    }
    printf("*");
}

int main(){
    hashTable *table = createHashTable();
    int n, m;
    char rna[4], protein[2], rnaSearch[10000];

    scanf("%d", &n);
    while(n--){
        scanf("%s", rna);
        scanf("%s", protein);
        getchar();
        insert(table, convertChatToInt(rna), protein);
    }

    scanf("%d", &m);
    while(m--){
        scanf("%s", rnaSearch);
        int size = strlen(rnaSearch);
        for(int i = 0; i < size; i += 3){
            char rnaConsult[4];
            rnaConsult[0] = rnaSearch[i];
            rnaConsult[1] = rnaSearch[i+1];
            rnaConsult[2] = rnaSearch[i+2];
            rnaConsult[3] = '\0';
            consult(table, convertChatToInt(rnaConsult));
        }
        printf("\n");
    }
}