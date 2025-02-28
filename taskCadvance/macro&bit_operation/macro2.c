#include <stdio.h>

#define min(X, Y) (((X) < (Y)) ? (X) : (Y))

int main()
{
    int a = 2, b = 3;
    printf("min = %d", min(a, b)); // 2
}