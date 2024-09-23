#include <stdio.h>
#include <stdlib.h>

void mem_init(size_t size);
void* mem_alloc(size_t size);
void mem_free(void* block);
void* mem_resize(void* block, size_t size);
void mem_deinit();

typedef struct{
    void *ptr;
    size_t size;
} MemoryBlock;

typedef struct{
    MemoryBlock * ptr;
    size_t pos;
    size_t size;
} MemList;

static int *main_block;
static int main_block_size;
static MemList * free_blocks;
static MemList * occ_blocks;

static void add_free_block(int *ptr, int size){
    if (free_blocks->pos >= free_blocks->size){
        // Resize
    }
    free_blocks->ptr[free_blocks->pos].ptr = ptr;
    free_blocks->ptr[free_blocks->pos].size = size;
    free_blocks->pos++;

    for (size_t i = 0; i < free_blocks->pos; i++) {
        printf("Free block %zu: Size = %zu, Pointer = %p\n", i, free_blocks->ptr[i].size, free_blocks->ptr[i].ptr);
    }
}

/** 
 * Initializes the memory manager with a specified size of memory pool. 
 * The memory pool could be any data structure, for instance, a large 
 * array or a similar contuguous block of memory. (You do not have to 
 * interact directly with the hardware or the operating system’s 
 * memory management functions).
*/
void mem_init(size_t size){
    printf("Initializing memory of size %ld \n",size);
    main_block = malloc(size);
    main_block_size = size;
    
    int slot_size = sizeof(void *)+sizeof(int);

    free_blocks = malloc(sizeof(MemList));
    occ_blocks = malloc(sizeof(MemList));

    free_blocks->ptr = malloc(20*(slot_size));
    occ_blocks->ptr = malloc(20*(slot_size));
    free_blocks->pos = 0;
    occ_blocks->pos = 0;
    free_blocks->size = 20*(slot_size);
    free_blocks->size = 20*(slot_size);

    add_free_block(main_block, size);
}

/**
 * Allocates a block of memory of the specified size. Find a 
 * suitable block in the pool, mark it as allocated, and return 
 * the pointer to the start of the allocated block.
 */
void* mem_alloc(size_t size){
    int* p = malloc(sizeof(int));
    *p = 10;
    return (void*)p;
}

/**
 * Frees the specified block of memory. For allocation and deallocation, 
 * you need a way to track which parts of the memory pool are free and which are allocated.
 */
void mem_free(void* block){
    return;
}

/**
 * Changes the size of the memory block, possibly moving it.
 */
void* mem_resize(void* block, size_t size){
    int* p = malloc(sizeof(int));
    *p = 10;
    return (void*)p;
}

/**
 * Frees up the memory pool that was initially allocated by the mem_init function, 
 * ensuring that all allocated memory is returned to the system.
 */
void mem_deinit(){
    return;
}

int main(){
    int size = sizeof(int)*4;
    mem_init(size);
    printf("Main block ptr %p\n", main_block);

    return 0;
}