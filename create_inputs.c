#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));

    int qt_inputs;
    int length;
    char bases[4] = {'A', 'C', 'G', 'T'};

    qt_inputs = (rand() % 1000000) + 1; 
    printf("%d\n", qt_inputs);
    for (int i = 0; i < qt_inputs; i++)
    {
        printf("%s ", (rand()%2 == 1) ? "insert" : "find");
        length = (rand()%12) +1 ;
        for (int j = 0; j <  length; j++)
        {
            printf("%c", bases[(rand()%4)]);
        }
        printf("\n");
    }
    

    return 0;
}