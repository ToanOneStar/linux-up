#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);
    switch (x)
    {
    case 10:
        printf("ten");
        break;
    case 20:
        printf("twenty");
        break;
    case 30:
        printf("thirty");
        break;
    default:
        printf("other");
        break;
    }

    if (x < 20)
    {
        if (x == 10)
            printf("ten");
        else
            printf("other");
    }
    else
    {
        if (x == 20)
            printf("twenty");
        else if (x == 30)
            printf("thirty");
        else
            printf("other");
    }
}