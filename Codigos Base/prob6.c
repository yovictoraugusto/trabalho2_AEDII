#include<stdio.h>
#include<stdlib.h>
#include<string.h>

# define MAX_SIZE 20

typedef struct{
    char c;
    int visited;
}cell;

void busca(cell matrix[MAX_SIZE][MAX_SIZE], int x, int y, int w, int h, int *count){
    if(x < 0 || y < 0)  return;
    else if(x >= w || y >= h)    return;
    else if(matrix[y][x].c == '#') return;
    else if(matrix[y][x].visited == 1)   return;
    
    matrix[y][x].visited = 1;
    (*count)++;
    busca(matrix, x+1, y, w, h, count);
    busca(matrix, x-1, y, w, h, count);
    busca(matrix, x, y+1, w, h, count);
    busca(matrix, x, y-1, w, h, count);
}

int main(){
    int w, h, startX, startY;
    
    scanf("%d %d", &w, &h);
    
    cell matrix[MAX_SIZE][MAX_SIZE];
    
    // w = x
    // h = y
    for(int y = 0; y < h; y++){
        for(int x = 0; x < w; x++){
            scanf(" %c", &matrix[y][x].c);
            matrix[y][x].visited = 0;
            if(matrix[y][x].c == '@'){
                startX = x;
                startY = y;
            }
        }
    }
    
    int count = 0;
    busca(matrix, startX, startY, w, h, &count);
    
    printf("%d\n", count);  

    return 0;
}