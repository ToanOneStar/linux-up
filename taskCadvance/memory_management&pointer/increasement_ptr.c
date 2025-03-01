#include <stdio.h>
#include <stdint.h>
uint64_t a = 0x0102030405060708;
uint8_t *d = &a;
uint8_t *b;
int main()
{
    b = (uint8_t *)d;
    printf("%d\n", *b); // 8
    b++;
    printf("%d\n", *b); // 7
    b++;
    printf("%d\n", *b); // 6
    b++;
    printf("%d\n", *b); // 5
    b++;
    return 0;
}