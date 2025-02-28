#include <stdio.h>
#include <string.h>

int main()
{
    int x;
    scanf("%d", &x);
    switch (x)
    {
    case 0:
        printf("x = 0\n");
        break;
    case 1:
        printf("x = 1\n");
        break;
    case 2:
        printf("x = 2\n");
        break;
    default:
        printf("other\n");
        break;
    }

    void *jump_table[] = {&&label0, &&label1, &&label2};
    if (x >= 0 && x <= 2)
    {
        goto *jump_table[x];
    }
    else
    {
        goto default_label;
    }

label0:
    printf("x = 0\n");
    goto end;
label1:
    printf("x = 1\n");
    goto end;
label2:
    printf("x = 2\n");
    goto end;
default_label:
    printf("other\n");
    goto end;
end:;
}