#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memory.h"

// Initialize memory with a single large block
void init_memory(Memory *memory, size_t total_size) {
    // Allocate memory for the head block
    memory->head = (Block *)malloc(sizeof(Block));

    // Initialize the head block
    // Your implementation here
}

// Allocate memory from the memory pool and return the address of the block
void* allocate_memory(Memory *memory, size_t size) {
    // Your implementation here
}

// Free allocated memory and merge adjacent free blocks
void free_memory(Memory *memory, void *ptr) {
    // Your implementation here
}

// Display the current memory blocks and their status
void display_memory(Memory *memory) {
    Block *current = memory->head;
    printf("\nMemory Blocks:\n");
    while (current != NULL) {
        printf("Block at %p: Size: %ld, Free: %s, Address: %p\n",
               (void *)current, current->size, current->is_free ? "Yes" : "No", current->address);
        current = current->next;
    }
}

// Display memory block sizes and write to a string
void display_memory_sizes(Memory *memory, char* output) {
    sprintf(output, "%s", "");
    Block *current = memory->head;
    while (current != NULL) {
        char temp_str[100];
        sprintf(temp_str, "%ld -> ", current->size);
        strcat(output, temp_str);
        current = current->next;
    }
#if DEBUG
    printf("%s\n", output);
#endif
}

// Display memory block status and write to a string
void display_memory_status(Memory *memory, char* output) {
    sprintf(output, "%s", "");
    Block *current = memory->head;
    while (current != NULL) {
        char temp_str[100];
        sprintf(temp_str, "%s -> ", current->is_free ? "Yes" : "No");
        strcat(output, temp_str);
        current = current->next;
    }
#if DEBUG
    printf("%s\n", output);
#endif
}

// Check all the link of the blocks, return 1 if all the links are correct, 0 otherwise
int check_link(Memory *memory) {
    Block *current = memory->head;
    while (current != NULL) {
        if (current->next) {
            if (current->next->prev != current) {
                return 0;
            }
        }
        current = current->next;
    }
    return 1;
}