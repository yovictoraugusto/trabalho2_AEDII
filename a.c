#include <stdio.h>
#include <stdlib.h>




int main(){
    char proteina1[13] = "AGAGTAAATGC";
    char proteina2[13] = "TTGGTGTGAA";

    int numero;

    scanf("%d", &numero);

    printf ("%d\n", numero);

    printf("insert %s\n", proteina1);
    for (int i = 0; i < numero/2 - 1; i++)
    {
        printf("insert %s\n", proteina2);
    }
    for (int i = 0; i < numero/2; i++)
    {
        printf("find %s\n", proteina1);
    }
    
    
    printf("find %s\n", proteina1);
    return 0;
}