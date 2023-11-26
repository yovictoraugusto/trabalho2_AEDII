#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 67

typedef struct hashItem{
    int key;
    char value[13];
    struct hashItem *next;
}hashItem;

typedef struct hashTable{
    hashItem* table[SIZE];
}hashTable;

hashTable* createHashTable() {
    hashTable* table = malloc(sizeof(hashTable));
    for(int i = 0; i < SIZE; i++) {
        table->table[i] = NULL;
    }
    return table;
}

int convertChatToInt(char str[]){
    int num = 0;
    for(int i = 0; i < 3; i++){
        num = num * 100 + str[i];
    }
    return num;
}

int main(){
    hashTable *table = createHashTable();
    int n;
    char op[7];
    char str[13];

    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%s", op);
        scanf("%s", str);
        //printf("%s %s", op, str);   
        if(strcmp(op, "insert") == 0){
            //insert
        }else if(strcmp(op, "find") == 0){
            //find
        }
    }

    return 0;
}