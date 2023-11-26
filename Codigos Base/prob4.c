#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct projects{
    int id;
    struct projects *next;
}projects;

typedef struct list{
    struct projects *head;
    struct projects *tail;
}list;

typedef struct node{
    char name[15];
    int height;
    struct list *list;
    struct node *left;
    struct node *right;
}node;

int alt_node(struct node *node){
    if(node == NULL)
        return 0;
    else
    return node->height;    
}

int fatorBalanceamento(struct node *node){
    return labs(alt_node(node->left) - alt_node(node->right));
}

int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}

node *rotacaoLL(node *node){
    struct node *aux;
    aux = node->left;
    node->left = aux->right;
    aux->right = node;
    node->height = maior(alt_node(node->left), alt_node(node->right)) + 1;
    aux->height = maior(alt_node(aux->left), node->height) + 1;
    node = aux;
    return node;
}

node *rotacaoRR(node *node){
    struct node *aux;
    aux = node->right;
    node->right = aux->left;
    aux->left = node;
    node->height = maior(alt_node(node->left), alt_node(node->right)) + 1;
    aux->height = maior(alt_node(aux->right), node->height) + 1;
    node = aux; 
    return node;
}

node *rotacaoLR(node *node){
    node->left = rotacaoRR(node->left);
    node = rotacaoLL(node);
    return node;
}

node *rotacaoRL(node *node){
    node->right = rotacaoLL(node->right);
    node = rotacaoRR(node);
    return node;
}

list *insertList(list *list, int id){
    projects *new;
    new = malloc(sizeof(projects));
    new->id = id;
    new->next = NULL;
    if(list == NULL){
        list = malloc(sizeof(list));
        list->head = new;
        list->tail = new;
    }else{
        list->tail->next = new;
        list->tail = new;
    }

    return list;
}

node *insert(node *root, char name[15], int id){
    if(root == NULL){
        node *new;
        new = malloc(sizeof(node));
        strcpy(new->name, name);
        new->height = 1;
        new->right = NULL;
        new->left = NULL;
        new->list =  NULL;
        new->list = insertList(new->list, id);
        return new;
    }else{
        if(strcmp(name, root->name) > 0){
            root->right = insert(root->right, name, id);
            if(fatorBalanceamento(root) >= 2){
                if(strcmp(name, root->right->name) > 0)
                    root = rotacaoRR(root);
                else
                    root = rotacaoRL(root);
            }
        }else if(strcmp(name, root->name) < 0){
            root->left = insert(root->left, name, id);
            if(fatorBalanceamento(root) >= 2){
                if(strcmp(name, root->left->name) < 0)
                    root = rotacaoLL(root);
                else
                    root = rotacaoLR(root);
            }
        }else{
            insertList(root->list, id);
            return root;
        }
    }
    root->height = maior(alt_node(root->left), alt_node(root->right)) + 1;
    return root;
}

void consult(node *root, char name[15]){
    if(root == NULL){
        printf("0\n");
    }else{
        struct node* actual = root;
        struct node* ant;
        while(actual != NULL){
            ant = actual;
            if(strcmp(name, actual->name) > 0)
                actual = actual->right;
            else if(strcmp(name, actual->name) < 0)
                actual = actual->left;
            else{
                printf("%d ", actual->height);
                projects *aux = actual->list->head;
                while(aux != NULL){
                    printf("%d ", aux->id);
                    aux = aux->next;
                }
                printf("\n");
                return;
            }
        }
        printf("0\n");
        return;
    }
}

int main(){
    node *root = NULL;
    int op;
    int id;
    char name[15];
    do{
        scanf("%d", &op);
        if(op == 1){
            scanf("%s", name);
            scanf("%d", &id);
            root = insert(root, name, id);
        }
        else if(op == 2){
            scanf("%s", name);
            consult(root, name);
        }
    }while(op != 0);
    return 0;
}