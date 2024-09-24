#include "memory_manager.h"

struct MemoryBlock{
    void *ptr;
    size_t size;
    int free;
    struct MemoryBlock* next;
    struct MemoryBlock* prev;
};

static void * m_block;
static size_t m_size;
static struct MemoryBlock * first_block;
static struct MemoryBlock * last_block;

void pop_mem(struct MemoryBlock* block){
    free(block);
}

struct MemoryBlock* add_mem(void* ptr, size_t size, int free, struct MemoryBlock* prev, struct MemoryBlock* next){
    printf("Adding memory %p, %ld, %d, %p, %p\n", ptr, size, free, next, prev);
    struct MemoryBlock* new_block = (struct MemoryBlock*)malloc(sizeof(struct MemoryBlock));
    *new_block = (struct MemoryBlock){ptr,size,free,next,prev};
    prev ? prev->next = new_block: 0;
    next ? next->prev = new_block : 0;
    printf("Added: n:%p, p:%p\n", next, prev);
    return new_block;
}

void split_mem(struct MemoryBlock* current_block, size_t size) {
    printf("Splitting %p, ptr=%p, %ld\n", current_block, current_block->ptr, size);
    size_t new_size = current_block->size-size;
    current_block->free = 0;
    current_block->size = size;
    current_block->next = add_mem(current_block->ptr+new_size, new_size, 1, current_block, current_block->next);
}

void merge_mem(struct MemoryBlock* block){
    if (block->next == NULL || block->next->free == 0) return;
    printf("Merge to stop fragment \n");
}

// Initializes the memory manager with a specified size of memory pool. 
void mem_init(size_t size){
    // TODO: om redan init: töm allt
    m_block = malloc(size);
    m_size = size;
    first_block = add_mem(m_block, m_size, 1, NULL, NULL);
}

// Allocates a block of memory of the specified size. Returns poitiers  
void* mem_alloc(size_t size){
    size = (size+7)&~7; // Align size by 8 
    struct MemoryBlock* current_block = first_block;
    while (current_block->free != 1 || current_block->size < size){
        printf("Looking: Size = %zu, Pointer = %p, Free= %d, \n", current_block->size, current_block->ptr, current_block->free);
        current_block = current_block->next;
    }
    split_mem(current_block, size);
    return current_block->ptr;
}

// Frees the specified block of memory
void mem_free(void* block){
    printf("Freeing %p\n", block);
    struct MemoryBlock * current_block = first_block;
    while (current_block != NULL && current_block->ptr != block){
        current_block = current_block->next;
    }
    if (current_block->ptr != block || current_block == NULL) return;
    current_block->free = 1;
    merge_mem(current_block);
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
    // Also remove metadata
    free(m_block);
}

int main(){
    int size = sizeof(int)*40;
    mem_init(size);
    void* block = mem_alloc(40);
    void* block2 = mem_alloc(40);
    mem_free(block2);
    printf("Allocated block %p\n", block);
    // mem_alloc(11);
    // mem_alloc(11);
    // mem_free(block);
    // void *ptr = mem_resize(block, 107);
    // printf("\n ptr = %p", ptr);
    // printf("--\n");
    // // mem_deinit();

    printf("\nListing all blocks:\n");
    struct MemoryBlock * current_block = first_block;
    while (current_block != NULL){
        printf("Block %p: Size = %zu, Pointer = %p, Free= %d, prev = %p, next = %p \n",current_block, current_block->size, current_block->ptr, current_block->free, current_block->prev, current_block->next);
        current_block = current_block->next;
    }

    return 0;
}