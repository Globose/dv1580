#include <stdio.h>
#include <stdlib.h>

void mem_init(size_t size);
void* mem_alloc(size_t size);
void mem_free(void* block);
void* mem_resize(void* block, size_t size);
void mem_deinit();


int main(){
    printf("Hello");
    return 0;
}

/*
Initializes the memory manager with a specified size of memory pool. 
The memory pool could be any data structure, for instance, a large 
array or a similar contuguous block of memory. (You do not have to 
interact directly with the hardware or the operating system’s 
memory management functions).
 */
void mem_init(size_t size){
    int *ptr = malloc(size);
}