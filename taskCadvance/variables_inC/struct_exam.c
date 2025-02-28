#include <stdio.h>

struct test
{
    char a;   // 1 byte
    char b;   // 1
    char c;   // 1
    int e;    // 4
    char j;   // 1
    double f; // 8
};

int main()
{
    struct test exam;
    printf("%d\n", sizeof(exam)); // = 24
}