#include <stdio.h>
#include <stdlib.h>


int main(){
    char buffer[4];
    char buff2[4];
    buffer[0] = 1; 
    buffer[1] = 2; 
    buffer[2] = 3; 
    buffer[3] = 4;
    buff2[0] = 5;
    buff2[1] = 6;
    buff2[2] = 7;
    buff2[3] = 8;
    buffer[4] = 9;
    printf("%p\n", &buffer[4]); 
    printf("%p\n", &buff2[0]); 
    printf("%d\n", buff2[0]);
    return 0;
}
