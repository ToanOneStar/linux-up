#include <stdio.h>
#include <stdint.h>
int main()
{
    // cach 1
    int arr[2][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    int(*ptr)[4];
    ptr = arr;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", *(*(ptr + i) + j));
        }
        printf("\n");
    }
    // cach 2
    int *x = &arr[0][0]; // CT: ptr + i*C + j
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", *(x + i * 4 + j));
        }
        printf("\n");
    }
}