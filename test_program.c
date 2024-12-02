#include <stdio.h>
#include <stdlib.h>

int test_case_1();
int test_case_2();
int test_case_3();
int test_case_4();
int test_case_5();
int test_case_6();
int test_case_7();
int test_case_8();
int test_case_9();
int test_case_10();


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <test_case_number>\n", argv[0]);
        return 1;
    }

    int test_case_number = atoi(argv[1]);
    
    switch (test_case_number)
    {   
        case 1:
            test_case_1();
            break;
        case 2:
            test_case_2();
            break;
        case 3:
            test_case_3();
            break;
        case 4:
            test_case_4();
            break;
        case 5:
            test_case_5();
            break;
        case 6:
            test_case_6();
            break;
        case 7:
            test_case_7();
            break;
        case 8:
            test_case_8();
            break;
        case 9:
            test_case_9();
            break;
        case 10:
            test_case_10();
            break;
    }
    return 0;
}