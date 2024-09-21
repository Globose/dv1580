#include <stdio.h>
#include <stdlib.h>

int minDays(int** grid, int gridSize, int* gridColSize);

int main(){
    int cols = 5;
    int rows = 4;
    int** grid = (int**)malloc(rows*sizeof(int));
    for (int i = 0; i < 5; i++){
        grid[i] = (int*)malloc(cols*sizeof(int));
    }
    int g2 [] = {0,1,1,0,0,1,1,0,0,0,0,0};
    // int g2 [] = {1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,1};
    /*
        11011
        11111
        11011
        11011
    */
    int counter = 0;
    for (int j = 0; j < rows; j++){
        for (int i = 0; i < cols; i++){
            grid[j][i] = g2[counter];
            counter++;
        }
    }

    int md = minDays(grid, rows, &cols);
    printf("%d",md);
    return 0;
}

int minDays(int** grid, int gridSize, int* gridColSize) {
    return 0;
}