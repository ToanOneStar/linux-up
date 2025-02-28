#include <stdio.h>

int main()
{
    int a = 2;         // 010
    a = a << 1;        // 100
    printf("%d\n", a); // = 2*2 = 4
    // 110100 = 52
    int b = 52;
    b |= (1 << 3); // 111100 = 60
    printf("%d\n", b);
    // clear
    b &= ~(1 << 3);
    printf("%d\n", b); // 52
    // reading
    int bit = (b >> 3) & 1;
    printf("%d\n", bit); // 0
    // toggle
    b ^= (1 << 1); // 110110 = 54
    printf("%d", b);
}