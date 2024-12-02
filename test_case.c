#include "memory.h"
#include <assert.h>
#include <string.h>

// test case 1: test allocate two blocks
int test_case_1() {
    Memory memory;
    init_memory(&memory, 1024);
    void *block1 = allocate_memory(&memory, 200);
    void *block2 = allocate_memory(&memory, 300);

    assert(block1 == memory.head->address);
    assert(block2 == block1 + 200);

    char output[1000];
    display_memory_sizes(&memory, output);
    assert(strcmp(output, "200 -> 300 -> 524 -> ") == 0);
    display_memory_status(&memory, output);
    assert(strcmp(output, "No -> No -> Yes -> ") == 0);
    return 0;
}

// test case 2: test allocate three blocks with total size larger than the memory pool
int test_case_2() {
    Memory memory;
    init_memory(&memory, 1024);
    void *block1 = allocate_memory(&memory, 200);
    void *block2 = allocate_memory(&memory, 300);
    void *block3 = allocate_memory(&memory, 700);

    assert(block1 == memory.head->address);
    assert(block2 == block1 + 200);
    assert(block3 == NULL);

    char output[1000];
    display_memory_sizes(&memory, output);
    assert(strcmp(output, "200 -> 300 -> 524 -> ") == 0);
    display_memory_status(&memory, output);
    assert(strcmp(output, "No -> No -> Yes -> ") == 0);
    return 0;
}

// test case 3: test allocate three blocks and free last block
int test_case_3() {
    Memory memory;
    init_memory(&memory, 1024);
    void *block1 = allocate_memory(&memory, 200);
    void *block2 = allocate_memory(&memory, 300);
    void *block3 = allocate_memory(&memory, 500);

    free_memory(&memory, block3);

    assert(block1 == memory.head->address);
    assert(block2 == block1 + 200);
    assert(block3 == block2 + 300);

    char output[1000];
    display_memory_sizes(&memory, output);
    assert(strcmp(output, "200 -> 300 -> 524 -> ") == 0);
    display_memory_status(&memory, output);
    assert(strcmp(output, "No -> No -> Yes -> ") == 0);
    return 0;
}
 
// test case 4: test allocate three blocks, free first two blocks and allocate a new block
int test_case_4() {
    Memory memory;
    init_memory(&memory, 1024);
    void *block1 = allocate_memory(&memory, 200);
    void *block2 = allocate_memory(&memory, 300);
    void *block3 = allocate_memory(&memory, 500);
    free_memory(&memory, block1);
    free_memory(&memory, block2);
    void *block4 = allocate_memory(&memory, 300);

    assert(block1 == memory.head->address);
    assert(block2 == block1 + 200);
    assert(block3 == block2 + 300);
    assert(block4 == block1);

    char output[1000];
    display_memory_sizes(&memory, output);
    assert(strcmp(output, "300 -> 200 -> 500 -> 24 -> ") == 0);
    display_memory_status(&memory, output);
    assert(strcmp(output, "No -> Yes -> No -> Yes -> ") == 0);
    return 0;
}

// test case 5: test allocate three blocks, free the first block, third block and allocate a new block
int test_case_5() {
    Memory memory;
    init_memory(&memory, 1024);
    void *block1 = allocate_memory(&memory, 200);
    void *block2 = allocate_memory(&memory, 300);
    void *block3 = allocate_memory(&memory, 500);
    free_memory(&memory, block1);
    free_memory(&memory, block3);
    void *block4 = allocate_memory(&memory, 300);

    assert(block1 == memory.head->address);
    assert(block2 == block1 + 200);
    assert(block3 == block2 + 300);
    assert(block4 == block3);

    char output[1000];
    display_memory_sizes(&memory, output);
    assert(strcmp(output, "200 -> 300 -> 300 -> 224 -> ") == 0);
    display_memory_status(&memory, output);
    assert(strcmp(output, "Yes -> No -> No -> Yes -> ") == 0);
    return 0;
}

