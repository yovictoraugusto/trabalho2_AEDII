/*Alunos:
    Ícaro Travain Darwich da Rocha RA:156.307
    Victor Augusto Reis Marques RA:156.620
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

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

int find_hash(char *value, int n, hashItem **hash){
    int key = convertChatToInt(value);
    int index = key % n;
    if(hash[index] == NULL){
        return 0;
    }else{
        hashItem *aux = hash[index];
        while(aux != NULL){    //retornar em caso de segmentation fault
            if(aux->key == key){
                return 1;
            }else{
                aux = aux->next;
            }
        }
    }
    return 0;
}

int is_prime(int x) {
    if (x < 2) {
        return 0;
    }
    if (x == 2 || x == 3) {
        return 1;
    }
    if (x % 2 == 0) {
        return 0;
    }

    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(){
    srand(time(NULL));

    int n, tamHash, teste;
    char op[7];
    char str[13];

    scanf("%d", &n);

    do{
        tamHash = (rand() % (n - 1)) + n;
    }while(!is_prime(tamHash));

    hashItem **hash = createHashTable(tamHash);

    for(int i = 0; i < n; i++){
        scanf("%s", op);
        scanf("%s", str);   
        if(strcmp(op, "insert") == 0){
            insert_hash(str, tamHash, hash);       
        }else if(strcmp(op, "find") == 0){
            printf("%s\n", find_hash(str, tamHash, hash) == 1 ? "yes": "no");
        }
    }

    return 0;
}