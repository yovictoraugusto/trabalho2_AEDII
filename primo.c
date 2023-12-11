#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int is_prime(int x) {
    if (x < 2) {
        return 0; // não é primo
    }
    if (x == 2 || x == 3) {
        return 1; // é primo
    }
    if (x % 2 == 0) {
        return 0; // número par (exceto 2)
    }

    // Verifica apenas até a raiz quadrada de x
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            return 0; // não é primo
        }
    }

    return 1; // é primo
}

int main() {
    srand(time(NULL));
    int contador = 0;

    int aleatorio;
    do
    {
        aleatorio = (rand() % (1000000 - 1)) + 1500000; 
        contador++;
    } while (!is_prime(aleatorio));
    

    printf("%d\n", aleatorio);
    printf("%d\n", contador);

    return 0;
}
