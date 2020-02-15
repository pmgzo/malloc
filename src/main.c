#include "node.h"
// #include <stdlib.h>

int main()
{
    // printf("sbrk =%d\n", sbrk(0));
    char *str = malloc(64);
    // printf("sbrk =%d\n", sbrk(0));
    // printf("coco");
    // printf("%d\n", PAGE_SIZE);

    // malloc(83);
    // free(str);

    for (int i = 0; i < 65; i++) {
        // printf("coucou");
        str[i] = 90;
    }
    // printf("\n");

    // for (int i = 0; i < 64; i++, str[i]=0);
    // for (int i = 0; i <= 128 + 17; i++, str2[i]=0);
    // for (int i = 0; i < 4; i++, str3[i]=0);
    // free(str3);
    return (0);
}