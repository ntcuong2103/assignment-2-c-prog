#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block Block;
typedef struct Memory Memory;

struct Block {
    size_t size;               // Size of the block
    int is_free;               // Block status: 1 for free, 0 for allocated
    void *address;             // Address of the allocated memory
    Block *next;        // Pointer to the next block
    Block *prev;        // Pointer to the previous block
};

struct Memory {
    Block *head;               // Head of the doubly linked list
};

void init_memory(Memory *memory, size_t size);
void *allocate_memory(Memory *memory, size_t size);
void free_memory(Memory *memory, void *ptr);
void display_memory_sizes(Memory *memory, char* output);
void display_memory_status(Memory *memory, char* output);
void display_memory(Memory *memory);
