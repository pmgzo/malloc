#include "node.h"

#include <stdio.h>

int main()
{
    // printf("%ld\n", NODE_SIZE);
    // printf("%d\n", PAGE_SIZE);

    // printf("begin brk = %p\n", sbrk(0));
    char *str = malloc(5);
    // printf("la\n");
    // printf("after brk = %p\n", sbrk(0));
    // printf("str = %p\n", str);
    str[0] = 't';
    str[1] = 'o';
    str[2] = 't';
    str[3] = 'o';
    str[4] = 0;
    char *str2 = malloc(5);
    str2[0] = 't';
    str2[1] = 'o';
    str2[2] = 't';
    str2[3] = 'o';
    str2[4] = 0;
    // printf("%s\n", str);
    //create node
    return (0);
}