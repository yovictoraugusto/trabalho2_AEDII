#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

struct Node
{
    char data[13];  
    struct Node *next;
};

typedef struct Node Node;

Node *hashTable[MAX_SIZE];

void initializeHashTable()
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        hashTable[i] = NULL;
    }
}

int hashIndexFunction(char string[])
{
    int sum = 0;
    size_t len = strlen(string);
    for (size_t i = 0; i < len; i++)
    {
        sum += string[i];
    }
    return sum % MAX_SIZE;
}

void insertIntoHashTable(char string[])
{
    int index = hashIndexFunction(string);
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode != NULL)
    {
        strcpy(newNode->data, string);
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

int searchInHashTable(char string[])
{
    int index = hashIndexFunction(string);
    Node *current = hashTable[index];
    while (current != NULL)
    {
        if (strcmp(current->data, string) == 0)
        {
            return 1; // Found
        }
        current = current->next;
    }
    return 0; // Not found
}

void freeHashTable()
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        Node *current = hashTable[i];
        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
        hashTable[i] = NULL;
    }
}

int main()
{
    initializeHashTable();

    char command[10], string[13];
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%s %s", command, string);

        if (strcmp(command, "insert") == 0)
        {
            insertIntoHashTable(string);
        }
        else if (strcmp(command, "find") == 0)
        {
            if (searchInHashTable(string) == 0)
            {
                printf("no\n");
            }
            else
            {
                printf("yes\n");
            }
        }
    }
    freeHashTable();
    return 0;
}
