#include <stdio.h>
#include <string.h>

int main()
{
    int x;
    scanf("%d", &x);
    if (x == 1)
    {
        printf("gia tri cua x = 1\n");
    }
    else if (x == 2)
    {
        printf("gia tri cua x = 2\n");
    }
    else
    {
        printf("x khac 1 va khac 2\n");
    }

    switch (x)
    {
    case 1:
        printf("gia tri cua x = 1\n");
        break;
    case 2:
        printf("gia tri cua x = 2\n");
        break;
    default:
        printf("x khac 1 va khac 2\n");
        break;
    }
}