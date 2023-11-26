#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct hashItem{
    int key;
    struct hashItem *next;
}hashItem;

hashItem** createHashTable(int size) {
    hashItem **hash = malloc(sizeof(hashItem * ) * size); 
    for(int i = 0; i < size; i++) {
        hash[i] = NULL;
    }
    return hash;
}

int convertChatToInt(char str[]){
    int conversao = 0;
    int contador = 0;
    while (contador < 13 || str[contador] != '\0')
    {
        //char entrada[1] = str[contador];
        if( str[contador] == 'A'){
            conversao += 1 * pow(5, contador);
        }else if(str[contador] == 'T'){
            conversao += 2 * pow(5, contador);
        }else if(str[contador] == 'C'){
           conversao += 3 * pow(5, contador);
        }else if(str[contador] == 'G'){
            conversao += 4 * pow(5, contador);
        }
        contador++;
    }
    
    return conversao;
}

hashItem **insert_hash(char *value, int n, hashItem **hash){ 
    int key = convertChatToInt(value);
    int index = key % n;
    
    //create a new node
    hashItem *newNode = malloc(sizeof(hashItem));
    newNode->key = key;
    newNode->next = NULL;

    //insert process
    if(hash[index] == NULL){
        hash[index] = newNode;
    }else{
        hashItem *aux = hash[index];
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = newNode;
    }

    return hash;
}

void find_hash(char *value, int n, hashItem **hash){
    int key = convertChatToInt(value);
    int index = key % n;
    if(hash[index] == NULL){
        printf("no\n");
    }else{
        hashItem *aux = hash[index];
        while(aux != NULL){    //retornar em caso de segmentation fault
            if(aux->key == key){
                printf("yes\n");
                return;
            }else{
                aux = aux->next;
            }
        }
        printf("no\n");
    }
    return;
}

int main(){
    int n;
    char op[7];
    char str[13];

    scanf("%d", &n);
    hashItem **hash = createHashTable(n);

    for(int i = 0; i<n; i++){
        scanf("%s", op);
        scanf("%s", str);
        //printf("%s %s", op, str);   
        if(strcmp(op, "insert") == 0){
            //printf("%d\n", convertChatToInt(str));
            insert_hash(str, n, hash);
        }else if(strcmp(op, "find") == 0){
            find_hash(str, n, hash);
        }
    }

    return 0;
}