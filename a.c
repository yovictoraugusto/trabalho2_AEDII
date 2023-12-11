#include <stdio.h>
#include <stdlib.h>




int main(){
    char letra[13] = "AAAAAAAAAAAA";
    int numero = 999999;



    printf ("%d\n", numero + 1);

    for (int i = 0; i < numero; i++)
    {
        printf("insert %s\n", letra);
    }
    
    printf("find C\n");
    return 0;
}