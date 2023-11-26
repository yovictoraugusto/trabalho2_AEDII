#include <stdio.h>

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

int main() {
    char alphabet[] = {'A', 'C', 'G', 'T'};
    int max_length = 12;

    print_sequences(max_length, alphabet);

    return 0;
}
