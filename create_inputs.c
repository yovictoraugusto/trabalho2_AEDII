#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void generate_sequences(int length, char *alphabet, char *prefix) {
    if (length == 0) {
        printf("%s\n", prefix);
        return;
    }

    for (int i = 0; i < 4; i++) {
        char new_prefix[length + 2]; // +2 para o caractere atual e o terminador nulo
        sprintf(new_prefix, "%s%c", prefix, alphabet[i]);
        generate_sequences(length - 1, alphabet, new_prefix);
    }
}

void print_sequences(int max_length, char *alphabet) {
    for (int i = 1; i <= max_length; i++) {
        generate_sequences(i, alphabet, "");
    }
}

int main()
{
    srand(time(NULL));

    int qt_inputs, op;
    int length;
    char bases[4] = {'A', 'C', 'G', 'T'};

    printf("qt de numeros:");
    scanf("%d", &qt_inputs);
    printf("1 - aleatorio\n2 - crescente\n");
    scanf("%d", &op);

    if (op == 1)
    {
        for (int i = 0; i < qt_inputs; i++)
        {
            printf("%s ", (rand() % 2 == 1) ? "insert" : "find");
            length = (rand() % 12) + 1;
            for (int j = 0; j < length; j++)
            {
                printf("%c", bases[(rand() % 4)]);
            }
            printf("\n");
        }
    }
    else if (op == 2)
    {
        int max_length = 12;
        print_sequences(max_length, bases);
    }

    return 0;
}