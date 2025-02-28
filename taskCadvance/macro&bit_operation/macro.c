#include <stdio.h>

#define SCREEN_ENABLE

int main()
{
#ifdef SCREEN_ENABLE // check xem SCREEN_ENABLE đã defined chưa -> YES
    printf("YES\n");
#else
    printf("NO\n");
#endif

#undef SCREEN_ENABLE // undefine SCREEN_ENABLE

#ifdef SCREEN_ENABLE // check xem SCREEN_ENABLE đã defined chưa -> NO
    printf("YES\n");
#else
    printf("NO\n");
#endif
}