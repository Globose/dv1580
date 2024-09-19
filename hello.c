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
    int maxSteak = 10;
    for (int j = 1; j < gridSize-1; j++){ // Horiz
        int rStreak = 0;
        for (int i = 0; i < *gridColSize; i++){
            if (grid[j][i] == 1){
                rStreak++;
            }
        }
        if (rStreak < maxSteak){
            maxSteak = rStreak;
        }
    }
    for (int i = 1; i < *gridColSize-1; i++){ // Vert
        int rStreak = 0;
        for (int j = 0; j < gridSize; j++){
            if (grid[j][i] == 1){
                rStreak++;
            }
        }
        if (rStreak < maxSteak){
            maxSteak = rStreak;
        }
    }
    for (int j = 0; j < gridSize-1; j++){
        int rStreak = 0;
        int tj = j;
        for (int i = 0; i < *gridColSize; i++){
            if (tj >= gridSize) break;
            if (grid[tj][i] == 1) rStreak++;
            tj++;
        }
        if (rStreak < maxSteak){
            maxSteak = rStreak;
        }
    }
    for (int j = 1; j < gridSize; j++){
        int rStreak = 0;
        int tj = j;
        for (int i = 0; i < *gridColSize; i++){
            if (tj < 0) break;
            if (grid[tj][i] == 1) rStreak++;
            tj--;
        }
        if (rStreak < maxSteak){
            maxSteak = rStreak;
        }
    }

    for (int i = 1; i < *gridColSize-1; i++){
        int rStreak = 0;
        int ti = i;
        for (int j = 0; j < gridSize; j++){
            if (ti >= gridSize) break;
            if (grid[j][ti] == 1) rStreak++;
            ti++;
        }
        if (rStreak < maxSteak){
            maxSteak = rStreak;
        }
    }
    for (int i = 1; i < *gridColSize-1; i++){
        int rStreak = 0;
        int ti = i;
        for (int j = gridSize-1; j >= 0; j--){
            if (ti >= gridSize) break;
            if (grid[j][ti] == 1) rStreak++;
            ti++;
        }
        if (rStreak < maxSteak && rStreak ){
            maxSteak = rStreak;
        }
    }

    return maxSteak;
}