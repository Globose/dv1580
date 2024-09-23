#include "memory_manager.h"

typedef struct{
    void *ptr;
    size_t size;
    int free;
} MemoryBlock;

static void * m_block;
static size_t m_size;
static MemoryBlock * blocks;
static size_t blocks_size;
static size_t blocks_pos;

void pop_mem(size_t index){
    blocks[index] = blocks[blocks_pos-1];
    blocks_pos--;
}

void add_mem(void* ptr, size_t size, int free){
    // TODO: add space if blockpos > blocksize
    blocks[blocks_pos] = (MemoryBlock){ptr, size, free};
    blocks_pos++;
}

// Initializes the memory manager with a specified size of memory pool. 
void mem_init(size_t size){
    // TODO: om redan init: töm allt
    m_block = malloc(size);
    m_size = size;
    blocks = malloc(sizeof(MemoryBlock)*16);
    blocks[0] = (MemoryBlock){m_block,size,1};
    blocks_pos = 1;
    blocks_size = 16;
}

// Allocates a block of memory of the specified size. Returns poitiers  
void* mem_alloc(size_t size){
    int block_index = -1;
    size = (size+7)&~7; // Align size by 8 
    for (size_t i = 0; i < blocks_pos; i++) {
        if (blocks[i].free == 1 && blocks[i].size >= size){
            if (block_index == -1){
                block_index = i;
            }
            else if (blocks[i].size < blocks[block_index].size){
                block_index = i;
            } 
        }
    }
    if (block_index == -1) return NULL;
    void * ptr = blocks[block_index].ptr;
    void * ptr_next = ptr + size;
    size_t size_next = blocks[block_index].size-size;
    pop_mem(block_index);
    add_mem(ptr, size, 0);
    add_mem(ptr_next, size_next, 1);
    return ptr;
}

// Frees the specified block of memory
void mem_free(void* block){
    for (int i = 0; i < blocks_pos; i++){
        if (blocks[i].ptr == block){
            blocks[i].free = 1;
            return;
        }
    }
}

// Changes the size of the memory block, possibly moving it.
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
    free(m_block);
}

int main(){
    int size = sizeof(int)*40;
    mem_init(size);
    void*block = mem_alloc(81);
    mem_alloc(11);
    mem_alloc(11);
    mem_free(block);
    void *ptr = mem_alloc(60);
    printf("\n ptr = %p", ptr);
    printf("--\n");
    mem_deinit();
    for (size_t i = 0; i < blocks_pos; i++) {
        printf("Block %ld: Size = %zu, Pointer = %p, Free= %d, \n", i, blocks[i].size, blocks[i].ptr, blocks[i].free);
    }

    return 0;
}