// test case 6: test allocate three blocks, free second block then last block and allocate a new block
int test_case_6() {
    Memory memory;
    init_memory(&memory, 1024);
    void *block1 = allocate_memory(&memory, 200);
    void *block2 = allocate_memory(&memory, 300);
    void *block3 = allocate_memory(&memory, 500);
    free_memory(&memory, block2);
    free_memory(&memory, block3);
    void *block4 = allocate_memory(&memory, 300);

    assert(block1 == memory.head->address);
    assert(block2 == block1 + 200);
    assert(block3 == block2 + 300);
    assert(block4 == block2);

    char output[1000];
    display_memory_sizes(&memory, output);
    assert(strcmp(output, "200 -> 300 -> 524 -> ") == 0);
    display_memory_status(&memory, output);
    assert(strcmp(output, "No -> No -> Yes -> ") == 0);
    return 0;
}

// test case 7: test allocate three blocks, free the second block and allocate a new block
int test_case_7() {
    Memory memory;
    init_memory(&memory, 1024);
    void *block1 = allocate_memory(&memory, 200);
    void *block2 = allocate_memory(&memory, 300);
    void *block3 = allocate_memory(&memory, 500);
    free_memory(&memory, block2);
    void *block4 = allocate_memory(&memory, 200);

    assert(block1 == memory.head->address);
    assert(block2 == block1 + 200);
    assert(block3 == block2 + 300);
    assert(block4 == block2);

    char output[1000];
    display_memory_sizes(&memory, output);

    assert(strcmp(output, "200 -> 200 -> 100 -> 500 -> 24 -> ") == 0);
    display_memory_status(&memory, output);

    assert(strcmp(output, "No -> No -> Yes -> No -> Yes -> ") == 0);
    return 0;
}

// test case 8: test allocate three blocks, free the second block and allocate a new block then free the last block
int test_case_8() {
    Memory memory;
    init_memory(&memory, 1024);
    void *block1 = allocate_memory(&memory, 200);
    void *block2 = allocate_memory(&memory, 300);
    void *block3 = allocate_memory(&memory, 500);
    free_memory(&memory, block2);
    void *block4 = allocate_memory(&memory, 200);
    free_memory(&memory, block3);

    assert(block1 == memory.head->address);
    assert(block2 == block1 + 200);
    assert(block3 == block2 + 300);
    assert(block4 == block2);

    char output[1000];
    display_memory_sizes(&memory, output);
    assert(strcmp(output, "200 -> 200 -> 624 -> ") == 0);
    display_memory_status(&memory, output);
    assert(strcmp(output, "No -> No -> Yes -> ") == 0);
    return 0;
}

// test case 9: test allocate three blocks, free the second block and allocate a new block then free the first two blocks
int test_case_9() {
    Memory memory;
    init_memory(&memory, 1024);
    void *block1 = allocate_memory(&memory, 200);
    void *block2 = allocate_memory(&memory, 300);
    void *block3 = allocate_memory(&memory, 500);
    free_memory(&memory, block2);
    void *block4 = allocate_memory(&memory, 200);
    free_memory(&memory, block1);
    free_memory(&memory, block3);

    assert(block1 == memory.head->address);
    assert(block2 == block1 + 200);
    assert(block3 == block2 + 300);
    assert(block4 == block2);


    char output[1000];
    display_memory_sizes(&memory, output);
    assert(strcmp(output, "200 -> 200 -> 624 -> ") == 0);
    display_memory_status(&memory, output);
    assert(strcmp(output, "Yes -> No -> Yes -> ") == 0);
    return 0;
}

// test case 10: test allocate three blocks, free the second block and allocate a new block then free the first two blocks and allocate a new block
int test_case_10() {
    Memory memory;
    init_memory(&memory, 1024);
    void *block1 = allocate_memory(&memory, 200);
    void *block2 = allocate_memory(&memory, 300);
    void *block3 = allocate_memory(&memory, 500);
    free_memory(&memory, block2);
    void *block4 = allocate_memory(&memory, 300);
    free_memory(&memory, block1);
    free_memory(&memory, block3);
    free_memory(&memory, block4);
    void *block5 = allocate_memory(&memory, 500);

    assert(block1 == memory.head->address);
    assert(block2 == block1 + 200);
    assert(block3 == block2 + 300);
    assert(block4 == block2);
    assert(block5 == block1);

    char output[1000];
    display_memory_sizes(&memory, output);
    assert(strcmp(output, "500 -> 524 -> ") == 0);
    display_memory_status(&memory, output);
    assert(strcmp(output, "No -> Yes -> ") == 0);
    return 0;
}